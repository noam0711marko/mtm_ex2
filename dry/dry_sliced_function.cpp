//
// Created by Noam Marko on 02/01/2022.
//

#include <iostream>
#include <vector>

using std::cout;

class BadInput{};

template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop){
    if(start<0 || start>=vec.size() || stop <0 || stop >= vec.size() || step<=0){
        throw BadInput();
    }
    std::vector<T> new_vec={};
    if (start>=stop){
        return new_vec;
    }
    for(int i=start; i<stop; i+=step){
        new_vec.push_back(vec[i]);
    }
    return new_vec;
};

void print_vec(const std::vector<char>& vec)
{
    for (auto x: vec) {
        std::cout << ' ' << x;
    }
    std::cout << std::endl;
}


int main(){
    std::vector<char> vec1 {'a','b','c','d','e'};
    std::vector<char> vec1_sliced1=slice(vec1, 0,2,4);
    std::cout << "vec1_sliced1 = ";
    print_vec(vec1_sliced1);
    std::vector<char> vec1_sliced2=slice(vec1, 1,1,5);
    std::cout << "vec1_sliced2 = ";
    print_vec(vec1_sliced2);

    return 0;

}
