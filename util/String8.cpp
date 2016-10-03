#include "String8.h"

String8();
String8(uint16_t size);
String8(char *input);

void append(String8 other, bool ignoreLength = true);
void append(char *input, bool ignoreLength = true);

bool equals(String8 other);
bool equals(char *input);

String8 atPosition(uint16_t position);
