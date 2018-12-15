#include "phonebook.h"
/*
    function "SaveInputData" : create File for Write;
                                                                          writing data of contact in File;
    function "ReadFile" : create File for Read;
                                                                reading File;
*/


void SaveInputData(Contact user)
{

    std::ofstream fileSave;
    fileSave.open("PhoneBook.txt", std::ifstream::app);

    if (fileSave.is_open())
    {
        std:: cout << "Saving...." << std::endl;
        fileSave << "----------------------------" << std::endl;
        fileSave << "Name:" << user.name << std::endl;
        fileSave << "Number:" << user.number << std::endl;
        fileSave << "----------------------------" << std::endl;
    }
    else
    {
       std:: cout << "Error: File open feiled" << std::endl;
    }
    fileSave.close();
}

void InputData(Contact user)
{
    std:: cout << "Name - "; std::cin >> user.name;
    std:: cout << "Number - "; std::cin >> user.number;std::cout << std::endl;


    std:: cout <<  "Total:"   << std::endl;
    std:: cout << "Name - "   << user.name << std::endl
                    << "Number - " << user.number << std::endl << std::endl;

    std::cout << "Save ?" << std::endl << "1. Yes   2.No" << std::endl ;

    int a =0;
    std::cin >> a;

    if (a == 1)
    {
        SaveInputData(user);
    }
    else
    {
        InputData(user);
    }
}

void OutputPhoneBook()
{
    std::string strOutput;
    std::ifstream fileOut;
    fileOut.open("PhoneBook.txt");
    while (!fileOut.eof())
    {
        fileOut >> strOutput;
        std::cout << strOutput<<std::endl;
        strOutput = " ";
    }
    fileOut.close();
}

void menu(Contact user)
{
    std::cout << "\n\n1. Add People " << std::endl << "2. Watch Phone Book" << std::endl;

    int a = 0;
    std::cin >> a;

    if (a == 1)
    {
        InputData(user);
    }
    else
    {
        OutputPhoneBook();
    }
}
