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

    Tensor b(shape, device);

    // add thensor
    Tensor c = a + b;
    cout << c << endl;
    return 0;
}