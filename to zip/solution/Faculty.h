#ifndef MTM_EX2_FACULTY_H
#define MTM_EX2_FACULTY_H

#include "Skill.h"
#include "Employee.h"
#include "exceptions.h"

/**
 * Faculty
 *
 * note: Faculty is a generic class!
 *
 * The following functions are available:
 *   Faculty                    - Constructor for faculty.
 *   ~Faculty                   - Default destructor for faculty.
 *   Faculty                    - Default Copy Constructor for faculty.
 *   Operator=                  - Default Assignment Operator for faculty.
 *   getId                      - Returns the ID of the faculty.
 *   getSkill                   - Returns the skill which is learned in the faculty.
 *   getAddedPoints             - Returns the points earned from learning in the faculty.
 *   operator<                  - Overloads the operator '<' for faculty (compare by ID).
 *   teach                      - Teach an employee the skill of the faculty and give him points for graduate.
 */

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

        /*
         * Faculty: Constructor for faculty.
         *
         * @param new_id - Target ID of the faculty.
         * @param new_name - Target name of the faculty.
         * @param new_points_from_faculty - Target points earned from the faculty.
         * @param new_condition - Target condition to get accepted to faculty.
         */
        explicit Faculty(int new_id, const Skill &new_skill, int new_points_from_faculty, Condition *new_condition);

        /*
         * ~Faculty: Default destructor for faculty.
         */
        ~Faculty() = default;

        /*
         * Faculty: Default Copy Constructor for faculty.
         *
         * @param - the faculty which is data is requested to be copied
         *
         * @return
         *      A new faculty with the same details as the faculty which was sent to the function
         */
        Faculty(const Faculty &) = default;

        /*
         * operator=: Default Assignment Operator for faculty.
         *
         * @param - the faculty which is data is requested to be assigned to the new faculty
         *
         * @return
         *      The same faculty, but with the same details as the faculty which was sent to the function
         */
        Faculty &operator=(const Faculty &) = default;

        /*
         * getId: Returns the id of a faculty.
         *
         * @return
         *      The ID of the workplace
         */
        int getId() const;

        /*
         * getSkill: Returns the skill which is learned in the faculty.
         *
         * @return
         *      The skill which is learned in the faculty.
         */
        Skill getSkill() const;

        /*
         * getAddedPoints: Returns the points earned from learning in the faculty.
         *
         * @return
         *      The points earned from learning in the faculty.
         */
        int getAddedPoints() const;

        /*
         * operator<: Overloads the operator '<' for faculty (compare by ID).
         *
         * @param faculty_1- the first faculty to compare.
         * @param faculty_2- the second faculty to compare.
         *
         * @return
         *      True - if first faculty's ID is smaller than second faculty's ID.
         *      False - otherwise.
         */
        template<class C>
        friend bool operator<(const Faculty<C> &faculty_1, const Faculty<C> &faculty_2);

        /*
         * teach: Teach an employee the skill of the faculty and give him points for graduate.
         *
         * @param employee - a pointer to the employee which is requested to be added to workplace
         *
         * @exceptions
         *      EmployeeNotAccepted - If the employee not meeting the hiring condition for the workplace
         */
        void teach(Employee *employee);

    };


//================================================= Implementations: =================================================//

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
            throw EmployeeNotAccepted();
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

    /*
     * cmp_faculties:
     * struct which contains only the operator() which compare between shared pointers to faculties by faculty's
     * operator '<'.
     * this struct is sent to the set which contains shared pointers to faculties, and it's necessary for it's sorting.
     */
    struct cmp_faculties {
        bool operator()(const shared_ptr<Faculty<Condition>> &a, const shared_ptr<Faculty<Condition>> &b) const {
            return (*a) < (*b);
        }
    };
}
#endif //MTM_EX2_FACULTY_H
