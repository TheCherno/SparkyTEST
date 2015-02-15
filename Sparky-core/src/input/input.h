#pragma once

class Input
{
private:
    bool quit;
public:
    Input();
    void update();
    bool closed();
};