#include <iostream>
#include "vector"
#include "memory"

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
}

/*** to fix: ***
class A {
public:
    std::vector<int*> values;
    void add(int x) { values.push_back(new int(x)); }
};
 */

//fixed:
class A {
public:
    std::vector<std::shared_ptr<int>> values;
    void add(int x){
        std::shared_ptr<int> value_pointer(new int(x));
        values.push_back(value_pointer);
    }
};

int main() {
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}


