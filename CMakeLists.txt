cmake_minimum_required(VERSION 3.10)
project(C_MLP)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(C_MLP 
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/src/Tensor.cpp
    ${PROJECT_SOURCE_DIR}/src/Storage.cpp
)
