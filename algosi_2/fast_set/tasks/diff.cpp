#include <iostream>
#include <vector>
#include "../src/fast_set.hpp" // надо избегать ../ 
//                                это делает код непереносимым
//                                вместо этого испоользуй target_include_directory в CmakeLists.txt

#define IS_GOOD_INPUT \
    if(!std::cin.good()){ \
        std::cout << "Input error" << std::endl; \
        return 0; \
    } \


int main(){
    size_t A_size, B_size;

    std::cout << "Set A size?" << std::endl;
    std::cin >> A_size;
    IS_GOOD_INPUT;
    
    std::vector<long long> A(A_size);   
    std::cout << "Enter A nums: ";
    for(auto &i: A){
        std::cin >> i;
        IS_GOOD_INPUT;
    }

    std::cout << "Set B size?" << std::endl;
    std::cin >> B_size;
    IS_GOOD_INPUT;

    std::vector<long long> B(B_size);  // Это дублирует прошлый код; Лучше даже такие маленькие циклы заносить в функции
    std::cout << "Enter B nums: ";
    for(auto &i: B){
        std::cin >> i;
        IS_GOOD_INPUT;
    }
    
    Fast_border_set fast_A = Fast_border_set(A);
    Fast_border_set fast_B = Fast_border_set(B);
    
    Fast_border_set* diff = fast_A.symm_diff(fast_B); // Лучше использовать std::unique_ptr чтобы не освобождать руками память

    
    std::cout << "Symmetrical difference:" << std::endl;
    diff->Print_nums();

    delete diff;

}