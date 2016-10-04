#ifndef AVIATOENGINE_AVI_STRING_H
#define AVIATOENGINE_AVI_STRING_H

#include <cstdint>

class AVI_String {

public:

    AVI_String();
    AVI_String(uint16_t length);
    AVI_String(char *input);

private:
    char *str;
    uint16_t length;

};


#endif //AVIATOENGINE_AVI_STRING_H
