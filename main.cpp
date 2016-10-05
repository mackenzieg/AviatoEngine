#include "Vector3.h"
#include "AVI_String.h"

#define ERROR_CHECKING 1

using namespace std;

int main() {
    std::cin.sync_with_stdio(0);
    AVI_String *s = new AVI_String((char *) "asd");

    cout << s << endl;
    cout << "Test" << endl;

    return 0;
}