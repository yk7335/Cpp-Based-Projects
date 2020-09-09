// YASH KALYANI -- Section: 511 -- Email- yk7335@tamu.edu

#include <string>
#include <regex>

#include "HashTable.hpp"
#include "CSVEditor.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    regex expr(".*,.*,(.*),(.*)");
	
    string inputPath = "./input.csv";
    string rosterPath = "./roster.csv";
    string outputPath = "./output.csv";
	
	int m = 0; 
	
	//OBTAIN M HERE
	ifstream filename;
	filename.open("roster.csv");
	string temp;
	while(getline(filename,temp)){
		m += 1;
	}

	cout << "M:" << m <<  endl;

    CSVEditor editor(inputPath, rosterPath, outputPath, expr, m);
    editor.readCSVToTable();
    editor.writeCSVToFile();
	
	std::tuple<int, int, double> stats = editor.getStats();
	
	cout << "minimum chain len = " << std::get<0>(stats) << endl;
	cout << "maximum chain len = " << std::get<1>(stats) << endl;
	cout << "average chain len = " << std::get<2>(stats) << endl;
	
    return 0;    
}
