#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <iostream>
#include "eratosfen.hpp"
#include <fstream>

void numbers_from_true_data(long long* data){
    std::ifstream file;
    file.open("../prime_numbers_up_to_10_6.txt");
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


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}