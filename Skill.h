//
// Created by Noam Marko on 01/01/2022.
//

#ifndef MTM_EX2_SKILL_H
#define MTM_EX2_SKILL_H

#include <iostream>


class Skill {
    unsigned int skill_id;
    std::string skill_name;
    unsigned int required_points_for_purchase;

public:
    Skill(unsigned int id, std::string name, unsigned int points);
    ~Skill()=default;
    Skill(Skill&)=default;
    Skill& operator=(const Skill&)=default;

    const unsigned int& getId() const;
    const std::string& getName() const;
    const unsigned int& getRequiredPoints() const;

    friend std::ostream& operator<<(std::ostream&, const Skill&);
    friend bool operator<(const Skill&, const Skill&);
    friend bool operator==(const Skill&, const Skill&);
};

bool operator<=(const Skill&, const Skill&);
bool operator>(const Skill&, const Skill&);
bool operator>=(const Skill&, const Skill&);
bool operator!=(const Skill&, const Skill&);


#endif //MTM_EX2_SKILL_H
