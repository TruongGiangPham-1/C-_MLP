
#pragma once
#include "Common.h"
#include <cstddef>

class Storage {
    public:
        /* data */
        void* data;
        size_t size;
        Device device;
        DTYPE dtype;
        Storage(size_t size, Device device, DTYPE dtype);
        ~Storage();
};
