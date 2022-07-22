cmake_minimum_required(VERSION 3.10)
project (eigen_test)



find_package (Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(include)

add_executable (eigen_test src/eigen_test.cpp)
set_target_properties(eigen_test 
PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries (eigen_test Eigen3::Eigen)

