cmake_minimum_required(VERSION 3.10)

# set the project name
project(SpaceInvaders)

# add the executable
add_executable(SpaceInvaders main.cpp alien.cpp window.cpp buffer.cpp buffer_renderer.cpp)

target_link_libraries(SpaceInvaders PUBLIC glfw GLEW GL)
