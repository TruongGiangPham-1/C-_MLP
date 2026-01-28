#pragma once
#include "Common.h"
#include "Storage.h"
#include <vector>
#include <memory>


class Tensor {
public:
    std::shared_ptr<Storage> storage;
    std::vector<int> shape;
    std::vector<int> strides;
    size_t offset;

    Tensor(std::vector<int> shape, Device device);
};