#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "FileReader.h"

using namespace std;

void FileReader::File::openFile(string filename)
{
        FileReader::File::fin.open(filename);
        // Make sure the file is open
        if (!fin) throw runtime_error("File does not exist");
}

void FileReader::File::readHeader()
{
    int pos = 0;
    vector<string> row;
    string line, word;
    getline(fin, line);
    stringstream s(line);
    while (getline(s, word, ','))
    {
        if (word == "Comments")
            FileReader::File::index = pos;
        row.push_back(word);
        pos++;
    }
}

vector<string> FileReader::File::readRecords()
{
    
    string line;
    while (fin.good())
    {
        vector<string> row;
        getline(fin, line);
        checkLine(line, row);
    }
    return comments;
}

void FileReader::File::checkLine(const string& line,vector<string> row)
{
    string word;
    stringstream s(line);
    
    if (line.find(',') != string::npos)
    {
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        checkForComment(line, row);
    }
    else
        comments[comments.size() - 1] = comments[comments.size() - 1] + line;
}

void FileReader::File::checkForComment(const string& line, vector<string> row)
{
    regex date("[0-9]{1,2}/[0-9]{1,2}/[0-9]{1,4} [0-9]{1,2}:[0-9]{1,2}");
    if (row.size() == 1)
    {
        return;
    }
    else if (regex_match(row[0], date))
    {
        comments.push_back(row[index]);
    }
    else
    {
        comments[comments.size() - 1] = comments[comments.size() - 1] + line;
    }
}
