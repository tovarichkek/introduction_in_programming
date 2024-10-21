add_executable(eratosfen eratosfen.cpp)

set(TEST_LIBRARIES
    gtest
    gmock 
    pthread
)

add_executable(testing_eratosfen testing_eratosfen.cpp)
target_link_libraries(testing_eratosfen PUBLIC ${TEST_LIBRARIES})


set(BENCH_LIBRARIES
    pthread 
    benchmark
)
set(TEST_COMPILER_FLAGS
   -O2
)

#add_definitions(-O2)
add_executable(benchmarking_eratosfen benchmark_eratosfen.cpp) 
target_compile_options(benchmarking_eratosfen PRIVATE ${TEST_COMPILER_FLAGS})
target_link_libraries(benchmarking_eratosfen PUBLIC ${BENCH_LIBRARIES})
#target_compile_options(benchmarking_eratosfen -O2)