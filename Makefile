all:
	cmake -S . -B build && cmake --build build && ./build/C_MLP