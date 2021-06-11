#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"
#include "../../myCstring.h"
#include "../../myCstring.cpp"
#include "../../String.h"
#include "../../String.cpp"

TEST_CASE("Default constructor"){
    String s1;

    CHECK(s1.findLength() == 0); 
    CHECK(s1.findCapacity() == 8); 
}

TEST_CASE("Constructor with parameters"){
    String s1("Alkan");

    CHECK(s1.findLength() == 5);
    CHECK(s1.findCapacity() == 10);
    CHECK(myStrcmp(s1.getData(),"Alkan") == 0);

    String s2("");

    CHECK(s2.findLength() == 0);
    CHECK(s2.findCapacity() == 0);
    CHECK(myStrcmp(s2.getData(),"") == 0);
    
}

TEST_CASE("Copy Constructor"){
    String s1("Alkan");
    String s2(s1);

    CHECK(s1.findLength() == s2.findLength());
    CHECK(s1.findCapacity() == s2.findCapacity());
    CHECK(myStrcmp(s1.getData(),s2.getData()) == 0);
}

TEST_CASE("Operator ="){
    String s1("Alkan");
    String s2;

    CHECK(s2.findLength() == 0);
    CHECK(s2.findCapacity() == 8);

    s2 = s1;
    
    CHECK(s1.findLength() == s2.findLength());
    CHECK(s1.findCapacity() == s2.findCapacity());
    CHECK(myStrcmp(s1.getData(),s2.getData()) == 0);
}

TEST_CASE("Operator == and operator !="){
    String s1("Alkan");
    String s2("Ahmet");
    String s3(s1);

    CHECK((s1 == s2) == false);
    CHECK((s1 != s2) == true);

    s2 = s1;

    CHECK((s1 == s2) == true);
    CHECK((s1 != s2) == false);

    CHECK((s1 == s3) == true);
    CHECK((s1 != s3) == false);
}

TEST_CASE("Push_back"){
    String s1("Alkan");
    s1.push_back('3');
    CHECK(s1.findLength() == 6);
    CHECK(s1.findCapacity() == 10);
    CHECK(myStrcmp(s1.getData(),"Alkan3") == 0);
    s1.push_back('6');
    s1.push_back('9');
    s1.push_back('m');
    s1.push_back('a');
    s1.push_back('c');
    s1.push_back('h');
    s1.push_back('i');
    s1.push_back('n');
    s1.push_back('e');
    CHECK(s1.findLength() == 15);
    CHECK(s1.findCapacity() == 20);
    CHECK(myStrcmp(s1.getData(),"Alkan369machine") == 0);
}

TEST_CASE("Pop back"){
    String s1("Alkan");
    s1.pop_back();
    
    CHECK(s1.findLength() == 4);
    CHECK(s1.findCapacity() == 10);
    CHECK(myStrcmp(s1.getData(),"Alka") == 0);

    s1.pop_back();
    s1.pop_back();
    s1.pop_back();
    s1.pop_back();
    s1.pop_back();
    s1.pop_back();
    
    CHECK(s1.findLength() == 0);
    CHECK(s1.findCapacity() == 10);
    CHECK(myStrcmp(s1.getData(),"\0") == 0);
}

TEST_CASE("Operator + and operator +="){
    String s1("Alkan");
    String s2(" e mnogo gotin");
    String s3;
    String s4;

    s3 = s1 + s2;

    CHECK(myStrcmp(s3.getData(),"Alkan e mnogo gotin") == 0);
    CHECK(s3.findLength() == 19);
    CHECK(s3.findCapacity() == 20);

    s4 += s1;

    CHECK(myStrcmp(s1.getData(),"Alkan e mnogo gotin") == 0);
    CHECK(s1.findLength() == 19);
    CHECK(s1.findCapacity() == 20);

    CHECK(myStrcmp(s4.getData(),"Alkan e mnogo gotin") == 0);
    CHECK(s4.findLength() == 19);
    CHECK(s4.findCapacity() == 32);
}

TEST_CASE("Operator []"){
    String s1("Alkan");

    CHECK(s1[0] == 'A');    
    CHECK(s1[1] == 'l');    
    CHECK(s1[2] == 'k');    
    CHECK(s1[3] == 'a');    
    CHECK(s1[4] == 'n');    

    s1[2] = 'l';

    CHECK(s1[2] == 'l');
}

TEST_CASE("Shink and erase"){
    String s1("Alkan");

    CHECK(s1.findLength() == 5);
    CHECK(s1.findCapacity() == 10);

    s1.shrink();

    CHECK(s1.findLength() == 5);
    CHECK(s1.findCapacity() == 6);

    s1.erase();

    CHECK(s1.findLength() == 0);
    CHECK(s1.findCapacity() == 6);
}

int main(){

    doctest::Context().run();

    return 0;
}