#include <iostream>
#include <exception>
#include "Discipline.h"

Discipline::Discipline(){
    name = "No name";
    compulsory = false;
    course = 0;
    grade = 2;
    passed = false;
}

Discipline::Discipline(const String& _name, bool _compulsory,size_t _course){
    name = _name;
    compulsory = _compulsory;
    course = _course;
    grade = 2;
    passed = false;
}

String Discipline::getName()const{
    return name;
}

bool Discipline::getCompulsory()const{
    return compulsory;
}

size_t Discipline::getCourse()const{
    return course;
}

size_t Discipline::getGrade()const{
    return grade;
}

bool Discipline::getPassed()const{
    return passed;
}

void Discipline::setName(const String other){
    name = other;
}
void Discipline::setCompulsory(const bool other){
    compulsory = other;
}

void Discipline::setCourse(size_t other){
    course = other;
}

void Discipline::setGrade(size_t add){
    if (add >= 2 && add <= 6){
        grade = add;
        if (grade >= 3 && grade <= 6){
            passed = true;
        }
        else{
        passed = false;
    }
        return;
    }
    throw std::out_of_range("The grade must be between 2 and 6");
}

void Discipline::print()const{
    std::cout << "Name of Discipline : " << name << std::endl;
    std::cout << "Compulsory         : " << std::boolalpha << compulsory << std::endl;
    std::cout << "Course             : " << course << std::endl;
    std::cout << "Grade              : " << grade << std::endl;
    std::cout << "Passed             : " << std::boolalpha << passed << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Discipline& discipline){
    out << "Discipline name : " << discipline.name << std::endl;
    out << "Compulsory      : " << std::boolalpha << discipline.compulsory << std::endl;
    out << "Course          : " << discipline.course << std::endl;
    out << "Grade           : " << discipline.grade << std::endl;
    out << "Passed          : " << std::boolalpha << discipline.passed << std::endl;
    return out;
}