project(table_iterator)

set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Threads REQUIRED)

set(table_iterator_SRCS
    main.cpp
    test_official.cpp
    test_iterator2d.cpp)

add_executable(table_iterator ${table_iterator_SRCS})
target_link_libraries(table_iterator
    ${GTEST_LIBRARIES}
    Threads::Threads)

add_test(AllTests table_iterator)
