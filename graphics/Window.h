#ifndef AVIATOENGINE_WINDOW_H
#define AVIATOENGINE_WINDOW_H

#include <cstdint>

class Window {
private:
    const char* windowTitle;
    int16_t windowHeight, windowWidth;

public:
    Window();

    Window(const char *windowTitle, int16_t windowHeight, int16_t windowWidth);
};


#endif //AVIATOENGINE_WINDOW_H
