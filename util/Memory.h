#ifndef AVIATOENGINE_MEMORY_H
#define AVIATOENGINE_MEMORY_H

namespace Memory {
    template <class T>
    void SafeDelete(T& t)
    {
        if (t) {
            delete t;
            t = nullptr;
        }
    }

    template <class T>
    void SafeDeleteArray(T& t)
    {
        if (t) {
            delete[] t;
            t = nullptr;
        }
    }

    template <class T>
    void SafeRelease(T& t)
    {
        if (t) {
            t->Release();
            t = nullptr;
        }
    }
}

#endif //AVIATOENGINE_MEMORY_H
