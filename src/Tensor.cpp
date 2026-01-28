
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

Tensor Tensor::operator+(const Tensor& other) {
    // Simple element-wise addition (assuming same shape and dtype)
    //TODO: cant do size comparison like this yet since size is vector
    //if (this->sizes != other.sizes) {
    //    throw std::invalid_argument("Tensor sizes do not match for addition");
    //}

    Tensor result(this->sizes, this->storage->device);
    size_t num_elements = 1;
    for (auto s : this->sizes) num_elements *= s;

    float* this_data = static_cast<float*>(this->storage->data);
    float* other_data = static_cast<float*>(other.storage->data);
    float* result_data = static_cast<float*>(result.storage->data);

    for (size_t i = 0; i < num_elements; i++) {
        result_data[i] = this_data[i] + other_data[i];
    }

    return result;
}

const vector<int64_t>& Tensor::size() const noexcept {
    return this->sizes;
}

const vector<int64_t>& Tensor::shape() const noexcept {
    return this->sizes;
}