#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

// [1] Советую пользоваться каким-нибудь форматером; в vscode есть встроенный

class Fast_border_set {
public:
  std::vector<size_t> data;
  long long min_el;
  long long max_el;

public:
  Fast_border_set(long long left, long long right) {
    min_el = left;
    max_el = right;
    data = std::vector<size_t>(right - left + 1);
  }
  // 0 - is element of set too
  Fast_border_set(std::vector<long long> &arr)
      : Fast_border_set(*std::min_element(arr.begin(), arr.end()),
                        *std::max_element(arr.begin(), arr.end())) {
    for (auto i : arr) {
      data[i - this->min_el]++; // [1] this тут не надо использовать; это отдельная идиома и она тут не нужна
    }
  }

// [2] Чтобы не писать второй конструктор можешь попробовать использовать шаблоны 
// template <typename Cont>
// Fast_border_set(Cont &list)  
  Fast_border_set(std::list<long long> &list)
      : Fast_border_set(*std::min_element(list.begin(), list.end()),
                        *std::max_element(list.begin(), list.end())) {
    for (auto i : list) {
      data[i - this->min_el]++;
    }
  }

  Fast_border_set(const Fast_border_set &B) { // [1] Такое копирование писать не надо тк оно сгенерируется компилятором само
    min_el = B.min_el;
    max_el = B.max_el;
    for (auto i : B.data) {
      this->data.push_back(i);
    }
  }
// [1] Такое удаление писать не надо тк оно сгенерируется компилятором само
  ~Fast_border_set() { 
    max_el = min_el - 1; // non-valid value, to detect errors (не получится тк компилятор может делать многое)
    data.clear();
    data.shrink_to_fit();
  }

  // checking for the same number of numbers in both data
  bool operator==(const Fast_border_set &B) const {
    size_t this_now = 0, B_now = 0;
    for (long long num = std::min(this->min_el, B.min_el);
         num <= std::max(this->max_el, B.max_el); num++) {

      if ((num < this->min_el) || (num > this->max_el)) {
        this_now = 0;
      } else {
        this_now = this->data[num - this->min_el];
      }
      if ((num < B.min_el) || (num > B.max_el)) {
        B_now = 0;
      } else {
        B_now = B.data[num - B.min_el];
      }

      if (this_now != B_now) {
        return false;
      }
    }
    return true;
  }

  void Print_nums() const;
  void Print_chars() const;
  Fast_border_set *symm_diff(Fast_border_set &B);
  void subnodes(std::list<Fast_border_set> &write_to) const;
  void all_nodes(std::list<Fast_border_set> &write_to) const;
};

void remove_equal(std::list<Fast_border_set> &write_to,
                  std::_List_iterator<Fast_border_set> begin,
                  std::_List_iterator<Fast_border_set> end);