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
        void CountWords(const string& s1);
        void createCSV();
        bool checkValidInput();
        void removePunctuations(string& s1);
        void removeNumbers(string& s1);
        void convertToLowerCase(string& s1);
    };
    
}