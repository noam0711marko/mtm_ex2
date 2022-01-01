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


