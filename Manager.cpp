//
// Created by dolle on 03/01/2022.
//

#include "Manager.h"

using std::endl;


Manager::Manager(int newId1, const string &newFirstName1, const string &newLastName1, int newYear1, int newId,
                 int new_salary) :Citizen(newId1,newFirstName1,newLastName1,newId1),salary(new_salary) {
}

int Manager::getSalary() {
    return salary;
}

void Manager::addEmployee(Employee* employee) {
      employees.insert(*employee);
}

void Manager::removeEmployee(int id_to_remove) {
    Employee temp(id_to_remove,"temp","temp",12);
    std::set<Employee>::iterator it= employees.find(temp);
    if(it==employees.end()){
        throw EmployeeIsNotHired();
    }
    employees.erase(temp);
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
    std::set<Employee>::const_iterator it=employees.cbegin();
    while (it!=employees.end()){
        Employee temp= *it;
        temp.printShort(os);
        it++;
    }
    return os;
}

Manager *Manager::clone() const {
    Manager* copy=new Manager(*this);
    return copy;
}
