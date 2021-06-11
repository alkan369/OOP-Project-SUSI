#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"
#include "../../myCstring.h"
#include "../../myCstring.cpp"

TEST_CASE("myStrCmp"){
    char a[] = "Alkan";
    char b[] = "Mehmet";

    CHECK(myStrcmp(a,"Alkan") == 0);

    CHECK(myStrcmp(b,"Mehmet") == 0);

    char c[] = "";
    char d[] = "\0";
    
    CHECK(myStrcmp(c,"") == 0);

    CHECK(myStrcmp(d,"\0") == 0);

    char e[] = "Alkan";

    CHECK(myStrcmp(a,e) == 0);
    CHECK(myStrcmp(b,e) != 0);

    char f[] = "alkan";
    CHECK(myStrcmp(a,f) != 0);

}


TEST_CASE("myStryCpy"){
    char a[] = "Alkan";
    char b[] = "Rocketman";

    myStrCpy(a,6,b);

    CHECK(myStrcmp(a,"Rocke") == 0);

    myStrCpy(b,10,"");

    CHECK(myStrcmp(b,"") == 0);

    char c[] = "Bigger";
    myStrCpy(c,7,a);

    CHECK(myStrcmp(c,"Rocke") == 0);

    myStrCpy(c,7,"\0");

    CHECK(myStrcmp(c,"\0") == 0);
}

TEST_CASE("MyStrlen"){
    char a[] = "Alkan";
    char b[] = "Diyarbakir";

    CHECK(myStrlen(a) == 5);
    CHECK(myStrlen(b) == 10);

    char c[] = "Burhanettin Ardagil";

    CHECK(myStrlen(c) == 19);

    char d[] = " ";

    CHECK(myStrlen(d) == 1);

    char e[] = "\0";;

    CHECK(myStrlen(e) == 0);
}


int main(){

    doctest::Context().run();


    return 0;
}