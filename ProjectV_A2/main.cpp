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
	std::string email;
} STUDENT_DATA;

int main(void) {
	std::vector <STUDENT_DATA> studentDataVector;
	STUDENT_DATA tempStudentData;
	std::string line;

	// Print the messsage depending on debug vs release build (file changes too)
#ifdef PRE_RELEASE
	std::ifstream inputFile("StudentData_Emails.txt");
	std::cout << "Running Pre Release Version 0.1... " << std::endl; // Req per assignment
#else
	std::ifstream inputFile("StudentData.txt");
	std::cout << "Running Version 1.0... " << std::endl; // Req per assignment
#endif

	if (!inputFile.is_open()) {
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	while (std::getline(inputFile, line)) {
		std::stringstream ss(line);
		std::getline(ss, tempStudentData.lastName, ',');

	// Read the email file version for prerelease
#ifdef PRE_RELEASE
		std::getline(ss, tempStudentData.firstName, ',');
		std::getline(ss, tempStudentData.email);
#else
		std::getline(ss, tempStudentData.firstName);
#endif

		// Leading space removal
		if (!tempStudentData.firstName.empty() &&
			tempStudentData.firstName[0] == ' ') {
			tempStudentData.firstName.erase(0, 1);
		}

		studentDataVector.push_back(tempStudentData);
	}

	// DEGUB LOGGING
#ifdef _DEBUG
	// All Students Data
	for (const STUDENT_DATA& student : studentDataVector) {
		std::cout << "First Name: " << student.firstName << '\n';
		std::cout << "Last Name:  " << student.lastName << '\n';

#ifdef PRE_RELEASE // Email only available in prerelease 
		std::cout << "Email:      " << student.email << '\n';
#endif
		std::cout << "--------------------------\n";

	}

	// Total num of students from each file
	std::cout << "Total Students Read: " << studentDataVector.size() << "\n";
#endif

	return 0;
}