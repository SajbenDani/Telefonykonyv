cmake_minimum_required(VERSION 3.23)
project(program)

set(CMAKE_CXX_STANDARD 14)

add_executable(program main.cpp Nevjegy.h Ceg.h Ember.h String.h Ceg.cpp Ember.cpp String.cpp Telefonkonyv.h Telefonkonyv.cpp memtrace.cpp)
add_compile_definitions(MEMTRACE)