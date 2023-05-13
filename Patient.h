#pragma once
#include <string>
#include "account.h"
#include "Disease.h"
struct Patients

{

	Account mAcc;
	std::string mGender;
	int mAge=0;
	std::string mName;
	std::string mDiagnosisHistory [10];
	int NumberOfDSymptomOfPatient = 0;
	int NumberOfDiagnosisHistory = 0;
	std::string mSymptom[20];
	
		
};

