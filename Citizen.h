//
// Created by dolle on 02/01/2022.
//

#ifndef MTM_EX2_CITIZEN_H
#define MTM_EX2_CITIZEN_H

#include "memory"
#include <iostream>
using std::string;
using std::shared_ptr;
class Citizen {
int id;
string first_name;
string last_name;
int year_of_birth;
protected:
Citizen(int new_id,string new_first_name,string new_last_name,int new_year);
    ~Citizen()= default;
    Citizen(const Citizen& old)= default;
    Citizen& operator=(const Citizen& old)= default;
public:
   int getId();
   string getFirstName();
    string getLastName();
    int getBirthYear();

    std::ostream& printShort(std::ostream&);
    std::ostream& printLong(std::ostream&);
    shared_ptr<Citizen> clone();
};


#endif //MTM_EX2_CITIZEN_H
