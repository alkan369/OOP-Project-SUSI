#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"
#include "../../Speciality.h"
#include "../../Speciality.cpp"
#include "../../Discipline.h"
#include "../../Discipline.cpp"
#include "../../String.h"
#include "../../String.cpp"
#include "../../Vector.h"
#include "../../myCstring.h"
#include "../../myCstring.cpp"

TEST_CASE("Default constructor"){
    Speciality s1;

    CHECK((s1.getSpecialityName() == "No name") == true);
    CHECK(s1.getSpecialityType() == NoSpeciality);
    CHECK(s1.getDisciplinesSize() == 0);
}

TEST_CASE("Constructor with parameters,copy constructor and operator ="){
    Speciality s1("Information Systems");
    Speciality s2(s1);
    Speciality s3;

    s3 = s1;

    CHECK((s2.getSpecialityName() == s1.getSpecialityName()) == true);
    CHECK((s2.getDisciplinesSize() == s1.getDisciplinesSize()) == true);
    CHECK((s2.getSpecialityType() == s1.getSpecialityType()) == true);

    CHECK((s3.getSpecialityName() == s1.getSpecialityName()) == true);
    CHECK((s3.getDisciplinesSize() == s1.getDisciplinesSize()) == true);
    CHECK((s3.getSpecialityType() == s1.getSpecialityType()) == true);

}

TEST_CASE("Getters"){
    Speciality s1("Software Engineering");
    
    s1.setSpecialityType(SoftwareEngineering);

    CHECK((s1.getDiscipline(0).getName() == "DIS1") == true);
    CHECK(s1.getDiscipline(0).getCompulsory() == true);
    CHECK(s1.getDiscipline(0).getCourse() == 1);
    CHECK(s1.getDiscipline(0).getGrade() == 2);
    CHECK(s1.getDiscipline(0).getPassed() == false);

}

TEST_CASE("Setters"){
    Speciality s1;

    s1.setName("Informatics");
    s1.setSpecialityType(Informatics);
    
    CHECK((s1.getSpecialityName() == "Informatics") == true);
    CHECK(s1.getDisciplinesSize() == 12);

    s1.addDiscipline(Discipline("FPR",true,4));

    CHECK(s1.getDisciplinesSize() == 13);

    s1.addGrade(0,6);

    CHECK(s1.getDiscipline(0).getGrade() == 6);
    CHECK(s1.getDiscipline(0).getPassed() == true);

    s1.pop_back();

    CHECK(s1.getDisciplinesSize() == 12);
}

int main(){

    doctest::Context().run();

    return 0;
}