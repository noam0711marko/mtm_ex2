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
            setScore(-n->getRequiredPoints()); //remove skill points of removed skills (?)
            skills.erase(n);
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

ostream &Employee::printShort(ostream &os) const{
    printFirstLastName(os);
    os << "Salary: " << salary << " Score: " << score << endl;
    return os;
}

//code duplication - need to fix it
ostream &Employee::printLong(ostream &os) const{
    printFirstLastName(os);
    printIdBirthYear(os);
    printSalaryScore(os);
    printSkills(os);
    return os;
}

ostream &Employee::printSalaryScore(ostream& os) const {
    os << "Salary: " << salary << " Score: " << score << endl;
    return os;
}

ostream &Employee::printSkills(ostream& os) const {
    for(const shared_ptr<Skill> &n : skills){
        os << n->getName() << endl;
    }
    return os;
}

Employee* Employee::clone() const {
    Employee* copy=new Employee(*this);
    return copy;
}

using std::cout;
int main(){
    Skill s0(0,"how to have fun",0);
    string string1="C";
    Skill s1(1,string1,0);
    Skill s2(2,"C++",0);
    Skill s3(3, "Python", 1);
    Employee noam(207580994, "Noam", "Marco", 1998);
    std::cout << "\033[4:97m" <<  "Meet Noam." << "\033[0m" << endl << "Noam is a young man, and as one, he should know " << s0;
    noam.learnSkill(s0);
    if(noam.hasSkill(0)){
        cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s0;
    }
    else{
        cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s0;
    }
    cout << endl << "Noam is going to study CS at The Technion!" << endl << "Here is some details about him:" << endl;
    cout << "\033[0:93m";
    noam.printLong(cout);
    cout << "\033[0m";
    cout << endl << "Start of studying...";
    cout << endl << "Teaching Noam C..." << endl;
    noam.learnSkill(s1);
    if(noam.hasSkill(1)){
        cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s1;
    }
    else{
        cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s1;
    }
    cout << endl << "Teaching Noam C++..." << endl;
    noam.learnSkill(s2);
    if(noam.hasSkill(2)){
        cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s2;
    }
    else{
        cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s2;
    }
    cout << endl << "Noam's skills in CS are better now!" << endl << "Updating Noam's score to 1..." << endl;
    noam.setScore(1);
    if(noam.getScore()==1){
        cout << "\033[1:92m" << "Worked! " << "\033[0m" << "Noam's score updated to " << noam.getScore() << endl;
    }
    else{
        cout << "\033[1:91m" << "Didn't work! " << "\033[0m" << "Noam's score updated to " << noam.getScore() << endl;
    }
    cout << endl << "Teaching Noam Python..." << endl;
    noam.learnSkill(s3);
    if(noam.hasSkill(3)){
        cout << "\033[1:92m" << "Works! " << "\033[0m" <<  "Noam knows " << s3;
    }
    else{
        cout << "\033[1:91m" << "Doesn't work! " << "\033[0m" << "Noam doesn't know " << s3;
    }
    cout << endl << "Oh no! MATAM course trying to make Noam forget " << s0;
    noam.forgetSkill(0);
    if(noam.hasSkill(0)){
        cout << "\033[1:91m" << "It Didn't work! " << "\033[0m" << "Noam Didn't forgot " << s0;
    }
    else{
        cout << "\033[1:92m" << "It worked! " << "\033[0m" << "Noam forgot " << s0;
    }
    cout << endl << "Here is some details about Noam:" << endl;
    cout << "\033[1:93m";
    noam.printShort(cout);
    cout << "\033[0m";
    cout << endl << "Wow! Noam found his first job!" << endl << "Updating Noam's salary to 10000..." << endl;
    noam.setSalary(10000);
    if(noam.getSalary()==10000){
        cout << "\033[1:32m" << "It worked! " << "\033[0m" << "Noam's salary updated to " << noam.getSalary() << endl;
    }
    else{
        cout << "\033[1:91m" << "It Didn't work! " << "\033[0m" << "Noam's salary is still " << noam.getSalary() << endl;
    }
    cout << endl << "Noam's long details:" << endl;
    cout << "\033[1:93m";
    noam.printLong(cout);
    cout << "\033[0m";
    Employee* ptr=noam.clone();
    Employee noam2 = *ptr;
    cout << endl << endl << "\033[4:97m" <<  "Meet Noam's clone." << "\033[0m" << endl << "here is some details about him: " << endl;
    cout << "\033[0:95m";
    noam2.printLong(cout);
    cout << "\033[0m";
    cout << endl << "Oh no! it seems to be a bug which deletes skills from Noam's clone!" << endl;
    for (int i=1; i<=3; ++i){
        noam2.forgetSkill(i);
    }
    cout << "Noam's clone details right now:" << endl;
    cout << "\033[0:95m";
    noam2.printLong(cout);
    cout << "\033[0m";
    cout << endl << "Lets make sure Noam still have his skills:" << endl;
    cout << "\033[0:93m";
    noam.printLong(cout);
    cout << "\033[0m";
    cout << endl << "That's a relief! Noam's clone was just a copy!" << endl;
    delete(ptr);
}

