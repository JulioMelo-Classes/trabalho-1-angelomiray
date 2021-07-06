cmake_minimum_required(VERSION 3.5)
project(TesteLp1 VERSION 0.1 LANGUAGES CXX )

#set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall -fsanitize=address,undefined -g" )
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 14)
#--------------------------------

# configura o diretório contendo os .h, assim você pode incluílos apenas com include "arquivo.h"
include_directories( include ../test_manager/include)

# Cria um executável com nome "run_tests", adiciona neste executável os arquivos do test manager e o seu main.cpp
add_executable( keno
                src/GameProcessing.cpp
                src/KenoBet.cpp
                src/main.cpp )

# The end