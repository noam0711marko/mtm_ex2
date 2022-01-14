#include "Manager.h"
#include "Citizen.h"

using std::endl;

namespace mtm {

    Manager::Manager(int new_id, const string &new_first_name, const string &new_last_name, int new_birth_year)
            : Citizen(new_id, new_first_name, new_last_name, new_birth_year), salary(0), workplace_id(NOT_HIRED) {}

    int Manager::getSalary() const {
        return salary;
    }

    void Manager::addEmployee(Employee *employee) {
        if (hasEmployee(employee->getId())) {
            throw EmployeeAlreadyHired();
        }
        employees.insert(employee);
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
        for (Employee *n: employees) {
            if (n->getId() == id_to_remove) {
                employees_ids.erase(n->getId());
                employees.erase(n);
                return;
            }
        }
        throw EmployeeIsNotHired();
    }

    void Manager::setSalary(int to_add) {
        if (salary + to_add < 0) {
            salary = 0;
            return;
        }
        salary += to_add;
    }

    ostream &Manager::printShort(ostream &os) const {
        printFullName(os);
        printSalary(os);
        return os;
    }

    ostream &Manager::printLong(ostream &os) const {
        printFullName(os);
        printIdBirthYear(os);
        printSalary(os);
        printEmployees(os);

        return os;
    }

    Manager *Manager::clone() const {
        Manager *copy = new Manager(*this);
        return copy;
    }

    ostream &Manager::printSalary(ostream &os) const {
        os << "Salary: " << salary << endl;
        return os;
    }

    ostream &Manager::printEmployees(ostream &os) const {
        /*set<Employee*>::iterator it=employees.begin();
        while (it!=employees.end()){
            Employee* temp= *it;
            temp->printShort(os);
            it++;
        }*/
        if(!employees.empty()){
            os << "Employees: " << endl;
        }
        else{
            //os << endl;
            return os;
        }
        for (Employee *n: employees) {
            n->printShort(os);
        }
        return os;
    }

    bool Manager::hasEmployee(int employee_id) {
        for (Employee *n: employees) {
            if (n->getId() == employee_id) {
                return true;
            }
        }
        return false;
    }

    bool Manager::isManagerHired() const {
        if (workplace_id != NOT_HIRED) {
            return true;
        }
        return false;
    }

    void Manager::setManagerWorkplace(int new_workplace_id) {
        new_workplace_id = new_workplace_id;
    }

    Employee *Manager::getEmployee(int employee_id) {
        for (Employee *n: employees) {
            if (n->getId() == employee_id) {
                return n;
            }
        }
        return nullptr;
    }

    set<int> Manager::getEmployeesIdsSet() {
        return employees_ids;
    }

    void Manager::setManagerNotHired() {
        workplace_id = NOT_HIRED;
    }

    /*Manager::Manager(const Manager &m) : Citizen(m), salary(m.salary), workplace_id(m.workplace_id) {
        for (Employee* n : m.employees){
            employees.insert(new Employee(*n));
        }
    }*/
}
