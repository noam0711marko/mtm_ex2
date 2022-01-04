#include "Workplace.h"

using std::endl;

Workplace::Workplace(int new_id, const string &new_name, int new_employee_salary, int new_manager_salary) :
    id(new_id), name(new_name), employee_salary(new_employee_salary), manager_salary(new_manager_salary), managers(){}

int Workplace::getID() const {
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
        throw ManagerAlreadyHired();
    }
    if(manager_to_hire->isManagerHired()){
        throw CanNotHireManager();
    }
    managers.insert(shared_ptr<Manager>(new Manager(*manager_to_hire)));
    manager_to_hire->setSalary(manager_salary);
    manager_to_hire->setManagerWorkplace(id);

}

bool Workplace::hasManager(int manager_id) {
    for(const shared_ptr<Manager> &n : managers){
        if(n->getId()==manager_id){
            return true;
        }
    }
    return false;
}

void Workplace::fireEmployee(int employee_id, int manager_id) {
    if(!hasManager(manager_id)){
        throw ManagerIsNotHired();
    }
    if(!hasEmployeeInManager(employee_id,manager_id)){
        throw EmployeeIsNotHired();
    }
    shared_ptr<Employee> employee= getEmployeeFromManager(employee_id, manager_id);
    shared_ptr<Manager> manager= getManager(manager_id);
    manager->removeEmployee(employee_id);
    employee->setSalary(-employee_salary);
}

bool Workplace::hasEmployeeInManager(int employee_id, int manager_id) {
    for(const shared_ptr<Manager> &n : managers){
        if(n->getId()==manager_id){
            return n->hasEmployee(employee_id);
        }
    }
    return false;
}

shared_ptr<Manager> Workplace::getManager(int manager_id) {
    assert(hasManager(manager_id));
    for(const shared_ptr<Manager> &n : managers){
        if(n->getId() == manager_id){
            return n;
        }
    }
    return nullptr;
}

shared_ptr<Employee> Workplace::getEmployeeFromManager(int employee_id, int manager_id) {
    shared_ptr<Manager> manager=getManager(manager_id);
    return manager->getEmployee(employee_id);
}

void Workplace::fireManager(int manager_id) {
    if(!hasManager(manager_id)){
        throw ManagerIsNotHired();
    }
    shared_ptr<Manager> manager = getManager(manager_id);
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
    for (const shared_ptr<Manager>& n : managers){
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
        throw ManagerIsNotHired();
    }
    for(const shared_ptr<Manager>& n : managers){
        if(hasEmployeeInManager(employee->getId(), n->getId())){
            throw EmployeeAlreadyHired();
        }
    }
    shared_ptr<Manager> manager= getManager(manager_id);
    manager->addEmployee(employee);
    employee->setSalary(employee_salary);
}
