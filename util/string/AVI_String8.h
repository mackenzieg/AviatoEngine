#ifndef AVIATOENGINE_AVI_STRING8_H
#define AVIATOENGINE_AVI_STRING8_H

#include <cstdint>
#include <cstring>
#include <stdlib.h>
#include <cstdio>

typedef char* str8;

struct __attribute__ ((__packed__)) AVI_String8 {
    uint16_t length;
    uint16_t allocate;
    char buffer[];
};

#define AVI_STRING8_LENGTH sizeof(struct AVI_String8)

/* Maybe too much.. */
#define STR8_MAX_PREALLOCATED 1048576

static inline void str8SetLength(str8 string, uint16_t newLength) {
    ((AVI_String8*)((string) - (sizeof(AVI_String8))))->length = newLength;
}

static inline void str8SetAllocate(str8 string, uint16_t newAllocate) {
    ((AVI_String8*)((string) - (sizeof(AVI_String8))))->allocate = newAllocate;
}

static inline void str8SetLengthAllocated(str8 string, uint16_t newLength, uint16_t newAllocated) {
    struct AVI_String8 *ref = (AVI_String8 *) ((str8) - (sizeof(struct AVI_String8)));
    ref->length = newLength;
    ref->allocate = newAllocated;
}

static inline uint16_t str8GetAvailable(const str8 string) {
    struct AVI_String8 *ref = (AVI_String8 *) ((str8) - (sizeof(struct AVI_String8)));
    return ref->allocate - ref->length;
}

static inline uint16_t str8GetLength(str8 string) {
    return ((AVI_String8 *) ((str8) - (sizeof(struct AVI_String8))))->length;
}

static inline uint16_t str8GetAllocated(str8 string) {
    return ((AVI_String8 *) ((str8) - (sizeof(struct AVI_String8))))->allocate;
}

int str8Printf(const str8 string);

/* Calculates the length of the string by looking for a null character */
uint16_t str8Length(char* string);

/* Generates a new str8 from data with a length of initLength */
str8 str8NewLength(const void *data, int initLength);

/* Generates a new str8 from the data provided */
str8 str8New(const char *data);

/* Generates a new str8 from the data provided with no extra allocated space */
str8 str8NewNoFreeSpace(const char *data);

/* Add more free space to the end. Requires copying.. slow */
str8 str8MakeRoomFor(str8 string, uint16_t addLength);

/* Removes all free space at the end of str8 */
str8 str8RemoveFreeSpace(str8 string);

/* Adds other to end of string */
str8 str8Append(str8 string, const char *other);

/* Adds other to end of string with known length */
str8 str8Append(str8 string, const char *other, uint16_t otherLength);

/* Adds other str8 to string */
str8 str8Append(str8 string, const str8 other);


/* Recalculates the string length */
void str8UpdateLength(str8 string);

 /* Set the length to 0 and puts the null character at start */
void str8Clear(str8 string);

/* Frees the memory of the structure */
void str8Free(str8 string);

#endif //AVIATOENGINE_AVI_STRING8_H
