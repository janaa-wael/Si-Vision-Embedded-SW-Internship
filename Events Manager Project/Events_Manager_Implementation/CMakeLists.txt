cmake_minimum_required(VERSION 3.10)

# Project name
project(EventsManager)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all .cpp files in current directory
# GLOB is a way to automatically detect source files without listing them manually.
file(GLOB SOURCES src/*.cpp)

# Add executable target
add_executable(final_program ${SOURCES})