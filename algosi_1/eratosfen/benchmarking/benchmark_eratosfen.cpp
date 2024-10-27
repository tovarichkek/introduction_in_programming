#include <iostream>
#include "../src/eratosfen.hpp"
#include <benchmark/benchmark.h>

#define MAX_BENCHMARK_N 100000

long long mass[MAX_COUNT_PRIME_NUMBERS] = {};

static void BM_eratosfen(benchmark::State& state) {
    for (auto _ : state){        
        prime_to_N(state.range(0), mass);
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

BENCHMARK_MAIN();

// gnu_plot
