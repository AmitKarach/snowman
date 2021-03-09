/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good snowman code") {
    // CHECK(snowman(11114411) == string("    \n_===_\n (.,.) \n( : )\n( : )"));
    //check the base
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(11111112) == string("     \n_===_\n (.,.) \n<( : )>\n(" ")"));
    CHECK(snowman(11111113) == string("     \n_===_\n (.,.) \n<( : )>\n(___)"));
    CHECK(snowman(11111114) == string("     \n_===_\n (.,.) \n<( : )>\n(   )"));


    //check the Belly
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(11111121) == string("     \n_===_\n (.,.) \n<(] [)>\n( : )"));
    CHECK(snowman(11111131) == string("     \n_===_\n (.,.) \n<(> <)>\n( : )"));
    CHECK(snowman(11111141) == string("     \n_===_\n (.,.) \n<(] [)>\n( : )"));

    //check the right hand
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(11111211) == string("     \n_===_\n (.,.)/\n<( : ) \n( : )"));
    CHECK(snowman(11111311) == string("     \n_===_\n (.,.) \n<( : )\\\n( : )"));
    CHECK(snowman(11111411) == string("     \n_===_\n (.,.) \n<( : ) \n( : )"));
    
    //check the left hand
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(11112111) == string("     \n_===_\n\\(.,.) \n ( : )>\n( : )"));
    CHECK(snowman(11113111) == string("     \n_===_\n (.,.) \n/( : )>\n( : )"));
    CHECK(snowman(11114111) == string("     \n_===_\n (.,.) \n ( : )>\n( : )"));

    //check the right eye
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(11121111) == string("     \n_===_\n (.,o) \n<( : )>\n( : )"));
    CHECK(snowman(11131111) == string("     \n_===_\n (.,O) \n<( : )>\n( : )"));
    CHECK(snowman(11141111) == string("     \n_===_\n (.,-) \n<( : )>\n( : )"));

    //check the left eye
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(11211111) == string("     \n_===_\n (o,.) \n<( : )>\n( : )"));
    CHECK(snowman(11311111) == string("     \n_===_\n (O,.) \n<( : )>\n( : )"));
    CHECK(snowman(11411111) == string("     \n_===_\n (-,.) \n<( : )>\n( : )"));

    //check the nose
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(12111111) == string("     \n_===_\n (...) \n<( : )>\n( : )"));
    CHECK(snowman(13111111) == string("     \n_===_\n (._.) \n<( : )>\n( : )"));
    CHECK(snowman(14111111) == string("     \n_===_\n (. .) \n<( : )>\n( : )"));

    //chek the hat
    CHECK(snowman(11111111) == string("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(21111111) == string(" ___ \n.....\n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(31111111) == string("  _  \n /_\\ \n (.,.) \n<( : )>\n( : )"));
    CHECK(snowman(41111111) == string(" ___ \n(_*_)\n (.,.) \n<( : )>\n( : )"));

}

TEST_CASE("not a legal entary") {
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111511));
    CHECK_THROWS(snowman(11115111));
    CHECK_THROWS(snowman(11151111));
    CHECK_THROWS(snowman(11511115));
    CHECK_THROWS(snowman(15111115));
    CHECK_THROWS(snowman(51111115));
}

TEST_CASE("not enough numbers") {
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1511111));    
}

TEST_CASE("a negative number entery") {
    CHECK_THROWS(snowman(1111111-5));
    CHECK_THROWS(snowman(111111-15));
    CHECK_THROWS(snowman(11111-115));
    CHECK_THROWS(snowman(1111-1115));
    CHECK_THROWS(snowman(111-11115));
    CHECK_THROWS(snowman(11-111115));
    CHECK_THROWS(snowman(1-1111115));
    CHECK_THROWS(snowman(-11111115));
}