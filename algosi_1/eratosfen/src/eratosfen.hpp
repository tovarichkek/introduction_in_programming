#pragma once
#include <iostream>
#include <limits.h>

int MAX_COUNT_PRIME_NUMBERS = 500000; //default

//eratosfen's algorithm, prime numbers from 2 to N are written im *mass
int prime_to_N(long long N, long long* mass){

    int elems = (N + 1) / CHAR_BIT + 1; //size in bytes = (count numubers from 0 to N) / (byte's size in bits) + 1
    char* numbers = (char*)calloc(elems, sizeof(char)); 
    if(!numbers){
        std::cout << "No memory" << std::endl;
        return 0;
    }

    numbers[0] = 0b00000011; //0 and 1 are compos
    

    long long ind_mass = 0; //index in mass of next prime number
    for(long long num = 2; num < N + 1; num++){
        if(((numbers[num / CHAR_BIT]) & (1 << num % CHAR_BIT)) == 0){
            mass[ind_mass] = num;
            ind_mass++;
            for(long long i = num * num; i < N + 1; i += num){ //optimisation: start mark numbers as compose from n^2, because 2n, 3n, 5n... were marked before
                numbers[i / CHAR_BIT] = (numbers[i / CHAR_BIT] | (1 << i % CHAR_BIT));
            }
        }
    }
    free(numbers);
    return ind_mass;
}

