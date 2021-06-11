#pragma once
#include "String.h"

class Discipline {
    private:
    String name;
    bool compulsory;
    size_t course;
    size_t grade;
    bool passed;

    public:
    
    // default and constructor with parameters
    Discipline();
    Discipline(const String& _name, bool  _compulsory, size_t _course);

    // getters
    String getName()const;
    bool getCompulsory()const;
    size_t getCourse()const;
    size_t getGrade() const;
    bool getPassed()const;

    // setters
    void setName(const String other);
    void setCompulsory(const bool other);
    void setCourse(size_t other);
    void setGrade(size_t add);

    // print method
    void print()const;

    // operator <<
    friend std::ostream& operator<<(std::ostream& out, const Discipline& discipline);

};
