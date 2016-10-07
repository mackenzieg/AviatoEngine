#ifndef AVIATOENGINE_WINDOW_H
#define AVIATOENGINE_WINDOW_H

#include <cstdint>

#include "AVI_Memory.h"

enum struct WindowState
{
    NoState = 0,
    WindowInit,
    WindowStarted,
    WindowPaused,
    WindowStopped,
    WindowShutDown,
};

class Application {
private:
    char* windowTitle;
    uint16_t windowWidth, windowHeight;

    bool vsyncEnabled;

    WindowState winState = WindowState::NoState;

public:
    Application();
    Application(uint16_t windowWidth, uint16_t windowHeight);
    Application(char *windowTitle, uint16_t windowWidth, uint16_t windowHeight);
    Application(char *windowTitle, uint16_t windowWidth, uint16_t windowHeight, bool vsyncEnabled);

    ~Application();

    void setTitle(char* newWindowTitle);
    void setWindowSize(uint16_t newWindowWidth, uint16_t newWindowHeight);
    void setVsync(bool newVsyncState);

    void init();
    void start();
    void pause();
    void stop();
};


#endif //AVIATOENGINE_WINDOW_H
