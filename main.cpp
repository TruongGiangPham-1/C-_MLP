#include <iostream>
#include "Common.h"

using namespace std;

int main() {
    Device device = CUDA;
    if (device == CPU) {
        cout << "Using CPU" << endl;
    } else if (device == CUDA) {
        cout << "Using CUDA" << endl;
    }
    return 0;
}