#ifndef MTM_EX2_EXCEPTIONS_H
#define MTM_EX2_EXCEPTIONS_H

#include <iostream>
namespace mtm {
    class exceptions : public std::exception {
    public:
        class NegativePoints : public std::exception {
        };

        class SkillAlreadyLearned : public std::exception {
        };

        class CanNotLearnSkill : public std::exception {
        };

        class DidNotLearnSkill : public std::exception {
        };

        class EmployeeAlreadyHired : public std::exception {
        };

        class EmployeeIsNotHired : public std::exception {
        };

        class ManagerAlreadyHired : public std::exception {
        };

        class CanNotHireManager : public std::exception {
        };

        class ManagerIsNotHired : public std::exception {
        };

        class EmployeeNotSelected : public std::exception {
        };

        class EmployeeNotAccepted : public std::exception {
        };

        class CitizenAlreadyExists : public std::exception {
        };

        class WorkplaceAlreadyExists : public std::exception {
        };

        class FacultyAlreadyExist : public std::exception {
        };

        class EmployeeDoesNotExist : public std::exception {
        };

        class ManagerDoesNotExist : public std::exception {
        };

        class WorkplaceDoesNotExist : public std::exception {
        };

        class FacultyDoesNotExist : public std::exception {
        };
    };
}
#endif //MTM_EX2_EXCEPTIONS_H

