#ifndef AVIATOENGINE_AVI_STRING8_H
#define AVIATOENGINE_AVI_STRING8_H

#include <cstdint>
#include <cstring>
#include <stdlib.h>

typedef char* str8;

struct __attribute__ ((__packed__)) AVI_String8 {
    uint16_t length;
    uint16_t allocate;
    char buffer[];
};

#define AVI_STRING8_LENGTH sizeof(struct AVI_String8)

static inline void str8SetLength(str8 string, uint16_t newLength) {
    ((AVI_String8*)((string) - (sizeof(AVI_String8))))->length = newLength;
}

static inline void str8SetAllocate(str8 string, uint16_t newAllocate) {
    ((AVI_String8*)((string) - (sizeof(AVI_String8))))->allocate = newAllocate;
}

static inline int str8GetAvaliable(const str8 string) {
    struct AVI_String8 *ref = (AVI_String8 *) ((str8) - (sizeof(struct AVI_String8)));
    return ref->allocate - ref->length;
}

uint16_t str8Length(char* string);

str8 str8NewLength(const void *data, int initLength);
str8 str8New(const char *data);

void str8Free(str8 string);


#endif //AVIATOENGINE_AVI_STRING8_H
