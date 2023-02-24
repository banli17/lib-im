cmake_minimum_required(VERSION 3.20)
project(lib-im)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp text2png.h)

add_executable(lib-im ${SOURCE_FILES})
add_definitions(-DMAGICKCORE_QUANTUM_DEPTH=16)
add_definitions(-DMAGICKCORE_HDRI_ENABLE=0)
find_package(ImageMagick COMPONENTS Magick++)

include_directories(/usr/local/Cellar/imagemagick/7.1.0-49_1/include/ImageMagick-7/)
target_link_libraries(lib-im /usr/local/Cellar/imagemagick/7.1.0-49_1/lib/libMagick++-7.Q16HDRI.dylib)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")