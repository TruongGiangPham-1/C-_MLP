
#pragma once
#include "Common.h"
#include <cstddef>

class Storage
{
private:
    /* data */
    void* data;
    size_t size;
    Device device;
public:
    Storage(size_t size, Device device);
    ~Storage();
};
