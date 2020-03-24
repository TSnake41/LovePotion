#include "common/runtime.h"

char * Object::ToString()
{
    char *buffer = (char *)malloc(64);
    if (!buffer)
        return nullptr;

    snprintf(buffer, 64, "%s: %p", this->type.c_str(), this);

    return buffer;
}