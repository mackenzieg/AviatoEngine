#ifndef AVIATOENGINE_WINDOW_H
#define AVIATOENGINE_WINDOW_H

#include <cstdint>

#include "Memory.h"

enum struct WindowState
{
    NoState = 0,
    WindowInit,
    WindowStarted,
    WindowPaused,
    WindowStopped,
    WindowShutDown,
};

class Window {
private:
    char* windowTitle;
    uint16_t windowWidth, windowHeight;

    bool vsyncEnabled;

    WindowState winState = WindowState::NoState;

public:
    Window();
    Window(uint16_t windowWidth, uint16_t windowHeight);
    Window(char *windowTitle, uint16_t windowWidth, uint16_t windowHeight);
    Window(char *windowTitle, uint16_t windowWidth, uint16_t windowHeight, bool vsyncEnabled);

    ~Window();

    void setTitle(char* newWindowTitle);
    void setWindowSize(uint16_t newWindowWidth, uint16_t newWindowHeight);
    void setVsync(bool newVsyncState);

    void Init();
    void Start();
    void Pause();
    void Stop();
};


#endif //AVIATOENGINE_WINDOW_H
