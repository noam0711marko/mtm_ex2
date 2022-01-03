//
// Created by dolle on 03/01/2022.
//

#include "Manager.h"
#include "Citizen.h"
using std::endl;


Manager::Manager(int newId1, const string &newFirstName1, const string &newLastName1, int newYear1, int newId)
:Citizen(newId1,newFirstName1,newLastName1,newId1),salary(0),employees() {
}

int Manager::getSalary() {
    return salary;
}

void Manager::addEmployee(Employee* employee) {
      employees.insert(employee);
}

void Manager::removeEmployee(int id_to_remove) {

    std::set<Employee*>::iterator it= employees.begin();
    while(it!=employees.end()) {
        int curr_id=(*it)->getId();
        if (curr_id == id_to_remove) {
            employees.erase(it);
            it++;
            curr_id=(*it)->getId();
        }
    }
    throw EmployeeIsNotHired();

}

void Manager::setSalary(int to_add) {
salary+= to_add;
}

ostream &Manager::printShort(ostream & os) const {
    os <<first_name <<" "<<last_name<<endl;
    return os;
}

ostream &Manager::printLong(ostream & os) const {
    printShort(os);
    os<<"id - "<<id<<" birth_year - "<<year_of_birth<<endl;
    os<<"Salary: "<<salary<<endl;
    os<<"Employees:"<<endl;
    std::set<Employee*>::iterator it=employees.begin();
    while (it!=employees.end()){
        Employee* temp= *it;
        temp->printShort(os);
        it++;
    }
    return os;
}

Manager *Manager::clone() const {
    Manager* copy=new Manager(*this);
    return copy;
}
