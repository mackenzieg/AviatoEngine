#include "Window.h"

Window::Window()
        : windowTitle(""),
          windowWidth(0),
          windowHeight(0),
          vsyncEnabled(false)
{
    this->init();
}

Window::Window(uint16_t windowWidth, uint16_t windowHeight)
        : windowTitle("GameEngine"),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(false)
{
    this->init();
}

Window::Window(char *windowTitle, uint16_t windowHeight, uint16_t windowWidth)
        : windowTitle(windowTitle),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(false)

{
    this->init();
}

Window::Window(char *windowTitle, uint16_t windowHeight, uint16_t windowWidth, bool vsyncEnabled)
        : windowTitle(windowTitle),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(vsyncEnabled)

{
    this->init();
}

Window::~Window()
{
    winState = WindowState::WindowShutDown;
    Memory::safeDelete(windowTitle);
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

void Window::init()
{
    winState = WindowState::WindowInit;
}

void Window::start()
{
    winState = WindowState::WindowStarted;
}

void Window::pause()
{
    winState = WindowState::WindowPaused;
}

void Window::stop()
{
    winState = WindowState::WindowStopped;
}