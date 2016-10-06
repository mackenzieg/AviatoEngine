#include "AVI_String8.h"

uint16_t str8Length(const char* string) {
    uint16_t size = 0;
    while(string[size] != '\0') {
        size++;
    }
    return size;
}

str8 str8NewLength(const void *data, uint16_t initLength) {
    void *sh = malloc(AVI_STRING8_LENGTH + initLength + 1);
    str8 string;
    if(data == nullptr) {
        memset(sh, 0, AVI_STRING8_LENGTH + initLength + 1);
    }
    if(sh == nullptr)
        return NULL;
    string = (char*) sh + AVI_STRING8_LENGTH;
    str8SetLengthAllocated(string, initLength, initLength);
    memcpy(string, data, initLength);
    string[initLength] = '\0';
    return string;
}

str8 str8New(const char *data) {
    return str8NewLength(data, str8Length(data));
}

void str8Free(str8 string) {
    if(string == NULL)
        return;
    free(string - (sizeof(struct AVI_String8)));
}

