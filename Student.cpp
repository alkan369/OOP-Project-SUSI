#include <iostream>
#include "Student.h"
#include <exception>


void Student::copy(const Student& other){
    name = other.name;
    fn = other.fn;
    course = other.course;
    speciality = other.speciality;
    group = other.group;
    status = other.status;
    averageGrade = other.averageGrade;
}

bool Student::validFN(size_t _fn){ 
    return _fn / 10000 > 0 && _fn / 10000 <= 9;
}

Student::Student(){
    name = "No name";
    fn = 10000;
    group = 0;
    status = Droppedout;
    averageGrade = 0;
}

Student::Student(const String& _name,size_t _fn,size_t _course,const Speciality& _speciality,size_t _group,const Status& _status){
    name = _name;
    if(!validFN(_fn)){
        throw std::invalid_argument("Invalid faculty number");
    }
    fn = _fn;
    course = _course;
    speciality = _speciality;
    group = _group;
    status = _status;
    averageGrade = 0;
}

Student::Student(const Student& other){
    copy(other);
}

Student& Student::operator=(const Student& other){
    if(this != &other){
        copy(other);
    }
    return *this;
}

String Student::getName() const{
    return name;
}

size_t Student::getFn() const{
    return fn;
}

size_t Student::getCourse() const{
    return course;
}

Speciality Student::getSpeciality() const{
    return speciality;
}

size_t Student::getGroup()const{
    return group;
}

Status Student::getStatus() const{
    return status;
}

double Student::getAverageGrade() const{
    return averageGrade;
}

void Student::setAveragegrade(){
    size_t size = speciality.getDisciplinesSize();
    size_t grades = 0;
    size_t cntGrade = 0;
    for(int i = 0; i < size;i++){
        grades = grades + speciality.getDiscipline(i).getGrade();
        ++cntGrade;
    }
    averageGrade = double(grades) / double(cntGrade);
}

void Student::setName(const String& add){
    name = add;
}

void Student::setFn(const size_t add){
    if (validFN(add)){
        fn = add;
        return;
    }
    throw std::invalid_argument("The faculty number must be 5 digit number");
}

void Student::setCourse(const size_t add){
    course = add;
}

void Student::setSpeciality(const Speciality& add){
    speciality = add;
}

void Student::setGroup(const size_t add){
    group = add;
}

void Student::setStatus(const Status& add){
    status = add;
}

void Student::setSpecialityName(const String& name){
    speciality.setName(name);
}

void Student::advanceCourse(){
    ++course;
}

void Student::lowerCourse(){
    --course;
}

void Student::print()const{
    std::cout << "Student's name        : " << name << std::endl;
    std::cout << "Student's fn          : " << fn << std::endl;
    std::cout << "Student's course      : " << course << std::endl;
    std::cout << "Student's speciality  : " << speciality.getSpecialityName() << std::endl;
    std::cout << "Student's group       : " << group << std::endl;
    std::cout << "Student's disciplines : " << std::endl;
    speciality.print();
}

void Student::addDiscipline(const Discipline& add){
    speciality.addDiscipline(add);
}

void Student::addGrade(size_t index,size_t add){
    speciality.addGrade(index,add);
}

void Student::pop_back(){
    speciality.pop_back();
}

std::ostream& operator<<(std::ostream& out, const Student& student){
    out << "Student's name        : " << student.name << std::endl;
    out << "Student's fn          : " << student.fn << std::endl;
    out << "Student's course      : " << student.course << std::endl;
    out << "Student's speciality  : " << student.speciality.getSpecialityName() << std::endl;
    out << "Student's disciplines : " << std::endl;
    out << student.speciality << std::endl;
    return out;
}