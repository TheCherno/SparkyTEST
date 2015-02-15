#pragma once

#include <windows.h>
#include <GL/glew.h>
#include <iostream>
#include <stdexcept>

struct WinInfo
{
    HWND hWnd;
    HGLRC hRC;
    HDC hDC;
    HINSTANCE hInstance;
};

class Window
{
private:
    unsigned int width, height;
    const char *title;
    int bits;
    WinInfo wInfo;
    bool quit;
    static Window *INSTANCE;
public:
    Window(const char *title, unsigned int width, unsigned int height);
    ~Window();
    void set_title(const char *title);
    unsigned int get_width() const;
    unsigned int get_height() const;
    void update();
    bool closed() { return quit; }
private:
    bool create();
public:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};