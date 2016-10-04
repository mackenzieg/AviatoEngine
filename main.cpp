#include <cfloat>
#include <cstdio>

#include "Vector3.h"
#include "AVI_String.h"

#define ERROR_CHECKING 1

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
    Vector3<double> f(1, 2, 1);

    AVI_String* ssssss = new AVI_String("FUK Me");

    std::cout << ssssss << std::endl;

    ssssss->append("FUK ME HARDER");

    std::cout << ssssss << std::endl;

    std::cout << v << std::endl;

    return 0;
}