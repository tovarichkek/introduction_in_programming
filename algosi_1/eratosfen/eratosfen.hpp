#pragma once

#define MAX_COUNT_PRIME_NUMBERS 500000

//eratosfen's algorithm, prime numbers from 2 to N are written im *mass
void prime_to_N(long long N, long long* mass){
    short int* numbers = (short int*)calloc(N + 1, sizeof(short int)); //0 - prime, 1 - compos
    numbers[0] = 1;
    numbers[1] = 1;

    long long ind_mass = 0; //index in mass of next prime number
    for(long long num = 2; num < N + 1; num++){
        if(numbers[num] == 0){
            mass[ind_mass] = num;
            ind_mass++;
            for(long long i = num; i < N + 1; i += num){
                numbers[i] = 1;
            }
        }
    }
    free(numbers);
}
// 6k, 6k + 1, 6k + 2, ... 6k + 5
// 1: 7
// 2: 11
// 3: 13
// 4: 17