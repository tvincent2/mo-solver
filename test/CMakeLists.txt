cmake_minimum_required(VERSION 2.8)
project(mo-solver-tests)
include_directories(../include
                    ../../mo-utils)
find_library(CPPUNIT_LIBRARY cppunit)

set(TESTS_SRC main.cpp
              UpperBoundSetTest.cpp
              MOLPTest.cpp)

add_executable(mo_solver_tests ${TESTS_SRC})
target_link_libraries(mo_solver_tests LINK_PUBLIC mo_solver ${CPPUNIT_LIBRARY})
