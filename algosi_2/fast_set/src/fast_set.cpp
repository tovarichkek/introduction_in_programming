#include "fast_set.hpp"

//return link to object in dynamic memory - symmetrical difference between this and B
//if memory runs out, returns nullptr
Fast_border_set* Fast_border_set::symm_diff(Fast_border_set& B){
    Fast_border_set* res = new Fast_border_set(std::min(this->min_el, B.min_el), std::max(this->max_el, B.max_el));
    if(res == nullptr){
        return nullptr;
    }
    size_t this_now = 0, B_now = 0;
    // [0] Этот алгоритм имеет плохую ассимптотику. Он иммет O(max - min). 
    // Если хранить std::vector<std::pair<{value}, {number of occurances}>> то ассимптотика будет O(N) N - количество элементов
    for(long long num = std::min(this->min_el, B.min_el); num <= std::max(this->max_el, B.max_el); num++){

        if((num < this->min_el) || (num > this->max_el)){
            this_now = 0;
        }
        else{
            this_now = this->data[num - this->min_el]; 
        }

        if((num < B.min_el) || (num > B.max_el)){
            B_now = 0;
        }
        else{
            B_now = B.data[num - B.min_el];
        }


        if(this_now > B_now){
            res->data[num - res->min_el] = this_now - B_now;
        }
        else{
            res->data[num - res->min_el] = B_now - this_now;
        }

    }
    return res;
}

//Print elements with space
void Fast_border_set::Print_nums() const{
    for(long long pos = 0; pos < this->data.size(); pos++){
        for(size_t rpts = 0; rpts < this->data[pos]; rpts++){
            std::cout << pos + min_el << ' ';
        }
    }
    std::cout << std::endl;
}

//Print elements like symbols with space(otherwise the output will be character codes)
void Fast_border_set::Print_chars() const{
    for(long long pos = 0; pos < this->data.size(); pos++){
        for(size_t rpts = 0; rpts < this->data[pos]; rpts++){
            if(pos + min_el < CHAR_MIN){
                std::cout << "type_of_elem is not char, it's smaller than CHAR_MIN" << std::endl;
                return;
            }
            if(pos + min_el > CHAR_MAX){
                std::cout << "type_of_elem is not char, it's bigger than CHAR_MIN" << std::endl;
                return;
            }
            std::cout << (char)(pos + min_el);
        }
    }
    std::cout << std::endl;
}


//write to end of list write_to elements, which is subnodes for *this(delete one element from data[i])
void Fast_border_set::subnodes(std::list<Fast_border_set>& write_to) const{
    for(size_t pos = 0; pos < this->data.size(); pos++){
        if(this->data[pos] > 0){
            write_to.push_back(Fast_border_set{*this});  //copying this to write_to
            auto it = write_to.end();
            it--; // get link to last elem
            it->data[pos] -= 1; // changing copy into subnode*/
        }
    }   
}

//leaves the list range /begin - end/  only unique elements
//TODO удаляет все совпадения, нужно с начала по конец
void remove_equal(std::list<Fast_border_set>& write_to, std::_List_iterator<Fast_border_set> begin, std::_List_iterator<Fast_border_set> end){
    for(auto i = begin; i != end; i++){
        auto j = i;
        j++;
        for(; j != end;){
            if(*i == *j){
                j = write_to.erase(j);
            }
            else{
                j++;
            }
        }
    }
}

//add root and all his subnodes to back of list write_to
void Fast_border_set::all_nodes(std::list<Fast_border_set>& write_to) const{
    write_to.push_back(Fast_border_set{*this});
    

    auto root = write_to.end();
    root--; // link to root

    
    for(auto it = root; it != write_to.end(); it++){
        it->subnodes(write_to);
        remove_equal(write_to, root, write_to.end());
    }
}