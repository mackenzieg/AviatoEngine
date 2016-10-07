#ifndef AVIATOENGINE_VECTOR2_H
#define AVIATOENGINE_VECTOR2_H

#include <iostream>

#include "AVI_Math.h"

#define FLOAT_EPSILON 0.00001
#define DOUBLE_EPSILON 0.00001

//TODO possibly move some vector math to the gpu

template<class T>
class Vector2 {
public:

    T x, y;

    Vector2();

    Vector2(T x, T y);

    T distance(Vector2<T> other);

    T distance(T x, T y);

    T distanceSquared(Vector2<T> other);

    T distanceSquared(T x, T y);

    T length();

    T dotProduct(Vector2<T> other);

    T dotProduct(T x, T y);

    Vector2 *normalize();

    Vector2 &operator=(const Vector2 &other);

    Vector2 &operator+=(const Vector2 &other);

    Vector2 &operator+=(const T &other);

    Vector2 &operator-=(const Vector2 &other);

    Vector2 &operator-=(const T &other);

    Vector2 &operator*=(const Vector2 &other);

    Vector2 &operator*=(const T &other);

    Vector2 &operator/=(const Vector2 &other);

    Vector2 &operator/=(const T &other);

    Vector2 &operator+(const Vector2 &other);

    Vector2 &operator+(const T &other);

    Vector2 &operator-(const Vector2 &other);

    Vector2 &operator-(const T &other);

    Vector2 &operator*(const Vector2 &other);

    Vector2 &operator*(const T &other);

    Vector2 &operator/(const Vector2 &other);

    Vector2 &operator/(const T &other);

    bool operator==(const Vector2<T> &other) const;

    bool operator!=(const Vector2<T> &other) const;

};

template<class T>
Vector2<T>::Vector2() : x(0), y(0) {}

template<class T>
Vector2<T>::Vector2(T x, T y) : x(x), y(y) {}

template<class T>
T Vector2<T>::distance(Vector2<T> other) {
    T deltaX = x - other.x;
    T deltaY = y - other.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

template<class T>
T Vector2<T>::distance(T x, T y) {
    T deltaX = this->x - x;
    T deltaY = this->y - y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

template<class T>
T Vector2<T>::distanceSquared(Vector2<T> other) {
    T deltaX = x - other.x;
    T deltaY = y - other.y;
    return (deltaX * deltaX + deltaY * deltaY);
}

template<class T>
T Vector2<T>::distanceSquared(T x, T y) {
    T deltaX = this->x - x;
    T deltaY = this->y - y;
    return (deltaX * deltaX + deltaY * deltaY);
}

template<class T>
T Vector2<T>::length() {
    return std::sqrt(x * x + y * y);
}

template<class T>
T Vector2<T>::dotProduct(Vector2<T> other) {
    return (x * other.x + y * other.y);
}

template<class T>
T Vector2<T>::dotProduct(T x, T y) {
    return (this->x * x + this->y * y);
}

template<class T>
Vector2<T> *Vector2<T>::normalize() {
    T length = length();
    T unitX = x;
    T unitY = y;
    if (length != 0) {
        unitX /= x;
        unitY /= y;
    }
    return new Vector2(unitX, unitY);
}

template<class T>
Vector2<T> &Vector2<T>::operator=(const Vector2<T> &other) {
    x = other.x;
    y = other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator+=(const Vector2 &other) {
    x = x + other.x;
    y = y + other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator+=(const T &other) {
    x = x + other.x;
    y = y + other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator-=(const Vector2 &other) {
    x = x - other.x;
    y = y - other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator-=(const T &other) {
    x = x - other.x;
    y = y - other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator*=(const Vector2 &other) {
    x = x * other.x;
    y = y * other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator*=(const T &other) {
    x = x * other.x;
    y = y * other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator/=(const Vector2 &other) {
    x = x / other.x;
    y = y / other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator/=(const T &other) {
    x = x / other.x;
    y = y / other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator+(const Vector2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator+(const T &other) {
    x += other;
    y += other;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator-(const Vector2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator-(const T &other) {
    x -= other;
    y -= other;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator*(const Vector2 &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator*(const T &other) {
    x *= other;
    y *= other;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator/(const Vector2 &other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

template<class T>
Vector2<T> &Vector2<T>::operator/(const T &other) {
    x /= other;
    y /= other;
    return *this;
}

template<class T>
bool Vector2<T>::operator==(const Vector2<T> &other) const {
    return x == other.x &&
           y == other.y;
}

//TODO calculate a proper epsilon
template<>
bool Vector2<float>::operator==(const Vector2<float> &other) const {
    float deltaX = x - other.x;
    float deltaY = y - other.y;
    return ((deltaX < FLOAT_EPSILON) && (-deltaX < FLOAT_EPSILON)) &&
           ((deltaY < FLOAT_EPSILON) && (-deltaY < FLOAT_EPSILON));
}

template<>
bool Vector2<double>::operator==(const Vector2<double> &other) const {
    double deltaX = x - other.x;
    double deltaY = y - other.y;
    return ((deltaX < DOUBLE_EPSILON) && (-deltaX < DOUBLE_EPSILON)) &&
           ((deltaY < DOUBLE_EPSILON) && (-deltaY < DOUBLE_EPSILON));
}

template<class T>
bool Vector2<T>::operator!=(const Vector2<T> &other) const {
    return !(other == *this);
}

template<class T>
std::ostream& operator<< (std::ostream& stream, const Vector2<T> &other) {
    stream << "(" << other.x << "," << other.y << ")";
    return stream;
}

#endif //AVIATOENGINE_VECTOR2_H