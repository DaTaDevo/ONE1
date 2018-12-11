#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
# include <fstream>

class PhoneBook
{
public:
    PhoneBook();
    void menu();
    void InputData();
    void OutputPhoneBook();
    void SaveInputData();
  private :
    std::ofstream fileSave;
    std::ifstream fileOut;
    std::string name;
    int number;
    int a;
};

#endif // PHONEBOOK_H
