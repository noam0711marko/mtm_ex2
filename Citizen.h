//
// Created by dolle on 02/01/2022.
//

//////////////////////////////////////////////////////
//////// don't forget to abstract this class /////////
//////////////////////////////////////////////////////

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
    Citizen(int new_id, const string& new_first_name, const string& new_last_name, int new_year);
    ~Citizen() = default;
    Citizen(const Citizen &old) = default;
    Citizen &operator=(const Citizen &old) = default;

public:
    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    int getBirthYear() const;

    friend bool operator<(const Citizen&, const Citizen&);
    friend bool operator==(const Citizen&, const Citizen&);

    std::ostream &printShort(std::ostream &) const;
    virtual std::ostream &printLong(std::ostream &) const;

    shared_ptr<Citizen> clone() const;
};

bool operator<=(const Citizen&, const Citizen&);
bool operator>(const Citizen&, const Citizen&);
bool operator>=(const Citizen&, const Citizen&);
bool operator!=(const Citizen&, const Citizen&);

#endif //MTM_EX2_CITIZEN_H