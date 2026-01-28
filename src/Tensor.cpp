
#include "Tensor.h"



Tensor::Tensor(std::vector<int> shape, Device device) : shape(shape), offset(0) {
    size_t num_element = 1;
    for (int s : shape) num_element *= s;
    
    // Allocate storage (assuming float for now)
    storage = std::make_shared<Storage>(num_element * sizeof(float), device);
    
    // Compute default row-major strides
    this->strides.resize(shape.size());
    int cur_stride = 1;
    for (int i = shape.size() - 1; i >= 0; i--) {
        this->strides[i] = cur_stride;
        cur_stride *= shape[i];
    }
}