#ifndef MTM_EX2_WORKPLACE_H
#define MTM_EX2_WORKPLACE_H

#include "Manager.h"


class Workplace {
    int id;
    string name;
    int employee_salary;
    int manager_salary;
    set<shared_ptr<Manager>, cmp_citizens> managers;

public:
    Workplace(int new_id, const string& new_name, int new_employee_salary, int new_manager_salary);
    ~Workplace() = default;
    Workplace(const Workplace&) = default;
    Workplace &operator=(const Workplace&) = default;

    int getID() const;
    string getName() const;
    int getWorkersSalary() const;
    int getManagersSalary() const;

    void hireEmployeeAction(Employee *employee, int manager_id);

    template<class Condition>
    void hireEmployee(Condition hiringCondition, Employee *employee, int manager_id) {
        if(!hiringCondition(employee)){
            throw EmployeeNotSelected();
        }
        hireEmployeeAction(employee, manager_id);
    }

    void hireManager(Manager* manager_to_hire);

    void fireEmployee(int employee_id, int manager_id);

    void fireManager(int manager_id);

    friend ostream& operator<<(ostream&, const Workplace&);

    bool hasManager(int manager_id);
    bool hasEmployeeInManager(int employee_id, int manager_id);
    bool hasEmployeeInWorkplace(int employee_id);

    ostream &printGroups(ostream&) const;

    int getNumOfManagers() const;

    class ManagerAlreadyHired : std::exception{};
    class CanNotHireManager : std::exception{};
    class ManagerIsNotHired : std::exception{};
    class EmployeeIsNotHired : std::exception{};
    class EmployeeNotSelected : std::exception{};
    class EmployeeAlreadyHired : std::exception{};

    shared_ptr<Manager> getManager(int manager_id);
    shared_ptr<Employee> getEmployeeFromManager(int employee_id, int manager_id);
};

struct cmp_workplaces{
    bool operator() (const shared_ptr<Workplace>& a, const shared_ptr<Workplace>& b) const {
        return (a->getID()<b->getID());
    }
};

#endif //MTM_EX2_WORKPLACE_H
