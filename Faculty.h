#ifndef MTM_EX2_FACULTY_H
#define MTM_EX2_FACULTY_H

#include "Skill.h"
#include "Employee.h"


template<class Condition>
class Faculty {
    int id;
    Condition condition;
    Skill skill;
    int points_from_faculty;

public:
    Faculty(int new_id, Condition* new_condition, const Skill& new_skill, int new_points_from_faculty);
    ~Faculty() = default;
    Faculty(const Faculty&) = default;
    Faculty &operator=(const Faculty&) = default;

    int getId() const;
    Skill getSkill() const;
    int getAddedPoints() const;

    void teach(Employee* employee);

    class EmployeeNotAccepted : std::exception{};
};

template<class Condition>
Faculty<Condition>::Faculty(int new_id, Condition* new_condition, const Skill& new_skill, int new_points_from_faculty) :
    id(new_id), condition(*new_condition), skill(new_skill), points_from_faculty(new_points_from_faculty){}

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

template<class Condition>
struct cmp_faculties{
    bool operator() (const Faculty<Condition>& a, const Faculty<Condition>& b) const {
        return a.getId()<b.getId();
    }
};


#endif //MTM_EX2_FACULTY_H
