cmake_minimum_required(VERSION 3.17.1)

project(Means VERSION 0.1)

# set(OpenCV_DIR /usr/lib/cmake/opencv4)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include)

# set(CMAKE_PREFIX_PATH /usr/include/opencv4)

FIND_PACKAGE(OpenCV REQUIRED core imgcodecs highgui)

set(SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(NAME_SRC ${SOURCE}/main.cpp ${SOURCE}/kmeans.cpp)

set(NAME_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/kmeans.h)

add_executable(Means ${NAME_SRC} ${NAME_HEADERS})

target_link_libraries(Means ${OpenCV_LIBS})

