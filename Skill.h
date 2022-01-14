#ifndef MTM_EX2_SKILL_H
#define MTM_EX2_SKILL_H

#include <iostream>
#include "memory"
#include "exceptions.h"

using std::shared_ptr;
using std::string;
using std::ostream;

/**
 * Skill
 *
 * The following functions are available:
 *   Skill                      - Constructor for skill.
 *   ~Skill                     - Default destructor for skill.
 *   Skill                      - Default Copy Constructor for skill.
 *   Operator=                  - Default Assignment Operator for skill.
 *   getId                      - Returns the ID of the skill.
 *   getName                    - Returns the name of the skill.
 *   getRequiredPoints          - Returns the required points to purchase the skill.
 *   operator<<                 - Overloads the operator '<<' for skill.
 *   operator<                  - Overloads the operator '<' for skill.
 *   operator==                 - Overloads the operator '==' for skill.
 *   operator++                 - Overloads the operator '++' for skill (postfix only).
 *   operator+                  - Overloads the operator '+' for skill.
 *   operator+=                 - Overloads the operator '+=' for skill.
 */

namespace mtm {
    class Skill {
        int id;
        string name;
        int required_points_for_purchase;

    public:

        /*
         * Skill: Constructor for skill.
         *
         * @param new_id - Target ID of the skill.
         * @param new_name - Target name of the skill.
         * @param new_required_points - Target required point needed to purchase the skill.
         */
        explicit Skill(int new_id, string new_name, int new_required_points);

        /*
         * ~Skill: Default destructor for skill.
         */
        ~Skill() = default;

        /*
         * Skill: Default Copy Constructor for skill.
         *
         * @param - the skill which is data is requested to be copied
         *
         * @return
         *      A new skill with the same details as the skill which was sent to the function
         */
        Skill(const Skill &) = default;

        /*
         * operator=: Default Assignment Operator for skill.
         *
         * @param - the skill which is data is requested to be assigned to the new skill
         *
         * @return
         *      The same skill, but with the same details as the skill which was sent to the function
         */
        Skill &operator=(const Skill &) = default;

        /*
         * getId: Returns the id of a skill.
         *
         * @return
         *      The ID of the skill
         */
        const int &getId() const;

        /*
         * getName: Returns the name of a skill.
         *
         * @return
         *      The name of the skill
         */
        const string &getName() const;

        /*
         * getRequiredPoints: Returns the required points to purchase the skill.
         *
         * @return
         *      The required points to purchase the skill
         */
        int getRequiredPoints() const;

        /*
         * operator<<: Overloads the operator '<<' for skill.
         *
         * @param os- output stream to print in to.
         * @param skill- the skill to print
         *
         * @return
         *      The output stream
         */
        friend ostream &operator<<(ostream& os, const Skill& skill);

        /*
         * operator<: Overloads the operator '<' for skill (compare by ID).
         *
         * @param skill_1- the first skill to compare.
         * @param skill_2- the second skill to compare.
         *
         * @return
         *      True - if first skill's ID is smaller than second skill's ID.
         *      False - otherwise.
         */
        friend bool operator<(const Skill &skill_1, const Skill &skill_2);

        /*
         * operator==: Overloads the operator '==' for skill (compare by ID).
         *
         * @param skill_1- the first skill to compare.
         * @param skill_2- the second skill to compare.
         *
         * @return
         *      True - if first skill's ID is equal to second skill's ID.
         *      False - otherwise.
         */
        friend bool operator==(const Skill &skill_1, const Skill &skill_2);

        /* Denies the permission to use ++ operator for skill in prefix */
        Skill &operator++() = delete;

        /*
         * operator++: Overloads the operator '++' for skill (postfix only).
         *
         * @param int- "dummy" parameter to determine it's the postfix parameter
         *
         * @return
         *      The skill with it's required points for purchase increased by 1
         */
        Skill operator++(int);

        /*
         * operator+=: Overloads the operator '+=' for skill.
         *
         * @param- amount to add to skill's required points for purchase
         *
         * @return
         *      The skill with it's required points for purchase increased by the amount sent to the function
         */
        Skill &operator+=(const int &);

        /*
         * operator+: Overloads the operator '+' for skill.
         *
         * @param skill - the skill which it's required points for purchase is requested to be updated.
         * @param num- amount to add to skill's required points for purchase
         *
         * @return
         *      The skill with it's required points for purchase increased by num
         */
        friend Skill operator+(const int &num, const Skill &skill);
        friend Skill operator+(const Skill &skill, const int &num);


    };

    /*
     * operator<=: Overloads the operator '<=' for skill (compare by ID).
     *
     * @param skill_1- the first skill to compare.
     * @param skill_2- the second skill to compare.
     *
     * @return
     *      True - if first skill's ID is smaller than or equal to second skill's ID.
     *      False - otherwise.
     */
    bool operator<=(const Skill &skill_1, const Skill &skill_2);

    /*
     * operator>: Overloads the operator '>' for skill (compare by ID).
     *
     * @param skill_1- the first skill to compare.
     * @param skill_2- the second skill to compare.
     *
     * @return
     *      True - if first skill's ID is bigger than second skill's ID.
     *      False - otherwise.
     */
    bool operator>(const Skill &skill_1, const Skill &skill_2);

    /*
     * operator>=: Overloads the operator '>=' for skill (compare by ID).
     *
     * @param skill_1- the first skill to compare.
     * @param skill_2- the second skill to compare.
     *
     * @return
     *      True - if first skill's ID is bigger than or equal to second skill's ID.
     *      False - otherwise.
     */
    bool operator>=(const Skill &skill_1, const Skill &skill_2);

    /*
     * operator!=: Overloads the operator '!=' for skill (compare by ID).
     *
     * @param skill_1- the first skill to compare.
     * @param skill_2- the second skill to compare.
     *
     * @return
     *      True - if first skill's ID is not equal to second skill's ID.
     *      False - otherwise.
     */
    bool operator!=(const Skill &skill_1, const Skill &skill_2);

    /*
     * cmp_skills:
     * struct which contains only the operator() which compare between skills by skill's operator <.
     * this struct is sent to the set which contains skills, and it's necessary for it's sorting.
     */
    struct cmp_skills {
        bool operator()(const Skill &a, const Skill &b) const { return a < b; }
    };
}
#endif //MTM_EX2_SKILL_H
