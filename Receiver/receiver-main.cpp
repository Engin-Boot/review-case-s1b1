#include "receiver.h"

int main() {
    receiver::rec ob;
    string s1;
    while (getline(cin, s1)) {
        getline(cin, s1);
        ob.removePunctuations(s1);
        ob.removeNumbers(s1);
        ob.convertToLowerCase(s1);
        ob.CountWords(s1);
    }
    try
    {
        ob.checkInputValidity();
    }
    catch (const std::exception& e)
    {
        cout << "Runtime error:" << e.what() << endl;
        exit(0);
    }
    ob.removeStopWords();
    ob.createCSV();
}