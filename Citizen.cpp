#include "Citizen.h"

#include <utility>

using std::endl;
using std::shared_ptr;
using std::ostream;
using std::string;

namespace mtm {

    Citizen::Citizen(int new_id, string new_first_name, string new_last_name, int new_year) :
            id(new_id), first_name(std::move(new_first_name)), last_name(std::move(new_last_name)),
            year_of_birth(new_year) {}

    int Citizen::getId() const {
        return id;
    }

    string Citizen::getFirstName() const {
        return first_name;
    }

    string Citizen::getLastName() const {
        return last_name;
    }

    int Citizen::getBirthYear() const {
        return year_of_birth;
    }

    ostream &Citizen::printFullName(ostream &out) const {
        out << first_name << " " << last_name << endl;
        return out;
    }

    ostream &Citizen::printIdBirthYear(ostream &os) const {
        os << "id - " << id << " birth_year - " << year_of_birth << endl;
        return os;
    }

    bool operator<(const Citizen &citizen_1, const Citizen &citizen_2) {
        if (citizen_1.id < citizen_2.id) {
            return true;
        }
        return false;
    }

    bool operator==(const Citizen &citizen_1, const Citizen &citizen_2) {
        if (citizen_1.id == citizen_2.id) {
            return true;
        }
        return false;
    }

    bool operator<=(const Citizen &citizen_1, const Citizen &citizen_2) {
        if (citizen_1 < citizen_2 || citizen_1 == citizen_2) {
            return true;
        }
        return false;
    }

    bool operator>(const Citizen &citizen_1, const Citizen &citizen_2) {
        if (citizen_2 < citizen_1) {
            return true;
        }
        return false;
    }

    bool operator>=(const Citizen &citizen_1, const Citizen &citizen_2) {
        if (citizen_2 < citizen_1 || citizen_1 == citizen_2) {
            return true;
        }
        return false;
    }

    bool operator!=(const Citizen &citizen_1, const Citizen &citizen_2) {
        if (citizen_1 == citizen_2) {
            return false;
        }
        return true;
    }
}