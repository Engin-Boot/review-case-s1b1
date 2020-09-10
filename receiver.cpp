#include "receiver.h"

void receiver::rec::CountWords(const string& s1) {
    string word = "";

    for (auto i : s1) {
        if (i == ' ') {

            rec::m[word]++;
            word = "";
        }
        else {
            word = word + i;
        }
    }
    rec::m[word]++;
}

void receiver::rec::createCSV() {
    fstream fout;
    fout.open("map.csv", ios::out | ios::app);

    unordered_map<string, int> ::iterator itr;

    for (itr = m.begin(); itr != m.end(); itr++) {
        fout << itr->second << "," << itr->first << "\n";
    }
}

void receiver::rec::removePunctuations(string& s1)
{
    s1.erase(remove_if(s1.begin(), s1.end(), ::ispunct), s1.end());
}

void receiver::rec::removeNumbers(string& s1)
{
    s1.erase(remove_if(s1.begin(), s1.end(), ::isdigit), s1.end());
}


int main() {
    receiver::rec ob;
    string s1;
    int count;
    cin >> count;
    while (count != 0) {
        getline(cin, s1);
        ob.removePunctuations(s1);
        ob.removeNumbers(s1);
        ob.CountWords(s1);
        count--;
    }
    ob.createCSV();
}