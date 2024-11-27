cmake_minimum_required(VERSION 3.10)

project(Eratosthenes_algorithm)

find_package(Boost COMPONENTS program_options)

add_executable(symmetric_diff src/fast_set.cpp tasks/diff.cpp)

if(NOT Boost_FOUND)
    message(WARNING "Did not find boost LIBS, didn't create substrings")
else()
    add_executable(substrings src/fast_set.cpp tasks/substrings.cpp)
    target_link_libraries(substrings Boost::program_options)
endif()
