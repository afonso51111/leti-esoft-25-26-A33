cmake_minimum_required(VERSION 3.20)
project(project-template)
set(CMAKE_CXX_STANDARD 17)

add_executable(project-template main.cpp)

include_directories(Core)
add_subdirectory(Core)
add_subdirectory(CoreTests)
add_subdirectory(ConsoleApp)

target_link_libraries(project-template Core)