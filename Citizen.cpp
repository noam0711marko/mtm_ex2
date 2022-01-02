//
// Created by dolle on 02/01/2022.
//

#include "Citizen.h"

using std::endl;
using std::shared_ptr;

Citizen::Citizen(int new_id, string new_first_name, string new_last_name, int new_year) : id(new_id),
                                                                                          first_name(new_first_name),
                                                                                          last_name(new_last_name),
                                                                                          year_of_birth(new_year) {

}

int Citizen::getId() {
    return id;
}

string Citizen::getFirstName() {
    return first_name;
}

string Citizen::getLastName() {
    return last_name;
}

int Citizen::getBirthYear() {
    return year_of_birth;
}

std::ostream &Citizen::printShort(std::ostream &out) {
    out << first_name << " " << last_name << endl;
    return out;
}

std::ostream &Citizen::printLong(std::ostream &out) {
    out << first_name << " " << last_name << endl;
    out << "id - " << id << " birth_year - " << year_of_birth << endl;
    return out;
}

shared_ptr<Citizen> Citizen::clone() {
    std::shared_ptr<Citizen> clone;
    clone = new Citizen(*this);
    return clone;
}
