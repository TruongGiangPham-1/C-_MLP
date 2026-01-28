
#include "Tensor.h"
#include "Common.h"

using namespace std;

Tensor::Tensor(std::vector<int64_t> sizes, Device device) : sizes(sizes), offset(0) {
    size_t num_element = 1;
    for (auto s : sizes) num_element *= s;
    
    // Allocate storage (assuming float for now)
    storage = std::make_shared<Storage>(num_element * sizeof(float), device, FLOAT32);
    
    // Compute default row-major strides
    this->strides.resize(sizes.size());
    int64_t cur_stride = 1;
    for (int64_t i = sizes.size() - 1; i >= 0; i--) {
        this->strides[i] = cur_stride;
        cur_stride *= sizes[i];
    }
}

const vector<int64_t>& Tensor::size() const noexcept {
    return this->sizes;
}

const vector<int64_t>& Tensor::shape() const noexcept {
    return this->sizes;
}