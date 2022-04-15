find_package(fmt REQUIRED)
include_directories(../../Sophus)

find_package(Pangolin REQUIRED)

add_executable(joinMap joinMap.cpp)
target_link_libraries(joinMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES} fmt::fmt)