#include<iostream>
#include<string>
#include<cctype>
#include<unordered_map>
#include<iterator>
#include<fstream>
#include<algorithm>
#include<sstream>
using namespace std;

namespace receiver {
    class rec
    {
    private:
        string s1;
        unordered_map<string, int> m;
    public:
        unsigned int countOfDifferentWordsInMap;
        bool checkInputValidity();
        void CountWords(const string& s1);
        void createCSV();
        void removePunctuations(string& s1);
        void removeNumbers(string& s1);
        void convertToLowerCase(string& s1);
        void removeStopWords();
    };
}
