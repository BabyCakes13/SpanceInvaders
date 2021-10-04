cmake_minimum_required(VERSION 3.10)

# set the project name
project(SpaceInvaders)

add_compile_options(-Wall -Wextra -pedantic)

# add the executable
add_executable(SpaceInvaders main.cpp alien.cpp application.cpp drawable.cpp)

target_link_libraries(SpaceInvaders PUBLIC pthread SDL2)
