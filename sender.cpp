#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>
#include "FileReader.h"

using namespace std;

void FileReader::File::readHeader()
{
    fstream fin;

    fin.open("review-report.csv", ios::in);

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
    fin.close();
}

vector<string> FileReader::File::readRecord()
{
    ifstream fin("review-report.csv");

    // Make sure the file is open
    //if (!fin.is_open()) throw runtime_error("Could not open file");

    vector<string> row,comments;
    regex date("[0-9]{1,2}/[0-9]{1,2}/[0-9]{1,4} [0-9]{1,2}:[0-9]{1,2}");
    string line, word;
    int comments_index=-1;
    string dummyLine;
    getline(fin, dummyLine);
    while (fin.good())
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        //cout << line<<endl;
        if (line.find(',') != string::npos)
        {
            while (getline(s, word, ','))
            {
                row.push_back(word);
                //cout << endl << "PUSH_BACK started" << endl;
            }
            if (row.size() == 1 )
            {
                //cout << "BLANK LINES..............."<<row[0]<<endl;
                continue;
            }
            else if (regex_match(row[0], date))
            {
                comments.push_back(row[index]);
            }
            else
            {
                comments[comments.size()-1] = comments[comments.size()-1] + line;
            }
        }
        else
            comments[comments.size() - 1] = comments[comments.size() - 1] + line;
        //cout << endl << "NOW............" << endl;
        //cout << row.size();
    }
    //cout << "NOW RETURNING"<<endl<<comments.size();
    return comments;
}

// ***** consumer code****

int main()
{
    FileReader::File f1;
    f1.readHeader();
    vector<string> comments;
    comments = f1.readRecord();
    cout << comments.size()<<endl;
    for (int i = 0; i < comments.size(); i++)
        cout << comments[i]<<endl;
}