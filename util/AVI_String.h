#ifndef AVIATOENGINE_AVI_STRING_H
#define AVIATOENGINE_AVI_STRING_H

#include <cstdint>
#include <cstring>

#define DEFAULT_AVI_STRING_SIZE 64

class AVI_String {

public:

    uint16_t stringLength(char* input);

    AVI_String();

    AVI_String(char *input);

    void append(char *other);

    void append(AVI_String *other);

    char* subString(uint16_t start, uint16_t end);

    char atLocation(uint16_t location);

private:
    char *str;
    uint16_t length;

};


#endif //AVIATOENGINE_AVI_STRING_H
