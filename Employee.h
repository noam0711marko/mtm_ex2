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

/**
 * Employee
 *
 * note: Employee is a class which is derived from Citizen!
 *
 * The following functions are available:
 *   Employee                   - Constructor for employee.
 *   ~Employee                  - Default destructor for employee which overrides citizen's destructor.
 *   Employee                   - Default Copy Constructor for employee.
 *   Operator=                  - Default Assignment Operator for employee.
 *   getSalary                  - Returns the salary of the employee (overrides citizen's method).
 *   getScore                   - Returns the score of the employee.
 *   learnSkill                 - Adds a skill to employee's "set of skills".
 *   forgetSkill                - Removes a skill from employee's "set of skills".
 *   hasSkill                   - Returns if a certain skill is in employee's "set of skills".
 *   setSalary                  - Adds to employee's salary.
 *   setScore                   - Adds to employee's score.
 *   printShort                 - Prints short details about the employee (overrides citizen's method).
 *   printLong                  - Prints long details about the employee (overrides citizen's method).
 *   printSalaryScore           - Prints employee's salary and score.
 *   printSkills                - Prints employee's skills.
 *   clone                      - creates a (deep) copy of an employee (overrides citizen's method).
 */

namespace mtm {
    class Employee : public Citizen {
        int salary;
        int score;
        set<Skill, cmp_skills> skills;

    public:

        /*
         * Employee: Constructor for employee.
         *
         * @param new_id - Target ID of the employee.
         * @param new_first_name - Target first name of the employee.
         * @param new_last_name - Target last name of the employee.
         * @param new_year - Target year of birth of the employee.
         *
         * note: employee's initial values for salary and score are 0, and his "set of skills" is empty.
         */
        explicit Employee(int new_id, const string &new_first_name, const string &new_last_name, int new_year);

        /*
         * ~Employee: Default destructor for employee which overrides citizen's destructor.
         */
        ~Employee() override = default;

        /*
         * Employee: Default Copy Constructor for employee.
         *
         * @param - the employee which is data is requested to be copied
         *
         * @return
         *      A new employee with the same details as the employee which was sent to the function
         */
        Employee(const Employee &) = default;

        /*
         * operator=: Default Assignment Operator for employee.
         *
         * @param - the employee which is data is requested to be assigned to the new employee
         *
         * @return
         *      The same employee, but with the same details as the employee which was sent to the function
         */
        Employee &operator=(const Employee &) = default;

        /*
         * getSalary: Returns the salary of the employee (overrides citizen's method).
         *
         * @return
         *      The salary of the employee
         */
        int getSalary() const override;

        /*
         * getScore: Returns the score of the employee.
         *
         * @return
         *      The score of the employee
         */
        int getScore() const;

        /*
         * learnSkill: Adds a skill to employee's "set of skills".
         *
         * @param - the skill which is requested to be added to employee's "set of skills"
         *
         * @exceptions
         *      SkillAlreadyLearned - If the skill is already in employee's "set of skills"
         *      CanNotLearnSkill - If the employee score isn't enough for purchasing the skill
         */
        void learnSkill(const Skill &);

        /*
         * forgetSkill: Removes a skill to employee's "set of skills".
         *
         * @param - the skill which is requested to be removed to employee's "set of skills"
         *
         * @exceptions
         *      DidNotLearnSkill - If the skill is not in employee's "set of skills"
         */
        void forgetSkill(const int &id_to_forget);

        /*
         * hasSkill: Returns if a certain skill is in employee's "set of skills".
         *
         * @param skill_id- the ID of the skill
         *
         * @return
         *      True - if the employee has this skill in his "set of skills".
         *      False - otherwise.
         */
        bool hasSkill(int skill_id) const;

        /*
         * setSalary: Adds to employee's salary.
         *
         * @param add_to_salary- the amount to add to employee's salary.
         */
        void setSalary(int add_to_salary);

        /*
         * setScore: Adds to employee's score.
         *
         * @param add_to_score- the amount to add to employee's score.
         */
        void setScore(int add_to_score);

        /*
         * printShort: Prints short details about the employee (overrides citizen's method).
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printShort(ostream &) const override;

        /*
         * printLong: Prints long details about the employee (overrides citizen's method).
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printLong(ostream &) const override;

        /*
         * printSalaryScore: Prints employee's salary and score.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printSalaryScore(ostream &) const;

        /*
         * printSkills: Prints employee's skills.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printSkills(ostream &) const;

        /*
         * clone: creates a (deep) copy of an employee (overrides citizen's method).
         *
         * @return
         *      A new employee which is a copy of the employee sent to the method.
         */
        Employee *clone() const override;
    };
}
#endif //MTM_EX2_EMPLOYEE_H
