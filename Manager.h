#ifndef MTM_EX2_MANAGER_H
#define MTM_EX2_MANAGER_H

#include "Employee.h"
#include "Citizen.h"


struct cmp_employees{
    bool operator() (const shared_ptr<Employee>& a, const shared_ptr<Employee>& b) const {return (*a)<(*b); }
};

class Manager: public Citizen{
    int salary;
    set<shared_ptr<Employee>, cmp_employees> employees;
public:
    Manager(int newId1, const string &newFirstName1, const string &newLastName1, int newYear1);

    int getSalary();

    void addEmployee(Employee* employee);
    void removeEmployee(int id_to_remove);


    void setSalary(int to_add);

    ostream &printShort(ostream&) const override;
    ostream &printLong(ostream&) const override;

    ostream &printSalary(ostream&) const;
    ostream &printEmployees(ostream&) const;

    Citizen* clone() const override;

    class EmployeeIsNotHired : std::exception{};
};



#endif //MTM_EX2_MANAGER_H
