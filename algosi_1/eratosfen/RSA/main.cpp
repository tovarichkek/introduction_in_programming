#include "RSA.hpp"
#include <cstring>
#include "../src/eratosfen.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>


//TODO использовать алгоритм Эратосфена вместо сгенерированного файлика prime_numbers

int main(){

    unsigned int message;
    unsigned int cipher, ans;

    char phrase[100];
    std::cout << "Phrase by which, would be generated keys" << std::endl;
    std::cin >> phrase;

    //TODO кодировать строчку вместо int, преобразовывая в unsigned int и кодируя по блокам 4 байта
    std::cout << "Number, which should be encoded" << std::endl;
    std::cin >> message;

    std::pair<unsigned int, unsigned int> public_key;
    std::pair<unsigned int, unsigned int> private_key;

    //simple_hash_function can be changed on other hash function
    generating_keys_by_data(phrase, std::strlen(phrase), &public_key, &private_key, simple_hash_function);
    
    encrypt_block(public_key, &message, &cipher);
    std::cout << "Encoded data: " << cipher << std::endl;

    decrypt_block(private_key, &cipher, &ans);
    std::cout << "Decoded data :" << ans << std::endl;


}