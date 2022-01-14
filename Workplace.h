#ifndef MTM_EX2_WORKPLACE_H
#define MTM_EX2_WORKPLACE_H

#include "Manager.h"
#include "exceptions.h"

/**
 * Workplace
 *
 * The following functions are available:
 *   Workplace                  - Constructor for workplace.
 *   ~Workplace                 - Default destructor for workplace.
 *   Workplace                  - Default Copy Constructor for workplace.
 *   Operator=                  - Default Assignment Operator for workplace.
 *   getId                      - Returns the ID of the workplace.
 *   getName                    - Returns the name of the workplace.
 *   getWorkersSalary           - Returns the salary of an employee in the workplace.
 *   getManagersSalary          - Returns the salary of a manager in the workplace.
 *   hireEmployee               - Adds an employee to the workplace.
 *   hireEmployeeAction         - Does the actions behind hireEmployee method.
 *   hireManager                - Adds a manager to the workplace.
 *   fireEmployee               - Removes an employee to the workplace.
 *   fireManager                - Removes a manager to the workplace.
 *   operator<<                 - Overloads the operator '<<' for workplace.
 *   hasManager                 - Returns if a certain manager is hired in this workplace.
 *   hasEmployeeInManager       - Returns if a certain employee is hired under specific manager in this workplace.
 *   hasEmployeeInWorkplace     - Returns if a certain employee is hired in this workplace.
 *   printGroups                - Prints all workplace's groups (each manager and his subjects).
 *   getNumOfManagers           - Returns the number of managers hired in the workplace.
 *   getManager                 - Returns a pointer to a manager from the workplace.
 *   getEmployeeFromManager     - Returns a pointer to an employee under specific manager from the workplace.
 *   hiredForAnotherManager     - Returns if a certain employee is hired under other than specific manager in workplace.
 */

namespace mtm {
    class Workplace {
        int id;
        string name;
        int employee_salary;
        int manager_salary;
        set<Manager *, cmp_citizens_ptr> managers;

    public:

        /*
         * Workplace: Constructor for workplace.
         *
         * @param new_id - Target ID of the workplace.
         * @param new_name - Target name of the workplace.
         * @param new_employee_salary - Target salary of an employee in the workplace.
         * @param new_manager_salary - Target salary of a manager in the workplace.
         */
        explicit Workplace(int new_id, string new_name, int new_employee_salary, int new_manager_salary);

        /*
         * ~Workplace: Default destructor for workplace.
         */
        ~Workplace() = default;

        /*
         * Workplace: Default Copy Constructor for workplace.
         *
         * @param - the workplace which is data is requested to be copied
         *
         * @return
         *      A new workplace with the same details as the workplace which was sent to the function
         */
        Workplace(const Workplace &) = default;

        /*
         * operator=: Default Assignment Operator for workplace.
         *
         * @param - the workplace which is data is requested to be assigned to the new workplace
         *
         * @return
         *      The same workplace, but with the same details as the workplace which was sent to the function
         */
        Workplace &operator=(const Workplace &) = default;

        /*
         * getId: Returns the id of a workplace.
         *
         * @return
         *      The ID of the workplace
         */
        int getId() const;

        /*
         * getName: Returns the name of a workplace.
         *
         * @return
         *      The name of the workplace
         */
        string getName() const;

        /*
         * getWorkersSalary: Returns the salary of an employee in the workplace.
         *
         * @return
         *      The salary of an employee in the workplace.
         */
        int getWorkersSalary() const;

        /*
         * getManagersSalary: Returns the salary of a manager in the workplace.
         *
         * @return
         *      The salary of a manager in the workplace.
         */
        int getManagersSalary() const;

        /*
         * hireEmployeeAction: Does the actions behind hireEmployee method.
         *
         * @param employee - a pointer to the employee which is requested to be added to workplace
         * @param manager_id - the ID of the manager that the new employee needs to be subject to.
         *
         * @exceptions
         *      ManagerIsNotHired - If the manager is not hired in the workplace.
         *      EmployeeAlreadyHired - If the employee is already hired in the workplace under this specific manager.
         */
        void hireEmployeeAction(Employee *employee, int manager_id);

        /*
         * hireEmployee: Adds an employee to the workplace.
         *
         * note: this is a generic function.
         *
         * @param hiringCondition - condition to get hired to the workplace
         * @param employee - a pointer to the employee which is requested to be added to workplace
         * @param manager_id - the ID of the manager that the new employee needs to be subject to.
         *
         * @exceptions
         *      EmployeeNotSelected - If the employee not meeting the hiring condition for the workplace
         */
        template<class Condition>
        void hireEmployee(Condition hiringCondition, Employee *employee, int manager_id) {
            if (!hiringCondition(employee)) {
                throw EmployeeNotSelected();
            }
            hireEmployeeAction(employee, manager_id);
        }

        /*
         * hireManager: Adds a manager to the workplace.
         *
         * @param manager - a pointer to the manager which is requested to be added to workplace
         *
         * @exceptions
         *      ManagerAlreadyHired - If the manager already hired in this workplace.
         *      CanNotHireManager - If the manager already hired in other workplace.
         */
        void hireManager(Manager *manager_to_hire);

        /*
         * fireEmployee: Removes an employee to the workplace.
         *
         * @param employee_id - the id of the employee which is requested to be removed
         * @param manager_id - the id of the manager which the employee is subject to
         *
         * @exceptions
         *      ManagerIsNotHired - If the manager is not hired in the workplace.
         *      EmployeeIsNotHired - If the employee is not hired under this specific manager in the workplace.
         */
        void fireEmployee(int employee_id, int manager_id) const;

        /*
         * fireManager: Removes a manager to the workplace.
         *
         * @param manager_id - the id of the manager which is requested to be removed
         *
         * @exceptions
         *      ManagerIsNotHired - If the manager is not hired in the workplace.
         */
        void fireManager(int manager_id);

        /*
         * operator<<: Overloads the operator '<<' for workplace.
         *
         * @param os- output stream to print in to.
         * @param workplace- the workplace to print
         *
         * @return
         *      The output stream
         */
        friend ostream &operator<<(ostream &os, const Workplace &workplace);

        /*
         * hasManager: Returns if a certain manager is hired in this workplace.
         *
         * @param manager_id- the ID of the manager
         *
         * @return
         *      True - if the manager is hired in the workplace
         *      False - otherwise.
         */
        bool hasManager(int manager_id) const;

        /*
         * hasEmployeeInManager: Returns if a certain employee is hired under specific manager in this workplace.
         *
         * @param employee_id - the ID of the employee
         * @param manager_id- the ID of the manager of the employee
         *
         * @return
         *      True - if the employee is hired in the workplace under this specific manager
         *      False - otherwise.
         */
        bool hasEmployeeInManager(int employee_id, int manager_id) const;

        /*
         * hasManager: Returns if a certain employee is hired in this workplace.
         *
         * @param employee_id- the ID of the employee
         *
         * @return
         *      True - if the employee is hired in the workplace
         *      False - otherwise.
         */
        bool hasEmployeeInWorkplace(int employee_id) const;

        /*
         * printGroups: Prints all workplace's groups (each manager and his subjects).
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printGroups(ostream &) const;

        /*
         * getNumOfManagers: Returns the number of managers hired in the workplace.
         *
         * @return
         *      The number of managers hired in the workplace.
         */
        int getNumOfManagers() const;

        /*
         * getManager: Returns a pointer to a manager from the workplace.
         *
         * @param manager_id- the ID of the manager
         *
         * @return
         *      A pointer to the requested manager
         */
        Manager *getManager(int manager_id) const;

        /*
         * getEmployeeFromManager: Returns a pointer to an employee under specific manager from the workplace.
         *
         * @param employee_id - the id of the employee which is requested to be removed
         * @param manager_id - the id of the manager which the employee is subject to
         *
         * @return
         *      A pointer to the requested employee
         */
        Employee *getEmployeeFromManager(int employee_id, int manager_id) const;

        /*
         * hiredForAnotherManager: Returns if a certain employee is hired under other than specific manager in workplace
         *
         * @param employee - a pointer to the employee which is requested to be removed
         * @param manager_id - the id of the manager which the employee is need to be subject to
         *
         * @return
         *      True - if the employee is hired in the workplace under other manager
         *      False - otherwise.
         */
        bool hiredForAnotherManager(Employee* employee, int manager_id) const;
    };

    /*
     * cmp_workplaces:
     * struct which contains only the operator() which compare between shared pointers to workplaces by workplace's IDs.
     * this struct is sent to the set which contains shared pointers to workplaces, and it's necessary for it's sorting.
     */
    struct cmp_workplaces {
        bool operator()(const shared_ptr<Workplace> &a, const shared_ptr<Workplace> &b) const {
            return (a->getId() < b->getId());
        }
    };
}
#endif //MTM_EX2_WORKPLACE_H
