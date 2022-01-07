#ifndef MTM_EX2_FACULTY_H
#define MTM_EX2_FACULTY_H

#include "Skill.h"
#include "Employee.h"
#include "exceptions.h"

namespace mtm {
    class Condition {
    public:
        virtual bool operator()(Employee *employee) = 0;
    };

    template<class Condition>
    class Faculty {
        int id;
        Skill skill;
        int points_from_faculty;
        Condition *condition;

    public:
        Faculty(int new_id, const Skill &new_skill, int new_points_from_faculty, Condition *new_condition);

        ~Faculty() = default;

        Faculty(const Faculty &) = default;

        Faculty &operator=(const Faculty &) = default;

        int getId() const;

        Skill getSkill() const;

        int getAddedPoints() const;

        template<class C>
        friend bool operator<(const Faculty<C> &, const Faculty<C> &);

        void teach(Employee *employee);

    };

    template<class Condition>
    Faculty<Condition>::Faculty(int new_id, const Skill &new_skill, int new_points_from_faculty,
                                Condition *new_condition) :
            id(new_id), skill(new_skill), points_from_faculty(new_points_from_faculty), condition(new_condition) {}


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
    void Faculty<Condition>::teach(Employee *employee) {

        if (!(*condition)(employee)) {
            throw exceptions::EmployeeNotAccepted();
        }
        employee->learnSkill(skill);
        employee->setScore(points_from_faculty);
    }


    template<class C>
    bool operator<(const Faculty<C> &faculty_1, const Faculty<C> &faculty_2) {
        if (faculty_1.id < faculty_2.id) {
            return true;
        }
        return false;
    }

    struct cmp_faculties {
        bool operator()(Faculty<Condition> *a, Faculty<Condition> *b) const { return (*a) < (*b); }
    };
}
#endif //MTM_EX2_FACULTY_H
