#include "Window.h"

Window::Window()
        : windowTitle(""),
          windowWidth(0),
          windowHeight(0) {

}

Window::Window(const char *windowTitle, int16_t windowHeight, int16_t windowWidth)
        : windowTitle(windowTitle),
          windowHeight(windowHeight),
          windowWidth(windowWidth) {

}
