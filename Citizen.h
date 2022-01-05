//////////////////////////////////////////////////////
//////// don't forget to abstract this class /////////
//////////////////////////////////////////////////////

#ifndef MTM_EX2_CITIZEN_H
#define MTM_EX2_CITIZEN_H

#include "memory"
#include <iostream>

using std::string;
using std::shared_ptr;
using std::ostream;

class Citizen {
    int id;
    string first_name;
    string last_name;
    int year_of_birth;

protected:
    Citizen(int new_id, const string& new_first_name, const string& new_last_name, int new_year);
    ~Citizen() = default;
    Citizen(const Citizen&) = default;
    Citizen &operator=(const Citizen&) = default;

public:
    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    int getBirthYear() const;

    friend bool operator<(const Citizen&, const Citizen&);
    friend bool operator==(const Citizen&, const Citizen&);

    virtual ostream &printShort(ostream &) const = 0;
    virtual ostream &printLong(ostream &) const = 0;

    ostream &printFirstLastName(ostream &out) const;
    ostream &printIdBirthYear(ostream &out) const;

    virtual Citizen* clone() const =0;
};

bool operator<=(const Citizen&, const Citizen&);
bool operator>(const Citizen&, const Citizen&);
bool operator>=(const Citizen&, const Citizen&);
bool operator!=(const Citizen&, const Citizen&);

struct cmp_citizens{
    bool operator() (const shared_ptr<Citizen>& a, const shared_ptr<Citizen>& b) const {return (*a)<(*b); }
};

#endif //MTM_EX2_CITIZEN_H
