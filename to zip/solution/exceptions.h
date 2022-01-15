#ifndef MTM_EX2_EXCEPTIONS_H
#define MTM_EX2_EXCEPTIONS_H

#include <iostream>

namespace mtm {
    class Exception : public std::exception {
    };

    /*
     * Skill related exception.
     * will be thrown if:
     *                  Negative number would be sent to skill with one of the addition operators
     */
    class NegativePoints : public Exception {
    };

    /*
     * Employee related exception.
     * will be thrown if:
     *                  Employee already learned the skill he is requested to learn
     */
    class SkillAlreadyLearned : public Exception {
    };

    /*
     * Employee related exception.
     * will be thrown if:
     *                  Employee doesn't have enough score to purchase the skill he is requested to learn
     */
    class CanNotLearnSkill : public Exception {
    };

    /*
     * Employee related exception.
     * will be thrown if:
     *                  Employee doesn't have  the skill he is requested to forget
     */
    class DidNotLearnSkill : public Exception {
    };

    /*
     * Manager related exception.
     * will be thrown if:
     *                  Employee is already subject to the manager
     */
    class EmployeeAlreadyHired : public Exception {
    };

    /*
     * Manager related exception.
     * will be thrown if:
     *                  Employee is not subject to the manager
     */
    class EmployeeIsNotHired : public Exception {
    };

    /*
     * Workplace related exception.
     * will be thrown if:
     *                  Manager is already hired at this workplace
     */
    class ManagerAlreadyHired : public Exception {
    };

    /*
     * Workplace related exception.
     * will be thrown if:
     *                  Manager is already hired at other workplace
     */
    class CanNotHireManager : public Exception {
    };

    /*
     * Workplace related exception.
     * will be thrown if:
     *                  Manager is not hired at this workplace
     */
    class ManagerIsNotHired : public Exception {
    };

    /*
     * Workplace related exception.
     * will be thrown if:
     *                  Employee doesn't meet workplace's hiring condition
     */
    class EmployeeNotSelected : public Exception {
    };

    /*
     * Faculty related exception.
     * will be thrown if:
     *                  Employee doesn't meet faculty's condition
     */
    class EmployeeNotAccepted : public Exception {
    };

    /*
     * City related exception.
     * will be thrown if:
     *                  Citizen with the same ID already exists in the city
     */
    class CitizenAlreadyExists : public Exception {
    };

    /*
     * City related exception.
     * will be thrown if:
     *                  Workplace with the same ID already exists in the city
     */
    class WorkplaceAlreadyExists : public Exception {
    };

    /*
     * City related exception.
     * will be thrown if:
     *                  Faculty with the same ID already exists in the city
     */
    class FacultyAlreadyExists : public Exception {
    };

    /*
     * City related exception.
     * will be thrown if:
     *                  Employee does not exist in the city
     */
    class EmployeeDoesNotExist : public Exception {
    };

    /*
     * City related exception.
     * will be thrown if:
     *                  Manager does not exist in the city
     */
    class ManagerDoesNotExist : public Exception {
    };

    /*
     * City related exception.
     * will be thrown if:
     *                  Workplace does not exist in the city
     */
    class WorkplaceDoesNotExist : public Exception {
    };

    /*
     * City related exception.
     * will be thrown if:
     *                  Faculty does not exist in the city
     */
    class FacultyDoesNotExist : public Exception {
    };
}
#endif //MTM_EX2_EXCEPTIONS_H

