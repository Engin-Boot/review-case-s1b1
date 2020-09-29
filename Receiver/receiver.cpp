#include "receiver.h"

bool receiver::rec::checkInputValidity() {
    if (m.size() == 0) {
        throw std::runtime_error("No input");
    }
    return true;
}


bool receiver::rec::checkIfOutputCSVNotAlreadyOpen() {
    fstream check;  // pre-processing -> checking if file is open in another application
    check.open("map.csv");
    if (check.fail())
    {
        if (remove("map.csv") != 0)
            throw std::runtime_error("map.csv' File is open in another application! Please close before restarting this program\n");
    }
    check.close();
    return true;
}

void receiver::rec::CountWords(const string& s1) {
    string word = "";
    stringstream ss(s1);
    while (ss >> word)
    {
        rec::m[word]++;
    }
    countOfDifferentWordsInMap = m.size();       //to hold size of map
}

void receiver::rec::removeStopWords()
{
    string stop[] = { "a","about","above","after","again","against","all","am","an","and","any","are","arent","as","at","be","because","been","before","being","below","between","both","but",
        "by","cant","cannot","could","couldnt","did","didnt","do","does","doesnt","doing","dont","down","during","each","few","for","from","further","had","hadnt","has","hasnt",
        "have","havent","having","he","hed","hell","hes","her","here","heres","hers","herself","him","himself","his","how","hows","i","id","im","ive","if","in","into",
        "is","isnt","it","its","itself","lets","me","more","most","mustnt","my","myself","no","nor","not","of","off","on","once","only","or","other","ought","our","ours",
        "ourselves","out","over","own","same","shant","she","shes","should","shouldnt","so","some","such","than","that","thats","the","their","theirs","them",
        "themselves","then","there","theres","these","they","theyd","theyll","theyre","theyve","this","those","through","to","too","under","until","up","very","was","wasnt","we",
        "were","weve","were","werent","what","whats","when","whens","where","wheres","which","while","who","whos","whom","why","whys","with","wont","would",
        "wouldnt","you","youd","youll","youre","youve","your","yours","yourself","yourselves" };

    int length = sizeof(stop) / sizeof(stop[0]);
    for (int i = 0; i < length; i++)
    {
        auto it = m.find(stop[i]);
        if (it != m.end()) {
            m.erase(it);
        }
    }
    countOfDifferentWordsInMap = m.size();           //to hold size of map

}

void receiver::rec::createCSV() {
    fstream fout;
    fout.open("map.csv", ios::out);

    fout << "Frequency of Word" << "," << "Word" << "\n";

    unordered_map<string, int> ::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        fout << itr->second << "," << itr->first << "\n";
    }        
}

void receiver::rec::removePunctuations(string& s1)
{
    s1.erase(remove_if(s1.begin(), s1.end(), ::iswpunct), s1.end());

}

void receiver::rec::removeNumbers(string& s1)
{
    s1.erase(remove_if(s1.begin(), s1.end(), ::iswdigit), s1.end());
}

void receiver::rec::convertToLowerCase(string& s1) {
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
}
