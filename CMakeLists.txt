cmake_minimum_required(VERSION 3.16)

project(MyGame)

set(CMAKE_CXX_STANDARD 17)

# 모듈 경로 등록
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

# 모듈 불러오기
include(Dependencies)
include(Compiler)

add_subdirectory(lib)
add_subdirectory(src)

