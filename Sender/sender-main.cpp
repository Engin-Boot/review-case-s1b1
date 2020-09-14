// ***** consumer code****
#include <iostream>
#include <vector>
#include "FileReader.h"

using namespace std;

int main(int argc, char* argv[])
{
    FileReader::File f1;
    try
    {
        if (argc == 2)
            f1.openFile(argv[1]);
        else
            f1.openFile();
    }
    catch (runtime_error r)
    {
        cout << "Runtime error: " << r.what() << endl;
        exit(0);
    }
    f1.readHeader();
    vector<string> comments;
    comments = f1.readRecords();
    for (int i = 0; (unsigned)i < comments.size(); i++)
        cout << comments[i] << endl;
    return 0;
}