#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
# include <fstream>


 class  Contact
 {
 public :
     std::string name;
     std::string number;
 };

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
    int a;
};

#endif // PHONEBOOK_H
