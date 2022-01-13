cmake_minimum_required(VERSION 3.20)
project(test_im)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Im.h Im.cpp)

add_executable(test_im ${SOURCE_FILES})
add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )
find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})

include_directories(/usr/local/Cellar/imagemagick/7.0.8-66/include/ImageMagick-7/)
target_link_libraries(test_im /usr/local/Cellar/imagemagick/7.0.8-66/lib/libMagick++-7.Q16HDRI.dylib)