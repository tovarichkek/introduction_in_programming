cmake_minimum_required(VERSION 3.10)

project(Eratosthenes_algorithm)

add_executable(eratosfen eratosfen.cpp)

find_library(TEST_LIBRARIES NAMES gtest gmock pthread)
if(NOT TEST_LIBRARIES_FOUND)
    message(WARNING "Did not find GTEST LIBS")
else()
    add_executable(testing_eratosfen testing_eratosfen.cpp)
    target_link_libraries(testing_eratosfen PUBLIC ${TEST_LIBRARIES})
endif()

set(BENCH_COMPILER_FLAGS
   -O2
)

find_library(BENCH_LIBRARIES NAMES benchmark pthread)
if(NOT BENCH_LIBRARIES)
    message(SEND_ERROR "Did not find Benchmarking LIBS")
else()
    add_executable(benchmarking_eratosfen benchmark_eratosfen.cpp) 
    target_compile_options(benchmarking_eratosfen PRIVATE ${BENCH_COMPILER_FLAGS})
    target_link_libraries(benchmarking_eratosfen PUBLIC ${BENCH_LIBRARIES})
endif()
