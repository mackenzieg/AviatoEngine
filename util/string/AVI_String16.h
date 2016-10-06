#ifndef AVIATOENGINE_AVI_STRING16_H
#define AVIATOENGINE_AVI_STRING16_H

#include <stdint.h>
#include "AVI_String8.h"

typedef uint16_t* str16;

struct __attribute__ ((__packed__)) AVI_String16 {
    uint16_t length;
    uint16_t allocate;
    uint16_t buffer[];
};


#endif //AVIATOENGINE_AVI_STRING16_H
