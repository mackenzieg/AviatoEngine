#ifndef AVIATOENGINE_VECTOR4_H
#define AVIATOENGINE_VECTOR4_H

template<class T>
class Vector4 {

public:
    T a, b, c, d;

    Vector4(T a, T b, T c, T d);

};

template<class T>
Vector4<T>::Vector4(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) {}

#endif //AVIATOENGINE_VECTOR4_H
