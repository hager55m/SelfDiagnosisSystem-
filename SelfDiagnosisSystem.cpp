#include <iostream>
#include<fstream>
#include <sstream>
#include <conio.h>
#include<string>
#include "Disease.h"
#include "account.h"
#include "Doctor.h"
#include "Patient.h"
#include <windows.h>


using namespace std;
string department[10] = { "Stomach","Brain","Skin" };
Doctors Doctor[10];
Patients Patient[10];
Diseases Disease[10];


int NumberOfDoctor = 0, NumberOfPatient = 0, NumberOfDisease = 0, NumberOfDepartment = 3;
int Id = -1;

void GetData();
void read();
void Write();


char CheckLogin(string Username, string Password, int& ID);
bool CheckUsername(char DOP, string Username);
bool CheckPassword(char DOP, string Password);
void Register();

void deleteRepeated(string arr[], int& n);
//Doctor
bool CheckSymptomsWhenAddDisease(string Symptom, int Count);
bool CheckSymptoms(string Symptom, int DiseaseIndix);
void ChangeTitle(string NewTitle, int DiseaseIndix);
void ChangeSymptom(std::string NewSymptom, int DiseaseIndix, int SympotomIndix);
void EdieInfoo(std::string NewInfo);
void ChangeAge(int NewAge);
void ChangeUsrname(std::string NewUsername);
void ChangePassword(std::string NewPassword);
void AddToArrayOfDisease();
void AddDisease();
void EditDisease(string Title, string NewSymptom);
void DisplayAll();
void viewpatientwithcertiandisease(int);
bool CheckTittle(std::string Tittle);
void AddDepartment();
void DeleteCertianSymptom(int DiseaeseIndix);
void EditDataInArrayOfDisease(int);

//patient
void MakeSureTheDiagnosisHistoryIsUniqe();
void EditinfoForPatient();
bool CheckUsername(string NewUsername);
void ChangeUsernameForPatient(string NewUsername);
void ChangePasswordForPatient(string Password);
void ChangeNameForPatient(string Name);
void ChangeAgeForPatient(int Age);
void FindOutINfoAboutCertainDisease();
void DiagnosisWithChoosingDepartment();
void DiagnosisWithoutChoosingDepartment();
void DeleteDiagnosisHistoryForPatient();
void CalculatePrsentageInDiagnosisWithoutChoosingDepartment();
void ViewDiagnosisHistory();
void View();

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{



   // GetData();
    read();



    int ChoiceOfLR;


    do
    {


        SetConsoleTextAttribute(h, 13);//13
        cout << "\t\t\t\t Welcom to self diagnosis system\n";
        cout << "\t\t\t\t\n\n\n";
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t1 for login        \n";
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t2 for regiteration\n";
        SetConsoleTextAttribute(h, 6);
        cout << "\t\t\t\t3 to exsit\n";
        SetConsoleTextAttribute(h, 13);
        cout << "\t\t\t\tplease enter your choice : ";

        cin >> ChoiceOfLR;
        if (ChoiceOfLR == 1)
        {

            string Username, Password;
            char Pass = '0';
            SetConsoleTextAttribute(h, 7);
            cout << "\t\t\t\tplease enter your username : ";
            cin.ignore();
            getline(cin, Username);

            cout << "\t\t\t\tplease enter your password : ";
            while (Pass != '\r')
            {

                Pass = _getch();
                if (Pass == '\r')
                    break;
                if (Pass == '\b')
                {
                    Password.pop_back();
                    cout << "\b \b";

                    continue;
                }

                cout << "*";
                Password += Pass;

            }
            cout << '\n';
            char DoctorOrPatient = CheckLogin(Username, Password, Id);




            switch (DoctorOrPatient)
            {
            case'D':
                SetConsoleTextAttribute(h, 13);
                cout << "\t\t\t\tsuccesfully login\n";
                SetConsoleTextAttribute(h, 7);
                std::cout << "\n\t\t\t\twelcome doctor \n\n";
                int Answer;
                do
                {
                    SetConsoleTextAttribute(h, 13);
                    std::cout << "\t\t\t\twhat do you wnat to do:\n";
                    SetConsoleTextAttribute(h, 14);//red
                    std::cout << "\t\t\t\tpress(1) if you want to edit information :\n";
                    SetConsoleTextAttribute(h, 14);//gray
                    std::cout << "\t\t\t\tpress(2) if you want to add disease :\n";
                    SetConsoleTextAttribute(h, 14);//yellow
                    std::cout << "\t\t\t\tpress(3) if you want to disply all diseases :\n";
                    SetConsoleTextAttribute(h, 14);//purple
                    std::cout << "\t\t\t\tpress(4) if you want to log out :";
                    SetConsoleTextAttribute(h, 13);
                    std::cin >> Answer;
                    string  NewInfo, NewTitle, NewSymptom, NewUsername, NewPassword;
                    int NewAge;
                    if (Answer < 1 || Answer > 4)
                    {
                        do
                        {
                            SetConsoleTextAttribute(h, 4);

                            cout << "\t\t\t\tPlease choose numberfrom(1 to 4) : ";
                            cin >> Answer;
                            cout << "\n";
                        } while (Answer > 4 || Answer < 1);
                    }

                    if (Answer == 1)
                    {
                        SetConsoleTextAttribute(h, 8);
                        cout << "\t\t\t\tyour information : \n\t\t\t\tPersonal information : " << Doctor[Id].mInfo << "\n\t\t\t\tAge     : " << Doctor[Id].mAge <<
                            "\n\t\t\t\tUsername : " << Doctor[Id].mAcc.mUsername << "\n\t\t\t\tPassword : " << Doctor[Id].mAcc.mPassword << "\n";
                        if (Doctor[Id].NumberOfDisease > 0)
                        {
                            cout << "\t\t\t\t Disease \n\t\t\t\t";
                        }
                        for (int i = 0; i < Doctor[Id].NumberOfDisease; i++)
                        {
                            cout << i + 1 << " " << Doctor[Id].mDis[i].mTitle << "\n";
                        }
                    }

                    int EditAnswer;

                    switch (Answer)
                    {

                    case 1:
                        SetConsoleTextAttribute(h, 13);//purple
                        cout << "\t\t\t\twhat do you want to edit:\n";
                        SetConsoleTextAttribute(h, 8);//purple
                        std::cout << "\t\t\t\tpress[1] if you want to edit your personal information :\n";
                        std::cout << "\t\t\t\tpress[2] if you want to edit your age :\n";
                        std::cout << "\t\t\t\tpress[3] if you want to edit your username :\n";
                        std::cout << "\t\t\t\tpress[4] if you want to edit your password :\n";
                        std::cout << "\t\t\t\tpress[5] if you want to edit disease :\n";
                        std::cout << "\t\t\t\tpress[6] if you want to exite :";
                        std::cin >> EditAnswer;

                        if (EditAnswer < 1 || EditAnswer > 6)
                        {
                            do
                            {
                                SetConsoleTextAttribute(h, 4);//purple
                                cout << "\t\t\t\tPlease choose numberfrom(1 to 6) : ";
                                cin >> EditAnswer;
                                cout << "\n";
                            } while (EditAnswer > 6 || EditAnswer < 1);
                        }
                        SetConsoleTextAttribute(h, 8);//purple


                        switch (EditAnswer)
                        {
                        case 1:
                            SetConsoleTextAttribute(h, 15);//purple
                            std::cout << "\t\t\t\tenter your new informtion:";

                            cin.ignore();
                            getline(std::cin, NewInfo);
                            EdieInfoo(NewInfo);
                            break;
                        case 2:
                            SetConsoleTextAttribute(h, 15);
                            std::cout << "\t\t\t\tPlease enter your new age:";
                            cin >> NewAge;
                            ChangeAge(NewAge);
                            break;
                        case 3:
                            SetConsoleTextAttribute(h, 15);
                            std::cout << "\t\t\t\tEnter your new username:";
                            cin.ignore();
                            getline(std::cin, NewUsername);
                            ChangeUsrname(NewUsername);
                            break;
                        case 4:
                            SetConsoleTextAttribute(h, 15);
                            std::cout << "\t\t\t\tenter your new password :";
                            cin.ignore();
                            getline(std::cin, NewPassword);
                            ChangePassword(NewPassword);
                            break;
                        case 5:
                            // m4 mawgod //
                            if (Doctor[Id].NumberOfDisease == 0)
                            {
                                SetConsoleTextAttribute(h, 4);
                                cout << "\t\t\t\t sorry you dont have aleady disease !!!! \n";
                            }

                            else
                            {
                                SetConsoleTextAttribute(h, 8);
                                std::cout << "\t\t\t\tenter your disease title :";
                                cin.ignore();
                                getline(std::cin, NewTitle);

                                EditDisease(NewTitle, NewSymptom);
                            }
                            break;
                        case 6:
                            break;
                        }
                        break;
                    case 2:
                        AddDisease();
                        break;
                    case 3:
                        DisplayAll();
                        break;
                    case 4:

                        break;

                    default:
                        break;

                    }


                } while (Answer != 4);





                break;
            case'P':
                SetConsoleTextAttribute(h, 13);
                cout << "\t\t\t\tsuccesfully login\n\n";
                int x = 2;//answer

                char answer = 'n';
                do
                {
                    SetConsoleTextAttribute(h, 13);
                    cout << "\t\t\t\tHOW CAN I HELP YOU\n";
                    SetConsoleTextAttribute(h, 14);
                    cout << "\t\t\t\tPRESS(1):VIEW YOUR INFO\n";
                    cout << "\t\t\t\tPRESS(2):EDIT YOUR INFO\n";
                    cout << "\t\t\t\tPRESS(3):DIAGNOSIS YOUR SELF\n";
                    cout << "\t\t\t\tPRESS(4):FIND OUT INFO ABOUT A CERTAIN DISEASE\n";
                    cout << "\t\t\t\tPRESS(5):VIEW DIAGNOSIS HISTORY \n";
                    cout << "\t\t\t\tPRESS(6):TO LOG OUT :";
                    cin >> x;
                    if (x < 1 || x > 6)
                        do {
                            SetConsoleTextAttribute(h, 4);
                            cout << "\t\t\t\tchoose from 1 to 6";
                            cin >> x;

                        } while (x < 1 || x > 6);
                        SetConsoleTextAttribute(h, 13);


                        switch (x)
                        {
                        case 1:
                            View();
                            break;
                        case 2:


                            EditinfoForPatient();
                            break;
                        case 3:
                            SetConsoleTextAttribute(h, 7);

                            cout << "\t\t\t\tPress(1) to Dignosis by choosing department \n";
                            cout << "\t\t\t\tPress(2) to Dignosis by choosing from all symptoms :";

                            int WayToDiagnosis;
                            cin >> WayToDiagnosis;
                            if (WayToDiagnosis > 2 || WayToDiagnosis < 1)
                            {
                                do
                                {
                                    SetConsoleTextAttribute(h, 4);
                                    cout << "\t\t\t\tChoose 1 or 2 \n";
                                    cout << "\t\t\t\t";

                                    cin >> WayToDiagnosis;
                                } while (WayToDiagnosis > 2 || WayToDiagnosis < 1);
                            }
                            SetConsoleTextAttribute(h, 15);
                            switch (WayToDiagnosis)
                            {
                            case 1:
                                DiagnosisWithChoosingDepartment();
                                break;
                            case 2:
                                DiagnosisWithoutChoosingDepartment();


                                break;
                            }
                            MakeSureTheDiagnosisHistoryIsUniqe();
                            break;
                        case 4:

                            FindOutINfoAboutCertainDisease();




                            break;
                        case 5:

                            MakeSureTheDiagnosisHistoryIsUniqe();
                            ViewDiagnosisHistory();
                        case 6:
                            break;
                        }

                } while (x != 6);


                break;

            }



        }
        else if (ChoiceOfLR == 2) {


            Register();
            cout << "\t\t\t\tsuccessfully registered\n";

        }

        else  if (ChoiceOfLR == 3) {


            cout << "\t\t\t\thope you visit our system soon !\n";
            break;
        }


    } while (ChoiceOfLR != 3);

    Write();
    return 0;
}



void GetData()
{
    Doctor[0].mAcc.mUsername = "hager";//Not Array
    Doctor[0].mAcc.mPassword = "1234";
    Doctor[0].mName = "Hager";
    Doctor[0].mGender = "Female";
    Doctor[0].mAge = 35;
    Doctor[0].mInfo = "Doctor of Surgery";

    Doctor[1].mAcc.mUsername = "yara ";
    Doctor[1].mAcc.mPassword = "Y164";
    Doctor[1].mName = "Yara";
    Doctor[1].mGender = "Female";
    Doctor[1].mAge = 28;
    Doctor[1].mInfo = "Doctor of Internist";

    Doctor[2].mAcc.mUsername = "nouran";
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
    Patient[0].mDiagnosisHistory[0] = "Colitis Liner";
    Patient[0].mDiagnosisHistory[1] = "Germ Stomach";

    Patient[0].NumberOfDiagnosisHistory = 2;




    Patient[1].mAcc.mUsername = "kareem ";
    Patient[1].mAcc.mPassword = "K123";
    Patient[1].mName = "Kareem";
    Patient[1].mGender = "Male";
    Patient[1].mAge = 45;




    Patient[2].mAcc.mUsername = "adam ";
    Patient[2].mAcc.mPassword = "A456";
    Patient[2].mName = "Adam";
    Patient[2].mGender = "Male";
    Patient[2].mAge = 45;


    Disease[0].Department = "stomach";
    Disease[0].mTitle = "colitis liner";
    Disease[0].mID = 0;
    Disease[0].Symptoms[0] = "diarrhea";
    Disease[0].Symptoms[1] = "abdominal pain";
    Disease[0].Symptoms[2] = "fever";
    Disease[0].Symptoms[3] = "bloody stools";// hn8ir el code
    Disease[0].counter = 0;
    Disease[0].percentage = 0;
    Disease[0].idofdepartment = 0;
    Disease[0].NumberOfSymptoms = 4;
    Disease[0].PatientName[0] = "Alaa Mustafa";
    Disease[0].NumberOfPatientWithDiseace++;
    Disease[0].GeneralInfo = "Colitis is swelling(inflammation) of the large intestine(colon)";
    // Disease[0].PatientOfDisease[2] = "";

    Disease[1].Department = "stomach";
    Disease[1].mTitle = "germ stomach";
    Disease[1].mID = 1;



    Disease[1].Symptoms[0] = "loss of appetite";
    Disease[1].Symptoms[1] = "frequent burping";
    Disease[1].Symptoms[2] = "bloating";
    Disease[1].Symptoms[3] = "nausea";
    Disease[1].counter = 0;
    Disease[1].percentage = 0;
    Disease[1].idofdepartment = 0;
    Disease[1].NumberOfSymptoms = 4;//
    Disease[1].PatientName[0] = "Ahmed Yehia";
    Disease[1].NumberOfPatientWithDiseace++;
    Disease[1].GeneralInfo = "Germ Stomach literally means joint inflammation.Joints are places where two bones meet such as your elbow or knee.";
    // Disease[1].PatientOfDisease = "";

    Disease[2].Department = "brain";
    Disease[2].mTitle = "epilepsy";
    Disease[2].mID = 2;
    Disease[2].Symptoms[0] = "Uncontrollable jerking and shaking, called a 'Fit'";
    Disease[2].Symptoms[1] = "Losing awareness and staring blankly into space";
    Disease[2].Symptoms[2] = "Becoming stiff";
    Disease[2].Symptoms[3] = "Collapsing";
    Disease[2].counter = 0;
    Disease[2].percentage = 0;
    Disease[2].idofdepartment = 1;
    Disease[2].NumberOfSymptoms = 4;
    Disease[2].PatientName[0] = "Adam Yossef";
    Disease[2].NumberOfPatientWithDiseace++;
    Disease[2].GeneralInfo = "Epilepsy is a central nervous system  disorder in which brain activity becomes abnormal causing seizures of unusual behavior ";
    // Disease[2].PatientOfDisease[2] = "";

    Disease[3].Department = "brain";
    Disease[3].mTitle = "alzheimer";
    Disease[3].mID = 3;
    Disease[3].Symptoms[0] = "Memory loss that disrupts daily life";
    Disease[3].Symptoms[1] = "Taking longer to complete normal daily tasks";
    Disease[3].Symptoms[2] = "Repeating questions or forgetting recently learned information";
    Disease[3].Symptoms[3] = "Losing track of dates or knowing current location";
    Disease[3].counter = 0;
    Disease[3].percentage = 0;
    Disease[3].idofdepartment = 1;
    Disease[3].NumberOfSymptoms = 4;
    Disease[3].PatientName[0] = "Mahmoud Ali";
    Disease[3].NumberOfPatientWithDiseace++;
    Disease[3].GeneralInfo = "Alzheimer's disease is the most common type of dementia. It is a progressive disease beginning with mild memory loss and possibly leading to loss of the ability to carry on a conversation.";
    //Disease[3].PatientOfDisease[2] = "";

    Disease[4].Department = "skin";
    Disease[4].mTitle = "smallpox";
    Disease[4].mID = 4;
    Disease[4].Symptoms[0] = "Backache";
    Disease[4].Symptoms[1] = "Abdominal pain";
    Disease[4].Symptoms[2] = "Vomiting";
    Disease[4].Symptoms[3] = "Diarrhoea";
    Disease[4].counter = 0;
    Disease[4].percentage = 0;
    Disease[4].idofdepartment = 2;
    Disease[4].NumberOfSymptoms = 4;
    Disease[4].PatientName[0] = "Khaled Mohamed";
    Disease[4].NumberOfPatientWithDiseace++;
    Disease[4].GeneralInfo = "Smallpox is an infectious disease caused by variola virus which belongs to the genus Orthopoxvirus.";
    // Disease[4].PatientOfDisease[2] = "";

    Disease[5].Department = "skin";
    Disease[5].mTitle = "gout";
    Disease[5].mID = 5;
    Disease[5].Symptoms[0] = "Joint swelling";
    Disease[5].Symptoms[1] = "Sudden and sever joint paint";
    Disease[5].Symptoms[2] = "Mild fever";
    Disease[5].Symptoms[3] = "Joint stiffness";
    Disease[5].counter = 0;
    Disease[5].percentage = 0;
    Disease[5].idofdepartment = 2;
    Disease[5].NumberOfSymptoms = 4;
    Disease[5].PatientName[0] = "hassan Omer";
    Disease[5].NumberOfPatientWithDiseace++;
    Disease[5].GeneralInfo = "Gout is a common form of inflammatory arthritis that is very painful. It usually affects one joint at a time (often the big toe joint). ";

    NumberOfDoctor = 3;
    NumberOfPatient = 3;
    NumberOfDisease = 6;
}

bool CheckUsername(char DOP, string Username)
{
    bool  CheckUser = true;
   
        for (int i = 0; i < NumberOfDoctor; i++)
        {
            if (Doctor[i].mAcc.mUsername == Username)
            {
                CheckUser = false;

            }
        }
       
        for (int i = 0; i < NumberOfPatient; i++)
        {
            if (Patient[i].mAcc.mUsername == Username)
            {
                CheckUser = false;

            }
        }
        

    
    return CheckUser;
}
bool CheckPassword(char DOP, string Password)
{
    bool  CheckPass = true;
    switch (DOP)
    {
    case 'd':
    case 'D':
        for (int i = 0; i < NumberOfDoctor; i++)
        {
            if (Doctor[i].mAcc.mPassword == Password)
            {
                CheckPass = false;

            }
        }
        break;
    case 'p':
    case 'P':
        for (int i = 0; i < NumberOfPatient; i++)
        {
            if (Patient[i].mAcc.mPassword == Password)
            {
                CheckPass = false;

            }
        }
        break;

    }
    return CheckPass;

}
char CheckLogin(string Username, string Password, int& ID)
{

    bool IsDoctor = false, IsPatient = false;
    for (int i = 0; i < NumberOfDoctor; i++)
    {
        if (Username == Doctor[i].mAcc.mUsername && Password == Doctor[i].mAcc.mPassword)
        {
            IsDoctor = true;
            Id = i;
        }
        else
            if (Username == Doctor[i].mAcc.mUsername && Password != Doctor[i].mAcc.mPassword)
            {
                while (Password != Doctor[i].mAcc.mPassword)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\tyour password isn't true please try again: ";
                    char Pass = '0';
                    string NewPassword;

                    while (Pass != '\r')
                    {
                        Pass = _getch();
                        if (Pass == '\r')
                            break;
                        if (Pass == '\b')
                        {
                            Password.pop_back();
                            cout << "\b \b";

                            continue;
                        }
                        cout << "*";
                        NewPassword += Pass;

                    }
                    Password = NewPassword;

                }
                cout << "\n";
                IsDoctor = true;
                Id = i;
            }
    }SetConsoleTextAttribute(h, 15);
    for (int i = 0; i < NumberOfPatient; i++)
    {
        if (Username == Patient[i].mAcc.mUsername && Password == Patient[i].mAcc.mPassword)
        {
            IsPatient = true;
            Id = i;

        }
        else
            if (Username == Patient[i].mAcc.mUsername && Password != Patient[i].mAcc.mPassword)
            {
                while (Password != Patient[i].mAcc.mPassword)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\tyour password isn't true please try again: ";
                    char Pass = '0';
                    string NewPassword;

                    while (Pass != '\r')
                    {
                        Pass = _getch();
                        if (Pass == '\r')
                        {
                            break;
                        }
                        if (Pass == '\b \b')
                        {
                            Password.pop_back();
                            cout << "\b";

                            continue;
                        }
                        cout << "*";
                        NewPassword += Pass;

                    }
                    Password = NewPassword;
                    cout << '\n';
                }
                IsPatient = true;
                Id = i;
            }
        SetConsoleTextAttribute(h, 15);
    }

    if (IsDoctor)
        return 'D';
    else
        if (IsPatient)
            return'P';
        else
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tERORR ! This account is not registered befor please register first \n";
            return 'N';
        }
    SetConsoleTextAttribute(h, 15);
}
void Register()
{

    string Username, Password, gender, info, name;
    int age;
    bool NotExsistUsername = false, NotExsistPassword = false;
    char DOP = 'n';
    SetConsoleTextAttribute(h, 15);
    cout << "\n\t\t\t\tpress D for doctor \n\t\t\t\tpress p for patient \n";

    cout << "\t\t\t\tplease enter your choice : ";
    cin >> DOP;
    while (DOP != 'd' && DOP != 'D' && DOP != 'P' && DOP != 'p')
    {
        cout << "\t\t\t\tplease choose (d or p ) : ";
        cin >> DOP;
    }

    switch (DOP)
    {
    case 'd':
    case 'D':
        cout << "\t\t\t\tplease enter your username : ";
        cin >> Username;
        NotExsistUsername = CheckUsername(DOP, Username);

        while (NotExsistUsername == false)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tthis username isn't available please enter a new one : ";
            cin >> Username;
            NotExsistUsername = CheckUsername(DOP, Username);
        }
        SetConsoleTextAttribute(h, 15);
        Doctor[NumberOfDoctor].mAcc.mUsername = Username;
        cout << "\t\t\t\tplease enter your password : ";
        cin >> Password;
        NotExsistPassword = CheckPassword(DOP, Password);

        while (NotExsistPassword == false)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tthis passwors isn't available please enter a new one : ";
            cin >> Password;
            NotExsistPassword = CheckPassword(DOP, Password);
        }
        SetConsoleTextAttribute(h, 15);
        Doctor[NumberOfDoctor].mAcc.mPassword = Password;
        cout << "\t\t\t\tplease enter your name : ";
        cin.ignore();
        getline(cin, name);
        Doctor[NumberOfDoctor].mName = name;
        cout << "\t\t\t\tplease enter your age : ";
        cin.ignore();
        cin >> age;
        Doctor[NumberOfDoctor].mAge = age;
        cout << "\t\t\t\tplease enter your gender : ";
        cin.ignore();
        getline(cin, gender);
        Doctor[NumberOfDoctor].mGender = gender;
        cout << "\t\t\t\tplease enter medical field : ";
        cin.ignore();
        cin >> info;
        Doctor[NumberOfDoctor].mInfo = info;
        NumberOfDoctor++;

        break;
    case 'p':
    case 'P':
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\tplease enter your username : ";
        cin >> Username;
        NotExsistUsername = CheckUsername(DOP, Username);

        while (NotExsistUsername == false)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tthis username isn't available please enter a new one : ";
            cin >> Username;
            NotExsistUsername = CheckUsername(DOP, Username);
        }
        SetConsoleTextAttribute(h, 15);
        Patient[NumberOfPatient].mAcc.mUsername = Username;
        cout << "\t\t\t\tplease enter your password : ";
        cin >> Password;
        NotExsistPassword = CheckPassword(DOP, Password);

        while (NotExsistPassword == false)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tthis passwors isn't available please enter a new one : ";
            cin >> Password;
            NotExsistPassword = CheckPassword(DOP, Password);
        }
        SetConsoleTextAttribute(h, 15);
        Patient[NumberOfPatient].mAcc.mPassword = Password;

        cout << "\t\t\t\tplease enter your name : ";
        cin >> name;
        Patient[NumberOfPatient].mName = name;
        cout << "\t\t\t\tplease enter your age : ";
        cin >> age;
        Patient[NumberOfPatient].mAge = age;
        cout << "\t\t\t\tplease enter your gender : ";
        cin >> gender;
        Patient[NumberOfPatient].mGender = gender;
        NumberOfPatient++;

        break;
    }

}

void read()
{

    fstream in("UserData.txt", ios::in);

    if (!in)
    {
        cout << "file not open";
        return;
    }
std::string line;
std::string lines[30][25];
int lineCount = 0;
int MaxLine[20];
while (std::getline(in, line))
{
    std::stringstream ss(line);
    std::string element;
    int elementCount = 0;
    while (std::getline(ss, element, ','))
    {
        lines[lineCount][elementCount] = element;
        elementCount++;


    }
    MaxLine[lineCount] = elementCount;
    lineCount++;

}
in.close();

// Print the lines
/*  for (int i = 0; i < lineCount; i++)
  {
      for (int j = 0; j <MaxLine[i] ; j++)
      {
          std::cout << lines[i][j] << " ";
      }
      std::cout << std::endl;
  }*/
int z = 0, x = 0;
NumberOfDoctor = stoi(lines[z++][x]);


for (int i = 0; i < NumberOfDoctor; i++)
{
    x = 0;
    Doctor[i].mAcc.mUsername = lines[z][x++];

    Doctor[i].mAcc.mPassword = lines[z][x++];
    Doctor[i].mName = lines[z][x++];
    Doctor[i].mAge = stoi(lines[z][x++]);
    Doctor[i].mGender = lines[z][x++];
    Doctor[i].mInfo = lines[z][x++];
    Doctor[i].NumberOfDisease = stoi(lines[z][x++]);
    for (int k = 0; k < Doctor[i].NumberOfDisease; k++)//disease of doctor
    {
        Doctor[i].mDis[k].mTitle = lines[z][x++];
        Doctor[i].mDis[k].NumberOfSymptoms = stoi(lines[z][x++]);
        for (int j = 0; j < Doctor[i].mDis[i].NumberOfSymptoms; j++)
        {
            Doctor[i].mDis[k].Symptoms[j] = lines[z][x++]; //symptom of dis of doctor 
        }
    }

    z++;
}




NumberOfPatient = stoi(lines[z++][0]);

for (int i = 0; i < NumberOfPatient; i++)
{

    x = 0;
    Patient[i].mAcc.mUsername = lines[z][x++];
    //cout << Patient[i].mAcc.mUsername;
    Patient[i].mAcc.mPassword = lines[z][x++];
    // cout << Patient[i].mAcc.mPassword;
    Patient[i].mName = lines[z][x++];
    // cout << Patient[i].mName;
    Patient[i].mAge = stoi(lines[z][x++]);
    // cout << Patient[i].mAge;
    Patient[i].mGender = lines[z][x++];
    //  cout << Patient[i].mGender;
    Patient[i].NumberOfDiagnosisHistory = stoi(lines[z][x++]);
    //   cout << Patient[i].NumberOfDiagnosisHistory<<Patient[i].mAcc.mUsername;
    Patient[i].NumberOfDSymptomOfPatient = stoi(lines[z][x++]);
    //  cout << "3";
    for (int k = 0; k < Patient[i].NumberOfDiagnosisHistory; k++)
    {

        Patient[i].mDiagnosisHistory[k] = lines[z][x++];
    }
    for (int j = 0; j < Patient[i].NumberOfDSymptomOfPatient; j++)
    {
        Patient[i].mSymptom[j] = lines[z][x++];
    }
    z++;

}

NumberOfDepartment = stoi(lines[z++][0]);
x = 0;
for (int i = 0; i < NumberOfDepartment; i++)
{

    department[i] = lines[z][x++];
}
z++;
NumberOfDisease = stoi(lines[z++][0]);


for (int i = 0; i < NumberOfDisease; i++)
{
    x = 0;


    Disease[i].Department = lines[z][x++];
    // cout << Disease[i].Department;
    Disease[i].mTitle = lines[z][x++];
    // cout << Disease[i].mTitle;
    Disease[i].mID = stoi(lines[z][x++]);
    // cout << Disease[i].mID;
    Disease[i].GeneralInfo = lines[z][x++];
    //  cout << Disease[i].GeneralInfo;
    Disease[i].percentage = stoi(lines[z][x++]);
    //  cout << Disease[i].percentage;
    Disease[i].idofdepartment = stoi(lines[z][x++]);

    // cout << Disease[i].idofdepartment;
    Disease[i].NumberOfPatientWithDiseace = stoi(lines[z][x++]);
    //  cout << Disease[i].NumberOfPatientWithDiseace;
    Disease[i].counter = stoi(lines[z][x++]);
    //  cout << Disease[i].counter;
    Disease[i].NumberOfSymptoms = stoi(lines[z][x++]);
    //cout << Disease[i].NumberOfSymptoms;

    for (int k = 0; k < Disease[i].NumberOfSymptoms; k++)
    {
        Disease[i].Symptoms[k] = lines[z][x++];

    }

    for (int j = 0; j < Disease[i].NumberOfPatientWithDiseace; j++)
    {
        Disease[i].PatientName[j] = lines[z][x++];

    }
    z++;

}//disease


//cout << "hallllllllllllla hallllla";

}
void Write()
{

    fstream out("UserData.txt", ios::out);
    if (!out)
    {
        cout << "file not open";
        return;
    }
    out << NumberOfDoctor << "\n";
    for (int i = 0; i < NumberOfDoctor; i++)
    {
        out << Doctor[i].mAcc.mUsername << "," << Doctor[i].mAcc.mPassword << "," << Doctor[i].mName << "," << Doctor[i].mAge << "," << Doctor[i].mGender << "," << Doctor[i].mInfo << "," << Doctor[i].NumberOfDisease << ",";
        for (int k = 0; k < Doctor[i].NumberOfDisease; k++)//disease of doctor
        {
            out << Doctor[i].mDis[k].mTitle << "," << Doctor[i].mDis[k].NumberOfSymptoms << ",";
            for (int j = 0; j < Doctor[i].mDis[k].NumberOfSymptoms; j++)
            {
                out << Doctor[i].mDis[k].Symptoms[j] << ",";
            }
        }
        out << "\n";
    }
    out << NumberOfPatient << "\n";
    for (int i = 0; i < NumberOfPatient; i++)
    {
        out << Patient[i].mAcc.mUsername << "," << Patient[i].mAcc.mPassword << "," << Patient[i].mName << "," << Patient[i].mAge << "," << Patient[i].mGender << "," << Patient[i].NumberOfDiagnosisHistory << "," << Patient[i].NumberOfDSymptomOfPatient << ",";
        for (int k = 0; k < Patient[i].NumberOfDiagnosisHistory; k++) {
            out << Patient[i].mDiagnosisHistory[k] << ",";
        }
        for (int j = 0; j < Patient[i].NumberOfDSymptomOfPatient; j++) {
            out << Patient[i].mSymptom[j] << ",";
        }
        out << "\n";
    }
    out << NumberOfDepartment << "\n";
    for (int i = 0; i < NumberOfDepartment; i++)
    {
        out << department[i] << ",";
    }

    out << "\n" << NumberOfDisease << "\n";
    for (int i = 0; i < NumberOfDisease; i++)
    {
        out << Disease[i].Department << "," << Disease[i].mTitle << "," << Disease[i].mID << "," << Disease[i].GeneralInfo << "," << Disease[i].percentage << "," << Disease[i].idofdepartment << "," << Disease[i].NumberOfPatientWithDiseace << "," << Disease[i].counter << "," << Disease[i].NumberOfSymptoms << ",";
        for (int k = 0; k < Disease[i].NumberOfSymptoms; k++)
        {
            out << Disease[i].Symptoms[k] << ",";
        }

        for (int j = 0; j < Disease[i].NumberOfPatientWithDiseace; j++)
        {
            out << Disease[i].PatientName[j] << ",";
        }
        out << "\n";
    }

    out.close();
}

void deleteRepeated(string arr[], int& n) {
    int last = 0;
    // Iterate over each element of the array
    for (int i = 0; i < n; i++) {
        bool found = false;
        // Compare the current element with all previous elements in the array
        for (int j = 0; j < last; j++) {
            // If a duplicate is found, set the flag and break the loop
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        // If the element is not a duplicate, add it to the array
        if (!found) {
            arr[last] = arr[i];
            last++;
        }
    }
    // Return the new size of the array
    n = last;
}

//doctor
void ChangeTitle(string NewTitle, int DiseaseIndix)
{
    string Lastname = Doctor[Id].mDis[DiseaseIndix].mTitle;


    for (int i = 0; i < NumberOfDisease; i++)
    {
        if (Lastname == Disease[i].mTitle)
            Disease[i].mTitle = NewTitle;
    }
    Doctor[Id].mDis[DiseaseIndix].mTitle = NewTitle;


    cout << "\t\t\t\tchange the title done \n";
}
void ChangeSymptom(std::string NewSymptom, int DiseaseIndix, int SympotomIndix)
{

    bool returnofcheck = CheckSymptoms(NewSymptom, DiseaseIndix);
    if (returnofcheck == true)
    {
        SetConsoleTextAttribute(h, 4);
        do {
            cout << "\t\t\t\tthis sympotom already exist enter new one :";
            cin >> NewSymptom;
            returnofcheck = CheckSymptoms(NewSymptom, DiseaseIndix);
        } while (returnofcheck == true);

    }
    
        Doctor[Id].mDis[DiseaseIndix].Symptoms[SympotomIndix] = NewSymptom;
    
}
void EdieInfoo(std::string NewInfo)
{
    Doctor[Id].mInfo = NewInfo;
}
void ChangeAge(int NewAge)
{
    Doctor[Id].mAge = NewAge;
}
void ChangeUsrname(std::string NewUsername)
{
    char DOP = 'D';
    bool Check = CheckUsername(DOP, NewUsername);
    if (Check == false)
    {
        do
        {
            SetConsoleTextAttribute(h, 4);//purple
            cout << "\t\t\t\t## This Username isn't  avilable plaese enter new one ## ";
            cin >> NewUsername;
            Check = CheckUsername(DOP, NewUsername);
        } while (Check == false);
    }
    SetConsoleTextAttribute(h, 8);//purple

    Doctor[Id].mAcc.mUsername = NewUsername;

}
void ChangePassword(std::string NewPassword)
{
    char DOP = 'D';
    bool Check = CheckPassword(DOP, NewPassword);
    if (Check == false)
    {
        do
        {
            SetConsoleTextAttribute(h, 4);//purple
            cout << "\t\t\t\t## This Password isn't  avilable plaese enter new one ## ";
            cin >> NewPassword;
            Check = CheckPassword(DOP, NewPassword);
        } while (Check == false);
    }
    SetConsoleTextAttribute(h, 8);//purple
    Doctor[Id].mAcc.mPassword = NewPassword;
}
void EditDisease(string Title, string NewSymptom) {
    int DiseaseAnswer;
    bool exitOFEdite = true;
    int DiseaeseIndix = -1;
    // / std::string NewSymptom; /
    for (int i = 0; i < Doctor[Id].NumberOfDisease; i++)
    {
        if (Doctor[Id].mDis[i].mTitle == Title)
        {
            DiseaeseIndix = i;
        }

    }
    if (DiseaeseIndix == -1)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\t## you cant edit this diseaese ## \n";
    }
    else
    {

        do
        {
            SetConsoleTextAttribute(h, 11);
            if (exitOFEdite == false)
                break;
            std::cout << "\t\t\t\tpress(1)if you want to add symptoms :\n";
            std::cout << "\t\t\t\tpress(2)if you want to change symptoms :\n";
            std::cout << "\t\t\t\tpress(3)if you want to change title :\n";
            std::cout << "\t\t\t\tpress(4)if you want to delete symptom :\n";
            std::cout << "\t\t\t\tpress(5)if you want to exit : ";

            std::cin >> DiseaseAnswer;

            if (DiseaseAnswer > 5 || DiseaseAnswer < 1)
            {
                do
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\tPlease enter number from (1 to 5) \n";
                    cout << "\t\t\t\t";
                    std::cin >> DiseaseAnswer;
                } while (DiseaseAnswer > 5 || DiseaseAnswer < 1);
            }
            SetConsoleTextAttribute(h, 11);
            string cont;
            switch (DiseaseAnswer) {
            case 1:

                do
                {
                    SetConsoleTextAttribute(h, 15);
                    cout << "\t\t\t\t enter new sympotom : ";
                    string sym;
                    cin >> sym;
                    bool Cannot = CheckSymptoms(sym,DiseaeseIndix);
                    if (Cannot)
                    {
                        cout << "this sympotom already exist";
                    }
                    else
                    {
                        Doctor[Id].mDis[DiseaeseIndix].Symptoms[Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms] = sym;
                        Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms++;
                    }

                    cout << "\n\t\t\t\t do you want to add a new sympotom ( y / n )";
                    cin >> cont;
                    if (cont != "Y" && cont != "y" && cont != "n" && cont != "N")
                    {
                        do
                        {
                            SetConsoleTextAttribute(h, 4);
                            cout << "\n\t\t\t\tPlease choose ( Y or N ) ";
                            cin >> cont;

                        } while (cont != "Y" && cont != "y" && cont != "n" && cont != "N");
                    }
                    SetConsoleTextAttribute(h, 15);


                } while (cont == "y" || cont == "Y");
                SetConsoleTextAttribute(h, 11);
                break;
            case 2:
                SetConsoleTextAttribute(h, 15);
                for (int i = 0; i < Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms; i++)
                {
                    cout << "\t\t\t\t" << i + 1 << " " << Doctor[Id].mDis[DiseaeseIndix].Symptoms[i] << "\n";

                }
                int choice;
                if (Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms > 0)
                {

                    cout << "\t\t\t\t\choose the number of certin sympotoms you want to change  : ";
                    cin.ignore();
                    cin >> choice;

                    if (choice > Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms || choice < 1)
                    {
                        do
                        {
                            SetConsoleTextAttribute(h, 4);
                            cout << "\t\t\t\tPlease enter number from (1 to " << Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms << " )\n";
                            /* cout << "\t\t\t\t";*/
                            std::cin >> choice;
                        } while (choice > Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms || choice < 1);
                    }
                    SetConsoleTextAttribute(h, 15);

                    choice--;//indext bta3 symptom 
                    cout << "\t\t\t\t please enter new symptom:";
                    cin.ignore();
                    getline(cin, NewSymptom);

                    ChangeSymptom(NewSymptom, DiseaeseIndix, choice);
                    break;
                }
                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "##you dont have symptoms to change\n";
                }
                SetConsoleTextAttribute(h, 15);
                break;// hna
            case 3:
                SetConsoleTextAttribute(h, 15);
                std::cout << "\t\t\t\tenter your new title :";

                cin.ignore();
                getline(std::cin, Title);
                bool Titlefound;
                Titlefound = CheckTittle(Title);
                if (Titlefound == true)
                {
                    do
                    {
                        SetConsoleTextAttribute(h, 4);
                        cout << "\t\t\t\tyou have aleady this title choose another one ";
                        cin.ignore();
                        getline(std::cin, Title);
                        Titlefound = CheckTittle(Title);
                    } while (Titlefound == true);
                }
                SetConsoleTextAttribute(h, 15);
                if (Titlefound == false)
                {
                    ChangeTitle(Title, DiseaeseIndix);
                }
                break;
            case 4:
                DeleteCertianSymptom(DiseaeseIndix);
                break;
            case 5:
                exitOFEdite = false;
                break;

            }

        } while (DiseaseAnswer >= 1 && DiseaseAnswer <= 5);
        EditDataInArrayOfDisease(DiseaeseIndix);
    }

}
bool CheckTittle(std::string Title)
{
    bool Havetitle = false;

    for (int i = 0; i < NumberOfDisease; i++)
    {
        if (Disease[i].mTitle == Title)
        {
            Havetitle = true;
            break;
        }
    }
    if (Havetitle == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void AddToArrayOfDisease()
{
    Disease[NumberOfDisease].Department = Doctor[Id].mDis[Doctor[Id].NumberOfDisease].Department;
    Disease[NumberOfDisease].mTitle = Doctor[Id].mDis[Doctor[Id].NumberOfDisease].mTitle;
    Disease[NumberOfDisease].mID = Doctor[Id].mDis[Doctor[Id].NumberOfDisease].mID;
    Disease[NumberOfDisease].NumberOfSymptoms = Doctor[Id].mDis[Doctor[Id].NumberOfDisease].NumberOfSymptoms;
    for (int i = 0; i < Disease[NumberOfDisease].NumberOfSymptoms; i++)
    {
        Disease[NumberOfDisease].Symptoms[i] = Doctor[Id].mDis[Doctor[Id].NumberOfDisease].Symptoms[i];
    }
    NumberOfDisease++;

}
void AddDepartment()
{
    string NewDepartment;
    string Answer = "N";

    do
    {
        SetConsoleTextAttribute(h, 15);
        bool IsFound = true;
        std::cout << "\t\t\t\t\Enter your department title : ";
        cin.ignore();
        getline(std::cin, NewDepartment);

        for (int i = 0; i < NumberOfDepartment; i++)
        {
            if (department[i] == NewDepartment)
            {
                SetConsoleTextAttribute(h, 4);
                std::cout << "\t\t\t\tThe Department exist\n";
                std::cout << "\t\t\t\tIf you want try again press(y/n) : ";
                cin.ignore();
                std::cin >> Answer;


                if (Answer != "y" && Answer != "Y" && Answer != "N" && Answer != "n")
                {
                    do
                    {
                        SetConsoleTextAttribute(h, 4);
                        cout << "\t\t\t\tplease chose(y/n):";
                        cin.ignore();
                        cin >> Answer;

                    } while (Answer != "y" && Answer != "Y" && Answer != "N" && Answer != "n");
                }



                IsFound = false;
                break;
            }
            SetConsoleTextAttribute(h, 15);
        }
        if (IsFound == true)
        {

            department[NumberOfDepartment] = NewDepartment;
            NumberOfDepartment++;

            break;
        }

    } while (Answer == "y" || Answer == "Y");

}
bool CheckSymptomsWhenAddDisease(string Symptom, int Count) {

    for (int i = 0; i < Doctor[Id].mDis[Doctor[Id].NumberOfDisease].NumberOfSymptoms; i++)
    {
        if (Doctor[Id].mDis[Doctor[Id].NumberOfDisease].Symptoms[i] == Symptom)
        {
            return true;

        }

    }
    return false;
}
bool CheckSymptoms(string Symptom, int DiseaseIndix) {
    for (int i = 0; i < Doctor[Id].mDis[DiseaseIndix].NumberOfSymptoms; i++) {
        if (Doctor[Id].mDis[DiseaseIndix].Symptoms[i] == Symptom) {
            return true;
        }
    }

    return false;
}
void AddDisease()
{
    int DepartmentChoice;
    do {
        SetConsoleTextAttribute(h, 11);
        cout << "\t\t\t\t witch department you want to add your New Disease in :\n";
        for (int i = 0; i < NumberOfDepartment; i++)
        {

            cout << "\t\t\t\t" << i + 1 << "  " << department[i] << "\n";

        }
        cout << "\t\t\t\t" << NumberOfDepartment + 1 << " ADD NEW DEPARTMENT ";
        cin >> DepartmentChoice;

        if (DepartmentChoice > NumberOfDepartment + 1 || DepartmentChoice < 1)
        {
            do
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\tplease enter number betwen (1 to " << NumberOfDepartment + 1 << " ) ";
                cin.ignore();
                cin >> DepartmentChoice;
            } while (DepartmentChoice > NumberOfDepartment + 1 || DepartmentChoice < 1);

        }
        SetConsoleTextAttribute(h, 11);

        if (DepartmentChoice == NumberOfDepartment + 1)
        {
            AddDepartment();
        }

    } while (DepartmentChoice > NumberOfDepartment + 1);


    Doctor[Id].mDis[Doctor[Id].NumberOfDisease].Department = department[DepartmentChoice - 1];

    Doctor[Id].mDis[Doctor[Id].NumberOfDisease].idofdepartment = --DepartmentChoice;
    Doctor[Id].mDis[Doctor[Id].NumberOfDisease].mID = NumberOfDisease;

    string Title;//add
    SetConsoleTextAttribute(h, 15);
    std::cout << "\t\t\t\tenter your disease title :";
    // std::cin.ignore();
    cin >> Title;//Change variable
    bool Check = CheckTittle(Title);
    if (Check == true)
    {
        do
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tThis disease exist\n";
            std::cout << "\t\t\t\tenter your disease title :\n";
            std::cin.ignore();
            getline(std::cin, Title);//Change variable
            Check = CheckTittle(Title);

        } while (Check == true);
    }
    SetConsoleTextAttribute(h, 14);
    if (Check == false)
    {
        Doctor[Id].mDis[Doctor[Id].NumberOfDisease].mTitle = Title;
        Disease[NumberOfDisease].Department = Doctor[Id].mDis[Doctor[Id].NumberOfDisease].Department;
        SetConsoleTextAttribute(h, 15);
        std::cout << "\t\t\t\tenter disease's sympotoms ";
        string cont;
        int i = 0;
        int Counter = 0;

        do
        {
            bool ChSym;
            std::string Sym;
            cout << "\t\t\t\t add  sympotom : ";
            cin.ignore();
            getline(std::cin, Sym);
            ChSym = CheckSymptomsWhenAddDisease(Sym, Doctor[Id].NumberOfDisease);
            if (ChSym) {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\tThis Symptom exist\n";
                cout << "\t\t\t\tIf you want try  again press ( y/n ): ";
                cin >> cont;
            }

            else {
                SetConsoleTextAttribute(h, 15);
                Doctor[Id].mDis[Doctor[Id].NumberOfDisease].Symptoms[i] = Sym;
                Doctor[Id].mDis[Doctor[Id].NumberOfDisease].NumberOfSymptoms++;

                cout << "\n\t\t\t\t do you want to add another sympotom ( y / n )";
                cin >> cont;
            }
            if (cont != "Y" && cont != "y" && cont != "n" && cont != "N")
            {
                do
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\n\t\t\t\tPlease choose ( Y or N ) " << endl;

                    cin >> cont;
                    cin.ignore();

                } while (cont != "Y" && cont != "y" && cont != "n" && cont != "N");
            }
            SetConsoleTextAttribute(h, 15);
            i++;
            Counter++;
        } while (cont == "Y" || cont == "y");

        Doctor[Id].mDis[Doctor[Id].NumberOfDisease].mID = NumberOfDisease;
        AddToArrayOfDisease();
        Doctor[Id].NumberOfDisease++;
    }

}
void DisplayAll()
{
    SetConsoleTextAttribute(h, 15);
    char answer;
    int certiandisease;
    for (int i = 0; i < NumberOfDisease; i++)
    {
        cout << "\t\t\t\t disease number " << i + 1 << " name is: ";
        cout << Disease[i].mTitle << "\n";

        cout << "\t\t\t\t disease number " << i + 1 << " id  is: ";
        cout << Disease[i].mID << "\n";

    }
    cout << "\t\t\t\tdo you want to view the patient with certian disease (y/n)? :";
    cin >> answer;
    while ((answer != 'Y') && (answer != 'y') && (answer != 'n') && (answer != 'N'))
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\tplease choose y or n :";
        cin >> answer;

    }
    if (answer == 'y' || answer == 'Y') {
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\tenter the id of the certian disease :";
        cin >> certiandisease;
        if (certiandisease > NumberOfDisease)
        {
            do
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\t please choose from( 0 to " << NumberOfDisease - 1 << ") :";
                cin >> certiandisease;
            } while (certiandisease > NumberOfDisease);
        }
        // ceck en all id from 1 to number of disease -1;
        SetConsoleTextAttribute(h, 15);
        viewpatientwithcertiandisease(certiandisease);

    }
    SetConsoleTextAttribute(h, 15);


}
void viewpatientwithcertiandisease(int certiandisease) {
    SetConsoleTextAttribute(h, 15);
    cout << " \t\t\t\tthe patient name is ";
    if (Disease[certiandisease].NumberOfPatientWithDiseace == 0)
    {
        SetConsoleTextAttribute(h, 15);
        cout << " no one ";

    }
    for (int i = 0; i < Disease[certiandisease].NumberOfPatientWithDiseace; i++)
    {
        SetConsoleTextAttribute(h, 15);
        cout << i + 1 << Disease[certiandisease].PatientName[i] << "\n";
    }
}
void DeleteCertianSymptom(int DiseaeseIndix)
{

    if (Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms == 0) {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\tthere is no symptome to delete \n";

    }
    else
    {
        SetConsoleTextAttribute(h, 15);
        for (int i = 0; i < Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms; i++)
        {
            cout << "\t\t\t\t" << Doctor[Id].mDis[DiseaeseIndix].Symptoms[i] << "\n";
        }
        int answer;
        cout << " \t\t\t\twant to delete all symptoms press(1) :\n";
        cout << " \t\t\t\t\want to delete certian symptom press(2) :";
        cin.ignore();
        cin >> answer;
        if (answer != 1 && answer != 2)
        {
            do
            {
                SetConsoleTextAttribute(h, 4);
                cout << " \t\t\t\tplease choose from (1 or 2):";
                cin.ignore();

                cin >> answer;
            } while (answer != 1 && answer != 2);

        }
        SetConsoleTextAttribute(h, 15);
        switch (answer)
        {
        case 1:

            for (int i = 0; i < Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms; i++)
            {
                Doctor[Id].mDis[DiseaeseIndix].Symptoms[i] = "NULL";
            }
            Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms = 0;
            break;
        case 2:
            SetConsoleTextAttribute(h, 15);
            char Del;
            do {

                int CertianSym;
                for (int i = 0; i < Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms; i++)
                {
                    cout << "\t\t\t\t" << 1 + i << Doctor[Id].mDis[DiseaeseIndix].Symptoms[i] << "\n";
                }
                cout << "\t\t\t\tchoose the certian symptom you want to delete :";
                cin >> CertianSym;
                if (CertianSym<1 || CertianSym>Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms)
                {
                    do
                    {
                        SetConsoleTextAttribute(h, 4);
                        cout << " \t\t\t\tplease choose from (1 to " << Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms << ")";
                        cin.ignore();
                        cin >> CertianSym;
                    } while (CertianSym<1 || CertianSym>Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms);

                }
                SetConsoleTextAttribute(h, 15);
                for (int i = CertianSym - 1; i < Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms; i++)
                {
                    Doctor[Id].mDis[DiseaeseIndix].Symptoms[i] = Doctor[Id].mDis[DiseaeseIndix].Symptoms[i + 1];
                }
                Doctor[Id].mDis[DiseaeseIndix].Symptoms[Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms - 1] = "NULL";
                Doctor[Id].mDis[DiseaeseIndix].NumberOfSymptoms--;

                cout << "\t\t\t\t\ want to delete another symptom  press (y or n):";
                cin.ignore(-1);
                cin >> Del;
                if (Del != 'Y' && Del != 'y' && Del != 'N' && Del != 'n')
                {
                    do
                    {
                        SetConsoleTextAttribute(h, 4);
                        cout << " \t\t\t\tplease choose n or y :";
                        cin.ignore();
                        cin >> Del;
                    } while (Del != 'Y' && Del != 'y' && Del != 'N' || Del != 'n');
                }
                SetConsoleTextAttribute(h, 15);

            } while (Del == 'Y' || Del == 'y');

            break;
        }

    }

}
void EditDataInArrayOfDisease(int IndixOfDiseaseOfDoctor)
{
    for (int i = 0; i < NumberOfDisease; i++)
    {
        if (Disease[i].mTitle == Doctor[Id].mDis[0].mTitle)
        {
            Disease[i].Department = Doctor[Id].mDis[IndixOfDiseaseOfDoctor].Department;
            Disease[i].mTitle = Doctor[Id].mDis[IndixOfDiseaseOfDoctor].mTitle;
            Disease[i].mID = Doctor[Id].mDis[IndixOfDiseaseOfDoctor].mID;
            Disease[i].NumberOfSymptoms = Doctor[Id].mDis[IndixOfDiseaseOfDoctor].NumberOfSymptoms;
            for (int j = 0; j < Disease[i].NumberOfSymptoms; j++)
            {
                Disease[i].Symptoms[j] = Doctor[Id].mDis[IndixOfDiseaseOfDoctor].Symptoms[j];
            }
        }
    }
}
//patient

void MakeSureTheDiagnosisHistoryIsUniqe()
{
    deleteRepeated(Patient[Id].mDiagnosisHistory, Patient[Id].NumberOfDiagnosisHistory);
}
void EditinfoForPatient() {
    int l;//answer bta3 edit
    char replay = 'y';
    int NewAgeForPatient;
    string NewNameForPatient;
    string NewUserNameForPatient;
    string NewPasswordForPatient;

    do {
        SetConsoleTextAttribute(h, 8);


        cout << " \t\t\t\tname is:" << Patient[Id].mName << "\n";
        cout << " \t\t\t\tusername is:" << Patient[Id].mAcc.mUsername << "\n";
        cout << " \t\t\t\tpassword is:" << Patient[Id].mAcc.mPassword << "\n";
        cout << " \t\t\t\tage is:" << Patient[Id].mAge << "\n";
        if (Patient[Id].NumberOfDiagnosisHistory > 0)
        {
            for (int i = 0; i < Patient[Id].NumberOfDiagnosisHistory; i++)
            {
                cout << "\t\t\t\t your diagnosis histry is:" << Patient[Id].mDiagnosisHistory[i] << "\n";
            }
        }






        SetConsoleTextAttribute(h, 13);
        bool LogOut = false;
        cout << "\t\t\t\tWHAT DO YOY WANT TO EDIT ?\n";
        SetConsoleTextAttribute(h, 14);
        cout << "\t\t\t\tPRESS(1):TO CHANGE NAME\n";
        cout << "\t\t\t\tPRESS(2):TO CHANGE USERNAME\n";
        cout << "\t\t\t\tPRESS(3):TO CHANGE PASSWORD\n";
        cout << "\t\t\t\tPRESS(4):TO CHANGE AGE\n";//before age _ after AGE
        cout << "\t\t\t\tPRESS(5):TO DELETE DIAGNOSIS HISTORY\n";
        cout << "\t\t\t\tPRESS(6):TO LOG OUT: ";

        cin >> l;
        if (l < 1 || l > 6) {
            do {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\tchoose from 1 to 5";
                cin >> l;

            } while (l < 1 || l >= 6);
        }
        SetConsoleTextAttribute(h, 14);
        switch (l) {
        case 1:
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\tENTER YOUR NEW NAME : ";
            cin.ignore();
            getline(cin, NewNameForPatient);
            ChangeNameForPatient(NewNameForPatient);
            break;
        case 2:
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\tENTER YOUR NEW USERNAME : ";
            cin.ignore();
            getline(cin, NewUserNameForPatient);
            ChangeUsernameForPatient(NewUserNameForPatient);
            break;
        case 3:
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\tENTER YOUR NEW PASSWORD : ";
            cin.ignore();
            ChangePasswordForPatient(NewPasswordForPatient);
            break;
        case 4:
            SetConsoleTextAttribute(h, 15);
            cout << "\t\t\t\tENTER YOUR NEW AGE : ";
            cin >> NewAgeForPatient;
            ChangeAgeForPatient(NewAgeForPatient);
            break;
        case 5:
            SetConsoleTextAttribute(h, 15);
            DeleteDiagnosisHistoryForPatient();
        case 6:
            LogOut = true;
            break;
        }
        if (LogOut)
        {
            break;
        }
        cout << "\t\t\t\tDO YOU WANT TO EDIT SOME THING ELSE IN YOUR INFO?(Y/N)\n";
        cin >> replay;
        if (replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N')
        {
            do
            {
                cout << "\t\t\t\tplease choose ( y / n ) : ";

            } while (replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N');
            cout << endl;
        }

    } while (replay == 'y' || replay == 'Y');


}
void DeleteDiagnosisHistoryForPatient() {
    SetConsoleTextAttribute(h, 15);
    if (Patient[Id].NumberOfDiagnosisHistory == 0)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\tYour diagnosis history is empty " << endl;
    }
    else
    {
        SetConsoleTextAttribute(h, 14);
        for (int i = 0; i < Patient[Id].NumberOfDiagnosisHistory; i++)
        {
            cout << "\t\t\t\tDiagnosis History : " << i + 1 << "  " << Patient[Id].mDiagnosisHistory[i] << endl;

        }
        SetConsoleTextAttribute(h, 15);
        int choice;
        cout << "\t\t\t\tPRESS(1) IF YOU WANT TO DELETE ALL THE DiagnosisHistory" << endl;
        cout << "\t\t\t\tPRESS(2) IF YOU WANT TO DELETE CERTAIN DISEASE IN YOUR  DiagnosisHistory" ;
        cin >> choice;
        if (choice < 1 || choice > 2)
            do {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\tchoose  1 or 2";
                cin >> choice;

            } while (choice < 1 || choice > 2);
            SetConsoleTextAttribute(h, 15);
            switch (choice)
            {
            case 1:
                for (int i = 0; i <= Patient[Id].NumberOfDiagnosisHistory; i++)
                {
                    Patient[Id].mDiagnosisHistory[i] = "NULL";
                    Patient[Id].NumberOfDiagnosisHistory--;
                }
                Patient[Id].NumberOfDiagnosisHistory = 0;
                break;
            case 2:
                SetConsoleTextAttribute(h, 15);
                string AnswerOfDeletingHistory;
                do {

                    cout << "\t\t\t\tCHOOSE NUMBER OF DISEASE THAT YOU WANT TO DELETE" << endl;
                    for (int i = 0; i < Patient[Id].NumberOfDiagnosisHistory; i++)
                    {
                        SetConsoleTextAttribute(h, 14);
                        cout << "\t\t\t\tDiagnosis History : " << i + 1 << Patient[Id].mDiagnosisHistory[i] << endl;

                    }
                    cout << "\t\t\t\t";
                    SetConsoleTextAttribute(h, 15);
                    int NumOfDiseaseToDelete;
                    cin >> NumOfDiseaseToDelete;

                    if (NumOfDiseaseToDelete < 1 || NumOfDiseaseToDelete >  Patient[Id].NumberOfDiagnosisHistory)
                        do {
                            SetConsoleTextAttribute(h, 4);
                            cout << "\t\t\t\tchoose number between 1 to" << Patient[Id].NumberOfDiagnosisHistory << endl;
                            cin >> NumOfDiseaseToDelete;

                        } while (NumOfDiseaseToDelete < 1 || NumOfDiseaseToDelete > Patient[Id].NumberOfDiagnosisHistory);
                        SetConsoleTextAttribute(h, 15);
                        for (int i = NumOfDiseaseToDelete - 1; i < Patient[Id].NumberOfDiagnosisHistory; i++)
                        {
                            Patient[Id].mDiagnosisHistory[i] = Patient[Id].mDiagnosisHistory[i + 1];
                        }

                        Patient[Id].mDiagnosisHistory[Patient[Id].NumberOfDiagnosisHistory] = "NULL";
                        Patient[Id].NumberOfDiagnosisHistory--;

                        cout << "\t\t\t\tDO YOU WANT TO DELETE SOMETHING ELSE IN YOUR DiagnosisHistory(Y/N) ";
                        cin >> AnswerOfDeletingHistory;

                        if (AnswerOfDeletingHistory != "y" && AnswerOfDeletingHistory != "Y" && AnswerOfDeletingHistory != "N" && AnswerOfDeletingHistory != "n")
                        {
                            do
                            {
                                SetConsoleTextAttribute(h, 4);
                                cout << "\t\t\t\tplease chose(y/n):";

                                cin >> AnswerOfDeletingHistory;

                            } while (AnswerOfDeletingHistory != "y" && AnswerOfDeletingHistory != "Y" && AnswerOfDeletingHistory != "N" && AnswerOfDeletingHistory != "n");
                        }
                        SetConsoleTextAttribute(h, 15);
                } while (AnswerOfDeletingHistory == "y" || AnswerOfDeletingHistory == "Y");
            }
    }
}
void FindOutINfoAboutCertainDisease()
{
    string want;
    do
    {

        SetConsoleTextAttribute(h, 11);
        bool isFind = false;
        int certainId;
        string certainDisease;
        for (int i = 0; i < NumberOfDisease; i++)
        {

            cout << " \t\t\t\t " << Disease[i].mID + 1 << " :" << Disease[i].mTitle << endl;
        }
        SetConsoleTextAttribute(h, 15);
        cout << "\t\t\t\t Please Enter the indext of  disease you want to know about :";
       
        cin >> certainId;
        certainId = certainId - 1;


        for (int i = 0; i < NumberOfDisease; i++)
        {
            SetConsoleTextAttribute(h, 3);
            if (certainId == Disease[i].mID)
            {
                isFind = true;
                cout << "\t\t\t\t" << Disease[i].mTitle << "\n";
                cout << "\t\t\t\tThe general Information :" << Disease[i].GeneralInfo << "\n";
                cout << "\t\t\t\tThe symptoms :\n";
                for (int j = 0; j < Disease[i].NumberOfSymptoms ; j++)
                {
                    cout << "\t\t\t \t" << j + 1 << ":" << Disease[i].Symptoms[j] << "\n";
                }
                break;
            }
        }
        SetConsoleTextAttribute(h, 11);
        if (isFind == false)
        {
            SetConsoleTextAttribute(h, 4);
            cout << " \t\t\t\tYour disease not found\t\t\n";
            cout << "\t\t\t\tIf you want to know about other Disease press (Y/y) else press (N/n):";
            cin >> want;

            if (want != "Y" && want != "y" && want != "N" && want != "n")
            {
                do {
                    SetConsoleTextAttribute(h, 4);
                    cout << "\t\t\t\tPlease enter (Y/y) to complete or (N/n) to Exit ";
                    cin >> want;

                } while (want != "Y" && want != "y" && want != "N" && want != "n");
            }
        }
        SetConsoleTextAttribute(h, 11);


    } while (want == "y" || want == "Y");
}
void DiagnosisWithChoosingDepartment()
{


    string a;
    //percentage of disease you may have
    do {
        string DiseaseUhave[10], DiseaseUmayhave[10];
        int counterDiseaeUhave = 0, counterDiseaseUmayhave = 0, m = 0, n = 0;//m =counterDiseaeUhave
        float Max = 0.0;
        string maxTitle;
        bool flag = false;
        float finalpercentage[10] = { 0.0 };
        int choice, w = 0;
        string  answer;

        for (int i = 0; i < NumberOfDepartment; i++)
        {
            SetConsoleTextAttribute(h, 11);
            cout <<"\t\t\t\t" << i + 1 << "." << department[i] << "\n";
        }

        cout << "\t\t\t\tPlease choose the number of the department you need :";
        cin >> choice;
        if (choice < 1 || choice>NumberOfDepartment)
        {
            do {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\tInvalid \n";
                cout << "\t\t\t\tplease enter from 1 to " << NumberOfDepartment << " : ";
                cin >> choice;
            } while (choice < 1 && choice>NumberOfDepartment);
        }
        SetConsoleTextAttribute(h, 15);



        choice = choice - 1;
        //function in doctor by hager return noofdisease=currentSize
        for (int i = 0; i < NumberOfDisease; i++)
        {
            if (choice == Disease[i].idofdepartment)
            {
                for (int y = 0; y < Disease[i].NumberOfSymptoms; y++)
                {
                    flag = false;//a5tar y
                    if (Disease[i].symcheck[y] == false)//awl mara ,lo =true - zhr 2bl kda
                    {
                        SetConsoleTextAttribute(h, 6);
                        cout << "\t\t\t\t" << Disease[i].Symptoms[y] << "\n";
                        SetConsoleTextAttribute(h, 15);
                        cout << "\t\t\t\tEnter (Y /y) if you have this Symptoms else press (n/N)  :";
                        cin >> answer;
                        if (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
                        {
                            do {
                                SetConsoleTextAttribute(h, 4);
                                cout << "\t\t\t\tInvalid \n";
                                cout << "\t\t\t\tplease enter(Y /y) if you have this Symptoms else press (n/N) \n ";
                                cin >> a;

                            } while (a != "Y" && a != "y" && a != "N" && a != "n");
                        }
                        SetConsoleTextAttribute(h, 15);
                        if (answer == "y" || answer == "Y")
                        {
                            Disease[i].counter++;
                            Patient[Id].mSymptom[Patient[Id].NumberOfDSymptomOfPatient] = Disease[i].Symptoms[y];
                            Patient[Id].NumberOfDSymptomOfPatient++;
                            flag = true;//a5tar 3rd

                        }


                    }


                    for (int h = 0; h < NumberOfDisease; h++)//h dah ele htshek menoh
                    {

                        if (choice == Disease[h].idofdepartment)
                        {
                            for (int p = 0; p < Disease[h].NumberOfSymptoms; p++)

                            {
                                if (Disease[i].Symptoms[y] == Disease[h].Symptoms[p])//for 3la y
                                {
                                    if (i == h)//nfs diseses
                                    {
                                        break;
                                    }

                                    Disease[h].symcheck[p] = true;//zhar 2bl kda
                                    if (flag == true)

                                        Disease[h].counter++;
                                }

                            }
                        }
                    }

                }

                Disease[i].percentage = (((float)Disease[i].counter) / (Disease[i].NumberOfSymptoms)) * 100;
                if (Disease[i].percentage > 60)
                {
                    Disease[i].PatientName[Disease[i].NumberOfPatientWithDiseace] = Patient[Id].mName;//b7t name fe disease .name
                    Disease[i].NumberOfPatientWithDiseace++;
                    m = counterDiseaeUhave;
                    counterDiseaeUhave++;
                    DiseaseUhave[m] = Disease[i].mTitle;

                }
                else if (Disease[i].percentage < 60 && Disease[i].percentage >0)
                {
                    n = counterDiseaseUmayhave;
                    counterDiseaseUmayhave++;
                    DiseaseUmayhave[n] = Disease[i].mTitle;
                    finalpercentage[n] = Disease[i].percentage;
                }
            }

        }
        Max = finalpercentage[0];
        maxTitle = DiseaseUmayhave[0];
        if (counterDiseaeUhave > 0)
        {
            SetConsoleTextAttribute(h, 15);
            for (int i = 0; i < counterDiseaeUhave; i++)
            {
                cout << "\t\t\t\tThe Diseases you have  :"  << DiseaseUhave[i] << "\n";

                Patient[Id].mDiagnosisHistory[Patient[Id].NumberOfDiagnosisHistory] = DiseaseUhave[i];

            }
        }
        else if (counterDiseaeUhave == 0 && counterDiseaseUmayhave > 0)
        {

            for (int i = 1; i < counterDiseaseUmayhave; i++)
            {
                if (finalpercentage[i] > Max)
                {
                    Max = finalpercentage[i];
                    maxTitle = DiseaseUmayhave[i];
                }
            }


            cout << "\t\t\t\tThe closest Disease you have is :" << maxTitle << " with percentage " << Max << "% \n";

        }
        else
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tUNFORTUNATELY!!There is no  matching disease\t\t\n";

            SetConsoleTextAttribute(h, 15);
        for (int i = 0; i < NumberOfDisease; i++)
        {
            Disease[i].symcheck[i] = false;
            Disease[i].counter = 0;
            Disease[i].percentage = 0.0;
        }
        cout << "\t\t\t\tIf you want to be Dignoased again press (Y/y) else press (N/n) : ";
        cin >> a;
        if (a != "Y" && a != "y" && a != "N" && a != "n")
        {
            do {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\tInvalid \n";
                cout << "\t\t\t\tIf you want to be Dignoased again press (Y/y) else press (N/n) : ";
                cin >> a;

            } while (a != "Y" && a != "y" && a != "N" && a != "n");
            if (a == "N" || a == "n")
            {
                break;
            }

        }
        SetConsoleTextAttribute(h, 15);

    } while (a == "Y" || a == "y");
}
void CalculatePrsentageInDiagnosisWithoutChoosingDepartment()
{
    SetConsoleTextAttribute(h, 2);

    string DiseaseYouHave[10], DiseaseYouMayHave[10];
    int NumberOfDiseaseYouHave = 0, NumberOfDiseaseYouMayHave = 0;
    float PerstentageOfDiseaseYouMayHave[10] = { 0 };
    for (int i = 0; i < NumberOfDisease; i++)
    {
        for (int j = 0; j < Disease[i].NumberOfSymptoms; j++)
        {
            for (int k = 0; k < Patient[Id].NumberOfDSymptomOfPatient; k++)
            {
                if (Disease[i].Symptoms[j] == Patient[Id].mSymptom[k])
                {
                    Disease[i].counter++;
                }
            }
        }

        Disease[i].percentage = (float)Disease[i].counter / Disease[i].NumberOfSymptoms * 100;
        if (Disease[i].percentage >= 60)
        {
            Disease[i].PatientName[Disease[i].NumberOfPatientWithDiseace] = Patient[Id].mName;
            Disease[i].NumberOfPatientWithDiseace++;
            DiseaseYouHave[NumberOfDiseaseYouHave] = Disease[i].mTitle;
            NumberOfDiseaseYouHave++;
        }
        else if (Disease[i].percentage < 60 && Disease[i].percentage>0)
        {
            DiseaseYouMayHave[NumberOfDiseaseYouMayHave] = Disease[i].mTitle;
            PerstentageOfDiseaseYouMayHave[NumberOfDiseaseYouMayHave] = Disease[i].percentage;
            NumberOfDiseaseYouMayHave++;
        }
    }
    deleteRepeated(DiseaseYouHave, NumberOfDiseaseYouHave);
    deleteRepeated(DiseaseYouMayHave, NumberOfDiseaseYouMayHave);
    if (NumberOfDiseaseYouHave > 0)
    {
        for (int l = 0; l < NumberOfDiseaseYouHave; l++)
        {
            cout << "\t\t\t\tyou have :" << DiseaseYouHave[l] << "\n";
            Patient[Id].mDiagnosisHistory[Patient[Id].NumberOfDiagnosisHistory] = DiseaseYouHave[l];
            Patient[Id].NumberOfDiagnosisHistory++;
        }

    }
    else
    {

        for (int l = 0; l < NumberOfDiseaseYouMayHave; l++)
        {
            cout << "\t\t\t\tyou have about " << PerstentageOfDiseaseYouMayHave[l] << ": " << DiseaseYouMayHave[l] << " \n";

        }
    }
    for (int i = 0; i < NumberOfDisease; i++)
    {
        Disease[i].counter = 0;
        Disease[i].percentage = 0;
    }


}
void DiagnosisWithoutChoosingDepartment()
{
    SetConsoleTextAttribute(h, 3);
    string AllSymtomsForAllDisease[50];
    int NumberOfAllSymtomsForAllDisease = 0;
    for (int i = 0; i < NumberOfDisease; i++)
    {
        for (int j = 0; j < Disease[i].NumberOfSymptoms; j++)
        {
            AllSymtomsForAllDisease[NumberOfAllSymtomsForAllDisease] = Disease[i].Symptoms[j];
            NumberOfAllSymtomsForAllDisease++;
        }
    }

    deleteRepeated(AllSymtomsForAllDisease, NumberOfAllSymtomsForAllDisease);

    for (int i = 0; i < NumberOfAllSymtomsForAllDisease; i++)
    {
        cout<<"\t\t\t\t" << i + 1 << " " << AllSymtomsForAllDisease[i] << endl;
    }
    int NOSymYouHave;
    SetConsoleTextAttribute(h, 15);
    cout << "\t\t\t\tchoose number of symptom do you have :";
    cin >> NOSymYouHave;
    if (NOSymYouHave > NumberOfAllSymtomsForAllDisease || NOSymYouHave < 1)
    {
        do
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tinvalid number please choose from (1 to " << NumberOfAllSymtomsForAllDisease << " ): " ;
            cin >> NOSymYouHave;
        } while (NOSymYouHave > NumberOfAllSymtomsForAllDisease || NOSymYouHave < 1);
    }
    SetConsoleTextAttribute(h, 15);
    Patient[Id].mSymptom[Patient[Id].NumberOfDSymptomOfPatient] = AllSymtomsForAllDisease[NOSymYouHave - 1];

    Patient[Id].NumberOfDSymptomOfPatient++;
    string ChooseAnotherSymptom = "h";
    cout << "\t\t\t\tDo you want to choose another symptom (y/n) :";
    cin >> ChooseAnotherSymptom;
    if (ChooseAnotherSymptom != "y" && ChooseAnotherSymptom != "Y" && ChooseAnotherSymptom != "n" && ChooseAnotherSymptom != "N")
    {
        do
        {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tplease enter y or n:";
            cin >> ChooseAnotherSymptom;
        } while (ChooseAnotherSymptom != "y" && ChooseAnotherSymptom != "Y" && ChooseAnotherSymptom != "n" && ChooseAnotherSymptom != "N");
    }
    SetConsoleTextAttribute(h, 15);
    while (ChooseAnotherSymptom == "Y" || ChooseAnotherSymptom == "y")
    {

        cout << "\t\t\t\t choose number of symptom do you have :";
        cin >> NOSymYouHave;
        if (NOSymYouHave > NumberOfAllSymtomsForAllDisease || NOSymYouHave < 1)
        {
            do
            {
                SetConsoleTextAttribute(h, 4);
                cout << "invalid number please choose from (1 to " << NumberOfAllSymtomsForAllDisease << " ) :" ;
                cin >> NOSymYouHave;
            } while (NOSymYouHave > NumberOfAllSymtomsForAllDisease || NOSymYouHave < 1);
        }
        SetConsoleTextAttribute(h, 15);
        Patient[Id].mSymptom[Patient[Id].NumberOfDSymptomOfPatient] = AllSymtomsForAllDisease[NOSymYouHave - 1];

        Patient[Id].NumberOfDSymptomOfPatient++;
        cout << "\t\t\t\tDo you want to choose another symptom (y/n) :";
        cin >> ChooseAnotherSymptom;
        if (ChooseAnotherSymptom != "y" && ChooseAnotherSymptom != "Y" && ChooseAnotherSymptom != "n" && ChooseAnotherSymptom != "N")
        {
            do
            {
                SetConsoleTextAttribute(h, 4);
                cout << "\t\t\t\tplease enter y or n:";
                cin >> ChooseAnotherSymptom;
            } while (ChooseAnotherSymptom != "y" && ChooseAnotherSymptom != "Y" && ChooseAnotherSymptom != "n" && ChooseAnotherSymptom != "N");
        }
        SetConsoleTextAttribute(h, 15);
    }



    deleteRepeated(Patient[Id].mSymptom, Patient[Id].NumberOfDSymptomOfPatient);

    CalculatePrsentageInDiagnosisWithoutChoosingDepartment();
}
void View() {
    SetConsoleTextAttribute(h, 8);
    cout << "\t\t\t\t User Name : " << Patient[Id].mAcc.mUsername << endl;
    cout << " \t\t\t\tPassword : " << Patient[Id].mAcc.mPassword << endl;
    cout << " \t\t\t\tName : " << Patient[Id].mName << endl;
    cout << " \t\t\t\tGender : " << Patient[Id].mGender << endl;
    cout << "\t\t\t\t Age : " << Patient[Id].mAge << endl;
    for (int i = 0; i < Patient[Id].NumberOfDiagnosisHistory; i++)
    {
        cout << "\t\t\t\tDiagnosis History : " << i + 1 << Patient[Id].mDiagnosisHistory[i] << endl;
        //cout << " Diagnosed : " << Patient[0].mDisease[0] << endl;
    }
    for (int i = 0; i < Patient[Id].NumberOfDSymptomOfPatient; i++) {
        cout << " \t\t\t\tSymptoms of the Disease : " << i + 1 << Patient[0].mSymptom[i] << "\n";
    }
}
bool CheckUsername(string NewUsername) {
    for (int i = 0; i < NumberOfPatient; i++)
    {
        if (Patient[i].mAcc.mUsername == NewUsername)
        {
            return false;

        }
    }
    return true;
}
void ChangeUsernameForPatient(string NewUsername)
{
    SetConsoleTextAttribute(h, 15);
    CheckUsername(NewUsername);
    bool isUsernameTaken = CheckUsername(NewUsername);
    if (isUsernameTaken == false) {
        do {
            SetConsoleTextAttribute(h, 4);
            cout << "\t\t\t\tthis username is already taken,try another one";
            //cin >> NewUsername;
            cin.ignore();
            getline(cin, NewUsername);

            isUsernameTaken = CheckUsername(NewUsername);
        } while (isUsernameTaken == false);
    }
    else {

        Patient[Id].mAcc.mUsername = NewUsername;
    }
}
void ChangePasswordForPatient(string Password) {
    Patient[Id].mAcc.mPassword = Password;
}
void ChangeNameForPatient(string Name) {
    Patient[Id].mName = Name;
}
void ChangeAgeForPatient(int Age) {
    Patient[Id].mAge = Age;
}
void ViewDiagnosisHistory() {
    if (Patient[Id].NumberOfDiagnosisHistory == 0)
    {
        SetConsoleTextAttribute(h, 4);
        cout << "\t\t\t\tyou Dont have any disease \n";
    }
    for (int i = 0; i < Patient[Id].NumberOfDiagnosisHistory; i++)
    {
        SetConsoleTextAttribute(h,3 );
        cout<<"\t\t\t\t" << i + 1 << " " << Patient[Id].mDiagnosisHistory[i] << endl;
    }
}