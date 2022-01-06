#include "Workplace.h"

using std::endl;

Workplace::Workplace(int new_id, const string &new_name, int new_employee_salary, int new_manager_salary) :
    id(new_id), name(new_name), employee_salary(new_employee_salary), manager_salary(new_manager_salary){}

int Workplace::getId() const {
    return id;
}

string Workplace::getName() const {
    return name;
}

int Workplace::getWorkersSalary() const {
    return employee_salary;
}

int Workplace::getManagersSalary() const {
    return manager_salary;
}

void Workplace::hireManager(Manager *manager_to_hire) {
    if(hasManager(manager_to_hire->getId())){
        throw exception::ManagerAlreadyHired();
    }
    if(manager_to_hire->isManagerHired()){
        throw exception::CanNotHireManager();
    }
    managers.insert(manager_to_hire);
    manager_to_hire->setSalary(manager_salary);
    manager_to_hire->setManagerWorkplace(id);

}

bool Workplace::hasManager(int manager_id) const{
    for(Manager* n : managers){
        if(n->getId()==manager_id){
            return true;
        }
    }
    return false;
}

void Workplace::fireEmployee(int employee_id, int manager_id) const{
    if(!hasManager(manager_id)){
        throw exception::ManagerIsNotHired();
    }
    if(!hasEmployeeInManager(employee_id,manager_id)){
        throw exception::EmployeeIsNotHired();
    }
    Employee* employee= getEmployeeFromManager(employee_id, manager_id);
    Manager* manager= getManager(manager_id);
    manager->removeEmployee(employee_id);
    employee->setSalary(-employee_salary);
}

bool Workplace::hasEmployeeInManager(int employee_id, int manager_id) const {
    for(Manager* n : managers){
        if(n->getId()==manager_id){
            return n->hasEmployee(employee_id);
        }
    }
    return false;
}

Manager* Workplace::getManager(int manager_id) const{
    for(Manager* n : managers){
        if(n->getId() == manager_id){
            return n;
        }
    }
    return nullptr;
}

Employee* Workplace::getEmployeeFromManager(int employee_id, int manager_id) const{
    Manager* manager=getManager(manager_id);
    return manager->getEmployee(employee_id);
}

void Workplace::fireManager(int manager_id) {
    if(!hasManager(manager_id)){
        throw exception::ManagerIsNotHired();
    }
    Manager* manager = getManager(manager_id);
    set<int> employees_under_manager = manager->getEmployeesIdsSet();
    for (int n : employees_under_manager){
        fireEmployee(n, manager_id);
    }
    manager->setManagerNotHired();
    manager->setSalary(-manager_salary);
    managers.erase(manager);
}

ostream &operator<<(ostream& os, const Workplace& workplace) {
    os << "Workplace name - " << workplace.name;
    if (workplace.getNumOfManagers()!=0){
        workplace.printGroups(os);
    }
    return os;
}

ostream &Workplace::printGroups(ostream& os) const {
    os << " Groups:" <<endl;
    for(Manager* n : managers){
        os << "Manager ";
        n->printLong(os);
    }
    return os;
}

int Workplace::getNumOfManagers() const {
    return (int)managers.size();
}

void Workplace::hireEmployeeAction(Employee *employee, int manager_id) {
    if(!hasManager(manager_id)){
        throw exception::ManagerIsNotHired();
    }
    for(Manager* n : managers){
        if(hasEmployeeInManager(employee->getId(), n->getId())){
            throw exception::EmployeeAlreadyHired();
        }
    }
    Manager* manager= getManager(manager_id);
    manager->addEmployee(employee);
    employee->setSalary(employee_salary);
}

bool Workplace::hasEmployeeInWorkplace(int employee_id) const{
    for(Manager* n : managers){
        if(hasEmployeeInManager(employee_id, n->getId())){
            return true;
        }
    }
    return false;
}
