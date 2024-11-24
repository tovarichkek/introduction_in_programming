#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <boost/program_options.hpp>
#include <iostream>
#include "../src/eratosfen.hpp"
#include <fstream>

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

void numbers_from_true_data(long long* data){
    std::ifstream file;
    file.open("../testing/prime_numbers_up_to_10_6.txt");
    for(int i = 0; !file.eof(); i++){
        file >> data[i];
    }
    file.close();
}

//check that elements from mass equal to elements from true_data up to N
TEST(AddTest, ERAT) {
    long long* mass = (long long*)malloc(sizeof(long long) * MAX_COUNT_PRIME_NUMBERS);
    long long* true_data = (long long*)malloc(sizeof(long long) * MAX_COUNT_PRIME_NUMBERS);

    numbers_from_true_data(true_data);
    for(int N = 2; N < 10000; N++){
        prime_to_N(N, mass);
        for(int i = 0; true_data[i] <= N; i++){
            EXPECT_EQ(true_data[i], mass[i]);
        }
    }
    free(mass);
    free(true_data);
}


int main(int argc, char *argv[]) {
    input_processing(argc, argv);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}