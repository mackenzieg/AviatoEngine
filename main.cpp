#include <iostream>
#include <cfloat>

#include "Vector3.h"

int main() {

    float x;

    *((int *) &x) = 1;
    *((int *) &x) = *((int *) &x) | 104 << 23;

    printf("Float system epsilon %.12f\n", FLT_EPSILON);
    printf("Float calculated epsilon %.12f\n", x);
    //TODO use this epsilon for comparision
    //TODO epsilon for comparison
    //TODO should be a multiple

    double y;

    *((int *) &y) = 1;
    *((int *) &y) = *((int *) &y) | 104 << 23;

    printf("Double epsilon %.12f\n", (1 + std::pow(2, -52)) - 1);

    Vector3<double> v(1, 1, 1);

    std::cout << "Push Test Deskto";
    return 0;
}