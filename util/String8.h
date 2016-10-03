#ifndef AVIATOENGINE_STRING_H
#define AVIATOENGINE_STRING_H

#include <cstring>
#include <cstdint>
#include <array>

#define DEFAULT_STRING8_SIZE 64
#define DEFAULT_STRING16_SIZE 32

class String8 {

public:
    String8();
    String8(uint_16 size);
    String8(char *input);

    void append(String8 other, bool ignoreLength = true);
    void append(char *input, bool ignoreLength = true);

    bool equals(String8 other);
    bool equals(char *input);

    bool contains(char input);
    bool contains(String8 input);

    String8 subString(uint16_t startIndex, uint16_t endIndex);

    char atPosition(uint16_t position);
    //String8 atPosition(uint16_t position);

private:
    //char *str;
    std::array<> *str;
    uint_16 length;

};


#endif //AVIATOENGINE_STRING_H
