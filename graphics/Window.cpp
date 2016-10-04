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

Window::Window(char *windowTitle, uint16_t windowHeight, uint16_t windowWidth)
        : windowTitle(windowTitle),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(false)

{
    this->Init();
}

Window::Window(char *windowTitle, uint16_t windowHeight, uint16_t windowWidth, bool vsyncEnabled)
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

void Window::setTitle(char* newWindowTitle)
{
    this->windowTitle = newWindowTitle;
}

void Window::setWindowSize(uint16_t newWindowWidth, uint16_t newWindowHeight)
{
    this->windowWidth = newWindowWidth;
    this->windowHeight = newWindowHeight;
}

void Window::setVsync(bool newVsyncState)
{
    this->vsyncEnabled = newVsyncState;
}

void Window::Init()
{
    winState = WindowState::WindowInit;
}

void Window::Start()
{
    winState = WindowState::WindowStarted;
}

void Window::Pause()
{
    winState = WindowState::WindowPaused;
}

void Window::Stop()
{
    winState = WindowState::WindowStopped;
}