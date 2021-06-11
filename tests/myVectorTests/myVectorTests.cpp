#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"
#include "../../Vector.h"

TEST_CASE("Default constructor"){
    Vector<int> v1;

    CHECK(v1.getSize() == 0);
    CHECK(v1.getCapacity() == 8);

}

TEST_CASE("Constructor with parameters"){
    Vector<int> v1(20);

    CHECK(v1.getSize() == 0);
    CHECK(v1.getCapacity() == 20);
}

TEST_CASE("Push_back"){
    Vector<int> v1;
    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);

    CHECK(v1.getSize() == 9);
    CHECK(v1.getCapacity() == 16);
}

TEST_CASE("Copy constructor"){
    Vector<int> v1;
    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);

    Vector<int> v2(v1);

    
    CHECK(v2.getSize() == 9);
    CHECK(v2.getCapacity() == 16);

    v2.push_back(69);

    CHECK(v2.getSize() == 10);
    CHECK(v2.getCapacity() == 16);
}

TEST_CASE("Operator ="){
    Vector<int> v1;
    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);

    Vector<int> v2;
    v2 = v1;

    CHECK(v2.getSize() == 9);
    CHECK(v2.getCapacity() == 16);

    v2.push_back(12);

    CHECK(v2.getSize() == 10);
    CHECK(v2.getCapacity() == 16);
}

TEST_CASE("Pop_back"){
    Vector<int> v1;
    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);

    Vector<int> v2;
    v2 = v1;

    CHECK(v2.getSize() == 9);
    CHECK(v2.getCapacity() == 16);

    v2.pop_back();

    CHECK(v2.getSize() == 8);
    CHECK(v2.getCapacity() == 16);

    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();


    CHECK(v2.getSize() == 0);
    CHECK(v2.getCapacity() == 16);

    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();
    v2.pop_back();

    
    CHECK(v2.getSize() == 0);
    CHECK(v2.getCapacity() == 16);

    v2.push_back(12);

    CHECK(v2.getSize() == 1);
    CHECK(v2.getCapacity() == 16);
}

TEST_CASE("POP"){
    Vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);

    CHECK(v1.getSize() == 9);    
    CHECK(v1.getCapacity() == 16);

    v1.pop();

    CHECK(v1.getSize() == 0);    
    CHECK(v1.getCapacity() == 16);    

    v1.push_back(31);

    CHECK(v1.getSize() == 1);
    CHECK(v1.getCapacity() == 16);
}

TEST_CASE("Operator []"){
    Vector<int> v1;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    
    CHECK(v1[0] == 1);
    CHECK(v1[1] == 2);
    CHECK(v1[2] == 3);
    CHECK(v1[3] == 4);
    CHECK(v1[4] == 5);
    CHECK(v1[5] == 6);
    CHECK(v1[6] == 7);
    CHECK(v1[7] == 8);
    CHECK(v1[8] == 9);

    v1[1] = 31;
    v1[2] = 69;
    v1[3] = 3169;
    v1[4] = 369;

    CHECK(v1[1] == 31);
    CHECK(v1[2] == 69);
    CHECK(v1[3] == 3169);
    CHECK(v1[4] == 369);
}

int main(){

    doctest::Context().run();

    return 0;
}