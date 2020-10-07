#define CATCH_CONFIG_MAIN 
#include "..\..\catch2\single_include\catch2\catch.hpp"
#include <ostream>
#include <array>
#include "set.hpp"

// =============== default instantiation: <int, 10> =================
TEST_CASE("empty print") {
    set unique;
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[]");
}

TEST_CASE("add one element print") {
    set unique;
    unique.add(3);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3]");
}

TEST_CASE("add three elements print") {
    set unique;
    unique.add(3);
    unique.add(5);
    unique.add(7);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3, 5, 7]");
}

TEST_CASE("add same element print") {
    set unique;
    unique.add(3);
    unique.add(3);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3]");
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

TEST_CASE("find max element") {
    set unique;
    unique.add(3);
    unique.add(5);
    unique.add(7);
    REQUIRE(unique.max() == 7);
}


// =============== instantiation: <char, 5> =================
TEST_CASE("empty print, <char, 5>") {
    set<char, 5> unique;
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[]");
}

TEST_CASE("add one element print, <char, 5>") {
    set<char, 5> unique;
    unique.add('a');
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[a]");
}

TEST_CASE("add three elements print, <char, 5>") {
    set<char, 5> unique;
    unique.add('a');
    unique.add('b');
    unique.add('c');
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[a, b, c]");
}

TEST_CASE("add same element print, <char, 5>") {
    set<char, 5> unique;
    unique.add('a');
    unique.add('a');
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[a]");
}

TEST_CASE("contains one element, <char, 5>") {
    set<char, 5> unique;
    unique.add('c');
    REQUIRE(unique.contains('c'));
}

TEST_CASE("contains two elements, <char, 5>") {
    set<char, 5> unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
}

TEST_CASE("not contains element, <char, 5>") {
    set<char, 5> unique;
    unique.add(3);
    REQUIRE(not unique.contains(5));
}

TEST_CASE("not contains two elements, <char, 5>") {
    set<char, 5> unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(not unique.contains(7));
    REQUIRE(not unique.contains(9));
}

TEST_CASE("remove element, <char, 5>") {
    set<char, 5> unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
    unique.remove(3);
    REQUIRE(not unique.contains(3));
    REQUIRE(unique.contains(5));
}

TEST_CASE("remove middle element, <char, 5>") {
    set<char, 5> unique;
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

TEST_CASE("remove last element, <char, 5>") {
    set<char, 5> unique;
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

TEST_CASE("remove max element, <char, 5>") {
    set<char, 5> unique;
    unique.add(1);
    unique.add(2);
    unique.add(3);
    unique.add(4);
    unique.add(5);
    REQUIRE(unique.contains(1));
    REQUIRE(unique.contains(2));
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(4));
    REQUIRE(unique.contains(5));
    unique.remove(5);
    unique.add(10);
    REQUIRE(not unique.contains(5));
    REQUIRE(unique.contains(1));
    REQUIRE(unique.contains(2));
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(4));
    REQUIRE(unique.contains(10));
}

TEST_CASE("find max element, <char, 5>") {
    set<char, 5> unique;
    unique.add('a');
    unique.add('b');
    unique.add('c');
    REQUIRE(unique.max() == 'c');
}

// =============== instantiation: <double, 12> =================
TEST_CASE("empty print, <double, 12>") {
    set<double, 12> unique;
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[]");
}

TEST_CASE("add one element print, <double, 12>") {
    set<double, 12> unique;
    unique.add(3);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3]");
}

TEST_CASE("add three elements print, <double, 12>") {
    set<double, 12> unique;
    unique.add(3);
    unique.add(5);
    unique.add(7);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3, 5, 7]");
}

TEST_CASE("add same element print, <double, 12>") {
    set<double, 12> unique;
    unique.add(3);
    unique.add(3);
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[3]");
}

TEST_CASE("contains one element, <double, 12>") {
    set<double, 12> unique;
    unique.add(3.3);
    REQUIRE(unique.contains(3.3));
}

TEST_CASE("contains two elements, <double, 12>") {
    set<double, 12> unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
}

TEST_CASE("not contains element, <double, 12>") {
    set<double, 12> unique;
    unique.add(3);
    REQUIRE(not unique.contains(5));
}

TEST_CASE("not contains two elements, <double, 12>") {
    set<double, 12> unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(not unique.contains(7));
    REQUIRE(not unique.contains(9));
}

TEST_CASE("remove element, <double, 12>") {
    set<double, 12> unique;
    unique.add(3);
    unique.add(5);
    REQUIRE(unique.contains(3));
    REQUIRE(unique.contains(5));
    unique.remove(3);
    REQUIRE(not unique.contains(3));
    REQUIRE(unique.contains(5));
}

TEST_CASE("remove middle element, <double, 12>") {
    set<double, 12> unique;
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

TEST_CASE("remove last element, <double, 12>") {
    set<double, 12> unique;
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

TEST_CASE("remove max element, <double, 12>") {
    set<double, 12> unique;
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
    unique.add(11);
    unique.add(12);
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
    REQUIRE(unique.contains(11));
    REQUIRE(unique.contains(12));
    unique.remove(12);
    unique.add(22);
    REQUIRE(not unique.contains(12));
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
    REQUIRE(unique.contains(11));
    REQUIRE(unique.contains(22));
}

TEST_CASE("find max element, <double, 12>") {
    set<double, 12> unique;
    unique.add(3.3);
    unique.add(5.5);
    unique.add(7.7);
    REQUIRE(unique.max() == 7.7);
}

// =============== instantiation: <std::array<char, 3>, 7> =================
using string = std::array<char, 3>;

TEST_CASE("empty print, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[]");
}

TEST_CASE("add one element print, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[[a, b]]");
}

TEST_CASE("add three elements print, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"cd"});
    unique.add(string{"ef"});
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[[a, b], [c, d], [e, f]]");
}

TEST_CASE("add same element print, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"ab"});
    std::stringstream stream;
    stream << unique;
    REQUIRE(stream.str() == "[[a, b]]");
}

TEST_CASE("contains one element, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    REQUIRE(unique.contains(string{"ab"}));
}

TEST_CASE("contains two elements, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"cd"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
}

TEST_CASE("not contains element, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    REQUIRE(not unique.contains(string{"cd"}));
}

TEST_CASE("not contains two elements, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"cd"});
    REQUIRE(not unique.contains(string{"ef"}));
    REQUIRE(not unique.contains(string{"gh"}));
}

TEST_CASE("remove element, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"cd"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
    unique.remove(string{"ab"});
    REQUIRE(not unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
}

TEST_CASE("remove middle element, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"cd"});
    unique.add(string{"ef"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
    REQUIRE(unique.contains(string{"ef"}));
    unique.remove(string{"cd"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(not unique.contains(string{"cd"}));
    REQUIRE(unique.contains(string{"ef"}));
}

TEST_CASE("remove last element, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"cd"});
    unique.add(string{"ef"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
    REQUIRE(unique.contains(string{"ef"}));
    unique.remove(string{"ef"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
    REQUIRE(not unique.contains(string{"ef"}));  
}

TEST_CASE("remove max element, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"ab"});
    unique.add(string{"cd"});
    unique.add(string{"ef"});
    unique.add(string{"gh"});
    unique.add(string{"ij"});
    unique.add(string{"kl"});
    unique.add(string{"mn"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
    REQUIRE(unique.contains(string{"ef"}));
    REQUIRE(unique.contains(string{"gh"}));
    REQUIRE(unique.contains(string{"ij"}));
    REQUIRE(unique.contains(string{"kl"}));
    REQUIRE(unique.contains(string{"mn"}));
    unique.remove(string{"mn"});
    REQUIRE(unique.contains(string{"ab"}));
    REQUIRE(unique.contains(string{"cd"}));
    REQUIRE(unique.contains(string{"ef"}));
    REQUIRE(unique.contains(string{"gh"}));
    REQUIRE(unique.contains(string{"ij"}));
    REQUIRE(unique.contains(string{"kl"}));
    REQUIRE(not unique.contains(string{"mn"}));
}

TEST_CASE("find max element, <std::array<char, 3>, 7>") {
    set<string, 7> unique;
    unique.add(string{"aa"});
    unique.add(string{"ab"});
    unique.add(string{"ac"});
    REQUIRE(unique.max() == string{"ac"});
}
