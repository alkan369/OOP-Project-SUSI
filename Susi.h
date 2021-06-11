#pragma once
#include "Student.h"


class Susi{
    private:
    Vector<Student> students;
    Vector<Speciality> specialities;
    Vector<String> commands;
    String wholeCommand;
    String mainCommand;

    //methonds in main system
    void initializeSpecialities();
    void initializeCommands();
    void split();
    size_t amountOfSpaces();
    void commandsCases();

    //command methods
    void enroll();
    void advance();
    void change();
    void graduate();
    void interrupt();
    void resume();
    void print();
    void printall();
    void enrollin();
    void addgrade();
    void protocol();
    void report();
    
    //serialization
    void open();
    void saveas();

    //other methods
    void swap(Student& student1, Student& student2);
    void sort();

    //fnCommands
    void fnCommands(size_t& fn,bool& foundFn,size_t& index);

    //helper methods
    void findStudent(size_t& fn,bool& foundFn,size_t& index);
    void advanceHelper(size_t index);
    bool checkSpeciality(String& specialityName);
    void removeDisciplines(size_t index);
    void checkDisciplines(const size_t& index,bool& passed,const String& specialityName);
    bool doesExist(const String& name)const;

    //serialization methods
    void readSerializationCommands(String& message);
    void deserialize(std::ifstream& fileName);
    void serialize(std::ofstream& fileName);

    public:
    void system();
};