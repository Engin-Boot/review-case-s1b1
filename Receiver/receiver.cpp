#include "receiver.h"

bool receiver::rec::checkInputValidity() {
    if (m.size() == 0) {
        throw std::runtime_error("No input");
    }
    return true;
}

void receiver::rec::CountWords(const string& s1) {
    string word = "";
    stringstream ss(s1);
    while (ss >> word)
        rec::m[word]++;
    count = m.size();
}

void receiver::rec::createCSV() {
    fstream fout;
    fout.open("map.csv", ios::out | ios::app);

    unordered_map<string, int> ::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        fout << itr->second << "," << itr->first << "\n";
    }
}

/*bool invalidChar(char c)
{
    return !(c >= 0 && c < 128);
}*/

void receiver::rec::removePunctuations(string& s1)
{
    s1.erase(remove_if(s1.begin(), s1.end(), ::iswpunct), s1.end());
    //s1.erase(remove_if(s1.begin(), s1.end(), invalidChar), s1.end());
}

void receiver::rec::removeNumbers(string& s1)
{
    s1.erase(remove_if(s1.begin(), s1.end(), ::iswdigit), s1.end());
}

void receiver::rec::convertToLowerCase(string& s1) {
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
}
