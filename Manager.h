//
// Created by dolle on 03/01/2022.
//

#ifndef MTM_EX2_MANAGER_H
#define MTM_EX2_MANAGER_H
#include "Employee.h"
#include "Citizen.h"

class Manager: public Citizen{
    int salary;
    std::set<Employee*> employees;
public:
    Manager(int newId1, const string &newFirstName1, const string &newLastName1, int newYear1, int newId);
    int getSalary();
    void addEmployee(Employee* employee);
    void removeEmployee(int id_to_remove);
    class EmployeeIsNotHired{};
    void setSalary(int to_add);
    ostream &printShort(ostream&) const;
    ostream &printLong(ostream&) const;
    virtual Manager* clone() const override;

};


#endif //MTM_EX2_MANAGER_H
