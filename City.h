#ifndef MTM_EX2_CITY_H
#define MTM_EX2_CITY_H

#include "Workplace.h"
#include "Faculty.h"
#include "Exception.h"

namespace mtm {
    class City {
        string name;
        set<Employee *, cmp_citizens_ptr> employees;
        set<Manager *, cmp_citizens_ptr> managers;
        set<shared_ptr<Citizen>, cmp_citizens_shared_ptr> citizens;
        //set<Workplace*, cmp_workplaces> workplaces;
        //set<Faculty<Condition>*, cmp_faculties> faculties;
        set<shared_ptr<Workplace>, cmp_workplaces> workplaces;
        set<shared_ptr<Faculty<Condition>>, cmp_faculties> faculties;

    public:
        explicit City(string new_name);

        ~City() = default;

        City(const City &) = default;
        //City(const City &);

        City &operator=(const City &) = default;

        void addEmployee(int new_id, const string &new_first_name, const string &new_last_name, int new_year);

        void addManager(int new_id, const string &new_first_name, const string &new_last_name, int new_year);

        void createWorkplace(int new_id, const string &new_name, int new_employee_salary, int new_manager_salary);

        void addFaculty(int new_id, const Skill &new_skill, int new_points_from_faculty, Condition *new_condition);

        void teachAtFaculty(int employee_id, int faculty_id) const;

        template<class Condition>
        void
        hireEmployeeAtWorkplace(Condition hiringCondition, int employee_id, int manager_id, int workplace_id) const {
            if (!exists(employee_id, employees)) {
                throw EmployeeDoesNotExist();
            }
            if (!exists(manager_id, managers)) {
                throw ManagerDoesNotExist();
            }
            if (!exists(workplace_id, workplaces)) {
                throw WorkplaceDoesNotExist();
            }
            Employee *employee = get(employee_id, employees);
            //Workplace* workplace= get(workplace_id, workplaces);
            shared_ptr<Workplace> workplace = get(workplace_id, workplaces);
            workplace->hireEmployee(hiringCondition, employee, manager_id);
        }

        void hireManagerAtWorkplace(int manager_id, int workplace_id) const;

        void fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id) const;

        void fireManagerAtWorkplace(int manager_id, int workplace_id) const;

        int getAllAboveSalary(ostream &, int salary) const;

        bool isWorkingInTheSameWorkplace(int employee_1, int employee_2) const;

        ostream &printAllEmployeesWithSkill(ostream &, int skill_id) const;

        template<class T, class CMP>
        bool exists(int id, set<T, CMP> set) const {
            for (T n: set) {
                if (n->getId() == id) {
                    return true;
                }
            }
            return false;
        }

        template<class T, class CMP>
        T get(int id, set<T, CMP> set) const {
            for (T n: set) {
                if (n->getId() == id) {
                    return n;
                }
            }
            return nullptr;
        }

        /*template<class T, class BASE_T, class CMP, class SP_CMP>
        void copy_set_of_ptrs(set<T*, CMP> copy_from, set<T*, CMP> copy_to,
                              set<shared_ptr<BASE_T>, SP_CMP> shared_ptr_set) const {
            for (T* n: copy_from) {
                T* ptr=new T(*n);
                copy_to.insert(ptr);
                shared_ptr_set.insert(shared_ptr<BASE_T>(ptr));
            }
        }

        template<class T, class CMP>
        void copy_set_of_shared_ptrs(set<shared_ptr<T>, CMP> copy_from, set<shared_ptr<T>, CMP> copy_to) const {
            for (const shared_ptr<T>& n: copy_from) {
                shared_ptr<T> sp(new T(*n));
                copy_to.insert(sp);
            }
        }*/

    };


}
#endif //MTM_EX2_CITY_H
