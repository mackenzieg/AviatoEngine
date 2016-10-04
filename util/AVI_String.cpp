#include "AVI_String.h"

AVI_String::AVI_String(char *input) : str(new char[DEFAULT_AVI_STRING_SIZE]) {
    length = stringLength(input);
    memcpy(str, input, length);
    if (str[length] != '\0')
        str[length] = '\0';
}

uint16_t AVI_String::stringLength(char *input) {
    uint16_t size = 0;
    while (input[size] != '\0' || input[size] != '\n') {
        ++size;
    }
    return size;
}

void AVI_String::append(char *other) {
    uint16_t otherLength = stringLength(other);
    uint16_t total = length + otherLength;
    if (length + otherLength <= DEFAULT_AVI_STRING_SIZE) {
        memcpy(str + length, other, otherLength);
    }
    char *temp = new char[total + 1];
    memcpy(temp, str, length);
    memcpy(temp + length, other, otherLength);
    str[total] = '\0';
}

void AVI_String::append(AVI_String *other) {
    uint16_t otherLength = stringLength(other->str);
    uint16_t total = length + otherLength;
    if (length + otherLength <= DEFAULT_AVI_STRING_SIZE) {
        memcpy(str + length, other, otherLength);
    }
    char *temp = new char[total + 1];
    memcpy(temp, str, length);
    memcpy(temp + length, other, otherLength);
    str[total] = '\0';
}

char* AVI_String::subString(uint16_t start, uint16_t end) {
    uint16_t difference = end - start;
    char* subStr = new char[difference + 1];
    memcpy(subStr, this->str + difference, difference);
    subStr[difference] = '\0';
    return subStr;
}

AVI_String& AVI_String::operator=(const AVI_String &other) {
    return *(new AVI_String(other.str));
}

AVI_String& AVI_String::operator=(const char* other) {
    return *(new AVI_String((char *) other));
}

AVI_String& AVI_String::operator+=(const AVI_String &other) {
    this->append(other.str);
    return *(this);
}

AVI_String& AVI_String::operator+=(const char* other) {
    this->append((char *) other);
    return *(this);
}

AVI_String& AVI_String::operator+(const AVI_String &other) {
    uint16_t otherLength = other.length;
    uint16_t total = length + otherLength;
    char *newString = new char[(length + otherLength) <= DEFAULT_AVI_STRING_SIZE ? 64 : total];
    newString = new char[total + 1];
    memcpy(newString, str, length);
    memcpy(newString + length, str, otherLength);
    newString[total] = '\0';
    return *(new AVI_String(newString));
}

AVI_String& AVI_String::operator+(const char *other) {

}

bool AVI_String::operator==(const AVI_String &other) const {
    for (int i = 0; i < length; i++) {
        if (other.str[i] != str[i])
            return false;
    }
    return true;
}

bool AVI_String::operator!=(const AVI_String &other) const {
    for (int i = 0; i < length; i++) {
        if (other.str[i] != str[i])
            return true;
    }
    return false;
}

std::ostream& AVI_String::operator<<(std::ostream& stream) {
    std::cout << "" << std::endl;
    stream << "asdasdas";
    stream << this->str;
    return stream;
}

char AVI_String::atLocation(uint16_t location) {
#ifdef ERROR_CHECKING
    if(location > length) {
        return '\0';
    }
#endif
    return str[location];
}

char *AVI_String::getHandle() {
    return str;
}

uint16_t AVI_String::getLength() {
    return length;
}

AVI_String::~AVI_String() {
    Memory::safeDeleteArray(str);
}