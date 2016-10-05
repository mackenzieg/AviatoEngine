#ifndef AVIATOENGINE_AVI_STRING_H
#define AVIATOENGINE_AVI_STRING_H

#include <cstdint>

#define MAX_ALLOCATION 1024

#define AVI_STRING_TYPE_8 0
#define AVI_STRING_TYPE_16 1

#define AVI_STRING_TYPE_MASK 0b00000111

typedef char *str;

/* Tell compiler not to reorder in memory */
struct __attribute__ ((__packed__)) AVI_String8 {
    uint8_t length;
    /* How many bytes allocated excluding header and null term */
    uint8_t allocate;
    /* Contains the flags such as type, will add more flags */
    unsigned char flags;    // contains the flags such as type, will add more flags later
    char buffer[];
};

struct __attribute__ ((__packed__)) AVI_String16 {
    uint16_t length;
    uint16_t allocate;
    unsigned char flags;
    char buffer[];
};

/* Finds the structure that matches the String size */
#define STR_STRUCT(T, string) ((struct AVI_String##T *)((string) - sizeof(struct AVI_String##T)))
/* Global variable that stores current structure reference */
//#define STR_STRUCT_VARIABLE(T, name, string) struct AVI_String##T *name = (struct AVI_String##T*) ((string) - (sizeof(struct AVI_String##T)))

static inline int strLength(const str string) {
    unsigned char flags = (unsigned char) string[-1];
    switch(flags & AVI_STRING_TYPE_MASK) {
        case AVI_STRING_TYPE_8:
            return STR_STRUCT(8, string)->length;
        case AVI_STRING_TYPE_16:
            return STR_STRUCT(16, string)->length;
        default:
            return -1;
    }
}

static inline int avaliableSpace(const str string) {
    unsigned char flags = (unsigned char) string[-1];
    switch(flags & AVI_STRING_TYPE_MASK) {
        case AVI_STRING_TYPE_8:
            struct AVI_String8* ref8 = (AVI_String8 *) ((struct AVR_String8*) (string) - sizeof(struct AVI_String8));
            return ref8->allocate - ref8->length;
        case AVI_STRING_TYPE_16:
            struct AVI_String16* ref16 = (AVI_String16 *) ((struct AVR_String16*) (string) - sizeof(struct AVI_String16));
            return ref16->allocate - ref16->length;
        default:
            return -1;
    }
}


#endif //AVIATOENGINE_AVI_STRING_H
