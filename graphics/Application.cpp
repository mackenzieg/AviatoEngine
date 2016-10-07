#include "Application.h"

Application::Application()
        : windowTitle((char *) ""),
          windowWidth(0),
          windowHeight(0),
          vsyncEnabled(false)
{
    this->init();
}

Application::Application(uint16_t windowWidth, uint16_t windowHeight)
        : windowTitle((char *) "GameEngine"),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(false)
{
    this->init();
}

Application::Application(char *windowTitle, uint16_t windowHeight, uint16_t windowWidth)
        : windowTitle(windowTitle),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(false)

{
    this->init();
}

Application::Application(char *windowTitle, uint16_t windowHeight, uint16_t windowWidth, bool vsyncEnabled)
        : windowTitle(windowTitle),
          windowWidth(windowWidth),
          windowHeight(windowHeight),
          vsyncEnabled(vsyncEnabled)

{
    this->init();
}

Application::~Application()
{
    winState = WindowState::WindowShutDown;
    Memory::safeDelete(windowTitle);
}

void Application::setTitle(char* newWindowTitle)
{
    this->windowTitle = newWindowTitle;
}

void Application::setWindowSize(uint16_t newWindowWidth, uint16_t newWindowHeight)
{
    this->windowWidth = newWindowWidth;
    this->windowHeight = newWindowHeight;
}

void Application::setVsync(bool newVsyncState)
{
    this->vsyncEnabled = newVsyncState;
}

void Application::init()
{
    winState = WindowState::WindowInit;
}

void Application::start()
{
    winState = WindowState::WindowStarted;
}

void Application::pause()
{
    winState = WindowState::WindowPaused;
}

void Application::stop()
{
    winState = WindowState::WindowStopped;
}