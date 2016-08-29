cmake_minimum_required(VERSION 3.5)
project(Analizador_lexico)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp lexico.h buffered_stream.h)
add_executable(Analizador_lexico ${SOURCE_FILES})