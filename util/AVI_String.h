#ifndef AVIATOENGINE_AVI_STRING_H
#define AVIATOENGINE_AVI_STRING_H

#include <cstdint>
#include <cstring>

#include "AVI_Memory.h"

#define DEFAULT_AVI_STRING_SIZE 64

class AVI_String {

public:

    AVI_String();

    AVI_String(char *input);

    void append(char *other);

    uint16_t stringLength(char* input);

    void append(AVI_String *other);

    char* subString(uint16_t start, uint16_t end);

    char atLocation(uint16_t location);

    AVI_String &operator=(const AVI_String &other);

    AVI_String &operator=(const char* other);

    AVI_String &operator+=(const AVI_String &other);

    AVI_String &operator+=(const char* other);

    AVI_String &operator+(const AVI_String &other);

    AVI_String &operator+(const char* other);

    bool operator==(const AVI_String &other) const;

    bool operator!=(const AVI_String &other) const;

    char* getHandle();

    uint16_t getLength();

    ~AVI_String();

private:
    char *str;
    uint16_t length;

};


#endif //AVIATOENGINE_AVI_STRING_H
