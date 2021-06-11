#include <iostream>
#include "Speciality.h"

void Speciality::copy(const Speciality& other){
    name = other.name;
    disciplines = other.disciplines;
    speciality = other.speciality;
}

void Speciality::disciplinesInSpeciality(){
    switch (speciality){
    case 1:{
        
        setName("Software Engineering");
        disciplines.push_back(Discipline("DIS1", true, 1));
        disciplines.push_back(Discipline("Algebra", true, 1));
        disciplines.push_back(Discipline("UP", true, 1));
        disciplines.push_back(Discipline("DSTR", false, 1)); // make it true
        disciplines.push_back(Discipline("Bazi danni", true, 2));
        disciplines.push_back(Discipline("Algebra2", false, 2));
        disciplines.push_back(Discipline("Descriptive Geometry", false, 2));
        disciplines.push_back(Discipline("Web Technologies", true, 3));
        disciplines.push_back(Discipline("Statistics", true, 3));
        disciplines.push_back(Discipline("Kvantova informatika", false, 3));
        disciplines.push_back(Discipline("Data Mining", true, 4));
        disciplines.push_back(Discipline("E-Business", false, 4));
        break;
    }

    case 2:{
        setName("Computer Sciences");
        disciplines.push_back(Discipline("DIS1", true, 1));
        disciplines.push_back(Discipline("Algebra1", true, 1));
        disciplines.push_back(Discipline("UP", true, 1));
        disciplines.push_back(Discipline("Functional Programming", true, 2));
        disciplines.push_back(Discipline("Algebra2", true, 2));
        disciplines.push_back(Discipline("Operation Systems", true, 2));
        disciplines.push_back(Discipline("Complex analysis", false, 2));
        disciplines.push_back(Discipline("Logical programming", true, 3));
        disciplines.push_back(Discipline("Data Basis", true, 3));
        disciplines.push_back(Discipline("Cloud Startup", false, 3));
        disciplines.push_back(Discipline("Artificial Intelligence", true, 4));
        disciplines.push_back(Discipline("Vector Computer Graphics", false, 4));
        break;
    }

    case 3:{
        setName("Information Systems");
        disciplines.push_back(Discipline ("DIS1", true, 1));
        disciplines.push_back(Discipline("Algebra", true, 1));
        disciplines.push_back(Discipline("UP", true, 1));
        disciplines.push_back(Discipline("Mathemathical introduction in economics", false, 1));
        disciplines.push_back(Discipline("Data Structures", true, 2));
        disciplines.push_back(Discipline("Statistics", true, 2));
        disciplines.push_back(Discipline("Data Basis", true, 3));
        disciplines.push_back(Discipline("XML Technologies", true, 3));
        disciplines.push_back(Discipline("Hamilton Systems", false, 3));
        disciplines.push_back(Discipline("Web technologies", true, 3));
        disciplines.push_back(Discipline("E-business systems", true, 4));
        disciplines.push_back(Discipline("Embedded and autonomous systems", false, 4));
        break;
    }

    case 4:{
        setName("Informatics");
        disciplines.push_back(Discipline("DIS1", true, 1));
        disciplines.push_back(Discipline ("Analytic Geometry", true, 1));
        disciplines.push_back(Discipline ("UP", true, 1));
        disciplines.push_back(Discipline ("English1", true, 2));
        disciplines.push_back(Discipline ("Introduction in robotics", false, 2));
        disciplines.push_back(Discipline ("Design and analysis in algorithms", true, 2));
        disciplines.push_back(Discipline ("Probabilities and Statistics", true, 3));
        disciplines.push_back(Discipline ("Software documentation", false, 3));
        disciplines.push_back(Discipline ("Semantics on languages for programming", true, 3));
        disciplines.push_back(Discipline ("Computer graphics", true, 4));
        disciplines.push_back(Discipline ("Introduction to computer networks", false, 4));
        disciplines.push_back(Discipline ("Software technologies", true, 4));
        break;
    }

    default:{
        std::cout << "No such speciality in the system" << std::endl;
        break;
    }

    }
}

Speciality::Speciality(){
    name = "No name";
    speciality = NoSpeciality;
}

Speciality::Speciality(const String& _name){
    name = _name;
    speciality = NoSpeciality;
}

Speciality::Speciality(const Speciality& other){
    copy(other);
}

Speciality& Speciality::operator=(const Speciality& other){
    if(this != &other){
        copy(other);
    }
    return *this;
}

String Speciality::getSpecialityName()const{
    return name;
}

SpecialityType Speciality::getSpecialityType()const{
    return speciality;
}

size_t Speciality::getDisciplinesSize()const{
    return disciplines.getSize();
}

Discipline Speciality::getDiscipline(const size_t index)const{
    if(index < disciplines.getSize()){
        return disciplines[index];
    }
    throw std::out_of_range("Index is bigger than the size of disciplines");
}

void Speciality::setName(const String& other){
    name = other;
}

void Speciality::setSpecialityType(const SpecialityType other){
    speciality = other;
    disciplinesInSpeciality();
}

void Speciality::addDiscipline(const Discipline& add){
    disciplines.push_back(add);
}

void Speciality::print()const{
    std::cout << "Speciality's name             : " << name << std::endl;
    std::cout << "Disciplines in the speciality :" << std::endl;
    size_t size = disciplines.getSize();
    for(int i = 0; i < size;i++){
        disciplines[i].print();
    }
    std::cout << std::endl;
}

void Speciality::addGrade(size_t index,size_t add){
    disciplines[index].setGrade(add);
}

void Speciality::pop_back(){
    disciplines.pop_back();
}

std::ostream& operator<<(std::ostream& out, const Speciality& speciality){
    out << "Speciality's name             : " << speciality.name << std::endl;
    out << "Disciplines in the speciality :" << std::endl;
    size_t size = speciality.disciplines.getSize();
    for(int i = 0; i < size;i++){
        out << speciality.disciplines[i] << std::endl;
    }
    return out;
}