#ifndef MTM_EX2_MANAGER_H
#define MTM_EX2_MANAGER_H

#include "Employee.h"
#include "Citizen.h"
#include "Exception.h"

namespace mtm {
    class Manager : public Citizen {
        int salary;
        set<Employee *, cmp_citizens_ptr> employees;
        int workplace_id;
        set<int> employees_ids;

        static const int NOT_HIRED = -1;
    public:
        Manager(int new_id, const string &new_first_name, const string &new_last_name, int new_birth_year);

        ~Manager() override = default;

        Manager(const Manager &) = default;

        //Manager(const Manager &m);

        Manager &operator=(const Manager &) = default;

        int getSalary() const override;

        void addEmployee(Employee *employee);

        void removeEmployee(int id_to_remove);


        void setSalary(int to_add);

        ostream &printShort(ostream &) const override;

        ostream &printLong(ostream &) const override;

        ostream &printSalary(ostream &) const;

        ostream &printEmployees(ostream &) const;

        Manager *clone() const override;

        bool hasEmployee(int employee_id);

        bool isManagerHired() const;

        void setManagerWorkplace(int new_workplace_id);

        set<int> getEmployeesIdsSet();

        void setManagerNotHired();

        Employee *getEmployee(int employee_id);

    };


}
#endif //MTM_EX2_MANAGER_H
