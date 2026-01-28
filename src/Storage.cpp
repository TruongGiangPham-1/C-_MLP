
#include "Storage.h"

// constructor
Storage::Storage(size_t size, Device device) {
    // Implementation for allocating storage based on device type
    if (device == CPU) {
        // Allocate CPU memory
        this->data = new unsigned char[size];
    } else if (device == CUDA) {
        // Allocate CUDA memory
    }
}

Storage::~Storage() {
    if (device == CPU) {
        // Deallocate CPU memory
        delete[] static_cast<unsigned char*>(this->data);
    } else if (device == CUDA) {
        // Deallocate CUDA memory
    }
}