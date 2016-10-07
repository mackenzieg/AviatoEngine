#include "Vector3.h"
#include "util/string/AVI_String8.h"

#define ERROR_CHECKING 1

using namespace std;

int main() {

    str8 string = str8New("Example");
    str8Printf(string);

    return 0;
}