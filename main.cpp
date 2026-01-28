#include <iostream>
#include "Common.h"
#include "Storage.h"
#include "Tensor.h"

using namespace std;

int main() {
    Device device = CPU;
    vector<int64_t> shape = {2, 2};
    Tensor a(shape, device);

    auto dim = a.size();
    cout << "size" << dim[0] << ", " << dim[1] << endl;
    return 0;
}