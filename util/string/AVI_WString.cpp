#include "AVI_WString.h"

AVI_WString::AVI_WString() : str(new uint16_t[DEFAULT_AVI_WSTRING_SIZE]) {
    length = DEFAULT_AVI_WSTRING_SIZE;
    str[0] = 0;
}

AVI_WString::AVI_WString(uint16_t *input) : str(new uint16_t[DEFAULT_AVI_WSTRING_SIZE]) {
    length = stringLength(input);
    memcpy(str, input, length);
    if (str[length] != 0) {
        str[length] = 0;
    }
}

uint16_t AVI_WString::stringLength(uint16_t *input) {
    uint16_t size = 0;

    while (input[size] != '\0') {
        ++size;
    }
    return size;
}

void AVI_WString::append(uint16_t *other) {
    uint16_t otherLength = stringLength(other);
    uint16_t total = length + otherLength;
    if (length + otherLength <= DEFAULT_AVI_WSTRING_SIZE) {
        memcpy(str + length, other, otherLength);
    }
    char *temp = new char[total + 1];
    memcpy(temp, str, length);
    memcpy(temp + length, other, otherLength);
    str[total] = 0;
}

void AVI_WString::append(AVI_WString *other) {
    uint16_t otherLength = stringLength(other->str);
    uint16_t total = length + otherLength;
    if (length + otherLength <= DEFAULT_AVI_WSTRING_SIZE) {
        memcpy(str + length, other, otherLength);
    }
    char *temp = new char[total + 1];
    memcpy(temp, str, length);
    memcpy(temp + length, other, otherLength);
    str[total] = 0;
}

uint16_t *AVI_WString::subString(uint16_t start, uint16_t end) {
    uint16_t difference = end - start;
    uint16_t *subStr = new uint16_t[difference + 1];
    memcpy(subStr, this->str + difference, difference);
    subStr[difference] = '\0';
    return subStr;
}

AVI_WString &AVI_WString::operator=(const AVI_WString &other) {
    return *(new AVI_WString(other.str));
}

AVI_WString &AVI_WString::operator=(const uint16_t *other) {
    return *(new AVI_WString((uint16_t *) other));
}

AVI_WString &AVI_WString::operator+=(const AVI_WString &other) {
    this->append(other.str);
    return *(this);
}

AVI_WString &AVI_WString::operator+=(const uint16_t *other) {
    this->append((uint16_t *) other);
    return *(this);
}

AVI_WString &AVI_WString::operator+(const AVI_WString &other) {
    uint16_t otherLength = other.length;
    uint16_t total = length + otherLength;
    uint16_t *newString = new uint16_t[(length + otherLength) <= DEFAULT_AVI_WSTRING_SIZE ? 64 : total];
    newString = new uint16_t[total + 1];
    memcpy(newString, str, length);
    memcpy(newString + length, str, otherLength);
    newString[total] = '\0';
    return *(new AVI_WString(newString));
}

AVI_WString &AVI_WString::operator+(const uint16_t *other) {
    this->append((uint16_t *) other);
    return (AVI_WString &) this;
}

bool AVI_WString::operator==(const AVI_WString &other) const {
    for (int i = 0; i < length; i++) {
        if (other.str[i] != str[i])
            return false;
    }
    return true;
}

bool AVI_WString::operator!=(const AVI_WString &other) const {
    for (int i = 0; i < length; i++) {
        if (other.str[i] != str[i])
            return true;
    }
    return false;
}

std::ostream &AVI_WString::operator<<(std::ostream &stream) {
    stream << str;
    return stream;
}

uint16_t AVI_WString::atLocation(uint16_t location) {
#ifdef ERROR_CHECKING
    if(location > length) {
        return 0;
    }
#endif
    return str[location];
}

uint16_t *AVI_WString::getHandle() {
    return str;
}

uint16_t AVI_WString::getLength() {
    return length;
}

AVI_WString::~AVI_WString() {
    Memory::safeDeleteArray(str);
}