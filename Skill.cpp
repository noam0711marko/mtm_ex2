#include "Skill.h"

using std::string;
using std::ostream;
using std::endl;

Skill::Skill(int id, const string& name, int points):
        skill_id(id), skill_name(name), required_points_for_purchase(points) {
}

const int &Skill::getId() const {
    return skill_id;
}

const string &Skill::getName() const {
    return skill_name;
}

int Skill::getRequiredPoints() const {
    return required_points_for_purchase;
}

ostream &operator<<(ostream& os, const Skill& skill) {
    os<<skill.skill_name<<endl;
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

int Skill::operator++(int) {
    Skill res=*this;
    ++res.required_points_for_purchase;
    return res.required_points_for_purchase;
}

int &Skill::operator+=(const int& points) {
    if(points<0){
        throw NegativePoints();
    }
    this->required_points_for_purchase+=points;
    return this->required_points_for_purchase;
}

Skill Skill::operator+(const int& points) {
    if(points<0){
        throw NegativePoints();
    }
    *this+=points;
    return *this;
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


