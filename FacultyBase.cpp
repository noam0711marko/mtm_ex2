#include "FacultyBase.h"

FacultyBase::FacultyBase(int new_id, const Skill &new_skill, int new_points_from_faculty) :
    id(new_id), skill(new_skill), points_from_faculty(new_points_from_faculty){}

bool operator<(const FacultyBase& faculty_1, const FacultyBase& faculty_2) {
    if(faculty_1.id < faculty_2.id){
        return true;
    }
    return false;
}
