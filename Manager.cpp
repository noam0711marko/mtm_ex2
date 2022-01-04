#include "Manager.h"
#include "Citizen.h"

using std::endl;


Manager::Manager(int newId1, const string &newFirstName1, const string &newLastName1, int newYear1)
    :Citizen(newId1,newFirstName1,newLastName1,newYear1),salary(0),employees()
    {}

int Manager::getSalary() {
    return salary;
}

void Manager::addEmployee(Employee* employee) {
      employees.insert(employee);
}

void Manager::removeEmployee(int id_to_remove) {
    set<Employee*>::iterator it= employees.begin();
    while(it!=employees.end()) {
        int curr_id=(*it)->getId();
        if (curr_id == id_to_remove) {
            employees.erase(it);
            return;
        }
        ++it;
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
    set<Employee*>::iterator it=employees.begin();
    while (it!=employees.end()){
        Employee* temp= *it;
        temp->printShort(os);
        it++;
    }
    return os;
}
