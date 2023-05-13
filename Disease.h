#pragma once
#include <string>
struct Diseases
{
	std::string mTitle, Symptoms[10];
	int NumberOfSymptoms = 0;
	
		int mID;
	int idofdepartment = 0; //file
	int counter = 0;
	float percentage = 0.0;
	std::string GeneralInfo="No info";
	std::string Department;
	int NumberOfPatientWithDiseace = 0;
	std::string PatientName[10];
	bool symcheck[50] = { false };
};
