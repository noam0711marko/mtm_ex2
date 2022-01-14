#include "Skill.h"

#include <utility>

using std::string;
using std::ostream;
using std::endl;

namespace mtm {
    Skill::Skill(int new_id, string new_name, int new_required_points) :
            id(new_id), name(std::move(new_name)), required_points_for_purchase(new_required_points) {
    }

    const int &Skill::getId() const {
        return id;
    }

    const string &Skill::getName() const {
        return name;
    }

    int Skill::getRequiredPoints() const {
        return required_points_for_purchase;
    }

    ostream &operator<<(ostream &os, const Skill &skill) {
        os << skill.name << endl;
        return os;
    }

    bool operator<(const Skill &skill_1, const Skill &skill_2) {
        if (skill_1.id < skill_2.id) {
            return true;
        }
        return false;
    }

    bool operator==(const Skill &skill_1, const Skill &skill_2) {
        if (skill_1.id == skill_2.id) {
            return true;
        }
        return false;
    }

    Skill Skill::operator++(int) {
        Skill res = *this;
        ++required_points_for_purchase;
        return res;
    }

    Skill &Skill::operator+=(const int &points) {
        if (points < 0) {
            throw NegativePoints();
        }
        required_points_for_purchase += points;
        return *this;
    }

    Skill operator+(const int &num, const Skill &skill) {
        if (num < 0) {
            throw NegativePoints();
        }
        Skill res = skill;
        res += num;
        return res;
    }

    Skill operator+(const Skill &skill, const int &num) {
        if (num < 0) {
            throw NegativePoints();
        }
        Skill res = skill;
        res += num;
        return res;
    }

    bool operator<=(const Skill &skill_1, const Skill &skill_2) {
        if (skill_1 < skill_2 || skill_1 == skill_2) {
            return true;
        }
        return false;
    }


    bool operator>(const Skill &skill_1, const Skill &skill_2) {
        if (skill_2 < skill_1) {
            return true;
        }
        return false;
    }

    bool operator>=(const Skill &skill_1, const Skill &skill_2) {
        if (skill_2 < skill_1 || skill_1 == skill_2) {
            return true;
        }
        return false;
    }

    bool operator!=(const Skill &skill_1, const Skill &skill_2) {
        if (skill_1 == skill_2) {
            return false;
        }
        return true;
    }
}