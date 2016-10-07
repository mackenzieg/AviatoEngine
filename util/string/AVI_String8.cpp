#include <cstdio>
#include "AVI_String8.h"

int str8Printf(const str8 string) {
    return printf((char*) string);
}

/* Calculates the length of the string by looking for a null character */
uint16_t str8Length(const char *string) {
    uint16_t size = 0;
    while (string[size] != '\0') {
        size++;
    }
    return size;
}

/* Generates a new str8 from data with a length of initLength */
str8 str8NewLength(const void *data, uint16_t initLength) {
    void *memReference = malloc(AVI_STRING8_LENGTH + initLength + 1);
    str8 string;
    if (data == nullptr) {
        memset(memReference, 0, AVI_STRING8_LENGTH + initLength + 1);
    }
    if (memReference == nullptr)
        return NULL;
    string = (char *) memReference + AVI_STRING8_LENGTH;
    str8SetLengthAllocated(string, initLength, initLength);
    memcpy(string, data, initLength);
    string[initLength] = '\0';
    return string;
}

/* Generates a new str8 from the data provided */
str8 str8New(const char *data) {
    return str8NewLength(data, str8Length(data));
}

/* Add more free space to the end. Requires copying.. slow */
str8 str8MakeRoomFor(str8 string, uint16_t addLength) {
    uint16_t available = str8GetAvailable(string);
    if (available >= addLength)
        return string;
    uint16_t newLength = str8GetLength(string) + addLength;

    /* Make this smarter.. literally just doubles */
    if (newLength < STR8_MAX_PREALLOCATED) {
        newLength *= 2;
    } else {
        newLength += STR8_MAX_PREALLOCATED;
    }

    void *newStr = realloc(string, newLength + AVI_STRING8_LENGTH + 1);
    if (newStr == NULL)
        return NULL;
    string = (char *) newStr + newLength;
    str8SetAllocate(string, newLength);
    return string;
}

/* Removes all free space at the end of str8 */
str8 str8RemoveFreeSpace(str8 string) {
    uint16_t stringLength = str8Length((const char *) string);
    void *newString = realloc(string, AVI_STRING8_LENGTH + stringLength + 1);
    if (newString == NULL)
        return NULL;
    string = (char *) newString + AVI_STRING8_LENGTH;
    str8SetAllocate(string, stringLength);
    return string;
}

/* Adds other to end of string */
str8 str8Append(str8 string, const char *other) {
    uint16_t currentLength = str8Length(other);
    string = str8MakeRoomFor(string, currentLength);
    if (string == NULL)
        return NULL;
    memcpy(string + currentLength, other, currentLength);
    str8SetLength(string, currentLength + currentLength);
    string[currentLength + currentLength] = '\0';
    return string;
}

/* Adds other to end of string with known length */
str8 str8Append(str8 string, const char *other, uint16_t otherLength) {
    uint16_t currentLength = str8Length(other);
    string = str8MakeRoomFor(string, otherLength);
    if (string == NULL)
        return NULL;
    memcpy(string + currentLength, other, otherLength);
    str8SetLength(string, currentLength + otherLength);
    string[currentLength + otherLength] = '\0';
    return string;
}

/* Recalculates the string length */
void str8UpdateLength(str8 string) {
    str8SetLength(string, str8Length((const char *) string));
}

/* Set the length to 0 and puts the null character at start */
void str8Clear(str8 string) {
    str8SetLength(string, 0);
    string[0] = '\0';
}

/* Frees the memory of the structure */
void str8Free(str8 string) {
    if (string == NULL)
        return;
    free(string - (sizeof(struct AVI_String8)));
}

//std::ostream& operator<< (std::ostream& stream, const str8 &string) {
//    stream << string;
//    return stream;
//}

