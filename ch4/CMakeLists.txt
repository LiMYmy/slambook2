cmake_minimum_required(VERSION 3.12)
project(useSophus)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)

find_package(Eigen3 REQUIRED)
find_package(fmt)

include_directories("../Sophus")

add_executable(useSophus useSophus.cpp)
target_compile_features(useSophus PUBLIC cxx_std_14)
target_link_libraries(useSophus Eigen3::Eigen fmt::fmt)
target_compile_definitions(useSophus PUBLIC USE_BASIC_LOGGING=ON)

add_subdirectory(example)
