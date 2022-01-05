#include "City.h"

City::City(const string& new_name) : name(new_name) {}


void City::addEmployee(int new_id, const string &new_first_name, const string &new_last_name, int new_year) {
    if(exists(new_id, employees) || exists(new_id, managers)){
        throw Exception::CitizenAlreadyExists();
    }
    Employee employee(new_id, new_first_name, new_last_name, new_year);
    Employee* ptr=new Employee(employee);
    employees.insert(ptr);
    citizens.insert(shared_ptr<Citizen>(ptr));
}

void City::addManager(int new_id, const string &new_first_name, const string &new_last_name, int new_year) {
    if(exists(new_id, employees) || exists(new_id, managers)){
        throw Exception::CitizenAlreadyExists();
    }
    Manager manager(new_id, new_first_name, new_last_name, new_year);
    Manager* ptr=new Manager(manager);
    managers.insert(ptr);
    citizens.insert(shared_ptr<Citizen>(ptr));
}

void City::createWorkplace(int new_id, const string &new_name, int new_employee_salary, int new_manager_salary) {
    if(exists(new_id, workplaces)){
        throw Exception::WorkplaceAlreadyExists();
    }
    Workplace* workplace=new Workplace(new_id, new_name, new_employee_salary, new_manager_salary);
    workplaces.insert(workplace);
}

void City::addFaculty(int new_id, const Skill& new_skill, int new_points_from_faculty, Condition* new_condition) {
    if(exists(new_id, faculties)){
        throw Exception::FacultyAlreadyExists();
    }
    Faculty<Condition>* faculty= new Faculty<Condition>(new_id, new_skill, new_points_from_faculty, new_condition);
    faculties.insert(faculty);
}

void City::hireManagerAtWorkplace(int manager_id, int workplace_id) const{
    if(!exists(manager_id, managers)){
        throw Exception::ManagerDoesNotExist();
    }
    if(!exists(workplace_id, workplaces)){
        throw Exception::WorkplaceDoesNotExist();
    }
    Workplace* workplace= get(workplace_id, workplaces);
    Manager* manager= get(manager_id, managers);
    workplace->hireManager(manager);
}


void City::fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id) const {
    if(!exists(employee_id, employees)){
        throw Exception::EmployeeDoesNotExist();
    }
    if(!exists(manager_id, managers)){
        throw Exception::ManagerDoesNotExist();
    }
    if(!exists(workplace_id, workplaces)){
        throw Exception::WorkplaceDoesNotExist();
    }
    Workplace* workplace= get(workplace_id, workplaces);
    workplace->fireEmployee(employee_id, manager_id);
}

void City::fireManagerAtWorkplace(int manager_id, int workplace_id) const {
    if(!exists(manager_id, managers)){
        throw Exception::ManagerDoesNotExist();
    }
    if(!exists(workplace_id, workplaces)){
        throw Exception::WorkplaceDoesNotExist();
    }
    Workplace* workplace= get(workplace_id, workplaces);
    workplace->fireManager(manager_id);
}

ostream &City::getAllAboveSalary(ostream& os, int salary) const {
    int counter=0;
    for(const shared_ptr<Citizen>& n : citizens){
        if(n->getSalary() > salary){
            n->printShort(os);
            ++counter;
        }
    }
    return os;
}

bool City::isWorkingInTheSameWorkplace(int employee_1, int employee_2) const {
    if(!exists(employee_1, employees)){
        throw Exception::EmployeeDoesNotExist();
    }
    if(!exists(employee_2, employees)){
        throw Exception::EmployeeDoesNotExist();
    }
    for(const Workplace* n : workplaces){
        if(n->hasEmployeeInWorkplace(employee_1) && n->hasEmployeeInWorkplace(employee_2)){
            return true;
        }
    }
    return false;
}

ostream &City::printAllEmployeesWithSkill(ostream &os, int skill_id) const {
    for(Employee* n : employees){
        if(n->hasSkill(skill_id)){
            n->printShort(os);
        }
    }
    return os;
}

void City::teachAtFaculty(int employee_id, int faculty_id) const{
    if(!exists(employee_id, employees)){
        throw Exception::EmployeeDoesNotExist();
    }
    if(!exists(faculty_id, faculties)){
        throw Exception::FacultyDoesNotExist();
    }
    Faculty<Condition>* faculty= get(faculty_id, faculties);
    Employee* employee= get(employee_id, employees);
    faculty->teach(employee);
}

City::City(const City& city) : name(city.name){
    copy_set(city.employees, employees);
    copy_set(city.managers, managers);
    copy_set(city.workplaces, workplaces);
    copy_set(city.faculties, faculties);
    for(Employee* n: employees){
        citizens.insert(shared_ptr<Citizen>(n));
    }
    for(Manager* m: managers){
        citizens.insert(shared_ptr<Citizen>(m));
    }
}

City &City::operator=(const City& city) {
    if(this == &city){
        return *this;
    }
    overwrite_set(city.employees, employees);
    overwrite_set(city.managers, managers);
    overwrite_set(city.workplaces, workplaces);
    overwrite_set(city.faculties, faculties);
    citizens.clear();
    for(Employee* n: employees){
        citizens.insert(shared_ptr<Citizen>(n));
    }
    for(Manager* m: managers){
        citizens.insert(shared_ptr<Citizen>(m));
    }
    return *this;
}









