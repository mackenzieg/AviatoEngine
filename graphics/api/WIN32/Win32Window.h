#ifndef AVIATOENGINE_WIN32WINDOW_H
#define AVIATOENGINE_WIN32WINDOW_H

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN 1
    #include <Windows.h>

class Win32Window {
private:
    HINSTANCE m_hInstance;

};

#endif

#endif //AVIATOENGINE_WIN32WINDOW_H
