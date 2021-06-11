#pragma once
#include "Speciality.h"
#include "myCstring.h"

enum Status {
    Enrolled,
    Droppedout,
    Graduated
};

class Student{
    private:
    String name;
    size_t fn;
    size_t course;
    Speciality speciality;
    size_t group;
    Status status;
    double averageGrade;
    void copy(const Student& other);
    // validation for fn (5 digits) 
    bool validFN(size_t fn);

    public:
    // default and constructor with parameters,copy constructor and operator =
    Student();
    Student(const String& _name,size_t _fn,size_t _course,const Speciality& _speciality,size_t _group,const Status& _status);
    Student(const Student& other);
    Student& operator=(const Student& other);

    // getters
    String getName()const;
    size_t getFn()const;
    size_t getCourse()const;
    Speciality getSpeciality()const;
    size_t getGroup()const;
    Status getStatus()const;
    double getAverageGrade()const;

    // setters
    void setAveragegrade();
    void setName(const String& add);
    void setFn(const size_t add);
    void setCourse(const size_t add);
    void setSpeciality(const Speciality& add);
    void setGroup(const size_t add);
    void setStatus(const Status& add);
    void setSpecialityName(const String& name);

    // methods to increase and decrease the course
    void advanceCourse();
    void lowerCourse();

    // print method
    void print()const;

    // methods to add discipline and add grade
    void addDiscipline(const Discipline& add);
    void addGrade(size_t index,size_t add);

    // method to remove discipline
    void pop_back();

    //operator <<
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
};
