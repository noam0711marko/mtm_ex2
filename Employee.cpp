#include "Employee.h"

#include <iostream>

using std::endl;

namespace mtm {

    Employee::Employee(int new_id, const string &new_first_name, const string &new_last_name, int new_year) : Citizen(
            new_id, new_first_name, new_last_name, new_year), salary(0), score(0) {}

    int Employee::getSalary() const {
        return salary;
    }

    int Employee::getScore() const {
        return score;
    }

    void Employee::learnSkill(const Skill &to_add) {
        if (hasSkill(to_add.getId())) {
            throw SkillAlreadyLearned();
        }
        if (to_add.getRequiredPoints() > score) {
            throw CanNotLearnSkill();
        }
        skills.insert(to_add);
        //setScore(to_add.getRequiredPoints());
    }

    void Employee::forgetSkill(const int &id_to_forget) {
        for (const Skill &n: skills) {
            if (n.getId() == id_to_forget) {
                //setScore(-n.getRequiredPoints()); //remove skill points of removed skills (?)
                skills.erase(n);
                return;
            }
        }
        throw DidNotLearnSkill();
    }

    bool Employee::hasSkill(int skill_id) const {
        for (const Skill &n: skills) {
            if (n.getId() == skill_id) {
                return true;
            }
        }
        return false;
    }

    void Employee::setSalary(int add_to_salary) {
        if (salary + add_to_salary < 0) {
            salary = 0;
            return;
        }
        salary += add_to_salary;
    }

    void Employee::setScore(int add_to_score) {
        if (score + add_to_score < 0) {
            score = 0;
            return;
        }
        score += add_to_score;
    }

    ostream &Employee::printShort(ostream &os) const {
        printFullName(os);
        printSalaryScore(os);
        os << endl;
        return os;
    }

    ostream &Employee::printLong(ostream &os) const {
        printFullName(os);
        printIdBirthYear(os);
        printSalaryScore(os);
        printSkills(os);
        return os;
    }

    ostream &Employee::printSalaryScore(ostream &os) const {
        os << "Salary: " << salary << " Score: " << score;
        return os;
    }

    ostream &Employee::printSkills(ostream &os) const {
        if(!skills.empty()){
            os << " Skills: " << endl;
            for (const Skill &n: skills) {
                os << n.getName() << endl;
            }
        }
        else{
            os << endl;
        }
        return os;
    }

    Employee *Employee::clone() const {
        Employee *copy = new Employee(*this);
        return copy;
    }
}