#include "City.h"

City::City(const string& new_name) : name(new_name) {}

bool City::EmployeeExist(int employee_id) const {
    for(Employee* n : employees){
        if(n->getId()==employee_id){
            return true;
        }
    }
    return false;
}

bool City::ManagerExist(int manager_id) const {
    for(Manager* n : managers){
        if(n->getId()==manager_id){
            return true;
        }
    }
    return false;
}

bool City::CitizenExist(int citizen_id) const {
    for(const shared_ptr<Citizen>& n : citizens){
        if(n->getId()==citizen_id){
            return true;
        }
    }
    return false;
}

bool City::WorkplaceExist(int workplace_id) const {
    for(Workplace* n : workplaces){
        if(n->getId() == workplace_id){
            return true;
        }
    }
    return false;
}

bool City::FacultyExist(int faculty_id) const {
    for(const shared_ptr<FacultyBase>& n : faculties){
        if(n->getId()==faculty_id){
            return true;
        }
    }
    return false;
}

void City::addEmployee(int new_id, const string &new_first_name, const string &new_last_name, int new_year) {
    if(CitizenExist(new_id)){
        throw CitizenAlreadyExists();
    }
    employees.insert(new Employee(new_id, new_first_name, new_last_name, new_year));
    Employee* employee= getEmployee(new_id);
    citizens.insert(shared_ptr<Citizen>(employee));
}

void City::addManager(int new_id, const string &new_first_name, const string &new_last_name, int new_year) {
    if(CitizenExist(new_id)){
        throw CitizenAlreadyExists();
    }
    managers.insert(new Manager(new_id, new_first_name, new_last_name, new_year));
    Manager* manager = getManager(new_id);
    citizens.insert(shared_ptr<Citizen>(manager));
}

void City::createWorkplace(int new_id, const string &new_name, int new_employee_salary, int new_manager_salary) {
    if(WorkplaceExist(new_id)){
        throw WorkplaceAlreadyExists();
    }
    workplaces.insert(new Workplace(new_id, new_name, new_employee_salary, new_manager_salary));
}

void City::hireManagerAtWorkplace(int manager_id, int workplace_id) const{
    if(!ManagerExist(manager_id)){
        throw ManagerDoesNotExist();
    }
    if(!WorkplaceExist(workplace_id)){
        throw WorkplaceDoesNotExist();
    }
    Workplace* workplace= getWorkplace(workplace_id);
    Manager* manager= getManager(manager_id);
    workplace->hireManager(manager);
}

Employee* City::getEmployee(int employee_id) const {
    for(Employee* n : employees){
        if(n->getId()==employee_id){
            return n;
        }
    }
    return nullptr;
}

Manager* City::getManager(int manager_id) const {
    for(Manager* n : managers){
        if(n->getId()==manager_id){
            return n;
        }
    }
    return nullptr;
}

Workplace* City::getWorkplace(int workplace_id) const {
    for(Workplace* n : workplaces){
        if(n->getId() == workplace_id){
            return n;
        }
    }
    return nullptr;
}

shared_ptr<FacultyBase> City::getFaculty(int faculty_id) const {
    for(shared_ptr<FacultyBase> n : faculties){
        if(n->getId()==faculty_id){
            return n;
        }
    }
    return nullptr;
}

void City::fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id) const {
    if(!EmployeeExist(employee_id)){
        throw EmployeeDoesNotExist();
    }
    if(!ManagerExist(manager_id)){
        throw ManagerDoesNotExist();
    }
    if(!WorkplaceExist(workplace_id)){
        throw WorkplaceDoesNotExist();
    }
    Workplace* workplace= getWorkplace(workplace_id);
    workplace->fireEmployee(employee_id, manager_id);
}

void City::fireManagerAtWorkplace(int manager_id, int workplace_id) const {
    if(!ManagerExist(manager_id)){
        throw ManagerDoesNotExist();
    }
    if(!WorkplaceExist(workplace_id)){
        throw WorkplaceDoesNotExist();
    }
    Workplace* workplace= getWorkplace(workplace_id);
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
    if(!EmployeeExist(employee_1)){
        throw EmployeeDoesNotExist();
    }
    if(!EmployeeExist(employee_2)){
        throw EmployeeDoesNotExist();
    }
    for(const Workplace* n : workplaces){
        if(n->hasEmployeeInWorkplace(employee_1) && n->hasEmployeeInWorkplace(employee_2)){
            return true;
        }
    }
    return false;
}

ostream &City::printAllEmployeesWithSkill(ostream &os, int skill_id) const {
    for(const Employee* n : employees){
        if(n->hasSkill(skill_id)){
            n->printShort(os);
        }
    }
    return os;
}

template<class Condition>
void City::addFaculty(int new_id, const Skill& new_skill, int new_points_from_faculty, Condition* new_condition) {
    for(const shared_ptr<FacultyBase>& n : faculties){
        if(n->getId()==new_id){
            throw FacultyAlreadyExists();
        }
    }
    Faculty<Condition> faculty(new_id, new_condition, new_skill, new_points_from_faculty);
    faculties.insert(shared_ptr<FacultyBase>(faculty));
}

void City::teachAtFaculty(int employee_id, int faculty_id) const{
    if(!EmployeeExist(employee_id)){
        throw EmployeeDoesNotExist();
    }
    if(!FacultyExist(faculty_id)){
        throw FacultyDoesNotExist();
    }
    shared_ptr<FacultyBase> faculty= getFaculty(faculty_id);
    Employee* employee= getEmployee(employee_id);
    faculty->teach(employee);
}








