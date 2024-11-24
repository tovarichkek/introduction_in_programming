#pragma once

#include <fstream>
#include <utility>
#include <cstdlib>

#include <iostream>

//TODO проверять длину файла
//line in prime_numbers_up_to_10_6.txt, which has maximum possible unsigned short ref
#define MAX_UNS_SHORT_LINE 6542
#define LAST_LINE 78498

int fast_pow_mod(unsigned int num, unsigned int pow, unsigned int mod);

void encrypt_block(std::pair<unsigned int, unsigned int> public_key, unsigned int* data, unsigned int* dest);
void decrypt_block(std::pair<unsigned int, unsigned int> private_key, unsigned int* data, unsigned int* dest);

bool check_prime(unsigned long long n);

std::pair<int, int> extended_evklid(unsigned int a, unsigned int b);

void make_keys(unsigned short p, unsigned short q, unsigned int e, std::pair<unsigned int, unsigned int>* public_key, std::pair<unsigned int, unsigned int>* private_key);

template<typename T> 
unsigned short simple_hash_function(T* data, size_t count_elems){
    unsigned short sum = 0;
    for(int i = 0; i < count_elems; i++){
        for(size_t num_byte = 0; num_byte < sizeof(T); num_byte++){
            char* byte = (char*)(&(data[i])) + num_byte;
            sum += *byte;
        }
        
    }
    return sum;
}


//TODO проверка на конец файла
template<typename T>
void generating_params_for_keys_by_data(T* data, size_t count_elems, unsigned short& p, unsigned short& q, unsigned int& e, unsigned short(* hash_function)(T*, size_t) = simple_hash_function){
    p = 0, q = 0, e = 0;

    std::ifstream prime_numbers;
    prime_numbers.open("../RSA/prime_numbers_up_to_10_6.txt");

    size_t num_str_p = MAX_UNS_SHORT_LINE % hash_function(data, count_elems);
    size_t num_str_q = MAX_UNS_SHORT_LINE % hash_function(data, count_elems / 2 + 1);

    std::cout << "num_str_p: " << num_str_p << "   |||   num_str_q: " << num_str_q << std::endl;

    int buff;

    size_t i = 1;
    while((p == 0) || (q == 0)){
        prime_numbers >> buff;
        if(i == num_str_p){
            p = buff;
        }
        if(i == num_str_q){
            q = buff;
        }
        i++;
    }

    //e should be smaller than (p - 1) * (q - 1)
    //TODO рандомно выбирать строку в файле и проверять, что меньше (p - 1) * (q - 1)
    size_t num_str_e = std::max(num_str_q, num_str_p) + 1; //заглушка временно, TODO

    std::cout << "num_str_e: " << num_str_e << std::endl;


    while(e == 0){
        prime_numbers >> buff;
        if(i == num_str_e){
            e = buff;
        }
        i++;
    }
    prime_numbers.close();
}


template<typename T>
void generating_keys_by_data(T* data, size_t count_elems, std::pair<unsigned int, unsigned int>* public_key, std::pair<unsigned int, unsigned int>* private_key, unsigned short(* hash_function)(T*, size_t) = simple_hash_function){
    unsigned short p = 0, q = 0;
    unsigned int e = 0;
    generating_params_for_keys_by_data(data, count_elems, p, q, e, hash_function);
    make_keys(p, q, e, public_key, private_key);
}

