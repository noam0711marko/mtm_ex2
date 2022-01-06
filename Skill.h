#ifndef MTM_EX2_SKILL_H
#define MTM_EX2_SKILL_H

#include <iostream>
#include "memory"
#include "exceptions.h"

using std::shared_ptr;

using std::string;
using std::ostream;

namespace mtm {
    class Skill {
        int id;
        string name;
        int required_points_for_purchase;

    public:
        Skill(int new_id, const string &new_name, int new_required_points);

        ~Skill() = default;

        Skill(const Skill &) = default;

        Skill &operator=(const Skill &) = default;

        const int &getId() const;

        const string &getName() const;

        int getRequiredPoints() const;

        friend ostream &operator<<(ostream &, const Skill &);

        friend bool operator<(const Skill &, const Skill &);

        friend bool operator==(const Skill &, const Skill &);

        int &operator++() = delete;

        int operator++(int);

        int &operator+=(const int &);

        Skill operator+(const int &);


    };

    bool operator<=(const Skill &, const Skill &);

    bool operator>(const Skill &, const Skill &);

    bool operator>=(const Skill &, const Skill &);

    bool operator!=(const Skill &, const Skill &);

    struct cmp_skills {
        bool operator()(const Skill &a, const Skill &b) const { return a < b; }
    };

}
#endif //MTM_EX2_SKILL_H
