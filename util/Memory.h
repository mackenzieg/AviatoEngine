#ifndef AVIATOENGINE_MEMORY_H
#define AVIATOENGINE_MEMORY_H

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
}

#endif //AVIATOENGINE_MEMORY_H
