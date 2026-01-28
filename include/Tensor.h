#pragma once
#include "Common.h"
#include "Storage.h"
#include <vector>
#include <memory>


class Tensor {
public:
    std::shared_ptr<Storage> storage;
    std::vector<int64_t> sizes;
    std::vector<int64_t> strides;
    size_t offset;  // offset from the start of the storage. Useful for views/slices
    /*
        eg: tensor[1, :] slicing rows we can use offset to point to the start of row 1
            tensor[:, 1] slicing columns, we use strides to jump to every next element in column 1
        Good read https://blog.ezyang.com/2019/05/pytorch-internals/
    */
    Tensor(std::vector<int64_t> sizes, Device device);
    const std::vector<int64_t>& size() const noexcept; 
    const std::vector<int64_t>& shape() const noexcept;

    Tensor operator+(const Tensor& other);
};