#include <iostream>
#include <vector>
#include <cstring>
#include <boost/program_options.hpp>
#include "../src/fast_set.hpp"

#define IS_GOOD_INPUT \
    if(!std::cin.good()){ \
        std::cout << "Input error" << std::endl; \
        return 0; \
    } \

class Input_params{
private:
    size_t PHRASE_MAX_LEN;
public:
    //constructor
    Input_params(int argc, char *argv[]){
        namespace prog_opts = boost::program_options;

        prog_opts::options_description desc("Allowed options");
        desc.add_options()
            ("string_max_size", prog_opts::value<size_t>()->default_value(100), "the maximum number of characters in a string from which substrings will be created")
            ("help", "help message")
        ;
    
        prog_opts::variables_map vm;
        prog_opts::store(prog_opts::parse_command_line(argc, argv, desc), vm);
        prog_opts::notify(vm);
    
        if(vm.count("help")){
            std::cout << desc << "\n";
            exit(1);
        }
        if(vm.count("string_max_size")){
            PHRASE_MAX_LEN = vm["string_max_size"].as<size_t>();
        }
    }

    //getter
    size_t get_PHRASE_MAX_LEN() const{
        return this->PHRASE_MAX_LEN;
    }
};

int main(int argc, char *argv[]){

    Input_params input = Input_params(argc, argv);

    char phrase[input.get_PHRASE_MAX_LEN()];

    std::cout << "Phrase whose substrings will be displayed: ";
    std::cin >> phrase;
    IS_GOOD_INPUT;


    std::vector<long long> A(strlen(phrase));
    
    for(size_t i = 0; i < strlen(phrase); i++){
        A[i] = phrase[i];
    }
    Fast_border_set fast_A = Fast_border_set(A);

    std::list<Fast_border_set> res = {}; // Здесь не нужен std::list. Достаьлчно std::vector
    
    fast_A.all_nodes(res);
    
    // [1] Это похоже на std::unordered_map, но с более плохой ассмптотикой. 
    // Попробуй реализовать аналогичный алгоритм используя стандартную структуру данных
    for(auto it = res.begin(); it != res.end(); it++){
        it->Print_chars();
    }
    
}