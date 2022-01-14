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
 *   getId                      - Returns the ID of a citizen.
 *   getFirstName               - Returns the first name of a citizen.
 *   getLastName                - Returns the last name of a citizen.
 *   getBirthYear               - Returns the year of birth of a citizen.
 *   getSalary                  - Pure Virtual method which Returns the salary of a citizen.
 *   operator<                  - Overloads the operator '<' for citizen (compare by ID).
 *   operator==                 - Overloads the operator '==' for citizen (compare by ID).
 *   printShort                 - Virtual method which prints short details about the citizen.
 *   printLong                  - Virtual method which prints long details about the citizen.
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
         */
        explicit Citizen(int new_id, string new_first_name, string new_last_name, int new_year);

        /*
         * Citizen: Default Copy Constructor for citizen.
         *
         * @param - the citizen which is data is requested to be copied
         *
         * @return
         *      A new citizen with the same details as the citizen which was sent to the function
         */
        Citizen(const Citizen&) = default;

        /*
         * operator=: Default Assignment Operator for citizen.
         *
         * @param - the citizen which is data is requested to be assigned to the new citizen
         *
         * @return
         *      The same citizen, but with the same details as the citizen which was sent to the function
         */
        Citizen &operator=(const Citizen &) = default;

        /*
         * ~Citizen: Virtual default destructor for citizen.
         *
         * note: It's a virtual method which will be overridden in the derived classes.
         */
        virtual ~Citizen() = default;

        /*
         * getId: Returns the id of a citizen.
         *
         * @return
         *      The ID of the citizen
         */
        int getId() const;

        /*
         * getFirstName: Returns the first name of a citizen.
         *
         * @return
         *      The first name of the citizen
         */
        string getFirstName() const;

        /*
         * getLastName: Returns the last name of a citizen.
         *
         * @return
         *      The last name of the citizen
         */
        string getLastName() const;

        /*
         * getBirthYear: Returns the year of birth of a citizen.
         *
         * @return
         *      The year of birth of the citizen
         */
        int getBirthYear() const;

        /*
         * getSalary: Pure Virtual method which Returns the salary of a citizen.
         *
         * note: It's a pure virtual method, so it can be used only in derived classes!
         *       Therefore, it's not implemented in this base abstract class.
         *
         * @return
         *      The salary of the citizen
         */
        virtual int getSalary() const = 0;

        /*
         * operator<: Overloads the operator '<' for citizen (compare by ID).
         *
         * @param citizen_1- the first citizen to compare.
         * @param citizen_2- the second citizen to compare.
         *
         * @return
         *      True - if first citizen's ID is smaller than second citizen's ID.
         *      False - otherwise.
         */
        friend bool operator<(const Citizen &citizen_1, const Citizen &citizen_2);

        /*
         * operator==: Overloads the operator '==' for citizen (compare by ID).
         *
         * @param citizen_1- the first citizen to compare.
         * @param citizen_2- the second citizen to compare.
         *
         * @return
         *      True - if first citizen's ID is equal to second citizen's ID.
         *      False - otherwise.
         */
        friend bool operator==(const Citizen &citizen_1, const Citizen &citizen_2);

        /*
         * printShort: Virtual method which prints short details about the citizen.
         *
         * note: It's a pure virtual method, so it can be used only in derived classes!
         *       Therefore, it's not implemented in this base abstract class.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        virtual ostream &printShort(ostream &) const = 0;

        /*
         * printLong: Virtual method which prints long details about the citizen.
         *
         * note: It's a pure virtual method, so it can be used only in derived classes!
         *       Therefore, it's not implemented in this base abstract class.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        virtual ostream &printLong(ostream &) const = 0;

        /*
         * printFullName: Prints citizen's full name.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printFullName(ostream &) const;

        /*
         * printIdBirthYear: Prints citizen's id and year of birth.
         *
         * @param - output stream to print in to.
         *
         * @return
         *      The output stream
         */
        ostream &printIdBirthYear(ostream &) const;

        /*
         * clone: Pure virtual method which creates a (deep) copy of a citizen.
         *
         * note: It's a pure virtual method, so it can be used only in derived classes!
         *       Therefore, it's not implemented in this base abstract class.
         *
         * @return
         *      A new citizen which is a copy of the citizen sent to the method.
         */
        virtual Citizen *clone() const = 0;
    };

    /*
     * operator<=: Overloads the operator '<=' for citizen (compare by ID).
     *
     * @param citizen_1- the first citizen to compare.
     * @param citizen_2- the second citizen to compare.
     *
     * @return
     *      True - if first citizen's ID is smaller than or equal to second citizen's ID.
     *      False - otherwise.
     */
    bool operator<=(const Citizen &citizen_1, const Citizen &citizen_2);

    /*
     * operator>: Overloads the operator '>' for citizen (compare by ID).
     *
     * @param citizen_1- the first citizen to compare.
     * @param citizen_2- the second citizen to compare.
     *
     * @return
     *      True - if first citizen's ID is bigger than second citizen's ID.
     *      False - otherwise.
     */
    bool operator>(const Citizen &citizen_1, const Citizen &citizen_2);

    /*
     * operator>=: Overloads the operator '>=' for citizen (compare by ID).
     *
     * @param citizen_1- the first citizen to compare.
     * @param citizen_2- the second citizen to compare.
     *
     * @return
     *      True - if first citizen's ID is bigger than or equal to second citizen's ID.
     *      False - otherwise.
     */
    bool operator>=(const Citizen &citizen_1, const Citizen &citizen_2);

    /*
     * operator!=: Overloads the operator '!=' for citizen (compare by ID).
     *
     * @param citizen_1- the first citizen to compare.
     * @param citizen_2- the second citizen to compare.
     *
     * @return
     *      True - if first citizen's ID is not equal to second citizen's ID.
     *      False - otherwise.
     */
    bool operator!=(const Citizen &citizen_1, const Citizen &citizen_2);


    /*
     * cmp_citizens_shared_ptr:
     * struct which contains only the operator() which compare between shared pointers to citizen by citizen's
     * operator <.
     * this struct is sent to the set which contains shared pointers to citizens, and it's necessary for it's sorting.
     */
    struct cmp_citizens_shared_ptr {
        bool operator()(const shared_ptr<Citizen> &a, const shared_ptr<Citizen> &b) const { return (*a) < (*b); }
    };

    /*
     * cmp_citizens_ptr:
     * struct which contains only the operator() which compare between pointers to citizen by citizen's operator <.
     * this struct is sent to the set which contains pointers to citizens, and it's necessary for it's sorting.
     */
    struct cmp_citizens_ptr {
        bool operator()(Citizen *a, Citizen *b) const { return (*a) < (*b); }
    };
}
#endif //MTM_EX2_CITIZEN_H
