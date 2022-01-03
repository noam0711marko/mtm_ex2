#include "Employee.h"

#include <iostream>

using std::endl;

Employee::Employee(int new_id, const string &new_first_name, const string &new_last_name, int new_year) : Citizen(
        new_id, new_first_name, new_last_name, new_year), salary(0), score(0), skills() {}

int Employee::getSalary() const {
    return salary;
}

int Employee::getScore() const {
    return score;
}

void Employee::learnSkill(const Skill& to_add) {
    if(hasSkill(to_add.getId())){
        throw SkillAlreadyLearned();
    }
    if(to_add.getRequiredPoints()>score){
        throw CanNotLearnSkill();
    }
    skills.insert(shared_ptr<Skill>(new Skill(to_add)));
    setScore(to_add.getRequiredPoints());
}

void Employee::forgetSkill(const int &id_to_forget) {
    for(const shared_ptr<Skill> &n : skills){
        if(n->getId()==id_to_forget){
            skills.erase(n);
            setScore(-n->getRequiredPoints()); //remove skill points of removed skills (?)
            return;
        }
    }
    throw DidNotLearnSkill();
}

bool Employee::hasSkill(int id) {
    for(const shared_ptr<Skill> &n : skills){
        if(n->getId()==id){
            return true;
        }
    }
    return false;
}

void Employee::setSalary(int add_to_salary) {
    salary+=add_to_salary;
}

void Employee::setScore(int add_to_score) {
    score+=add_to_score;
}

ostream &Employee::printShort(ostream &out) const{
    out << "Short_Print" << endl;
    printFirstLastName(out);
    out << "Salary: " << salary << " Score: " << score << endl;
    return out;
}

//code duplication - need to fix it
ostream &Employee::printLong(ostream &out) const{
    out << "Long_Print" << endl;
    printFirstLastName(out);
    printIdBirthYear(out);
    printSalaryScore(out);
    printSkills(out);
    return out;
}

ostream &Employee::printSalaryScore(ostream& out) const {
    out << "Salary: " << salary << " Score: " << score << endl;
    return out;
}

ostream &Employee::printSkills(ostream& out) const {
    for(const shared_ptr<Skill> &n : skills){
        out << n->getName() << endl;
    }
    return out;
}

Employee* Employee::clone() const {
    Employee* copy=new Employee(*this);
    return copy;
}


int main(){
    Skill s0(0,"how to have fun",0);
    std::string string1="C";
    Skill s1(1,string1,0);
    Skill s2(2,"C++",0);
    Skill s3(3, "Python", 1);
    Employee noam(207580994, "Noam", "Marco", 1998);
    std::cout << "\033[4:97m" <<  "Meet Noam." << "\033[0m" << endl << "Noam is a young man, and as one, he should know " << s0;
    noam.learnSkill(s0);
    if(noam.hasSkill(0)){
        std::cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s0;
    }
    else{
        std::cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s0;
    }
    std::cout << endl << "Noam is going to study CS at The Technion!" << endl << "Here is some details about him:" << endl;
    std::cout << "\033[0:93m";
    noam.printLong(std::cout);
    std::cout << "\033[0m";
    std:: cout << endl << "Start of studying...";
    std::cout << endl << "Teaching Noam C..." << endl;
    noam.learnSkill(s1);
    if(noam.hasSkill(1)){
        std::cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s1;
    }
    else{
        std::cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s1;
    }
    std::cout << endl << "Teaching Noam C++..." << endl;
    noam.learnSkill(s2);
    if(noam.hasSkill(2)){
        std::cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s2;
    }
    else{
        std::cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s2;
    }
    std::cout << endl << "Noam's skills in CS are better now!" << endl << "Updating Noam's score to 1..." << endl;
    noam.setScore(1);
    if(noam.getScore()==1){
        std::cout << "\033[1:92m" << "Worked! " << "\033[0m" << "Noam's score updated to " << noam.getScore() << endl;
    }
    else{
        std::cout << "\033[1:91m" << "Didn't work! " << "\033[0m" << "Noam's score updated to " << noam.getScore() << endl;
    }
    std::cout << endl << "Teaching Noam Python..." << endl;
    noam.learnSkill(s3);
    if(noam.hasSkill(3)){
        std::cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s3;
    }
    else{
        std::cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s3;
    }
    std::cout << endl << "Oh no! Matam course trying to make Noam forget " << s0;
    noam.forgetSkill(0);
    if(noam.hasSkill(0)){
        std::cout << "\033[1:91m" << "It Didn't work! " << "\033[0m" << "Noam Didn't forgot " << s0;
    }
    else{
        std::cout << "\033[1:92m" << "It worked! " << "\033[0m" << "Noam forgot " << s0;
    }
    std::cout << endl << "Here is some details about Noam:" << endl;
    std::cout << "\033[1:93m";
    noam.printShort(std::cout);
    std::cout << "\033[0m";
    std::cout << endl << "Wow! Noam found his first job!" << endl << "Updating Noam's salary to 10000..." << endl;
    noam.setSalary(10000);
    if(noam.getSalary()==10000){
        std::cout << "\033[1:32m" << "It worked! " << "\033[0m" << "Noam's salary updated to " << noam.getSalary() << endl;
    }
    else{
        std::cout << "\033[1:91m" << "It Didn't work! " << "\033[0m" << "Noam's salary is still " << noam.getSalary() << endl;
    }
    std::cout << endl << "Noam's long details:" << endl;
    std::cout << "\033[1:93m";
    noam.printLong(std::cout);
    std::cout << "\033[0m";
}

