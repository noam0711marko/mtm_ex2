#ifndef MTM_EX2_EXCEPTIONS_H
#define MTM_EX2_EXCEPTIONS_H

#include <iostream>
namespace mtm {
    class exceptions : public std::exception{};

        class NegativePoints : public exceptions {
        };

        class SkillAlreadyLearned : public exceptions {
        };

        class CanNotLearnSkill : public exceptions {
        };

        class DidNotLearnSkill : public exceptions {
        };

        class EmployeeAlreadyHired : public exceptions {
        };

        class EmployeeIsNotHired : public exceptions {
        };

        class ManagerAlreadyHired : public exceptions {
        };

        class CanNotHireManager : public exceptions {
        };

        class ManagerIsNotHired : public exceptions {
        };

        class EmployeeNotSelected : public exceptions {
        };

        class EmployeeNotAccepted : public exceptions {
        };

        class CitizenAlreadyExists : public exceptions {
        };

        class WorkplaceAlreadyExists : public exceptions {
        };

        class FacultyAlreadyExist : public exceptions {
        };

        class EmployeeDoesNotExist : public exceptions {
        };

        class ManagerDoesNotExist : public exceptions {
        };

        class WorkplaceDoesNotExist : public exceptions {
        };

        class FacultyDoesNotExist : public exceptions {
        };
    };

#endif //MTM_EX2_EXCEPTIONS_H

