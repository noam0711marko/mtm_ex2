#ifndef MTM_EX2_MANAGER_H
#define MTM_EX2_MANAGER_H

#include "Employee.h"
#include "Citizen.h"
#include "exceptions.h"

/**
 * Manager
 *
 * note: Manager is a class which is derived from Citizen!
 *
 * The following functions are available:
 *   Employee                   - Constructor for manager.
 *   ~Employee                  - Default destructor for manager which overrides citizen's destructor.
 *   Employee                   - Default Copy Constructor for manager.
 *   Operator=                  - Default Assignment Operator for manager.
 *   getSalary                  - Returns the salary of the manager (overrides citizen's method).
 *   addEmployee                - Adds an employee to manager's subjects.
 *   removeEmployee             - Removes an employee from manager's subjects.
 *   setSalary                  - Adds to manager's salary.
 *   printShort                 - Prints short details about the manager (overrides citizen's method).
 *   printLong                  - Prints long details about the manager (overrides citizen's method).
 *   printSalary                - Prints manager's salary.
 *   printEmployees             - Prints manager's subjects.
 *   clone                      - creates a (deep) copy of a manager (overrides citizen's method).
 *   hasEmployee                - Returns if a certain employee is subject to the manager.
 *   isManagerHired             - Returns if a manager is hired in a workplace.
 *   setManagerWorkplace        - Changes manager's workplace ID.
 *   getEmployeesIdsSet         - Returns the set of manager's subject's IDs.
 *   setManagerNotHired         - Changes manager's workplace ID to 'not hired'.
 *   getEmployee                - Returns a pointer to one of manager's subjects.
 */

namespace mtm {
    class Manager : public Citizen {
        int salary;
        set<Employee *, cmp_citizens_ptr> employees;
        int workplace_id;
        set<int> employees_ids;

        static const int NOT_HIRED = -1;
    public:

        /*
         * Manager: Constructor for manager.
         *
         * @param new_id - Target ID of the manager.
         * @param new_first_name - Target first name of the manager.
         * @param new_last_name - Target last name of the manager.
         * @param new_year - Target year of birth of the manager.
         *
         * note: manager's initial value for salary is 0, and he has no subjects.
         */
        explicit Manager(int new_id, const string &new_first_name, const string &new_last_name, int new_birth_year);

        /*
         * ~Manager: Default destructor for manager which overrides citizen's destructor.
         */
        ~Manager() override = default;

        /*
         * Manager: Default Copy Constructor for manager.
         *
         * @param - the manager which is data is requested to be copied
         *
         * @return
         *      A new manager with the same details as the manager which was sent to the function
         */
        Manager(const Manager &) = default;

        /*
         * operator=: Default Assignment Operator for manager.
         *
         * @param - the manager which is data is requested to be assigned to the new manager
         *
         * @return
         *      The same manager, but with the same details as the manager which was sent to the function
         */
        Manager &operator=(const Manager &) = default;

        /*
         * getSalary: Returns the salary of the manager (overrides citizen's method).
         *
         * @return
         *      The salary of the manager
         */
        int getSalary() const override;

        /*
         * addEmployee: Adds an employee to manager's subjects.
         *
         * @param - the employee which is requested to be added to manager's subjects
         *
         * @exceptions
         *      EmployeeAlreadyHired - If the employee is already a subject of this manager
         */
        void addEmployee(Employee *employee);

        /*
         * removeEmployee: Removes an employee from manager's subjects.
         *
         * @param - the employee which is requested to be removed from manager's subjects
         *
         * @exceptions
         *      EmployeeIsNotHired - If the employee is not a subject of this manager
         */
        void removeEmployee(int id_to_remove);

        /*
         * setSalary: Adds to manager's salary.
         *
         * @param add_to_salary- the amount to add to manager's salary.
         */
        void setSalary(int to_add);

        /*
         * printShort: Prints short details about the manager (overrides citizen's method).
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printShort(ostream &) const override;

        /*
         * printLong: Prints long details about the manager (overrides citizen's method).
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printLong(ostream &) const override;

        /*
         * printSalaryScore: Prints manager's salary.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printSalary(ostream &) const;

        /*
         * printEmployees: Prints manager's subjects.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printEmployees(ostream &) const;

        /*
         * clone: creates a (deep) copy of a manager (overrides citizen's method).
         *
         * @return
         *      A new manager which is a copy of the manager sent to the method.
         */
        Manager *clone() const override;

        /*
         * hasEmployee: Returns if a certain employee is subject to the manager.
         *
         * @param employee_id- the ID of the employee
         *
         * @return
         *      True - if the employee is subject to the manager.
         *      False - otherwise.
         */
        bool hasEmployee(int employee_id);

        /*
         * isManagerHired: Returns if a manager is hired in a workplace.
         *
         * @return
         *      True - if the manager is hired in a workplace.
         *      False - otherwise.
         */
        bool isManagerHired() const;

        /*
         * setManagerWorkplace: Changes manager's workplace ID.
         *
         * @param new_workplace_id- the id of manager's new workplace
         */
        void setManagerWorkplace(int new_workplace_id);

        /*
         * getEmployeesIdsSet: Returns the set of manager's subject's IDs.
         *
         * @return
         *      The set of manager's subject's IDs.
         */
        set<int> getEmployeesIdsSet();

        /*
         * setManagerWorkplace: Changes manager's workplace ID to 'not hired'
         */
        void setManagerNotHired();

        /*
         * getEmployee: Returns a pointer to one of manager's subjects.
         *
         * @param employee_id- the ID of the employee
         *
         * @return
         *      A pointer to the requested employee
         */
        Employee *getEmployee(int employee_id);
    };
}
#endif //MTM_EX2_MANAGER_H
