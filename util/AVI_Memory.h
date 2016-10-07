#ifndef AVIATOENGINE_MEMORY_H
#define AVIATOENGINE_MEMORY_H

#include <cstdio>

namespace Memory {
    template <class T>
    void safeDelete(T& t)
    {
        if (t) {
            delete t;
            t = nullptr;
        }
    }

    template <class T>
    void safeDeleteArray(T& t)
    {
        if (t) {
            delete[] t;
            t = nullptr;
        }
    }

    template <class T>
    void safeRelease(T& t)
    {
        if (t) {
            t->Release();
            t = nullptr;
        }
    }

    void hexDump(void *addr, int len)
    {
        int i;
        unsigned char buff[17];
        unsigned char *pc = (unsigned char*)addr;

        // Process every byte in the data.
        for (i = 0; i < len; i++) {
            // Multiple of 16 means new line (with line offset).

            if ((i % 16) == 0) {
                // Just don't print ASCII for the zeroth line.
                if (i != 0)
                    printf("  %s\n", buff);

                // Output the offset.
                printf("  %04X ", i);
            }

            // Now the hex code for the specific character.
            printf(" %02X", pc[i]);
            // And store a printable ASCII character for later.
            if ((pc[i] < 0x20) || (pc[i] > 0x7e)) {
                buff[i % 16] = '.';
            }
            else {
                buff[i % 16] = pc[i];
            }

            buff[(i % 16) + 1] = '\0';
        }

        // Pad out last line if not exactly 16 characters.
        while ((i % 16) != 0) {
            printf("   ");
            i++;
        }

        // And print the final ASCII bit.
        printf("  %s\n", buff);
    }

}

#endif //AVIATOENGINE_MEMORY_H
