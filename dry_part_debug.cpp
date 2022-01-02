//
// Created by Noam Marko on 02/01/2022.
//
#include <iostream>
#include "vector"

template<class T>
        std::vector<T> slice(std::vector<T> vec, int start, int step, int stop);

//to debug:

class A {
public:
    std::vector<int*> values;
    void add(int x) { values.push_back(new int(x)); }
    ~A();
};
A::~A() {
    int len=values.size();
    for (int i=0; i<len; ++i){
        delete(values[i]);
    }
}
int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}

//slice function:
template<class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop){
    if(start<0 || start>=vec.size() || stop <0 || stop >= vec.size() || step<=0){
        /*throw badInput; //update this */
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
