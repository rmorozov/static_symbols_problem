cmake_minimum_required(VERSION 3.5)

project(broken_linkage)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 ")#-fvisibility=hidden")# -flto")

add_library(lib_a_ok SHARED lib_a.cpp)
add_library(lib_b_ok SHARED lib_b.cpp)

add_executable(app_ok main.cpp)
target_link_libraries(app_ok lib_a_ok lib_b_ok)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto")

add_library(lib_a_crash SHARED lib_a.cpp)
add_library(lib_b_crash SHARED lib_b.cpp)
add_executable(app_crash main.cpp)

# behaves like -fvisibility=hidden is switched on
# meaning internal linkage
target_compile_options(app_crash PUBLIC "-flto")
target_link_libraries(app_crash lib_a_crash lib_b_crash)
