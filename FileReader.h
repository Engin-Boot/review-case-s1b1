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
		int index;
		void readHeader();
		vector<string> readRecord();
	};
}