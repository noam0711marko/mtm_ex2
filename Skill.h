//
// Created by Noam Marko on 01/01/2022.
//

#ifndef MTM_EX2_SKILL_H
#define MTM_EX2_SKILL_H

#include <iostream>


class Skill {
    unsigned int skill_id;
    std::string skill_name;
    unsigned int points_for_purchase;

public:
    Skill(unsigned int id, std::string name, unsigned int points);
    ~Skill()=default;
    Skill(Skill&)=default;
    Skill& operator=(const Skill&)=default;
};


#endif //MTM_EX2_SKILL_H
