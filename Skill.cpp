//
// Created by Noam Marko on 01/01/2022.
//

#include "Skill.h"

Skill::Skill(unsigned int id, std::string name, unsigned int points):
        skill_id(id), skill_name(name), required_points_for_purchase(points) {
}

const unsigned int &Skill::getId() const {
    return skill_id;
}

const std::string &Skill::getName() const {
    return skill_name;
}

const unsigned int &Skill::getRequiredPoints() const {
    return required_points_for_purchase;
}

std::ostream &operator<<(std::ostream& os, const Skill& skill) {
    os<<skill.skill_name<<std::endl;
    return os;
}

bool operator<(const Skill& skill_1, const Skill& skill_2) {
    if(skill_1.skill_id<skill_2.skill_id){
        return true;
    }
    return false;
}

bool operator==(const Skill& skill_1, const Skill& skill_2) {
    if(skill_1.skill_id==skill_2.skill_id){
        return true;
    }
    return false;
}

bool operator<=(const Skill& skill_1, const Skill& skill_2) {
    if(skill_1<skill_2 || skill_1==skill_2){
        return true;
    }
    return false;
}

bool operator>(const Skill& skill_1, const Skill& skill_2) {
    if(skill_2<skill_1){
        return true;
    }
    return false;
}

bool operator>=(const Skill& skill_1, const Skill& skill_2) {
    if(skill_2<skill_1 || skill_1==skill_2){
        return true;
    }
    return false;
}

bool operator!=(const Skill& skill_1, const Skill& skill_2) {
    if(skill_1==skill_2){
        return false;
    }
    return true;
}




