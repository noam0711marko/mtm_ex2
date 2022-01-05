#ifndef MTM_EX2_WORKPLACE_H
#define MTM_EX2_WORKPLACE_H

#include "Manager.h"
#include "Exception.h"


class Workplace {
    int id;
    string name;
    int employee_salary;
    int manager_salary;
    set<Manager*, cmp_citizens_ptr> managers;

public:
    Workplace(int new_id, const string& new_name, int new_employee_salary, int new_manager_salary);
    ~Workplace() = default;
    Workplace(const Workplace&) = default;
    Workplace &operator=(const Workplace&) = default;

    int getId() const;
    string getName() const;
    int getWorkersSalary() const;
    int getManagersSalary() const;

    void hireEmployeeAction(Employee *employee, int manager_id);

    template<class Condition>
    void hireEmployee(Condition hiringCondition, Employee *employee, int manager_id) {
        if(!hiringCondition(employee)){
            throw Exception::EmployeeNotSelected();
        }
        hireEmployeeAction(employee, manager_id);
    }

    void hireManager(Manager* manager_to_hire);

    void fireEmployee(int employee_id, int manager_id) const;

    void fireManager(int manager_id);

    friend ostream& operator<<(ostream&, const Workplace&);

    bool hasManager(int manager_id) const;
    bool hasEmployeeInManager(int employee_id, int manager_id) const;
    bool hasEmployeeInWorkplace(int employee_id) const;

    ostream &printGroups(ostream&) const;

    int getNumOfManagers() const;


    Manager* getManager(int manager_id) const;
    Employee* getEmployeeFromManager(int employee_id, int manager_id) const;
};

struct cmp_workplaces{
    bool operator() (Workplace* a, Workplace* b) const {
        return (a->getId() < b->getId());
    }
};

#endif //MTM_EX2_WORKPLACE_H
