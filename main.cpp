#include <iostream>
#include "Skill.h"

using std::cout;

int main() {
    Skill s1(1,"C++",0);
    cout << s1;
    Skill s2(2,"C",1);
    s1+=2;
    cout << "required points to purchase " << s1 << "is: " << s1.getRequiredPoints() << std::endl << std::endl;
    Skill s3(3, "Java", 15);
    cout << "s3 was " << s3;
    s3=s2;
    cout << "but now, it's " << s3 << "and s2 is " << s2 << std::endl;
    Skill s11=s1;
    s1=s2+4;
    cout << "now, required points to purchase " << s1 << "is: " << s1.getRequiredPoints() << std::endl << std::endl;
    if(s1==s2){
        cout << "s1 and s2 ids are equal now";
    }
    else{
        cout << "s1 and s2 ids aren't equal";
        return 1;
    }
    cout << std::endl;
    if(s1!=s11){
        cout << "s1 is no longer " << s11;
    }
    else {
        cout << "s1 is still " << s11;
        return 1;
    }
    cout << std::endl;
    if (s11<s2){
        cout << "s11 id smaller than s2 id: " << s11.getId() << " < " << s2.getId();
    }
    else{
        cout << "s11 id isn't smaller than s2 id: " << s11.getId() << " >= " << s2.getId();
        return 1;
    }
    cout << std::endl;

    return 0;
}
