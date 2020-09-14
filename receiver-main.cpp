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

    if (ob.checkInputValidity()) {
        ob.createCSV();
    }
}