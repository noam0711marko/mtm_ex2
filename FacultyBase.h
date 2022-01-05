#ifndef MTM_EX2_FACULTYBASE_H
#define MTM_EX2_FACULTYBASE_H

#include "Skill.h"
#include "Employee.h"

class FacultyBase {
protected:
    int id;
    Skill skill;
    int points_from_faculty;

public:
    FacultyBase(int new_id, const Skill& new_skill, int new_points_from_faculty);
    ~FacultyBase() = default;
    FacultyBase(const FacultyBase&) = default;
    FacultyBase &operator=(const FacultyBase&) = default;

    virtual int getId() const=0;
    virtual Skill getSkill() const=0;
    virtual int getAddedPoints() const=0;

    virtual void teach(Employee* employee)=0;

    friend bool operator<(const FacultyBase&, const FacultyBase&);
};


#endif //MTM_EX2_FACULTYBASE_H
