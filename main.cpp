#include "graphics/api/Platform.h"
#include "graphics/api/WIN32/Win32Window.h"

#include <iostream>

#if defined(AVI_PLATFORM_WIN32)

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    Win32Window appWindow = Win32Window(hInstance, 1280, 720);

    MSG msg{};

    while (1) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        if (msg.message == WM_QUIT) {
            break;
        }
    }
}

#elif defined(AVI_PLATFORM_APPLE) || defined(AVI_PLATFORM_LINUX)

int main(int argc, char **argv)
{
    //Use for Apple and Linux Creation//Entry Point
}

#else

#error "OS NOT SUPPORTED"

#endif
