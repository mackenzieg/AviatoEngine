#ifndef AVIATOENGINE_WIN32WINDOW_H
#define AVIATOENGINE_WIN32WINDOW_H

#include <cstdint>

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN 1
    #include <Windows.h>

class Win32Window {
public:
    static HINSTANCE hInstance;
    static bool initialized;

    HWND hwnd;
    int16_t screenWidth, screenHeight, windowWidth, windowHeight;

public:
    Win32Window();
    Win32Window(int16_t width, int16_t height);
    ~Win32Window();

    LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static Win32Window* ApplicationHandle = nullptr;

#endif

#endif //AVIATOENGINE_WIN32WINDOW_H
