#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Reads the csv file records

namespace FileReader
{
	class File
	{
	public:
		vector<string> comments;
		int index;
		void readHeader();
		vector<string> readRecords();
		void checkLine(string, vector<string>);
		void checkForComment(string, vector<string>);
	};
}