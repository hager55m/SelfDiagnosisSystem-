#pragma once
#include <string>
#include "account.h"
#include "Disease.h"
struct Doctors
{
	Diseases mDis[10];
	int NumberOfDisease=0;
	Account mAcc;
	int mAge=0;
	std::string mInfo;
	std::string mGender;
	std::string mName;
	
};


 