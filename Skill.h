#ifndef MTM_EX2_SKILL_H
#define MTM_EX2_SKILL_H

#include <iostream>

using std::string;
using std::ostream;

class Skill {
    int skill_id;
    string skill_name;
    int required_points_for_purchase;

public:
    Skill(int id, const string& name, int points);
    ~Skill()=default;
    Skill(Skill&)=default;
    Skill& operator=(const Skill&)=default;

    const int& getId() const;
    const string& getName() const;
    int getRequiredPoints() const;

    friend ostream& operator<<(ostream&, const Skill&);
    friend bool operator<(const Skill&, const Skill&);
    friend bool operator==(const Skill&, const Skill&);

    int& operator++()=delete;
    int operator++(int);
    int& operator+=(const int&);

    Skill operator+(const int&);

    class NegativePoints : std::exception{};

};

bool operator<=(const Skill&, const Skill&);
bool operator>(const Skill&, const Skill&);
bool operator>=(const Skill&, const Skill&);
bool operator!=(const Skill&, const Skill&);



#endif //MTM_EX2_SKILL_H
