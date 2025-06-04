cmake_minimum_required(VERSION 3.10.0)
project(lab8)

enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(lab8 main.cpp src/task1.cpp src/task2.cpp src/task3.cpp)
target_link_libraries(lab8 ${OpenCV_LIBS} ${OPENSSL_CRYPTO_LIBRARY}) 
