#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Reads the csv file records

namespace FileReader
{
	class File
	{
	public:
		vector<string> comments;
		int index=0;
		ifstream fin;
		void selectFilename(int, char* []);
		void openFile(string filename = "review-report.csv");
		void readHeader();
		vector<string> readRecords();
		void checkLine(const string&, vector<string>);
		void checkForComment(const string&, vector<string>);
	};
}