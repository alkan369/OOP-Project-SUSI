#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"
#include "../../Student.h"
#include "../../Student.cpp"
#include "../../Speciality.h"
#include "../../Speciality.cpp"
#include "../../Discipline.h"
#include "../../Discipline.cpp"
#include "../../String.h"
#include "../../String.cpp"
#include "../../myCstring.h"
#include "../../myCstring.cpp"
#include "../../Vector.h"

TEST_CASE("Default constructor"){
    Student s1;

    CHECK((s1.getName() == "No name") == true);
    CHECK(s1.getFn() == 10000);
    CHECK(s1.getGroup() == 0);
    CHECK(s1.getStatus() == Droppedout);
    CHECK(s1.getAverageGrade() == 0);
}

TEST_CASE("Contructor with parameters,copy constructor,operator ="){
    Student s1("Alkan",72018,1,Speciality("Information Systems"),1,Enrolled);

    CHECK((s1.getName() == "Alkan") == true);
    CHECK(s1.getFn() == 72018);
    CHECK(s1.getGroup() == 1);
    CHECK(s1.getStatus() == Enrolled);
    CHECK(s1.getAverageGrade() == 0);
    CHECK(s1.getSpeciality().getSpecialityName() == "Information Systems");

    Student s2(s1);

    CHECK((s2.getName() == "Alkan") == true);
    CHECK(s2.getFn() == 72018);
    CHECK(s2.getGroup() == 1);
    CHECK(s2.getStatus() == Enrolled);
    CHECK(s2.getAverageGrade() == 0);
    CHECK(s2.getSpeciality().getSpecialityName() == "Information Systems");


    Student s3;

    s3 = s2;   

    CHECK((s3.getName() == "Alkan") == true);
    CHECK(s3.getFn() == 72018);
    CHECK(s3.getGroup() == 1);
    CHECK(s3.getStatus() == Enrolled);
    CHECK(s3.getAverageGrade() == 0);
    CHECK(s3.getSpeciality().getSpecialityName() == "Information Systems");
 
}

TEST_CASE("Getters"){
    Student s1("Alkan",72018,1,Speciality("Information Systems"),1,Enrolled);

    CHECK(s1.getName() == "Alkan");
    CHECK(s1.getFn() == 72018);
    CHECK(s1.getCourse() == 1);
    CHECK(s1.getSpeciality().getSpecialityName() == "Information Systems");
    CHECK(s1.getGroup() == 1);
    CHECK(s1.getStatus() == Enrolled);
    CHECK(s1.getAverageGrade() == 0);

}

TEST_CASE("Setters"){
    Student s1;

    s1.setName("Alkan");
    s1.setFn(72018);
    s1.setCourse(1);
    s1.setSpeciality(Speciality("Information Systems"));
    s1.setGroup(1);
    s1.setStatus(Enrolled);
    CHECK(s1.getSpeciality().getSpecialityName() == "Information Systems");
    s1.setSpecialityName("Software Engineering");
    CHECK(s1.getCourse() == 1);
    s1.advanceCourse();
    CHECK(s1.getCourse() == 2);
    s1.lowerCourse();
    CHECK(s1.getCourse() == 1);
    CHECK(s1.getName() == "Alkan");
    CHECK(s1.getFn() == 72018);
    CHECK(s1.getGroup() == 1);
    CHECK(s1.getStatus() == Enrolled);
    CHECK(s1.getSpeciality().getSpecialityName() == "Software Engineering");
    CHECK(s1.getAverageGrade() == 0);

    s1.addDiscipline(Discipline("OOP",true,1));

    CHECK(s1.getSpeciality().getDisciplinesSize() == 1);
    CHECK(s1.getSpeciality().getDiscipline(0).getName() == "OOP");
    CHECK(s1.getSpeciality().getDiscipline(0).getCompulsory() == true);
    CHECK(s1.getSpeciality().getDiscipline(0).getGrade() == 2);
    CHECK(s1.getSpeciality().getDiscipline(0).getPassed() == false);

    s1.addGrade(0,6);

    CHECK(s1.getSpeciality().getDiscipline(0).getGrade() == 6);
    CHECK(s1.getSpeciality().getDiscipline(0).getPassed() == true);

    s1.pop_back();

    CHECK(s1.getSpeciality().getDisciplinesSize() == 0);

    s1.pop_back();
    s1.pop_back();
    s1.pop_back();
    s1.pop_back();
    s1.pop_back();

    CHECK(s1.getSpeciality().getDisciplinesSize() == 0);

    s1.addDiscipline(Discipline("FPR",true,1));

    CHECK(s1.getSpeciality().getDisciplinesSize() == 1);

}

int main(){

    doctest::Context().run();

    return 0;
}