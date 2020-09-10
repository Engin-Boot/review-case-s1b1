#include<iostream>
#include<string>
#include<cctype>
#include<unordered_map>
#include<iterator>
#include<fstream>
using namespace std;

class rec
{
private:
    string s1;
    unordered_map<string, int> m;
public:
    void CountWords(const string& s1);
    void createCSV();
    void removePunctuations(string& s1);
};


void rec::CountWords(const string& s1) {
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
  //  unordered_map<string, int> ::iterator itr;
}

void rec::createCSV() {
    fstream fout;
    fout.open("map.csv", ios::out | ios::app);

    unordered_map<string, int> ::iterator itr;

    for (itr = m.begin(); itr != m.end(); itr++) {
        fout << itr->second << "," << itr->first << "\n";
    }
}

void rec::removePunctuations(string& s1)
{
    s1.erase(remove_if(s1.begin(), s1.end(), ispunct));
}


int main() {
    rec ob;
    string s1;
    int count;
    cin >> count;
    while (count!=-1) {
        getline(cin, s1);
      //  ob.removePunctuations(s1);
        ob.CountWords(s1);
        count--;
    }
    ob.createCSV();
}