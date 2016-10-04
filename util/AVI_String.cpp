#include "AVI_String.h"

uint16_t AVI_String::stringLength(char* input) {
    uint16_t size = 0;
    while (input[size] != '\0' || input[size] != '\n') {
        ++size;
    }
    return size;
}

AVI_String::AVI_String() : length(0), str(new char[DEFAULT_AVI_STRING_SIZE + 1]) {
    str[0] = '\0';
}

AVI_String::AVI_String(char *input) : str(new char[DEFAULT_AVI_STRING_SIZE]) {
    length = stringLength(input);
    memcpy(str, input, length);
    if(str[length] != '\0')
        str[length] = '\0';
}

void AVI_String::append(char *other) {
    uint16_t otherLength = stringLength(other);
    uint16_t total = length + otherLength;
    if(length + otherLength <= DEFAULT_AVI_STRING_SIZE) {
        memcpy(str + length, other, otherLength);
    }
    char *temp = new char[total + 1];
    memcpy(temp, str, length);
    memcpy(temp + length, other, otherLength);
    str[total] = '\0';
}

void AVI_String::append(AVI_String *other) {

}

char* AVI_String::subString(uint16_t start, uint16_t end) {

}

char AVI_String::atLocation(uint16_t location) {

}
