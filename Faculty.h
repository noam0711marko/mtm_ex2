#ifndef MTM_EX2_FACULTY_H
#define MTM_EX2_FACULTY_H

#include "Skill.h"
#include "Employee.h"
#include "FacultyBase.h"

class Condition{
public:
    virtual bool operator()(Employee* employee){
        return employee->getId()>0;
    }
};

template<class Condition>
class Faculty : public FacultyBase {
    Condition condition;

public:
    Faculty(int new_id, const Skill& new_skill, int new_points_from_faculty, Condition* new_condition);
    ~Faculty() = default;
    Faculty(const Faculty&) = default;
    Faculty &operator=(const Faculty&) = default;

    int getId() const override;
    Skill getSkill() const override;
    int getAddedPoints() const override;

    void teach(Employee* employee) override;

    class EmployeeNotAccepted : std::exception{};
};

template<class Condition>
Faculty<Condition>::Faculty(int new_id, const Skill& new_skill, int new_points_from_faculty, Condition* new_condition) :
    FacultyBase(new_id, new_skill, new_points_from_faculty), condition(*new_condition){}

template<class Condition>
int Faculty<Condition>::getId() const {
    return id;
}

template<class Condition>
Skill Faculty<Condition>::getSkill() const {
    return skill;
}

template<class Condition>
int Faculty<Condition>::getAddedPoints() const {
    return points_from_faculty;
}

template<class Condition>
void Faculty<Condition>::teach(Employee* employee) {
    if(!condition(employee)){
        throw EmployeeNotAccepted();
    }
    employee->learnSkill(skill);
    employee->setScore(points_from_faculty);
}



#endif //MTM_EX2_FACULTY_H
