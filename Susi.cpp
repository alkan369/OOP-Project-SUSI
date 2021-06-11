#include <iostream>
#include <fstream>
#include "Susi.h"

void Susi::initializeSpecialities(){
    Speciality specialitySI;
    specialitySI.setSpecialityType(SoftwareEngineering);
    Speciality specialityKn;
    specialityKn.setSpecialityType(ComputerScience);
    Speciality specialityIS;
    specialityIS.setSpecialityType(InformationSystems);
    Speciality specialityInf;
    specialityInf.setSpecialityType(Informatics);
    specialities.push_back(specialitySI);
    specialities.push_back(specialityKn);
    specialities.push_back(specialityIS);
    specialities.push_back(specialityInf);
}

void Susi::initializeCommands(){
    commands.push_back("enroll");//0
    commands.push_back("advance");//1
    commands.push_back("change");//2
    commands.push_back("graduate");//3   
    commands.push_back("interrupt");//4  
    commands.push_back("resume");//5     
    commands.push_back("print");//6
    commands.push_back("printall");//7
    commands.push_back("enrollin");//8
    commands.push_back("addgrade");//9   
    commands.push_back("protocol");//10  
    commands.push_back("report");//11    
    commands.push_back("open");//12
    commands.push_back("close");//13
    commands.push_back("save");//14
    commands.push_back("saveas");//15
    commands.push_back("help");//16
    commands.push_back("exit");//17
}

void Susi::split(){
    if (amountOfSpaces() > 0){
        size_t size = wholeCommand.findLength();
        String temp;
        for (int i = 0; i < size; i++){
            if (wholeCommand[i] == ' '){
                mainCommand = temp;
                std::cout << "The Main command is : " << std::endl;
                std::cout << mainCommand << std::endl;
                break;
            }
            temp.push_back(wholeCommand[i]);
        }
    }
    else{
        mainCommand = wholeCommand;
    }
    commandsCases();
}

size_t Susi::amountOfSpaces(){
    size_t cnt = 0;
    for(int i = 0; wholeCommand[i] != '\0'; i++){
        if(wholeCommand[i] == ' '){
            ++cnt;
        }
    }
    return cnt;
}

void Susi::commandsCases(){
    int choice = -1;
    size_t size = commands.getSize();
    for (int i = 0; i < size; i++){
        if(mainCommand == commands[i]){
            choice = i;
            break;
        }
    }
    switch (choice){
        case 0:{
            if(amountOfSpaces() >= 4){
                try{
                    enroll();
                }
                catch(const std::exception& e){
                    std::cout << e.what() << std::endl;
                }
            }
            else{
                std::cout << "The command must contain faculty number, speciality, group and student name" << std::endl;
            }
            break;
        }
        case 1:{
            if(amountOfSpaces() == 1){
                advance();
            }
            else{
                std::cout << "The command must contain only student's faculty number" << std::endl; 
            }
            break;
        }
        case 2 :{
            if(amountOfSpaces() >= 2){
                change();
            }
            else{
                std::cout << "The command must contain student's faculty number and option(program,group,year)" << std::endl; 
            }
            break;
        }
        case 3:{
            if(amountOfSpaces() == 1){
                graduate();
            }
            else{
                std::cout << "The command must contain only student's faculty number" << std::endl;
            }
            break;
        }
        case 4:{
            if(amountOfSpaces() == 1){
                interrupt();
            }
            else{
                std::cout << "The command must contain only student's faculty number" << std::endl;
            }
            break;
        }
        case 5:{
            if(amountOfSpaces() == 1){
                resume();
            }
            else{
                std::cout << "The command must contain only student's faculty number" <<std::endl;
            }
            break;
        }
        case 6:{
            if(amountOfSpaces() == 1){
                print();
            }
            else{
                std::cout << "The command must contain only student faculty number" << std::endl;
            }
            break;
        }
        case 7:{
            if(amountOfSpaces() >= 2){
                printall();
            }
            else{
                std::cout << "The command must contain only speciality and course" << std::endl;
            }
            break;
        }
        case 8:{
            if(amountOfSpaces() >= 2){
                enrollin();
            }
            else{
                std::cout << "The command must contain only a faculty number and a non-compulsory discipline" << std::endl;
            }

            break;
        }
        case 9:{
            if(amountOfSpaces() >= 3){
                addgrade();
            }
            else{
                std::cout << "The command must contain student's faculty number , discipline and grade" << std::endl;
            }
            break;
        }
        case 10:{
            if(amountOfSpaces() >= 1){
                protocol();
            }
            else{
                std::cout << "The command must contain a course" << std::endl;
            }
            break;
        }
        case 11:{
            if(amountOfSpaces() == 1){
                report();
            
            }
            else{
                std::cout << "The command must contain a student's faculty number" << std::endl;
            }
            break;
        }
        case 12:{
            if(amountOfSpaces() >= 1){ 
                open();
            }
            else{
                std::cout << "The command must contain a file's name" << std::endl;
            }
            break;
        }
        case 13:{
            std::cout << "The closing is done automatically" << std::endl;
            break;
        }
        case 14:{
            std::cout << "The saving is done automatically" << std::endl;
            break;
        }
        case 15:{
            saveas();
            break;
        }
        case 16 :{
            std::cout << "Helping..." << std::endl;
            break;
        }
        case 17:{
            std::cout << "Exitting" << std::endl;
            break;
        }
        default:{
            std::cout << "Invalid command" << std::endl;
            break;
        }
    }
}

void Susi::enroll(){
    size_t size = wholeCommand.findLength();
    size_t spaceCNT = 0;
    size_t fn = 0;
    String specialityName;
    size_t group = 0;
    String studentName;
    bool foundSpaceInSpecialityName = false;
    for(int i = 0; i < size; i++){
        if(spaceCNT == 1 && wholeCommand[i] != ' ' && wholeCommand[i] >= '0' && wholeCommand[i] <='9'){
            fn = fn * 10 + (wholeCommand[i] - '0');
        } 
        if(spaceCNT == 2){
            specialityName.push_back(wholeCommand[i]);
            if(!foundSpaceInSpecialityName && wholeCommand[i] == ' ' && !(wholeCommand[i+1] >= '0' && wholeCommand[i+1] <= '9')){
                foundSpaceInSpecialityName = true;
                --spaceCNT;
            }
        }
        if(spaceCNT >= 3 && wholeCommand[i] != ' ' && wholeCommand[i] >= '0' && wholeCommand[i] <='9'){
            group = group * 10 + (wholeCommand[i] - '0');
        }

        if(spaceCNT >= 4 && !(wholeCommand[i] >= '0' && wholeCommand[i] <='9')){
            studentName.push_back(wholeCommand[i]);
            if(wholeCommand[i] == ' '){
                --spaceCNT;
            }
        }
        if(wholeCommand[i] == ' '){
            ++spaceCNT;
        }
    }
    bool foundFn = false;
    size_t index;
    findStudent(fn, foundFn, index);
    if (foundFn){
        std::cout << "Student with such faculty number already exists" << std::endl;
        return;
    }
    
    specialityName.pop_back();
    if(!checkSpeciality(specialityName)){
        std::cout << "Invalid speciality" << std::endl;
        return;
    }
    std::cout << std::endl;
    students.push_back(Student(studentName,fn,0,Speciality(specialityName),group,Enrolled));
    index = students.getSize() - 1;
    advanceHelper(index);
    std::cout << "Enrolled Student" << std::endl;
}

void Susi::advance(){
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    fnCommands(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    advanceHelper(index);
    std::cout << "Advanced" << std::endl;
    students[index].print();
}

void Susi::change(){
    size_t size = wholeCommand.findLength();
    size_t intervalCnt = 0;
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    String choice;
    String specialityName;
    size_t group = 0;
    for(int i = 0; i < size; i++){
        if(intervalCnt == 2 && wholeCommand[i] != ' '){
            choice.push_back(wholeCommand[i]);
        }
        if(intervalCnt == 1 && wholeCommand[i] != ' ' && wholeCommand[i] >= '0' && wholeCommand[i] <= '9'){
            fn = fn * 10 + (wholeCommand[i] - '0');
        }
        if(intervalCnt >= 3){
            if(choice == "program"){
                specialityName.push_back(wholeCommand[i]);
            }
            else if(choice == "group" && wholeCommand[i] >= '0' && wholeCommand[i] <= '9'){
                group = group * 10 + (wholeCommand[i] - '0');
            }
        }
        if(wholeCommand[i] == ' '){
            ++intervalCnt;
        }
    }
    findStudent(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    if(students[index].getStatus() != Enrolled){
        std::cout << "The student has dropped out or has graduated" << std::endl;
        return;
    }
    if(choice == "year"){
        std::cout << "The student can only advance in the next year" << std::endl;
        advanceHelper(index);
    }
    else if(choice == "program"){
        if(!checkSpeciality(specialityName)){
            std::cout << "Invalid speciality" << std::endl;
            return;
        }
        bool passedAll = false;
        checkDisciplines(index,passedAll,specialityName);
        if(!passedAll){
            std::cout << "The student has not passed all compulsory disciplines" << std::endl;
            return;
        }
        students[index].setSpecialityName(specialityName);
        removeDisciplines(index);   
        students[index].lowerCourse();
        advanceHelper(index);
    }
    else if(choice == "group"){
        students[index].setGroup(group);
    }
    else{
        std::cout << "Invalid choice the choices are program,group and year" << std::endl;
    }
}

void Susi::graduate(){
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    fnCommands(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    size_t disciplinesSize = students[index].getSpeciality().getDisciplinesSize();
    for (int j = 0; j < disciplinesSize; j++){
        if (!(students[index].getSpeciality().getDiscipline(j).getPassed())){
            std::cout << "The student has not passed all of his disciplines" << std::endl;
            return;
        }
    }
    students[index].setStatus(Graduated);
}

void Susi::interrupt(){
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    fnCommands(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    students[index].setStatus(Droppedout);
}

void Susi::resume(){
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    fnCommands(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    if (students[index].getStatus() == Droppedout){
        students[index].setStatus(Enrolled);
    }
}

void Susi::print(){
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    fnCommands(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    students[index].print();
}

void Susi::printall(){
    size_t size = wholeCommand.findLength();
    String specialityName;
    size_t course;
    size_t intervalCnt = 0;
    bool foundIntervalinName = false;
    for(int i = 0; i < size; i++){
        if(intervalCnt == 1){
            specialityName.push_back(wholeCommand[i]);
            if(!foundIntervalinName && wholeCommand[i] == ' ' && !(wholeCommand[i+1] >= '0' && wholeCommand[i+1] <= '9')){
                --intervalCnt;
                foundIntervalinName = true;
            }
        }
        if(intervalCnt >= 2 && wholeCommand[i] >= '0' && wholeCommand[i] <='9'){
            course = wholeCommand[i] - '0';
        }
        if(wholeCommand[i] == ' '){
            ++intervalCnt;
        }
    }
    specialityName.pop_back();
    bool foundStudents = false;
    size_t sizeOfStudents = students.getSize();
    for(int i = 0; i < sizeOfStudents;i++){
        if(specialityName == students[i].getSpeciality().getSpecialityName() && course == students[i].getCourse()){
            students[i].print();
            foundStudents = true;
        }
    }
    if(!foundStudents){
        std::cout << "No students with this speciality and this course have been found" << std::endl;
        return;
    }
}

void Susi::enrollin(){
    size_t size = wholeCommand.findLength();
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    String disciplineName;
    size_t intervalCNT = 0;
    for(int i = 0; i < size; i++){
        if(intervalCNT == 1 && wholeCommand[i] != ' ' && wholeCommand[i] >= '0' && wholeCommand[i] <='9'){
            fn = fn * 10 + (wholeCommand[i] - '0');
        }
        if(intervalCNT == 2){
            disciplineName.push_back(wholeCommand[i]);
            if(wholeCommand[i] == ' '){
                --intervalCNT;
            }
        }
        if(wholeCommand[i] == ' '){
            ++intervalCNT;
        }
    }
    findStudent(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    if(students[index].getStatus() != Enrolled){
        std::cout << "The student has dropped out or has graduated" << std::endl;
        return;
    }
    size_t specialitySize = specialities.getSize();
    for(int i = 0; i < specialitySize;i++){
        if(students[index].getSpeciality().getSpecialityName() == specialities[i].getSpecialityName()){
            size_t disciplineSize = specialities[i].getDisciplinesSize();
            for(int j = 0; j < disciplineSize;j++){
                bool compulsory = specialities[i].getDiscipline(j).getCompulsory();
                size_t course = specialities[i].getDiscipline(j).getCourse();
                if(!compulsory && course == students[index].getCourse() && disciplineName == specialities[i].getDiscipline(j).getName()){
                    students[index].addDiscipline(specialities[i].getDiscipline(j));
                }
            }
        }
    }
}

void Susi::addgrade(){
    size_t size = wholeCommand.findLength();
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    String disciplineName;
    size_t grade;
    size_t intervalCNT = 0;
    for(int i = 0; i < size; i++){
        if(intervalCNT == 1 && wholeCommand[i] != ' ' && wholeCommand[i] >= '0' && wholeCommand[i] <= '9'){
            fn = fn * 10 + (wholeCommand[i] - '0');
        }
        if(intervalCNT == 2){
            disciplineName.push_back(wholeCommand[i]);
            if(wholeCommand[i] == ' ' && !(wholeCommand[i+1] >= '0' && wholeCommand[i+1] <= '9')){
                --intervalCNT;
            }
        }
        if(intervalCNT >= 3 && wholeCommand[i] != ' ' && wholeCommand[i] >= '0' && wholeCommand[i] <= '9'){
            grade = wholeCommand[i] - '0';
        }
        if(wholeCommand[i] == ' '){
            ++intervalCNT;
        }
    }
    if(!(grade >= 2 && grade <= 6)){
        std::cout << "The grade must be in the interval 2 and 6" << std::endl;
        return;
    }
    disciplineName.pop_back();
    findStudent(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }     
    if(students[index].getStatus() != Enrolled){
        std::cout << "This student has graduated or has dropped out" << std::endl;
        return;
    }
    size_t disciplinesSize = students[index].getSpeciality().getDisciplinesSize();
    bool enrolled = false;
    for (int j = 0; j < disciplinesSize; j++) {
        if (disciplineName == students[index].getSpeciality().getDiscipline(j).getName()){
            students[index].addGrade(j,grade);
            enrolled = true;
            std::cout << "Added grade" << std::endl;
            break;
        }
    }
    if (!enrolled){
        std::cout << "The student has not enrolled the entered discipline" << std::endl;
        return;
    }
}

void Susi::protocol(){
    size_t size = wholeCommand.findLength();
    String disciplineName;
    bool foundInterval = false;
    for(int i = 0; i < size; i++){
        if(foundInterval){
            disciplineName.push_back(wholeCommand[i]);
        }
        if(wholeCommand[i] == ' '){
            foundInterval = true;
        }
    }
    sort();
    size_t studentsSize = students.getSize();
    for(int i = 0; i < studentsSize; i++){
        size_t disciplinesSize = students[i].getSpeciality().getDisciplinesSize();
        for(int j = 0; j < disciplinesSize; j++){
            if (disciplineName == students[i].getSpeciality().getDiscipline(j).getName()){
                std::cout << "Student's name           : " << students[i].getName() << std::endl;
                std::cout << "Student's faculty number : " << students[i].getFn() << std::endl;
                std::cout << "Student's course         : " << students[i].getCourse() << std::endl;
                std::cout << "Student's speciality     : " << students[i].getSpeciality().getSpecialityName() << std::endl;
                std::cout << "Student's group          : " << students[i].getGroup() << std::endl;
                students[i].getSpeciality().getDiscipline(j).print();
            }
        }
    }
}

void Susi::report(){
    size_t fn = 0;
    bool foundFn = false;
    size_t index;
    fnCommands(fn,foundFn,index);
    if(!foundFn){
        std::cout << "Student with such faculty number has not been found" << std::endl;
        return;
    }
    students[index].print();
    students[index].setAveragegrade();
    std::cout << "Student's average grade : " << students[index].getAverageGrade() << std::endl;
}

void Susi::open(){
    String fileName;
    readSerializationCommands(fileName);
    if(doesExist(fileName)){
        std::ifstream file(fileName.getData());
        deserialize(file);
        file.close();
        std::cout << "Data has been loaded" << std::endl;
    }
    else{
        std::ofstream file(fileName.getData());
        file.close();
        std::cout << "File has been created" << std::endl;
    }
}

void Susi::saveas(){
    String fileName;
    readSerializationCommands(fileName);
    std::ofstream file(fileName.getData());
    serialize(file);
    if(file.good()){
        std::cout << "Data has been saved" << std::endl;
    }
    else{
        std::cout << "Error saving the data" << std::endl;
    }
    file.close();
}

void Susi::swap(Student& student1, Student& student2){
    Student temp(student1);
    student1 = student2;
    student2 = temp;
}

void Susi::sort(){
    size_t size = students.getSize();
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(students[i].getFn() > students[j].getFn()){
                swap(students[i],students[j]);
            }
        }
    }
}

void Susi::fnCommands(size_t& fn,bool& foundFn,size_t& index){
    size_t size = wholeCommand.findLength();
    bool foundInterval = false;
    for(int i = 0; i < size; i++){
        if(foundInterval && wholeCommand[i] >= '0' && wholeCommand[i] <= '9'){
            fn = fn * 10 + (wholeCommand[i] - '0');
        }
        if(wholeCommand[i] == ' '){
            foundInterval = true;
        }
    }
    findStudent(fn,foundFn,index);
}

void Susi::findStudent(size_t& fn,bool& foundFn,size_t& index){
    size_t studentsSize = students.getSize();
    for(int i = 0; i < studentsSize; i++){
        if(fn == students[i].getFn()){
            foundFn = true;
            index = i;
            break;
        }
    }
}

void Susi::advanceHelper(size_t index){
    students[index].advanceCourse();
    size_t specialitiesSize = specialities.getSize();
    for(int i = 0; i < specialitiesSize;i++){
        if(students[index].getSpeciality().getSpecialityName() == specialities[i].getSpecialityName()){
            size_t disciplinesSize = specialities[i].getDisciplinesSize();
            for (int j = 0; j < disciplinesSize; j++){
                bool compulsory = specialities[i].getDiscipline(j).getCompulsory();
                size_t course   = specialities[i].getDiscipline(j).getCourse();
                if(compulsory && course == students[index].getCourse()){
                    students[index].addDiscipline(specialities[i].getDiscipline(j));
                }
            }
        }
    }
}

bool Susi::checkSpeciality(String& specialityName){
    size_t specialitySize = specialities.getSize();
    for(int i = 0; i < specialitySize;i++){
        if(specialityName == specialities[i].getSpecialityName()){
            return true;
        }
    }
    return false;
}

void Susi::removeDisciplines(size_t index){
    size_t disciplineSize = students[index].getSpeciality().getDisciplinesSize();
    for(int i = disciplineSize - 1; i >= 0; i--){
        if(students[index].getSpeciality().getDiscipline(i).getCourse() == students[index].getCourse()){
            students[index].pop_back();
        }
    }
}

void Susi::checkDisciplines(const size_t& index,bool& passedAll,const String& specialityName){
    size_t specialitiesSize = specialities.getSize();
        for(int i = 0; i < specialitiesSize; i++){
            if(specialityName == specialities[i].getSpecialityName()){
                size_t disciplineSize = specialities[i].getDisciplinesSize();
                size_t studentDisciplines = students[index].getSpeciality().getDisciplinesSize();
                for(int j = 0; j < disciplineSize; j++){
                    for(int k = 0; k < studentDisciplines; k++){ 
                        String name1 = students[index].getSpeciality().getDiscipline(k).getName();
                        String name2 = specialities[i].getDiscipline(j).getName();
                        bool compulsory1 = students[index].getSpeciality().getDiscipline(k).getCompulsory();
                        bool compulsory2 = specialities[i].getDiscipline(j).getCompulsory();
                        size_t course1 = students[index].getSpeciality().getDiscipline(k).getCourse();
                        size_t course2 = specialities[i].getDiscipline(j).getCourse();
                        size_t studentCourse = students[index].getCourse();
                        if(name1 == name2 && compulsory2 && course1 < studentCourse && course2 < studentCourse ){
                            if(!students[index].getSpeciality().getDiscipline(k).getPassed()){ 
                                passedAll = false;
                                return;
                            }
                        }
                    }
                }
                passedAll = true;
                break;
            }
        }
}

bool Susi::doesExist(const String& name)const{
    std::ifstream file(name.getData());
    bool result = file.good();
    file.close();
    return result;
}

void Susi::readSerializationCommands(String& fileName){
    size_t size = wholeCommand.findLength();
    bool foundSpace = false;
    for(int i = 0; i < size; i++){
        if(foundSpace){
            fileName.push_back(wholeCommand[i]);
        }
        if(wholeCommand[i] == ' '){
            foundSpace = true;
        }
    }

}

void Susi::deserialize(std::ifstream& fileName){
    if(!fileName.is_open()){
        std::cout << "The file has not been opened" << std::endl;
        return;
    }
    students.pop();
    while(!fileName.eof()){
        size_t size;
        fileName >> size;
        for(int i = 0; i < size; i++){ 
        size_t fn;
        fileName >> fn;
        fileName.ignore();
        String specialityName;
        fileName >> specialityName;
        size_t course;
        fileName >> course;
        fileName.ignore();
        String studentName;
        fileName >> studentName;
        size_t group;
        fileName >> group;
        Status status;
        size_t st;
        fileName >> st;
        status = Status(st);
        Student student(studentName, fn, course, Speciality(specialityName), group, status);
        size_t sizeDiscipline;
        fileName >> sizeDiscipline;
        fileName.ignore();
        for (int j = 0; j < sizeDiscipline; j++){
            String disciplineName;
            fileName >> disciplineName;
            size_t grade;
            fileName >> grade;
            bool compulsory;
            fileName >> compulsory;
            size_t disciplineCourse;
            fileName >> disciplineCourse;
            student.addDiscipline(Discipline(disciplineName, compulsory, course));
            student.addGrade(j, grade);
            fileName.ignore();
        }
        students.push_back(student);
        }
        fileName.ignore();
    }
}

void Susi::serialize(std::ofstream& fileName){
    if(!fileName.is_open()){
        std::cout << "The file has not been opened" << std::endl;
        return;
    }
    fileName << students.getSize() << "\n";
    size_t size = students.getSize();
    for(int i = 0; i < size;i++){
        fileName << students[i].getFn() << "\n";
        fileName << students[i].getSpeciality().getSpecialityName() << "\n";
        fileName << students[i].getCourse() << "\n";
        fileName << students[i].getName() << "\n";
        fileName << students[i].getGroup() << "\n";
        fileName << students[i].getStatus() << "\n";
        fileName <<  students[i].getSpeciality().getDisciplinesSize() << "\n";
        size_t sizeDisciplines = students[i].getSpeciality().getDisciplinesSize();
        for(int j = 0; j < sizeDisciplines; j++){
            fileName << students[i].getSpeciality().getDiscipline(j).getName() << "\n";
            fileName << students[i].getSpeciality().getDiscipline(j).getGrade() << "\n";
            fileName << students[i].getSpeciality().getDiscipline(j).getCompulsory() << "\n";
            fileName << students[i].getSpeciality().getDiscipline(j).getCourse() << "\n";
        }
    }
}

void Susi::system(){
    initializeSpecialities();
    initializeCommands();
    std::cout << "The specialities and the disciplines are : " << std::endl;
    size_t size = specialities.getSize();
    for(int i = 0; i < size; i++){
        specialities[i].print();
    }
    do {
        size_t commandSetSize = commands.getSize();
        std::cout << "Commands are : " << std::endl;
        for (int i = 0; i < commandSetSize; i++){
            std::cout << commands[i] << std::endl;
        }
        std::cout << "Enter command : " << std::endl;
        std::cin >> wholeCommand;
        split();
    }
    while (wholeCommand != "exit");
    std::cout << "Exitted" << std::endl;
}