#include <iostream>
#include <fstream>
#include <sstream>

int main() {

	//open file
	std::ifstream inFile;
	inFile.open("data.csv");

	//setup ss and converter for lines
	std::stringstream ss;
	std::stringstream converter;

	std::string item;
	while (getline(inFile, item)) {

		//variables
		int firstVal;
		std::string sFirstVal;
		int secondVal;
		std::string sSecondVal;
		std::string text;

		//clear ss and set new item
		ss.clear();
		ss.str(item);

		//get line and use comma as delimiter
		getline(ss, sFirstVal, ',');
		getline(ss, sSecondVal, ',');
		getline(ss, text);

		//clear converter and convert first val
		converter.clear();
		converter.str("");

		converter << sFirstVal;
		converter >> firstVal;

		//clear converter and convert second val
		converter.clear();
		converter.str("");

		converter << sSecondVal;
		converter >> secondVal;

		int total = firstVal + secondVal;
		for (int i = 0; i < total; ++i) {
			std::cout << text;
		}
		std::cout << std::endl;
	}	

	return 0;
}
