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
void SaveInputData(Contact user);
void menu(Contact user);
void InputData(Contact user);
void OutputPhoneBook();

#endif // PHONEBOOK_H
