#include "RSA.hpp"
#include <math.h>
#include <iostream>
#include <fstream>


//a ^ b mod c
int fast_pow_mod(unsigned int num, unsigned int pow, unsigned int mod){
    unsigned int result = 1;
    while(pow > 0){
        if(pow % 2 == 0){
            pow /= 2;
            num = (((unsigned long long)(num)) * num) % mod;    
        }
        else{
            pow--;
            result = (result * ((unsigned long long)(num))) % mod;
            pow /= 2;
            num = (((unsigned long long)(num)) * num) % mod;    
        }
    }
    return result;

}

//----------------------encrypt and decrypt - the same functions???
//encrypt one block with size ???unsigned int???
void encrypt_block(std::pair<unsigned int, unsigned int> public_key, unsigned int* data, unsigned int* dest){
    if(data == nullptr || dest == nullptr){
        std::cout << "Incorrect ptr to dest or to data" << std::endl;
        return;
    }

    *dest = fast_pow_mod(*data, public_key.first, public_key.second);
}
void decrypt_block(std::pair<unsigned int, unsigned int> private_key, unsigned int* data, unsigned int* dest){
    if(data == nullptr || dest == nullptr){
        std::cout << "Incorrect ptr to dest or to data" << std::endl;
        return;
    }

    *dest = fast_pow_mod(*data, private_key.first, private_key.second);
}
//-----------------------------------------------------------------

bool check_prime(unsigned long long n){
    for(int i = 2; i <= std::sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

std::pair<int, int> extended_evklid(unsigned int a, unsigned int b){
    unsigned int q, r;
    int x, y;
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0;
    while(b > 0){
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    return std::make_pair(x2, y2);
}

//p, q, e must be prime!!!!!  e < (p - 1) * (q - 1) !!!
void make_keys(unsigned short p, unsigned short q, unsigned int e, std::pair<unsigned int, unsigned int>* public_key, std::pair<unsigned int, unsigned int>* private_key){
    if(!check_prime(p)){
        std::cout << "ERROR! p is not prime" << std::endl;
        return;
    }
    if(!check_prime(q)){
        std::cout << "ERROR! q is not prime" << std::endl;
        return;
    }
    if(!check_prime(e)){
        std::cout << "ERROR! e is not prime" << std::endl;
        return;
    }
    if(e >= (p - 1) * (q - 1)){
        std::cout << "ERROR! e is equal or more than (p - 1) * (q - 1)" << std::endl;
        return;
    }

    unsigned int N = p * q;
    unsigned int fi = (p - 1) * (q - 1);
    std::pair<int, int> roots = extended_evklid(e, fi);
    unsigned int d;

    if(roots.first < 0){
        d = fi + roots.first;
    }
    else{
        d = roots.first;
    }

    *public_key = std::make_pair(e, N);
    *private_key = std::make_pair(d, N);
    
}