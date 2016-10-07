#ifndef AVIATOENGINE_AVI_WSTRING_H
#define AVIATOENGINE_AVI_WSTRING_H

#include <cstdint>
#include <iostream>
#include <cstring>

#include "AVI_Memory.h"

#define DEFAULT_AVI_WSTRING_SIZE 64

class AVI_WString {

public:

    AVI_WString();

    AVI_WString(uint16_t *input);

    void append(uint16_t *other);

    uint16_t stringLength(uint16_t *input);

    void append(AVI_WString *other);

    uint16_t *subString(uint16_t start, uint16_t end);

    uint16_t atLocation(uint16_t location);

    AVI_WString &operator=(const AVI_WString &other);

    AVI_WString &operator=(const uint16_t *other);

    AVI_WString &operator+=(const AVI_WString &other);

    AVI_WString &operator+=(const uint16_t *other);

    AVI_WString &operator+(const AVI_WString &other);

    AVI_WString &operator+(const uint16_t *other);

    bool operator==(const AVI_WString &other) const;

    bool operator!=(const AVI_WString &other) const;

    std::ostream &operator<<(std::ostream &stream);

    uint16_t *getHandle();

    uint16_t getLength();

    ~AVI_WString();

private:
    uint16_t *str;
    uint16_t length;

};

#endif //AVIATOENGINE_AVI_WSTRING_H
