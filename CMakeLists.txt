cmake_minimum_required(VERSION 3.16)
project(populationdynamics)

enable_testing(GTest required)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
include_directories(BEFORE include ${GTEST_INCLUDE_DIRS})

FILE(GLOB_RECURSE sources src/*.cpp)

add_executable(populationdynamics main.cpp ${sources} )

add_executable(test_feedvisitor test/controller/actions/FeedVisitorTest.cpp ${sources})
target_link_libraries(test_feedvisitor gtest)
add_test(feedvisitor test_feedvisitor)
