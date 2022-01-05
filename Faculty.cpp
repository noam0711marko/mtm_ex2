#include "Faculty.h"

bool operator<(const Faculty<Condition>& faculty_1, const Faculty<Condition>& faculty_2) {
    if(faculty_1.id < faculty_2.id){
        return true;
    }
    return false;
}