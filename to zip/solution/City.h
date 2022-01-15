#ifndef MTM_EX2_CITY_H
#define MTM_EX2_CITY_H

#include "Workplace.h"
#include "Faculty.h"
#include "exceptions.h"

/**
 * City
 *
 * The following functions are available:
 *   City                        - Constructor for city.
 *   ~City                       - Default destructor for city.
 *   City                        - Default Copy Constructor for city.
 *   Operator=                   - Default Assignment Operator for city.
 *   addEmployee                 - Adds an employee to the city.
 *   addManager                  - Adds a manager to the city.
 *   createWorkplace             - Adds a workplace to the city.
 *   addFaculty                  - Adds a faculty to the city.
 *   teachAtFaculty              - Sends employee to learn at a faculty in the city and teaches him faculty's skill.
 *   hireEmployeeAtWorkplace     - Adds an employee to a workplace in the city.
 *   hireManagerAtWorkplace      - Adds a manager to a workplace in the city.
 *   fireEmployeeAtWorkplace     - Removes an employees from a workplace in the city.
 *   fireManagerAtWorkplace      - Removes a manager from a workplace in the city.
 *   getAllAboveSalary           - Prints short details about all the citizens of the city with more salary than given
 *                                 number, and returns how many are they.
 *   isWorkingInTheSameWorkplace - Returns if two employees works in the same workplace.
 *   printAllEmployeesWithSkill  - Prints short details about all the employees which have a certain skill.
 *   exists                      - Generic function to check if a specific variable exists in a set of it's type.
 *   get                         - Generic function to get a specific variable from a set of it's type.
 */

namespace mtm {
    class City {
        string name;
        set<Employee *, cmp_citizens_ptr> employees;
        set<Manager *, cmp_citizens_ptr> managers;
        set<shared_ptr<Citizen>, cmp_citizens_shared_ptr> citizens;
        set<shared_ptr<Workplace>, cmp_workplaces> workplaces;
        set<shared_ptr<Faculty<Condition>>, cmp_faculties> faculties;

    public:

        /*
         * City: Constructor for city.
         *
         * @param new_name - Target name of the city.
         */
        explicit City(string new_name);

        /*
         * ~City: Default destructor for city.
         */
        ~City() = default;

        /*
         * City: Default Copy Constructor for city.
         *
         * @param - the city which is data is requested to be copied
         *
         * @return
         *      A new city with the same details as the city which was sent to the function
         */
        City(const City &) = default;

        /*
         * operator=: Default Assignment Operator for city.
         *
         * @param - the city which is data is requested to be assigned to the new city
         *
         * @return
         *      The same city, but with the same details as the city which was sent to the function
         */
        City &operator=(const City &) = default;

        /*
         * addEmployee: Adds an employee to the city.
         *
         * @param new_id - Target ID of the employee.
         * @param new_first_name - Target first name of the employee.
         * @param new_last_name - Target last name of the employee.
         * @param new_year - Target year of birth of the employee.
         *
         * @exceptions
         *      CitizenAlreadyExists - If a citizen with same ID already exists in the city.
         */
        void addEmployee(int new_id, const string &new_first_name, const string &new_last_name, int new_year);

        /*
         * addManager: Adds a manager to the city.
         *
         * @param new_id - Target ID of the manager.
         * @param new_first_name - Target first name of the manager.
         * @param new_last_name - Target last name of the manager.
         * @param new_year - Target year of birth of the manager.
         *
         * @exceptions
         *      CitizenAlreadyExists - If a citizen with same ID already exists in the city.
         */
        void addManager(int new_id, const string &new_first_name, const string &new_last_name, int new_year);

        /*
         * createWorkplace: Adds a workplace to the city.
         *
         * @param new_id - Target ID of the workplace.
         * @param new_name - Target name of the workplace.
         * @param new_employee_salary - Target salary of an employee in the workplace.
         * @param new_manager_salary - Target salary of a manager in the workplace.
         *
         * @exceptions
         *      WorkplaceAlreadyExists - If a workplace with same ID already exists in the city.
         */
        void createWorkplace(int new_id, const string &new_name, int new_employee_salary, int new_manager_salary);

        /*
         * addFaculty: Adds a faculty to the city.
         *
         * @param new_id - Target ID of the faculty.
         * @param new_name - Target name of the faculty.
         * @param new_points_from_faculty - Target points earned from the faculty.
         * @param new_condition - Target condition to get accepted to faculty.
         *
         * @exceptions
         *      FacultyAlreadyExists - If a faculty with same ID already exists in the city.
         */
        void addFaculty(int new_id, const Skill &new_skill, int new_points_from_faculty, Condition *new_condition);

        /*
         * teachAtFaculty: Sends employee to learn at a faculty in the city and teaches him faculty's skill.
         *
         * @param employee_id - the ID of the employee who is requested to be send to the faculty
         * @param faculty_id - the ID of the faculty
         *
         * @exceptions
         *      EmployeeDoesNotExist - If there is no employee with the given ID in the city
         *      FacultyDoesNotExist - If there is no faculty with the given ID in the city
         *      EmployeeNotAccepted - If the employee not meeting the hiring condition for the workplace
         */
        void teachAtFaculty(int employee_id, int faculty_id) const;

        /*
         * hireEmployeeAtWorkplace: Adds an employee to a workplace in the city.
         *
         * note: this is a generic function.
         *
         * @param hiringCondition - condition to get hired to the workplace
         * @param employee_id - the ID of the employee which is requested to be added to workplace
         * @param manager_id - the ID of the manager that the new employee needs to be subject to.
         * @param workplace_id - the ID of the workplace
         *
         * @exceptions
         *      EmployeeDoesNotExist - If there is no employee with the given ID in the city
         *      ManagerDoesNotExist - If there is no manager with the given ID in the city
         *      WorkplaceDoesNotExist - If there is no workplace with the given ID in the city
         *      EmployeeNotSelected - If the employee not meeting the hiring condition for the workplace
         *      ManagerIsNotHired - If the manager is not hired in the workplace
         *      EmployeeAlreadyHired - If the employee is already hired in the workplace under this specific manager
         */
        template<class Condition>
        void
        hireEmployeeAtWorkplace(Condition hiringCondition, int employee_id, int manager_id, int workplace_id) const {
            if (!exists(employee_id, employees)) {
                throw EmployeeDoesNotExist();
            }
            if (!exists(manager_id, managers)) {
                throw ManagerDoesNotExist();
            }
            if (!exists(workplace_id, workplaces)) {
                throw WorkplaceDoesNotExist();
            }
            Employee *employee = get(employee_id, employees);
            shared_ptr<Workplace> workplace = get(workplace_id, workplaces);
            workplace->hireEmployee(hiringCondition, employee, manager_id);
        }

        /*
         * hireManagerAtWorkplace: Adds an employee to a workplace in the city.
         *
         * @param manager_id - the ID of the manager which is requested to be added to workplace
         * @param workplace_id - the ID of the workplace
         *
         * @exceptions
         *      ManagerDoesNotExist - If there is no manager with the given ID in the city
         *      WorkplaceDoesNotExist - If there is no workplace with the given ID in the city
         *      ManagerAlreadyHired - If the manager already hired in this workplace.
         *      CanNotHireManager - If the manager already hired in other workplace.
         */
        void hireManagerAtWorkplace(int manager_id, int workplace_id) const;

        /*
         * fireEmployeeAtWorkplace: Removes an employee from a workplace in the city.
         *
         * @param employee_id - the ID of the employee which is requested to be removed from the workplace
         * @param manager_id - the ID of the manager that the employee is subject to.
         * @param workplace_id - the ID of the workplace
         *
         * @exceptions
         *      EmployeeDoesNotExist - If there is no employee with the given ID in the city
         *      ManagerDoesNotExist - If there is no manager with the given ID in the city
         *      WorkplaceDoesNotExist - If there is no workplace with the given ID in the city
         *      ManagerIsNotHired - If the manager is not hired in the workplace.
         *      EmployeeIsNotHired - If the employee is not hired under this specific manager in the workplace.
         */
        void fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id) const;

        /*
         * fireManagerAtWorkplace: Removes a manager from a workplace in the city.
         *
         * @param manager_id - the ID of the manager which is requested to be removed from the workplace
         * @param workplace_id - the ID of the workplace
         *
         * @exceptions
         *      ManagerDoesNotExist - If there is no manager with the given ID in the city
         *      WorkplaceDoesNotExist - If there is no workplace with the given ID in the city
         *      ManagerIsNotHired - If the manager is not hired in the workplace.
         */
        void fireManagerAtWorkplace(int manager_id, int workplace_id) const;

        /*
         * getAllAboveSalary: Prints short details about all the citizens of the city with more salary than given
         *                    number, and returns how many are they.
         *
         * @param os- output stream to print in to.
         * @param salary - low verge salary to compare to
         *
         * @return
         *      The number of citizen which earns more than the given salary
         */
        int getAllAboveSalary(ostream &os, int salary) const;

        /*
         * isWorkingInTheSameWorkplace: Returns if two employees works in the same workplace.
         *
         * @param employee_1 - the ID of the first employee to check
         * @param employee_2 - the ID of the second employee to check
         *
         * @return
         *      True - if both the employees work in the same workplace
         *      False - otherwise.
         */
        bool isWorkingInTheSameWorkplace(int employee_1, int employee_2) const;

        /*
         * printAllEmployeesWithSkill: Prints short details about all the employees which have a certain skill.
         *
         * @param os- output stream to print in to.
         * @param skill_id - the ID of the skill to check
         *
         * @return
         *      The output stream
         */
        ostream &printAllEmployeesWithSkill(ostream &os, int skill_id) const;

        /*
         * exists: Generic function to check if a specific variable exists in a set of it's type.
         *
         * @param id - the ID of the variable to check
         * @param set - set of variable's type
         *
         * @return
         *      True - if the variable exists in the set
         *      False - otherwise.
         */
        template<class T, class CMP>
        bool exists(int id, set<T, CMP> set) const {
            for (T n: set) {
                if (n->getId() == id) {
                    return true;
                }
            }
            return false;
        }

        /*
         * get: Generic function to get a specific variable from a set of it's type.
         *
         * @param id - the ID of the variable to check
         * @param set - set of variable's type
         *
         * @return
         *      the variable - if the variable exists in the set
         *      nullptr - otherwise.
         */
        template<class T, class CMP>
        T get(int id, set<T, CMP> set) const {
            for (T n: set) {
                if (n->getId() == id) {
                    return n;
                }
            }
            return nullptr;
        }
    };
}
#endif //MTM_EX2_CITY_H
