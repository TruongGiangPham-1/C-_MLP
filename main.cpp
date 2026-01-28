#include <iostream>
#include "Common.h"
#include "Storage.h"
#include "Tensor.h"

using namespace std;

int main() {
    Device device = CPU;
    vector<int> shape = {2, 2};
    Tensor a(shape, device);

    printf("a dim %d\n", a.shape());
    return 0;
}