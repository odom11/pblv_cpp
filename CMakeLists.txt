cmake_minimum_required(VERSION 3.16)
project(populationdynamics)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
include_directories(BEFORE include)

FILE(GLOB_RECURSE sources src/*.cpp)



add_executable(populationdynamics main.cpp ${sources} src/controller/actions/gridtools.cpp include/Coordinate.h src/Coordinate.cpp include/controller/actions/FeedVisitor.h src/controller/actions/FeedVisitor.cpp include/controller/actions/GetEatenVisitor.h src/controller/actions/GetEatenVisitor.cpp)
add_executable(test_executable test/BasicTest.cpp)
target_include_directories(test_executable PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(test_executable ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME test1 COMMAND test_executable)