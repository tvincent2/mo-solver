cmake_minimum_required(VERSION 2.8)
project(mo-solver-library)
SET(CMAKE_CXX_FLAGS "-std=c++11")
include_directories(../include
                    ../../mo-utils/include)

set(MOSOLVER_SRC  UpperBoundSet.cpp
                  MOLP.cpp
                  MOLPUpdateComputation.cpp)

add_library(mo_solver ${MOSOLVER_SRC})
