#define CATCH_CONFIG_MAIN  

#include "../SenderTest/catch.hpp"
#include "../Receiver/receiver.h"

receiver::rec obj;

TEST_CASE("If input is a string with special characters then output is a plain string")
{
    string input = { "expect_o , p…atronum!" };
    obj.removePunctuations(input);
    REQUIRE(input == "expecto  patronum");
}

TEST_CASE("If input is a string with digit then output is a plain string")
{
    string input = { "exp1ecto 5 patronum2" };
    obj.removeNumbers(input);
    REQUIRE(input == "expecto  patronum");
}

TEST_CASE("If input is a string with upper and lower case then output is a string with all lower case")
{
    string input = { "EXpecTo pAtROnum" };
    obj.convertToLowerCase(input);
    REQUIRE(input == "expecto patronum");
}

TEST_CASE("When a number of words with multiple spaces in between is given it counts number of different words correctly neglicting extra spaces")
{
    string input = { "  Expecto       Patronum  " };
    obj.CountWords(input);
    REQUIRE(obj.count == 2);
}

TEST_CASE("When input has has multiple occurence of a word then it acccumulates these occurrences as one while different words are treated separately")
{
    receiver::rec test_object;
    string input = { "Happy Happy Cake Cake Cake Day" };
    test_object.CountWords(input);
    REQUIRE(test_object.count == 3);

}

TEST_CASE("When we have counted frequency of each word and generate the output then we find file named map in the current directory")
{
    obj.createCSV();

    ifstream fin("map.csv");

    REQUIRE(!fin.fail() == true);
}

TEST_CASE("If there is no input then throw exception")
{
    receiver::rec empty_object;
    REQUIRE_THROWS_AS(empty_object.checkInputValidity(), std::runtime_error);
}

