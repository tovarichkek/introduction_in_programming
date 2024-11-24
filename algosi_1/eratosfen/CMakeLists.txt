cmake_minimum_required(VERSION 3.10)

project(Eratosthenes_algorithm)

find_package(GTest)
find_package(Boost COMPONENTS program_options)
find_package(benchmark)


set(BENCH_COMPILER_FLAGS
   -O2
)

if(NOT Boost_FOUND)
    message(WARNING "Did not find boost LIBS")
else()
    ###ERATOSFEN
    add_executable(eratosfen src/eratosfen.cpp)
    target_link_libraries(eratosfen Boost::program_options)

    ###TESTING
    if(NOT GTest_FOUND)
        message(WARNING "Did not find GTEST LIBS")
    else()
        enable_testing()

        add_executable(testing_eratosfen testing/testing_eratosfen.cpp)
        target_link_libraries(testing_eratosfen GTest::gtest GTest::gtest_main Boost::program_options)

        add_test(NAME Test_erat COMMAND testing_eratosfen)

    endif()
    
    ###BENCHMARK
    if(NOT benchmark_FOUND)
        message(WARNING "Did not find Benchmarking LIBS")
    else()
        add_executable(benchmarking_eratosfen benchmarking/benchmark_eratosfen.cpp) 
        target_link_libraries(benchmarking_eratosfen benchmark Boost::program_options)
        target_compile_options(benchmarking_eratosfen PRIVATE ${BENCH_COMPILER_FLAGS})
    endif()

    ###RSA
    add_executable(RSA_example RSA/RSA.cpp RSA/main.cpp)
    
    #TODO testing

endif()
