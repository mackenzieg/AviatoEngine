#ifndef AVIATOENGINE_PLATFORM_H
#define AVIATOENGINE_PLATFORM_H

#if defined(_WIN32)
    #define AVI_PLATFORM_WIN32 1

    #define WIN32_LEAN_AND_MEAN 1
    #include <Windows.h>
#elif defined(_apple) //TODO : Check if Apple Macro is Correct
    #define AVI_PLATFORM_APPLE 1

#elif defined(_unix) //TODO : Check if Linux Macro is Correct
    #define AVI_PLATFORM_LINUX 1

#else
    #error "OS Not Supported"
#endif

#endif //AVIATOENGINE_PLATFORM_H
