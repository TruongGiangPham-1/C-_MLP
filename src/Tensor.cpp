
#include "Tensor.h"
#include "Common.h"


Tensor::Tensor(std::vector<int> sizes, Device device) : sizes(sizes), offset(0) {
    size_t num_element = 1;
    for (int s : sizes) num_element *= s;
    
    // Allocate storage (assuming float for now)
    storage = std::make_shared<Storage>(num_element * sizeof(float), device, FLOAT32);
    
    // Compute default row-major strides
    this->strides.resize(sizes.size());
    int cur_stride = 1;
    for (int i = sizes.size() - 1; i >= 0; i--) {
        this->strides[i] = cur_stride;
        cur_stride *= sizes[i];
    }
}

int Tensor::size() const noexcept {
    return sizes.size();
}

int Tensor::shape() const noexcept {
    return sizes.size();
}