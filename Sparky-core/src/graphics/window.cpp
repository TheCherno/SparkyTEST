#include "window.h"

Window* Window::INSTANCE;

Window::Window(const char *title, unsigned int width, unsigned int height)
{
    this->title = title;
    this->width = width;
    this->height = height;
    bits = 32;

    if (create())
        INSTANCE = this;
}

Window::~Window()
{
}

bool Window::create()
{
    wInfo.hInstance = GetModuleHandle(NULL);
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc = (WNDPROC)Window::WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = wInfo.hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "Window";

    if (!RegisterClass(&wc))
    {
        MessageBox(NULL, "Registering class failed!", "Error", MB_OK | MB_ICONEXCLAMATION);
        return false;
    }

    GLuint pformat;
    PIXELFORMATDESCRIPTOR pfd =
    {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA, bits, 0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        16,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    wInfo.hWnd = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
        "Window", title,
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
        GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2, width, height, NULL, NULL, wInfo.hInstance, NULL);
    if (!wInfo.hWnd)
    {
        MessageBox(NULL, "Window creation failed!", "Error", MB_OK | MB_ICONEXCLAMATION);
        return false;
    }
    if (!(wInfo.hDC = GetDC(wInfo.hWnd)))
    {
        std::cout << "Creating device context failed!" << std::endl;
        return false;
    }
    if (!(pformat = ChoosePixelFormat(wInfo.hDC, &pfd)))
    {
        std::cout << "Finding pixel format failed!" << std::endl;
        return false;
    }
    if (!SetPixelFormat(wInfo.hDC, pformat, &pfd))
    {
        std::cout << "Setting pixel format failed!" << std::endl;
        return false;
    }
    if (!(wInfo.hRC = wglCreateContext(wInfo.hDC)))
    {
        std::cout << "Creating OpenGL context failed!" << std::endl;
        return false;
    }

    if (!wglMakeCurrent(wInfo.hDC, wInfo.hRC))
    {
        std::cout << "Setting OpenGL context failed!" << std::endl;
        return false;
    }

    GLenum error = glewInit();
    if (error != GLEW_OK)
        std::cout << "Error: " << glewGetErrorString(error) << std::endl;

    std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

    ShowWindow(wInfo.hWnd, SW_SHOW);
    return true;
}

void Window::set_title(const char *title)
{
    this->title = title;
    SetWindowText(wInfo.hWnd, title);
}

unsigned int Window::get_width() const
{
    return width;
}

unsigned int Window::get_height() const
{
    return height;
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        Window::INSTANCE->quit = true;
        break;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void Window::update()
{
    MSG msg;
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            quit = true;
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    SwapBuffers(wInfo.hDC);
}
