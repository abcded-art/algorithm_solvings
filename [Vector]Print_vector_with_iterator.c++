#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> vec){
    for(typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << std::endl;
    }
}

int main(int argc, const char* argv[]){
    std::vector<int> v;
    v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40);
    v.insert(v.begin() + 1, 15);
    v.erase(v.begin() + 3);
    print_vector(v);
    return 0;
}