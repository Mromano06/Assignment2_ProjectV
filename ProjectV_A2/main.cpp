#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Matthew Romano - Sept 17th, 2026 - A2, Project V
// Main implementation of file reader

// Struct to hold a persons information
typedef struct {
	std::string firstName;
	std::string lastName;
} STUDENT_DATA;

int main(void) {
	std::vector <STUDENT_DATA> studentDataVector;
	std::ifstream inputFile("StudentData.txt"); 
	STUDENT_DATA tempStudentData;
	std::string line;

	if (!inputFile.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}
	
	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		std::getline(ss, tempStudentData.lastName, ',');
		std::getline(ss, tempStudentData.firstName);

		if (std::getline(inputFile, tempStudentData.firstName, ',')) {
			// Leading space removal
			if (!tempStudentData.firstName.empty() &&
				tempStudentData.firstName[0] == ' ') {
				tempStudentData.firstName.erase(0, 1);
			}
		}

		studentDataVector.push_back(tempStudentData);
	}

	// Just for basic testing/debug
	std::cout << "Total Students Read: " << studentDataVector.size() << "\n";

	return 0;
}