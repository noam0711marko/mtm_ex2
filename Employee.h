#ifndef MTM_EX2_EMPLOYEE_H
#define MTM_EX2_EMPLOYEE_H

#include <iostream>
#include "Citizen.h"
#include "Skill.h"
#include "set"
#include "memory"

using std::shared_ptr;
using std::set;
using std::string;
using std::ostream;

struct cmp_skills{
    bool operator() (const shared_ptr<Skill>& a, const shared_ptr<Skill>& b) const {return (*a)<(*b); }
};

class Employee : public Citizen {
    int salary;
    int score;
    set<shared_ptr<Skill>, cmp_skills> skills;

public:
    Employee(int new_id, const string& new_first_name, const string& new_last_name, int new_year);
    ~Employee()=default;
    Employee(const Employee&) = default;
    Employee &operator=(const Employee&) = default;

    int getSalary() const;
    int getScore() const;

    void learnSkill(const Skill&);
    void forgetSkill(const int& id_to_forget);

    bool hasSkill(int id);

    void setSalary(int add_to_salary);
    void setScore(int add_to_score);

    ostream &printShort(ostream&) const override;
    ostream &printLong(ostream&) const override;

    ostream &printSalaryScore(ostream&) const;
    ostream &printSkills(ostream&) const;

    Citizen* clone() const override;

    class SkillAlreadyLearned : std::exception{};
    class CanNotLearnSkill : std::exception{};
    class DidNotLearnSkill : std::exception{};
};


#endif //MTM_EX2_EMPLOYEE_H
