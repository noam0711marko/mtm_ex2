#ifndef MTM_EX2_CITY_H
#define MTM_EX2_CITY_H

#include "Workplace.h"
#include "Faculty.h"
#include "Exception.h"


class City {
    string name;
    set<Employee*, cmp_citizens_ptr> employees;
    set<Manager*, cmp_citizens_ptr> managers;
    set<shared_ptr<Citizen>, cmp_citizens_shared_ptr> citizens;
    set<Workplace*, cmp_workplaces> workplaces;
    set<Faculty<Condition>*, cmp_faculties> faculties;

public:
    explicit City(const string& new_name);
    ~City();
    City(const City&);
    City &operator=(const City&);

    void addEmployee(int new_id, const string& new_first_name, const string& new_last_name, int new_year);
    void addManager(int new_id, const string& new_first_name, const string& new_last_name, int new_year);
    void createWorkplace(int new_id, const string& new_name, int new_employee_salary, int new_manager_salary);
    void addFaculty(int new_id, const Skill& new_skill, int new_points_from_faculty, Condition* new_condition);

    void teachAtFaculty(int employee_id, int faculty_id) const;

    template<class Condition>
    void hireEmployeeAtWorkplace(Condition hiringCondition, int employee_id, int manager_id, int workplace_id) const{
        if(!exists(employee_id, employees)){
            throw Exception::EmployeeDoesNotExist();
        }
        if(!exists(manager_id, managers)){
            throw Exception::ManagerDoesNotExist();
        }
        if(!exists(workplace_id, workplaces)){
            throw Exception::WorkplaceDoesNotExist();
        }
        Employee* employee= get(employee_id, employees);
        Workplace* workplace= get(workplace_id, workplaces);
        workplace->template hireEmployee(hiringCondition, employee, manager_id);
    }

    void hireManagerAtWorkplace(int manager_id, int workplace_id) const;

    void fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id) const;

    void fireManagerAtWorkplace(int manager_id, int workplace_id) const;

    ostream &getAllAboveSalary(ostream&, int salary) const;

    bool isWorkingInTheSameWorkplace(int employee_1, int employee_2) const;

    ostream &printAllEmployeesWithSkill(ostream&, int skill_id) const;

    bool employeeExists(int emp_id) const;

    template<class T, class CMP>
    bool exists(int id, set<T, CMP> set ) const {
        for(T n : set){
            if(n->getId() == id){
                return true;
            }
        }
        return false;
    }

    template<class T, class CMP>
    T* get(int id, set<T*, CMP> set ) const {
        for(T* n : set){
            if(n->getId() == id){
                return n;
            }
        }
        return nullptr;
    }
/*
    template<class T, class CMP>
    shared_ptr<Citizen> addCitizen(int new_id, const string &new_first_name, const string &new_last_name, int new_year, set<T*, CMP> set ) const {
        T new_citizen(new_id, new_first_name, new_last_name, new_year);
        shared_ptr<Citizen> sharedPtr(new T(new_citizen));
        T* ptr=new T(new_citizen);
        set.insert(ptr);

        return sharedPtr;
    }
*/
    template<class T, class CMP>
    void copy_set(set<T*, CMP> copy_from, set<T*, CMP> copy_to ) {
        for(T* n : copy_from){
            copy_to.insert(new T(*n));
        }
    }

    template<class T, class CMP>
    void delete_set(set<T*, CMP> delete_set) {
        for(T* m : delete_set){
            delete_set.erase(m);
            delete(m);
        }
    }

    template<class T, class CMP>
    void overwrite_set(set<T*, CMP> overwrite_from, set<T*, CMP> overwrite_to ) {
        delete_set(overwrite_to);
        copy_set(overwrite_from, overwrite_to);
    }

};



#endif //MTM_EX2_CITY_H
