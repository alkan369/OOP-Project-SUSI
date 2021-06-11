#pragma once
#include "Vector.h"
#include "Discipline.h"
#include "String.h"

enum SpecialityType{
    NoSpeciality,
    SoftwareEngineering,
    ComputerScience,
    InformationSystems,
    Informatics
};

class Speciality{
    private:
    String name;
    Vector<Discipline> disciplines;
    SpecialityType speciality;
    void copy(const Speciality& other);
    void disciplinesInSpeciality();

    public:
    // default and constructor with parameters, copy constructor and operator =
    Speciality();
    Speciality(const String& _name);
    Speciality(const Speciality& other);
    Speciality& operator=(const Speciality& other);

    // getters
    String getSpecialityName()const;
    SpecialityType getSpecialityType()const;
    size_t getDisciplinesSize()const;
    Discipline getDiscipline(const size_t index)const;

    // setters
    void setName(const String& other);
    void setSpecialityType(const SpecialityType other);
    
    // methods to add discipline,print method and method to add grade
    void addDiscipline(const Discipline& add);
    void print()const;
    void addGrade(size_t index,size_t add);
    
    // method to remove discipline
    void pop_back();

    // operator <<
    friend std::ostream& operator<<(std::ostream& out, const Speciality& speciality);
};