#include "Manager.h"
#include "Citizen.h"
#include <assert.h>

using std::endl;

Manager::Manager(int new_id, const string &new_first_name, const string &new_last_name, int new_birth_year)
    : Citizen(new_id, new_first_name, new_last_name, new_birth_year), salary(0),
        employees(), workplace_id(NOT_HIRED), employees_ids() {}

int Manager::getSalary() {
    return salary;
}

void Manager::addEmployee(Employee* employee) {
    if(hasEmployee(employee->getId())){
        throw EmployeeAlreadyHired();
    }
    employees.insert(shared_ptr<Employee> (new Employee(*employee)));
    employees_ids.insert(employee->getId());
}

void Manager::removeEmployee(int id_to_remove) {
    /*set<Employee*>::iterator it= employees.begin();
    while(it!=employees.end()) {
        int curr_id=(*it)->getId();
        if (curr_id == id_to_remove) {
            employees.erase(it);
            return;
        }
        ++it;
    }
    throw EmployeeIsNotHired();
*/
    for(const shared_ptr<Employee> &n : employees){
        if(n->getId()==id_to_remove){
            employees.erase(n);
            employees_ids.erase(n->getId());
            return;
        }
    }
    throw EmployeeIsNotHired();
}

void Manager::setSalary(int to_add) {
salary+= to_add;
}

ostream &Manager::printShort(ostream & os) const {
    printFirstLastName(os);
    printSalary(os);
    return os;
}

ostream &Manager::printLong(ostream & os) const {
    printFirstLastName(os);
    printIdBirthYear(os);
    printSalary(os);
    os<<"Employees:"<<endl;
    printEmployees(os);

    return os;
}

Citizen *Manager::clone() const {
    Citizen* copy=new Manager(*this);
    return copy;
}

ostream &Manager::printSalary(ostream &os) const {
    os<<"Salary: "<<salary<<endl;
    return os;
}

ostream &Manager::printEmployees(ostream &os) const {
    /*set<Employee*>::iterator it=employees.begin();
    while (it!=employees.end()){
        Employee* temp= *it;
        temp->printShort(os);
        it++;
    }*/
    for(const shared_ptr<Employee> &n : employees){
            n->printShort(os);
    }
    return os;
}

bool Manager::hasEmployee(int employee_id) {
    for(const shared_ptr<Employee> &n : employees){
        if(n->getId() == employee_id){
            return true;
        }
    }
    return false;
}

bool Manager::isManagerHired() const {
    if(workplace_id!=NOT_HIRED){
        return true;
    }
    return false;
}

void Manager::setManagerWorkplace(int new_workplace_id) {
    new_workplace_id=new_workplace_id;
}

shared_ptr<Employee> Manager::getEmployee(int employee_id) {
    assert(hasEmployee(employee_id));
    for(const shared_ptr<Employee> &n : employees){
        if(n->getId() == employee_id){
            return n;
        }
    }
    return nullptr;
}

set<int> Manager::getEmployeesIdsSet() {
    return employees_ids;
}

void Manager::setManagerNotHired() {
    workplace_id=NOT_HIRED;
}
