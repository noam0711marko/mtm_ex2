#ifndef MTM_EX2_EMPLOYEE_H
#define MTM_EX2_EMPLOYEE_H

#include <iostream>
#include "Citizen.h"
#include "Skill.h"
#include "set"
#include "memory"
#include "exceptions.h"

using std::shared_ptr;
using std::set;
using std::string;
using std::ostream;

namespace mtm {
    class Employee : public Citizen {
        int salary;
        int score;
        set<Skill, cmp_skills> skills;
        set<int> faculties_id;

    public:
        explicit Employee(int new_id, const string &new_first_name, const string &new_last_name, int new_year);

        ~Employee() override = default;

        Employee(const Employee &) = default;

        Employee &operator=(const Employee &) = default;

        int getSalary() const override;

        int getScore() const;

        void learnSkill(const Skill &);

        void forgetSkill(const int &id_to_forget);

        bool hasSkill(int skill_id) const;

        void setSalary(int add_to_salary);

        void setScore(int add_to_score);

        ostream &printShort(ostream &) const override;

        ostream &printLong(ostream &) const override;

        ostream &printSalaryScore(ostream &) const;

        ostream &printSkills(ostream &) const;

        Employee *clone() const override;

        //bool alreadyInFaculty(int faculty_id);

        //void addFacultyToEmployee(int faculty_id);

    };

}
#endif //MTM_EX2_EMPLOYEE_H
