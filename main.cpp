#include <iostream>
#include <cstdlib>
#include <Vector4.h>
#include "graphics/api/Platform.h"
#include "graphics/api/WIN32/Win32Window.h"
#include "string/AVI_String.h"

//#include "util/LeakDetector.h"

#if defined(AVI_PLATFORM_WIN32)

//Window Entry Point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    //atexit(report_mem_leak);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);


#if 0
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
#endif
    return 0;
}

#elif defined(AVI_PLATFORM_APPLE) || defined(AVI_PLATFORM_LINUX)

int main(int argc, char **argv)
{


    //Use for Apple and Linux Creation//Entry Point
}

#else

#error "OS NOT SUPPORTED"

#endif
