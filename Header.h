#pragma once
#include "Doctor.h"
#include"account.h"
#include "Disease.h"
#include"Patient.h"
void GetData()
{
    Doctor[0].mAcc.mUsername = "Hager";//Not Array
    Doctor[0].mAcc.mPassword = "1234";
    Doctor[0].mName = "Hager";
    Doctor[0].mGender = "Female";
    Doctor[0].mAge = 35;
    Doctor[0].mInfo = "Doctor of Surgery";

    Doctor[1].mAcc.mUsername = "Yara Roby@medicine.com";
    Doctor[1].mAcc.mPassword = "Y164";
    Doctor[1].mName = "Yara";
    Doctor[1].mGender = "Female";
    Doctor[1].mAge = 28;
    Doctor[1].mInfo = "Doctor of Internist";

    Doctor[2].mAcc.mUsername = "Nouran Abdelhameed@medicine.com";
    Doctor[2].mAcc.mPassword = "N236";
    Doctor[2].mName = "Nouran";
    Doctor[2].mGender = "Female";
    Doctor[2].mAge = 30;
    Doctor[2].mInfo = "Doctor of Neurologist";

    Patient[0].mAcc.mUsername = "omar";
    Patient[0].mAcc.mPassword = "1234";
    Patient[0].mName = "Omar";
    Patient[0].mGender = "Male";
    Patient[0].mAge = 45;




    Patient[1].mAcc.mUsername = "Kareem Adel";
    Patient[1].mAcc.mPassword = "K123";
    Patient[1].mName = "Kareem";
    Patient[1].mGender = "Male";
    Patient[1].mAge = 45;




    Patient[2].mAcc.mUsername = "Adam Yasser";
    Patient[2].mAcc.mPassword = "A456";
    Patient[2].mName = "Adam";
    Patient[2].mGender = "Male";
    Patient[2].mAge = 45;


    Disease[0].Department = "Stomach";
    Disease[0].mTitle = "Colitis Liner";
    Disease[0].mID = 0;
    Disease[0].Symptoms[0] = "Diarrhea";
    Disease[0].Symptoms[1] = "Abdominal pain";
    Disease[0].Symptoms[2] = "Fever";
    Disease[0].Symptoms[3] = "bloating";
    Disease[0].counter = 0;
    Disease[0].percentage = 0;
    Disease[0].idofdepartment = 0;
    Disease[0].NumberOfSymptoms = 4;
    //  Disease[0].PatientOfDisease[2] = "";

    Disease[1].Department = "Stomach";
    Disease[1].mTitle = "Germ Stomach";
    Disease[1].mID = 1;
    Disease[1].Symptoms[0] = "Loss of appetite";
    Disease[1].Symptoms[1] = "Frequent burping";
    Disease[1].Symptoms[2] = "Bloating";
    Disease[1].Symptoms[3] = "Nausea";
    Disease[1].counter = 0;
    Disease[1].percentage = 0;
    Disease[1].idofdepartment = 0;
    Disease[1].NumberOfSymptoms = 4;

    // Disease[1].PatientOfDisease = "";

    Disease[2].Department = "Brain";
    Disease[2].mTitle = "Epilepsy";
    Disease[2].mID = 2;
    Disease[2].Symptoms[0] = "Uncontrollable jerking and shaking, called a 'Fit'";
    Disease[2].Symptoms[1] = "Losing awareness and staring blankly into space";
    Disease[2].Symptoms[2] = "Becoming stiff";
    Disease[2].Symptoms[3] = "Collapsing";
    Disease[2].counter = 0;
    Disease[2].percentage = 0;
    Disease[2].idofdepartment = 1;
    Disease[2].NumberOfSymptoms = 4;

    // Disease[2].PatientOfDisease[2] = "";

    Disease[3].Department = "Brain";
    Disease[3].mTitle = "Alzheimer";
    Disease[3].mID = 3;
    Disease[3].Symptoms[0] = "Memory loss that disrupts daily life";
    Disease[3].Symptoms[1] = "Taking longer to complete normal daily tasks";
    Disease[3].Symptoms[2] = "Repeating questions or forgetting recently learned information";
    Disease[3].Symptoms[3] = "Losing track of dates or knowing current location";
    Disease[3].counter = 0;
    Disease[3].percentage = 0;
    Disease[3].idofdepartment = 1;
    Disease[3].NumberOfSymptoms = 4;

    //Disease[3].PatientOfDisease[2] = "";

    Disease[4].Department = "Skin";
    Disease[4].mTitle = "Smallpox";
    Disease[4].mID = 4;
    Disease[4].Symptoms[0] = "Backache";
    Disease[4].Symptoms[1] = "Abdominal pain";
    Disease[4].Symptoms[2] = "Vomiting";
    Disease[4].Symptoms[3] = "Diarrhoea";
    Disease[4].counter = 0;
    Disease[4].percentage = 0;
    Disease[4].idofdepartment = 2;
    Disease[4].NumberOfSymptoms = 4;

    // Disease[4].PatientOfDisease[2] = "";

    Disease[5].Department = "Skin";
    Disease[5].mTitle = "Gout";
    Disease[5].mID = 5;
    Disease[5].Symptoms[0] = "Joint swelling";
    Disease[5].Symptoms[1] = "Sudden and sever joint paint";
    Disease[5].Symptoms[2] = "Mild fever";
    Disease[5].Symptoms[3] = "Joint stiffness";
    Disease[5].counter = 0;
    Disease[5].percentage = 0;
    Disease[5].idofdepartment = 2;
    Disease[5].NumberOfSymptoms = 4;


    NumberOfDoctor = 4;
    NumberOfPatient = 4;
    NumberOfDisease = 6;
}