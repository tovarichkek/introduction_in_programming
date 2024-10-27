#include <iostream>
#include <stdlib.h>
#include "eratosfen.hpp"

int main(){
    int N;      
    std::cout << "N up to which the search for prime numbers will be carried out: " << std::endl;
    std::cin >> N;
    if(N < 0){
        std::cout << "N can be only non-negative\n" << std::endl;
        return 0;
    }

    long long mass[MAX_COUNT_PRIME_NUMBERS] = {};
    prime_to_N(N, mass);
    
    std::cout << "Prime numbers: " << std::endl;



    for(int i = 0; mass[i] != 0; i++){
        std::cout << mass[i] << std::endl;
    }
    std::cout << std::endl;
}