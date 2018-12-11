#include "phonebook.h"

PhoneBook::PhoneBook()
{};

void PhoneBook::menu()
{
    std::cout << "\n\n1. Add People " << std::endl << "2. Watch Phone Book" << std::endl;


    std::cin >> a;

    if (a == 1)
    {
        InputData();
    }
    else
    {
        OutputPhoneBook();
    }

}

void PhoneBook::InputData()
{
    std:: cout << "Name - "; std::cin >> name;
    std:: cout << "Number - "; std::cin >> number;std::cout << std::endl;


    std:: cout <<  "Total:"   << std::endl;
    std:: cout <<  "Name - "   << name << std::endl
                    << "Number - " << number << std::endl << std::endl;

    std::cout << "Save ?" << std::endl << "1. Yes   2.No" << std::endl ;

    std::cin >> a;

    if (a == 1)
    {
        SaveInputData();
    }
    else
    {
        InputData();
    }
}

void PhoneBook::OutputPhoneBook()
{
    std::string strOutput;
    fileOut.open("PhoneBook.txt");
    while (!fileOut.eof())
    {
        fileOut >> strOutput;
        std::cout << strOutput;
        strOutput = " ";
    }
    fileOut.close();
}

void PhoneBook::SaveInputData()
{
    fileSave.open("PhoneBook.txt");

    if (fileSave.is_open())
    {
        std:: cout << "Saving...." << std::endl;
        fileSave << "Name:" << name;
        fileSave << "Number:" << number;
    }
    else
    {
       std:: cout << "Error: File open feiled" << std::endl;
    }
    fileSave.close();
}
