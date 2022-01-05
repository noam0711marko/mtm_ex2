#ifndef MTM_EX2_EXCEPTION_H
#define MTM_EX2_EXCEPTION_H

#include <iostream>

    class Exception : public std::exception {
        class NegativePoints {
        };

        class SkillAlreadyLearned {
        };

        class CanNotLearnSkill {
        };

        class DidNotLearnSkill {
        };

        class EmployeeAlreadyHired {
        };

        class EmployeeIsNotHired {
        };

        class ManagerAlreadyHired {
        };

        class CanNotHireManager {
        };

        class ManagerIsNotHired {
        };

        class EmployeeNotSelected {
        };

        class EmployeeNotAccepted {
        };

        class CitizenAlreadyExists;

        class WorkplaceAlreadyExists {
        };

        class FacultyAlreadyExists {
        };

        class EmployeeDoesNotExist {
        };

        class ManagerDoesNotExist {
        };

        class WorkplaceDoesNotExist {
        };

        class FacultyDoesNotExist {
        };
    };

#endif //MTM_EX2_EXCEPTION_H

