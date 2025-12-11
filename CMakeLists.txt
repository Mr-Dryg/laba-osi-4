cmake_minimum_required(VERSION 3.11)
project(laba)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(src)

add_executable(prog1 prog_1.c)
target_link_libraries(prog1 realiz_1)

# add_executable(prog2 prog_2.c)
# target_link_libraries(prog2 realiz_1 realiz_2)

enable_testing()
# add_subdirectory(tests)