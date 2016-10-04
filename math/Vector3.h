#ifndef AVIATOENGINE_VECTOR3_H
#define AVIATOENGINE_VECTOR3_H

#include "AVI_Math.h"

#define FLOAT_EPSILON 0.00001
#define DOUBLE_EPSILON 0.00001

template<class T>
class Vector3 {
public:

    T x, y, z;

//    union {
//        T x, y, z;
//        T vector[3];
//    };

    Vector3();

    Vector3(T x, T y, T z);

    T distance(Vector3<T> other);

    T distance(T x, T y, T z);

    T distanceSquared(Vector3<T> other);

    T distanceSquared(T x, T y, T z);

    T length();

    T dotProduct(Vector3<T> other);

    T dotProduct(T x, T y, T z);

    Vector3<T> *crossProduct(Vector3<T> other);

    Vector3<T> *crossProduct(T x, T y, T z);

    Vector3 *normalize();

    Vector3 &operator=(const Vector3 &other);

    Vector3 &operator+=(const Vector3 &other);

    Vector3 &operator+=(const T &other);

    Vector3 &operator-=(const Vector3 &other);

    Vector3 &operator-=(const T &other);

    Vector3 &operator*=(const Vector3 &other);

    Vector3 &operator*=(const T &other);

    Vector3 &operator/=(const Vector3 &other);

    Vector3 &operator/=(const T &other);

    Vector3 &operator+(const Vector3 &other);

    Vector3 &operator+(const T &other);

    Vector3 &operator-(const Vector3 &other);

    Vector3 &operator-(const T &other);

    Vector3 &operator*(const Vector3 &other);

    Vector3 &operator*(const T &other);

    Vector3 &operator/(const Vector3 &other);

    Vector3 &operator/(const T &other);

    bool inline operator==(const Vector3<T> &other) const;

    bool operator!=(const Vector3<T> &other) const;

};

template<class T>
T Vector3<T>::distance(Vector3<T> other) {
    T deltaX = x - other.x;
    T deltaY = y - other.y;
    T deltaZ = z - other.z;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

template<class T>
T Vector3<T>::distance(T x, T y, T z) {
    T deltaX = this->x - x;
    T deltaY = this->y - y;
    T deltaZ = this->z - z;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

template<class T>
T Vector3<T>::distanceSquared(Vector3<T> other) {
    T deltaX = x - other.x;
    T deltaY = y - other.y;
    T deltaZ = z - other.z;
    return (deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

template<class T>
T Vector3<T>::distanceSquared(T x, T y, T z) {
    T deltaX = this->x - x;
    T deltaY = this->y - y;
    T deltaZ = this->z - z;
    return (deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

template<class T>
T Vector3<T>::length() {
    return std::sqrt(x * x + y * y + z * z);
}

template<class T>
T Vector3<T>::dotProduct(Vector3<T> other) {
    return (x * other.x + y * other.y + z * other.z);
}

template<class T>
T Vector3<T>::dotProduct(T x, T y, T z) {
    return (this->x * x + this->y * y + this->z * z);
}

template<class T>
Vector3<T> *Vector3<T>::crossProduct(Vector3<T> other) {
    return new Vector3((y * other.z - z * other.y),
                       (z * other.x - x * other.z),
                       (x * other.y - y * other.x));
}

template<class T>
Vector3<T> *Vector3<T>::crossProduct(T x, T y, T z) {
    return new Vector3((this->y * z - this->z * y),
                       (this->z * x - this->x * z),
                       (this->x * y - this->y * x));
}

template<class T>
Vector3<T> *Vector3<T>::normalize() {
    T length = length();
    T unitX = x;
    T unitY = y;
    T unitZ = z;
    if (length != 0) {
        unitX /= x;
        unitY /= y;
        unitZ /= z;
    }
    return new Vector3(unitX, unitY, unitZ);
}

template<class T>
Vector3<T> &Vector3<T>::operator=(const Vector3<T> &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator+=(const Vector3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator+=(const T &other) {
    x += other;
    y += other;
    z += other;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator-=(const Vector3 &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator-=(const T &other) {
    x -= other;
    y -= other;
    z -= other;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator*=(const Vector3 &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator*=(const T &other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator/=(const Vector3 &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator/=(const T &other) {
    x /= other;
    y /= other;
    z /= other;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator+(const Vector3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator+(const T &other) {
    x += other;
    y += other;
    z += other;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator-(const Vector3 &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator-(const T &other) {
    x -= other;
    y -= other;
    z -= other;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator*(const Vector3 &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator*(const T &other) {
    x *= other;
    y *= other;
    z *= other;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator/(const Vector3 &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

template<class T>
Vector3<T> &Vector3<T>::operator/(const T &other) {
    x /= other;
    y /= other;
    z /= other;
    return *this;
}
// http://stackoverflow.com/questions/19985160/distinguishing-integer-from-floating-point-types-in-a-template

//TODO fix
template<class T>
bool Vector3<T>::operator==(const Vector3<T> &other) const {
    return x == other.x &&
           y == other.y &&
           z == other.z;
}

template<>
bool Vector3<float>::operator==(const Vector3<float> &other) const {
    float deltaX = x - other.x;
    float deltaY = y - other.y;
    float deltaZ = z - other.z;
    return ((deltaX < FLOAT_EPSILON) && (-deltaX < FLOAT_EPSILON)) &&
           ((deltaY < FLOAT_EPSILON) && (-deltaY < FLOAT_EPSILON)) &&
           ((deltaZ < FLOAT_EPSILON) && (-deltaZ < FLOAT_EPSILON));
}

template<>
bool Vector3<double>::operator==(const Vector3<double> &other) const {
    double deltaX = x - other.x;
    double deltaY = y - other.y;
    double deltaZ = z - other.z;
    return ((deltaX < DOUBLE_EPSILON) && (-deltaX < DOUBLE_EPSILON)) &&
           ((deltaY < DOUBLE_EPSILON) && (-deltaY < DOUBLE_EPSILON)) &&
           ((deltaZ < DOUBLE_EPSILON) && (-deltaZ < DOUBLE_EPSILON));
}


//TODO fix
template<class T>
bool Vector3<T>::operator!=(const Vector3<T> &other) const {
    return !(other == *this);
}

template<class T>
Vector3<T>::Vector3() : x(0), y(0), z(0) {}

template<class T>
Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z) {}

#endif //AVIATOENGINE_VECTOR3_H
