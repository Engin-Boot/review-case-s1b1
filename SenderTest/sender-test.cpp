#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "../Sender/FileReader.h"

using namespace std;

TEST_CASE("when openFile() is called then it opens the respective file, provided the file exists") {
    FileReader::File fobj;
    SECTION("when openFile() is given a filename which does not exist then output appropriate message and exit gracefully") {
        REQUIRE_THROWS_AS(fobj.openFile("report.csv"), runtime_error);
    }
    SECTION("when openFile() is given a valid filename then the respective file is opened") {
        fobj.openFile("sample-review/review-report.csv");
        REQUIRE(fobj.fin.good() == true);
    }
    SECTION("when openFile() is given no filename then the default file is opened") {
        fobj.openFile();
        REQUIRE(fobj.fin.good() == true);
    }
}

TEST_CASE("when readHeader() is called then index gets the positional value where 'Comments' is present in the header") {
    FileReader::File fobj;
    fobj.openFile("SenderTest/HeaderCheck.csv");
    fobj.readHeader();
    REQUIRE((fobj.index + 1) == 4); // add 1 to the index value as positioning index begins with 0
}

TEST_CASE("when checkForComment() is called then the comment is searched for and picked and stored from a particular record") {
    FileReader::File fobj;
    fobj.openFile("SenderTest/RecordCheck.csv");
    fobj.readHeader();
    string line = "5/13/2020 15:50,remove this log if not required";
    vector <string> row = { "5/13/2020 15:50","remove this log if not required" };
    fobj.checkForComment(line, row);
    vector<string> words = { "remove this log if not required" };
    REQUIRE(fobj.comments == words);    // comment from the line is stored in the global variable 'comments'
}

TEST_CASE("when checkLine() is called then each comma-separated word from a particular line are read and the comment from that line is stored in the global variable 'comments'") {
    FileReader::File fobj;
    fobj.openFile("SenderTest/RecordCheck.csv");
    fobj.readHeader();
    string line = "5/13/2020 15:50,remove this log if not required";
    fobj.checkLine(line, {});
    vector<string> words = { "remove this log if not required" };
    REQUIRE(fobj.comments == words);    // comment from the line is stored in the global variable 'comments'
}

TEST_CASE("when readRecords() is called then the comments are read from each record") {
    FileReader::File fobj;
    fobj.openFile("SenderTest/RecordCheck.csv");
    fobj.readHeader();
    fobj.readRecords();
    vector <string> records = { "change spelling", "remove this log if not required", "Don't use static context",
        "remove this log if not required", "verify the string ", "please add test cases for firebase performance"};
    REQUIRE(fobj.comments == records);
}
