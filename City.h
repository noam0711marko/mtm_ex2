#ifndef MTM_EX2_CITY_H
#define MTM_EX2_CITY_H

#include "Workplace.h"
#include "Faculty.h"

class City {
    string name;
    set<shared_ptr<Employee>, cmp_citizens> employees;
    set<shared_ptr<Manager>, cmp_citizens> managers;
    set<shared_ptr<Workplace>, cmp_workplaces> workplaces;
    //template<class Condition>
    //set<shared_ptr<Faculty<Condition>>, cmp_faculties<Condition>> faculties;

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

    //hireEmployeeAtWorkplace

    void hireManagerAtWorkplace(int manager_id, int workplace_id);

    void fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id);

    void fireManagerAtWorkplace(int manager_id, int workplace_id);

    ostream &getAllAboveSalary(ostream&, int salary) const;

    bool isWorkingInTheSameWorkplace(int employee_1, int employee_2) const;

    ostream &printAllEmployeesWithSkill(ostream&) const;

    bool EmployeeExist(int employee_id) const;
    bool ManagerExist(int manager_id) const;
    bool WorkplaceExist(int workplace_id) const;
    //bool FacultyExist(int faculty_id) const;

    Employee* getEmployee(int employee_id) const;
    Manager* getManager(int manager_id) const;
    Workplace* getWorkplace(int workplace_id) const;
    //Employee* getFaculty(int employee_id) const;

    class EmployeeAlreadyExists : std::exception{};
    class ManagerAlreadyExists : std::exception{};
    class WorkplaceAlreadyExists : std::exception{};
    class FacultyAlreadyExists : std::exception{};
    class EmployeeDoesNotExist : std::exception{};
    class ManagerDoesNotExist : std::exception{};
    class WorkplaceDoesNotExist : std::exception{};
    class FacultyDoesNotExist : std::exception{};

};


#endif //MTM_EX2_CITY_H
