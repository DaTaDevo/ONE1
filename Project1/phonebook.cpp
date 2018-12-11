#include "phonebook.h"
Contact user;
PhoneBook::PhoneBook()
{};



void PhoneBook::InputData()
{
    std:: cout << "Name - "; std::cin >> user.name;
    std:: cout << "Number - "; std::cin >> user.number;std::cout << std::endl;


    std:: cout <<  "Total:"   << std::endl;
    std:: cout <<  "Name - "   << user.name << std::endl
                    << "Number - " << user.number << std::endl << std::endl;

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
    fileSave.open("PhoneBook.txt", std::ifstream::app);

    if (fileSave.is_open())
    {
        std:: cout << "Saving...." << std::endl;
        fileSave << "Name:" << user.name << std::endl;
        fileSave << "Number:" << user.number;
    }
    else
    {
       std:: cout << "Error: File open feiled" << std::endl;
    }
    fileSave.close();
}

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
