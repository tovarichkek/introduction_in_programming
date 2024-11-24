#include <iostream>
#include <stdlib.h>
#include "eratosfen.hpp"
#include <boost/program_options.hpp>

void input_processing(int argc, char *argv[]){
    namespace prog_opts = boost::program_options;

    prog_opts::options_description desc("Allowed options");
    desc.add_options()
        ("mass_primes_size", prog_opts::value<int>(), "max size of mass with prime numbers")
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
}

int main(int argc, char *argv[]){
    
    input_processing(argc, argv);

    int N;      
    std::cout << "N up to which the search for prime numbers will be carried out: " << std::endl;
    std::cin >> N;
    if(!std::cin.good()){
        std::cout << "Input error" << std::endl;
    }
    else if(N < 0){
        std::cout << "N can be only non-negative\n" << std::endl;
        return 0;
    }

    long long* mass = (long long*)malloc(MAX_COUNT_PRIME_NUMBERS * sizeof(long long));
    if(!mass){
        std::cout << "No memory" << std::endl;
    }
    else{
        int count_primes = prime_to_N(N, mass);
        std::cout << "Prime numbers: " << std::endl;

        for(int i = 0; i < count_primes; i++){
            std::cout << mass[i] << std::endl;
        }
        std::cout << std::endl;
    }
}