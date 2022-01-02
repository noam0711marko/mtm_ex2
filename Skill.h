//
// Created by Noam Marko on 01/01/2022.
//

#ifndef MTM_EX2_SKILL_H
#define MTM_EX2_SKILL_H

#include <iostream>


class Skill {
    int skill_id;
    std::string skill_name;
    int required_points_for_purchase;

public:
    Skill(int id, std::string name, int points);
    ~Skill()=default;
    Skill(Skill&)=default;
    Skill& operator=(const Skill&)=default;

    const int& getId() const;
    const std::string& getName() const;
    const int& getRequiredPoints() const;

    friend std::ostream& operator<<(std::ostream&, const Skill&);
    friend bool operator<(const Skill&, const Skill&);
    friend bool operator==(const Skill&, const Skill&);

    int& operator++()=delete;
    int operator++(int);
    int& operator+=(const int&);

    Skill operator+(const int&);

};

bool operator<=(const Skill&, const Skill&);
bool operator>(const Skill&, const Skill&);
bool operator>=(const Skill&, const Skill&);
bool operator!=(const Skill&, const Skill&);



#endif //MTM_EX2_SKILL_H
