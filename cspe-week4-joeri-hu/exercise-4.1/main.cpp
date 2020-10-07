#define CATCH_CONFIG_MAIN 
#include "..\..\catch2\single_include\catch2\catch.hpp"
#include <ostream>
#include "set.hpp"

TEST_CASE("empty print") {
    set unique;
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]");
}

TEST_CASE("add one element print") {
    set unique;
    unique.add(3);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3, 0, 0, 0, 0, 0, 0, 0, 0, 0]");
}

TEST_CASE("add three elements print") {
    set unique;
    unique.add(3);
    unique.add(5);
    unique.add(7);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3, 5, 7, 0, 0, 0, 0, 0, 0, 0]");
}

TEST_CASE("add same element print") {
    set unique;
    unique.add(3);
    unique.add(3);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3, 0, 0, 0, 0, 0, 0, 0, 0, 0]");
}

TEST_CASE("contains one element") {
    set unique;
    unique.add(3);
    REQUIRE(unique.contains(3));
}

TEST_CASE("contains two elements") {
    set unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
}

TEST_CASE("not contains element") {
    set unique;
    unique.add(3);
    REQUIRE(not unique.contains(5));
}

TEST_CASE("not contains two elements") {
    set unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(not unique.contains(7));
    REQUIRE(not unique.contains(9));
}

TEST_CASE("remove element") {
    set unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
    unique.remove(3);
    REQUIRE(not unique.contains(3));
    REQUIRE(unique.contains(5));
}

TEST_CASE("remove middle element") {
    set unique;
    unique.add(3);
    unique.add(5);
    unique.add(7);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
    REQUIRE(unique.contains(7));
    unique.remove(5);
    REQUIRE(unique.contains(3));
    REQUIRE(not unique.contains(5));
    REQUIRE(unique.contains(7));
}

TEST_CASE("remove last element") {
    set unique;
    unique.add(3);
    unique.add(5);
    unique.add(7);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
    REQUIRE(unique.contains(7));
    unique.remove(7);
    unique.add(9);
    REQUIRE(not unique.contains(7));
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
    REQUIRE(unique.contains(9));    
}

TEST_CASE("remove max element") {
    set unique;
    unique.add(1);
    unique.add(2);
    unique.add(3);
    unique.add(4);
    unique.add(5);
    unique.add(6);
    unique.add(7);
    unique.add(8);
    unique.add(9);
    unique.add(10);
    REQUIRE(unique.contains(1));
    REQUIRE(unique.contains(2));
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(4));
    REQUIRE(unique.contains(5));
    REQUIRE(unique.contains(6));
    REQUIRE(unique.contains(7));
    REQUIRE(unique.contains(8));
    REQUIRE(unique.contains(9));
    REQUIRE(unique.contains(10));
    unique.remove(10);
    unique.add(20);
    REQUIRE(not unique.contains(10));
    REQUIRE(unique.contains(1));
    REQUIRE(unique.contains(2));
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(4));
    REQUIRE(unique.contains(5));
    REQUIRE(unique.contains(6));
    REQUIRE(unique.contains(7));
    REQUIRE(unique.contains(8));
    REQUIRE(unique.contains(9));
    REQUIRE(unique.contains(20));
}
