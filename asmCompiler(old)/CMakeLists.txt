# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.0)

# Set the project name and version
project(ASM_Compiler VERSION 1.0)

# Add an executable target
add_executable(compiler src/compiler.cpp)