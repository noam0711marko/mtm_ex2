#ifndef MTM_EX2_CITIZEN_H
#define MTM_EX2_CITIZEN_H

#include <memory>
#include <iostream>
#include "exceptions.h"

using std::string;
using std::shared_ptr;
using std::ostream;


/**
 * Citizen
 *
 * note: Citizen is an Abstract class!
 *
 * The following functions are available:
 *   Citizen                    - Constructor for citizen.
 *   ~Citizen                   - Virtual default destructor for citizen.
 *   Citizen                    - Default Copy Constructor for citizen.
 *   Operator=                  - Default Assignment Operator for citizen.
 *   getId                      - Returns the id of a citizen.
 *   getFirstName               - Returns the first name of a citizen.
 *   getLastName                - Returns the last name of a citizen.
 *   getBirthYear               - Returns the year of birth of a citizen.
 *   getSalary                  - Pure Virtual method which Returns the salary of a citizen.
 *   operator<                  - Returns if one citizen's ID is smaller than the second's ID.
 *   operator==                 - Returns if one citizen's ID is equal to the second's ID.
 *   printShort                 - Prints short details about the citizen
 *   printLong                  - Prints long details about the citizen
 *   printFullName              - Prints citizen's full name.
 *   printIdBirthYear           - Prints citizen's id and year of birth.
 *   clone                      - Pure virtual method which creates a (deep) copy of a citizen.
 */

namespace mtm {
    class Citizen {
        int id;
        string first_name;
        string last_name;
        int year_of_birth;

    public:
        /*
         * Citizen: Constructor for citizen.
         *
         * @param new_id - Target ID of the citizen.
         * @param new_first_name - Target first name of the citizen.
         * @param new_last_name - Target last name of the citizen.
         * @param new_year - Target year of birth of the citizen.
         *
         * @return
         *      A new citizen with the inserted details
         */
        explicit Citizen(int new_id, string new_first_name, string new_last_name, int new_year);

        Citizen(const Citizen &) = default;

        Citizen &operator=(const Citizen &) = default;

        virtual ~Citizen() = default;

        int getId() const;

        string getFirstName() const;

        string getLastName() const;

        int getBirthYear() const;

        virtual int getSalary() const = 0;

        friend bool operator<(const Citizen &, const Citizen &);

        friend bool operator==(const Citizen &, const Citizen &);

        virtual ostream &printShort(ostream &) const = 0;

        virtual ostream &printLong(ostream &) const = 0;

        ostream &printFullName(ostream &out) const;

        ostream &printIdBirthYear(ostream &out) const;

        virtual Citizen *clone() const = 0;
    };

    bool operator<=(const Citizen &, const Citizen &);

    bool operator>(const Citizen &, const Citizen &);

    bool operator>=(const Citizen &, const Citizen &);

    bool operator!=(const Citizen &, const Citizen &);

    struct cmp_citizens_shared_ptr {
        bool operator()(const shared_ptr<Citizen> &a, const shared_ptr<Citizen> &b) const { return (*a) < (*b); }
    };

    struct cmp_citizens_ptr {
        bool operator()(Citizen *a, Citizen *b) const { return (*a) < (*b); }
    };
}
#endif //MTM_EX2_CITIZEN_H
