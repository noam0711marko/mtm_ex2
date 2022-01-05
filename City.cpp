#include "City.h"

City::City(string new_name) : name(new_name), employees(), managers(), workplaces(), faculties() {}

bool City::EmployeeExist(int employee_id) const {
    for(const shared_ptr<Employee>& n : employees){
        if(n->getId()==employee_id){
            return true;
        }
    }
    return false;
}

bool City::ManagerExist(int manager_id) const {
    for(const shared_ptr<Manager>& n : managers){
        if(n->getId()==manager_id){
            return true;
        }
    }
    return false;
}

bool City::WorkplaceExist(int workplace_id) const {
    for(const shared_ptr<Workplace>& n : workplaces){
        if(n->getId()==workplace_id){
            return true;
        }
    }
    return false;
}

void City::addEmployee(int new_id, const string &new_first_name, const string &new_last_name, int new_year) {
    if(EmployeeExist(new_id)){
        throw EmployeeAlreadyExists();
    }
    employees.insert(shared_ptr<Employee>(new Employee(new_id, new_first_name, new_last_name, new_year)));
}

void City::addManager(int new_id, const string &new_first_name, const string &new_last_name, int new_year) {
    if(ManagerExist(new_id)){
        throw ManagerAlreadyExists();
    }
    managers.insert(shared_ptr<Manager>(new Manager(new_id, new_first_name, new_last_name, new_year)));
}

void City::createWorkplace(int new_id, const string &new_name, int new_employee_salary, int new_manager_salary) {
    if(WorkplaceExist(new_id)){
        throw WorkplaceAlreadyExists();
    }
    workplaces.insert(shared_ptr<Workplace>(new Workplace(new_id, new_name, new_employee_salary, new_manager_salary)));
}

void City::hireManagerAtWorkplace(int manager_id, int workplace_id) {
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

Employee *City::getEmployee(int employee_id) const {
    assert(EmployeeExist(employee_id));
    for(const shared_ptr<Employee>& n : employees){
        if(n->getId()==employee_id){
            return dynamic_cast<Employee *>(n->clone());
        }
    }
    return nullptr;
}

Manager *City::getManager(int manager_id) const {
    assert(ManagerExist(manager_id));
    for(const shared_ptr<Manager>& n : managers){
        if(n->getId()==manager_id){
            return dynamic_cast<Manager *>(n->clone());
        }
    }
    return nullptr;
}

Workplace *City::getWorkplace(int workplace_id) const {
    assert(WorkplaceExist(workplace_id));
    for(const shared_ptr<Workplace>& n : workplaces){
        if(n->getID()==workplace_id){
            return dynamic_cast<Workplace *>(n->clone());
        }
    }
    return nullptr;
}

void City::fireEmployeeAtWorkplace(int employee_id, int manager_id, int workplace_id) {
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

void City::fireManagerAtWorkplace(int manager_id, int workplace_id) {
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
    set<shared_ptr<Employee>>::iterator employees_iterator=employees.begin();
    set<shared_ptr<Manager>>::iterator managers_iterator=managers.begin();
    shared_ptr<Employee> current_employee=*employees_iterator;
    shared_ptr<Manager> current_manager=*managers_iterator;
    /* explanation:
     * runs through employees and managers sets together.
     * from each pair, takes the one with smaller id and checks if it's salary is bigger than requested.
     * if it is - print it and continue, if not - just continue
     */
    while(employees_iterator!=employees.end() && managers_iterator!=managers.end()){
        current_employee=*employees_iterator;
        current_manager=*managers_iterator;
        if(current_employee->getId()<current_manager->getId()){
            if(current_employee->getSalary()>=salary){
                current_employee->printShort(os);
                ++counter;
            }
            ++employees_iterator;
            continue;
        }
        else{
            if(current_manager->getSalary()>=salary){
                current_manager->printShort(os);
                ++counter;
            }
            ++managers_iterator;
            continue;
        }
    }
    //in PDF says "returns their quantity", so I added a counter, but I don't have an example of printing so I'm not
    //quite sure if my prints are good and what to do with the counter...
    return os;
}

bool City::isWorkingInTheSameWorkplace(int employee_1, int employee_2) const {
    if(!EmployeeExist(employee_1)){
        throw EmployeeDoesNotExist();
    }
    if(!EmployeeExist(employee_2)){
        throw EmployeeDoesNotExist();
    }
    for(const shared_ptr<Workplace>& n : workplaces){
        if(n->hasEmployeeInWorkplace(employee_1) && n->hasEmployeeInWorkplace(employee_2)){
            return true;
        }
    }
    return false;
}

//again, I'm not sure about print because I don't have the test right now, but this should generally work
ostream &City::printAllEmployeesWithSkill(ostream &os) const {
    for(const shared_ptr<Employee>& n : employees){
        if(n->getNumOfSkills()!=0){
            n->printShort(os);
        }
    }
    return os;
}


