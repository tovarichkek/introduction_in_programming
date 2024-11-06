#include <iostream>
#include "../src/eratosfen.hpp"
#include <benchmark/benchmark.h>
#include <boost/program_options.hpp>

static long long* mass_for_tests;

int MAX_COUNT_PRIME_NUMBERS;
static int MAX_BENCHMARK_N = 500000;

static void input_processing(int argc, char *argv[]){
    namespace prog_opts = boost::program_options;

    prog_opts::options_description desc("Allowed options");
    desc.add_options()
        ("mass_primes_size", prog_opts::value<int>(), "max size of mass with prime numbers")
        ("max_bench_N", prog_opts::value<int>(), "max N in eratosfen, to which benchmarking will reach")
        ("help", "help message")
    ;
    
    prog_opts::variables_map vm;
    prog_opts::store(prog_opts::parse_command_line(argc, argv, desc), vm);
    prog_opts::notify(vm);
    
    if(vm.count("help")){
        std::cout << desc << "\n";
        exit(1);

    }
    
    if(vm.count("mass_primes_size")){
        MAX_COUNT_PRIME_NUMBERS = vm["mass_primes_size"].as<int>();
    }
    else{
        MAX_COUNT_PRIME_NUMBERS = 500000; //default
    }
    
    if(vm.count("max_bench_N")){
        MAX_BENCHMARK_N = vm["max_bench_N"].as<int>();
    }
    else{
        MAX_BENCHMARK_N = 10000; //default
    }
}

static void BM_eratosfen(benchmark::State& state) {
    for (auto _ : state){        
        prime_to_N(state.range(0), mass_for_tests);
    }
}

static void CustomArguments(benchmark::internal::Benchmark* b) {
    
    long long i;

    for (i = 30; i <= 5000 && i < MAX_BENCHMARK_N; i *= 1.2){
        b->Arg(i);
    }
    for (; i <= 20000 && i <= MAX_BENCHMARK_N; i *= 1.1){
        b->Arg(i);
    }
    for (; i <= MAX_BENCHMARK_N; i *= 1.05){
        b->Arg(i);
    }

}

BENCHMARK(BM_eratosfen)->Apply(CustomArguments);

//BENCHMARK(BM_eratosfen)->RangeMultiplier(2)->Range(8, 8<<15);
//BENCHMARK(BM_eratosfen)->DenseRange(10, 100, 10);

//BENCHMARK_MAIN();


int main(int argc, char** argv){

    input_processing(argc, argv);

    mass_for_tests = (long long *)malloc(MAX_COUNT_PRIME_NUMBERS * sizeof(long long));

    ::benchmark::Initialize(&argc, argv); 
    ::benchmark::RunSpecifiedBenchmarks(); 
    ::benchmark::Shutdown();
    
    free(mass_for_tests);

    return 0; 
    //BENCHMARK_MAIN();

}

