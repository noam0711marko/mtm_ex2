#ifndef MTM_EX2_CITY_H
#define MTM_EX2_CITY_H

#include "Workplace.h"
#include "Faculty.h"

class City {
    string name;
    set<Employee, cmp_citizens> employees;
    set<Manager, cmp_citizens> managers;
    set<shared_ptr<Citizen>, cmp_citizens_ptr> citizens;
    set<Workplace, cmp_workplaces> workplaces;
    //template<class Condition>
    //set<Faculty<Condition>, cmp_faculties<Condition>> faculties;

public:
    City(string new_name);
    ~City() = default;
    City(const City&) = default;
    City &operator=(const City&) = default;

    void addEmployee(int new_id, const string& new_first_name, const string& new_last_name, int new_year);
    void addManager(int new_id, const string& new_first_name, const string& new_last_name, int new_year);
    void createWorkplace(int new_id, const string& new_name, int new_employee_salary, int new_manager_salary);
    //addFaculty

    //teachAtFaculty

    template<class Condition>
    void hireEmployeeAtWorkplace(Condition hiringCondition, int employee_id, int manager_id, int workplace_id) const{
        if(!EmployeeExist(employee_id)){
            throw EmployeeDoesNotExist();
        }
        if(!ManagerExist(manager_id)){
            throw ManagerDoesNotExist();
        }
        if(!WorkplaceExist(workplace_id)){
            throw WorkplaceDoesNotExist();
        }
        Employee* employee= getEmployee(employee_id);
        Workplace* workplace= getWorkplace(workplace_id);
        workplace->template hireEmployee(hiringCondition, employee, manager_id);
    }

    void hireManagerAtWorkplace(int manager_id, int workplace_id) const;

    void fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id) const;

    void fireManagerAtWorkplace(int manager_id, int workplace_id) const;

    ostream &getAllAboveSalary(ostream&, int salary) const;

    bool isWorkingInTheSameWorkplace(int employee_1, int employee_2) const;

    ostream &printAllEmployeesWithSkill(ostream&) const;

    bool EmployeeExist(int employee_id) const;
    bool ManagerExist(int manager_id) const;
    bool CitizenExist(int citizen_id) const;
    bool WorkplaceExist(int workplace_id) const;
    //bool FacultyExist(int faculty_id) const;

    Employee* getEmployee(int employee_id) const;
    Manager* getManager(int manager_id) const;
    Workplace* getWorkplace(int workplace_id) const;
    //Employee* getFaculty(int employee_id) const;

    class CitizenAlreadyExists : std::exception{};
    class WorkplaceAlreadyExists : std::exception{};
    class FacultyAlreadyExists : std::exception{};
    class EmployeeDoesNotExist : std::exception{};
    class ManagerDoesNotExist : std::exception{};
    class WorkplaceDoesNotExist : std::exception{};
    class FacultyDoesNotExist : std::exception{};

};


#endif //MTM_EX2_CITY_H
