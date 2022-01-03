//
// Created by Noam Marko on 03/01/2022.
//

#include "Employee.h"

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
    if(to_add.getRequiredPoints()>=score){
        throw CanNotLearnSkill();
    }
    skills.insert(shared_ptr<Skill>(new Skill(to_add)));
    setScore(to_add.getRequiredPoints());
}

void Employee::forgetSkill(const int &id_to_forget) {
    for(const shared_ptr<Skill> &n : skills){
        if(n->getId()==id_to_forget){
            skills.erase(n);
            return;
        }
    }
    throw DidNotLearnSkill();
}

bool Employee::hasSkill(int id) {
    for(const shared_ptr<Skill> &n : skills){
        if(n->getId()==id){
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

ostream &Employee::printShort(ostream &out) const{
    out << "Short_Print" << endl;
    out << this->getFirstName() << this->getLastName() << endl;
    out << "Salary: " << salary << " Score: " << score << endl;
    return out;
}

//code duplication - need to fix it
ostream &Employee::printLong(ostream &out) const{
    out << "Long_Print" << endl;
    out << this->getFirstName() << this->getLastName() << endl;
    out << "id - " << this->getId() << " birth_year - " << this->getBirthYear() << endl;
    out << "Salary: " << salary << " Score: " << score << endl;
    for(const shared_ptr<Skill> &n : skills){
        out << n->getName() << endl;
    }
    return out;
}

Employee* Employee::clone() const {
    Employee* clone=new Employee(*this);
    return clone;
}

