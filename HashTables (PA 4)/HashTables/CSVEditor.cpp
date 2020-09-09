// YASH KALYANI -- Section: 511 -- Email- yk7335@tamu.edu

#include "CSVEditor.hpp"
#include <ostream>
#include <iostream>
#include <vector>
#include <regex>
#include <list>
#include <utility> 
#include <string>

CSVEditor::CSVEditor(string& inputPath, string& rosterPath, string& outputPath, regex expr, int m) {
    //IMPLEMENT
    this->hashTable = new HashTable<string>(m);
    this->input.open(inputPath);
    this->regexPattern=expr;
    this->roster.open(rosterPath);
    this->output.open(outputPath);
}

CSVEditor::~CSVEditor(){
	//IMPLEMENT
    delete hashTable;
}

void CSVEditor::readCSVToTable() {
	//IMPLEMENT
    //regex_search
    //regexPattern
    smatch var;
	string temp;
    while((getline(input,temp)))
    {
        regex_search(temp,var,regexPattern);
        hashTable->insert(stoi(var[1]),var[2]);

    }
}

void CSVEditor::writeCSVToFile() {
	//IMPLEMENT 
    //regex_search
    //regexPattern  
    string temp;
    smatch var;
    while(getline(roster,temp)) {
        regex_search(temp,var,regexPattern);
        if(hashTable->search(stoi(var[1])) == nullptr){output << temp << endl;
        }else{
            string* Values = hashTable->search(stoi(var[1]));
            output << temp.erase(temp.size()-2,2) << ","<< *Values<< endl;}}
}

std::tuple<int, int, double> CSVEditor::getStats(){
	//IMPLEMENT
	return std::make_tuple(hashTable->minChainLen(), hashTable->maxChainLen(), hashTable->averageChainLen());
}