#include "Window.h"

Window::Window()
        : windowTitle(""),
          windowWidth(0),
          windowHeight(0),
          vsyncEnabled(false)
{
    this->Init();
}

Window::Window(uint16_t windowWidth, uint16_t windowHeight)
        : windowTitle("GameEngine"),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(false)
{
    this->Init();
}


Window::Window(const char *windowTitle, int16_t windowHeight, int16_t windowWidth)
        : windowTitle(windowTitle),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(false)

{
    this->Init();
}

Window::Window(const char *windowTitle, int16_t windowHeight, int16_t windowWidth, bool vsyncEnabled)
        : windowTitle(windowTitle),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(vsyncEnabled)

{
    this->Init();
}

Window::~Window()
{
    winState = WindowState::WindowShutDown;
    Memory::SafeDelete(windowTitle);
}

Window::setTitle(const char* newWindowTitle)
{
    this->windowTitle = newWindowtitle;
}

Window::setWindowSize(uint16_t newWindowWidth, uint16_t newWindowHeight)
{
    this->windowWidth = newWindowWidth;
    this->windowHeight = newWindowHeight;
}

Window::setVsync(bool newVsyncState)
{
    this->vsyncEnabled = newVsyncState;
}

Window::Init()
{
    winState = WindowState::WindowInit;
}

Window::Start()
{
    winState = WindowState::WindowStarted;
}

Window::Pause()
{
    winState = WindowState::WindowPaused;
}

Window::Stop()
{
 winState = WindowState::WindowStopped;
}