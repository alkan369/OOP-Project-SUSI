#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"
#include "../../Discipline.h"
#include "../../Discipline.cpp"
#include "../../String.h"
#include "../../String.cpp"
#include "../../myCstring.h"
#include "../../myCstring.cpp"

TEST_CASE("Default constructor"){
    Discipline d1;
    
    CHECK((d1.getName() == "No name") == true);
    CHECK(d1.getCompulsory() == false);
    CHECK(d1.getCourse() == 0);
    CHECK(d1.getGrade() == 2);
    CHECK(d1.getPassed() == false);
}

TEST_CASE("Constructor with parameters,Copy constructor and operator = (default ones)"){
    Discipline d1("UP",true,1);

    CHECK((d1.getName() == "UP") == true);
    CHECK(d1.getCompulsory() == true);
    CHECK(d1.getCourse() == 1);
    CHECK(d1.getGrade() == 2);
    CHECK(d1.getPassed() == false);

    Discipline d2;
    d2 = d1;

    CHECK((d2.getName() == "UP") == true);
    CHECK(d2.getCompulsory() == true);
    CHECK(d2.getCourse() == 1);
    CHECK(d2.getGrade() == 2);
    CHECK(d2.getPassed() == false);

    Discipline d3(d1);

    CHECK((d3.getName() == "UP") == true);
    CHECK(d3.getCompulsory() == true);
    CHECK(d3.getCourse() == 1);
    CHECK(d3.getGrade() == 2);
    CHECK(d3.getPassed() == false);

}

TEST_CASE("Getters"){
    Discipline d1("Algebra",true,1);

    CHECK((d1.getName() == "Algebra") == true);
    CHECK(d1.getCompulsory() == true);
    CHECK(d1.getCourse() == 1);
    CHECK(d1.getGrade() == 2);
    CHECK(d1.getPassed() == false);
}

TEST_CASE("Setters"){
    Discipline d1("DIS1",true,1);

    d1.setName("OOP");
    d1.setCourse(2);
    d1.setCompulsory(false);
    d1.setGrade(2);

    CHECK((d1.getName() == "OOP") == true);
    CHECK(d1.getCourse() == 2);
    CHECK(d1.getCompulsory() == false);
    CHECK(d1.getGrade() == 2);
    CHECK(d1.getPassed() == false);

    d1.setGrade(6);

    CHECK(d1.getGrade() == 6);
    CHECK(d1.getPassed() == true);

}

int main(){

    doctest::Context().run();
    return 0;
}