#ifndef MTM_EX2_MANAGER_H
#define MTM_EX2_MANAGER_H

#include "Employee.h"
#include "Citizen.h"

class Manager: public Citizen{
    int salary;
    set<shared_ptr<Employee>, cmp_citizens_shared_ptr> employees;
    int workplace_id;
    set<int> employees_ids;

    static const int NOT_HIRED=-1;
public:
    Manager(int new_id, const string &new_first_name, const string &new_last_name, int new_birth_year);
    ~Manager() = default;
    Manager(const Manager&) = default;
    Manager &operator=(const Manager&) = default;

    int getSalary() const override;

    void addEmployee(Employee* employee);
    void removeEmployee(int id_to_remove);


    void setSalary(int to_add);

    ostream &printShort(ostream&) const override;
    ostream &printLong(ostream&) const override;

    ostream &printSalary(ostream&) const;
    ostream &printEmployees(ostream&) const;

    Citizen* clone() const override;

    bool hasEmployee(int employee_id);

    bool isManagerHired() const;
    void setManagerWorkplace (int new_workplace_id);

    set<int> getEmployeesIdsSet();

    void setManagerNotHired();

    shared_ptr<Employee> getEmployee(int employee_id);

};



#endif //MTM_EX2_MANAGER_H
