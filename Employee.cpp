#include "Employee.h"

#include <iostream>

using std::endl;

Employee::Employee(int new_id, const string &new_first_name, const string &new_last_name, int new_year) : Citizen(
        new_id, new_first_name, new_last_name, new_year), salary(0), score(0), skills() {}

int Employee::getSalary() const {
    return salary;
}

int Employee::getScore() const {
    return score;
}

void Employee::learnSkill(const Skill& to_add) {
    if(hasSkill(to_add.getId())){
        throw SkillAlreadyLearned();
    }
    if(to_add.getRequiredPoints()>score){
        throw CanNotLearnSkill();
    }
    skills.insert(shared_ptr<Skill>(new Skill(to_add)));
    /*setScore(to_add.getRequiredPoints());*/
}

void Employee::forgetSkill(const int &id_to_forget) {
    for(const shared_ptr<Skill> &n : skills){
        if(n->getId()==id_to_forget){
            /*setScore(-n->getRequiredPoints());*/ //remove skill points of removed skills (?)
            skills.erase(n);
            return;
        }
    }
    throw DidNotLearnSkill();
}

bool Employee::hasSkill(int skill_id) {
    for(const shared_ptr<Skill> &n : skills){
        if(n->getId() == skill_id){
            return true;
        }
    }
    return false;
}

void Employee::setSalary(int add_to_salary) {
    salary+=add_to_salary;
}

void Employee::setScore(int add_to_score) {
    score+=add_to_score;
}

ostream &Employee::printShort(ostream &os) const{
    printFirstLastName(os);
    printSalaryScore(os);
    os << endl;
    return os;
}

ostream &Employee::printLong(ostream &os) const{
    printFirstLastName(os);
    printIdBirthYear(os);
    printSalaryScore(os);
    printSkills(os);
    return os;
}

ostream &Employee::printSalaryScore(ostream& os) const {
    os << "Salary: " << salary << " Score: " << score;
    return os;
}

ostream &Employee::printSkills(ostream& os) const {
    os << " Skills:" << endl;
    for(const shared_ptr<Skill> &n : skills){
        os << n->getName() << endl;
    }
    return os;
}

Citizen* Employee::clone() const {
    Citizen* copy=new Employee(*this);
    return copy;
}

int Employee::getNumOfSkills() const {
    return (int)skills.size();
}
