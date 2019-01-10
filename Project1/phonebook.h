#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

 class  Contact
 {
 public :
     std::string name;
     std::string number;
     std::string nameOfFile;
     std::vector <std::string> transfer;
 };
std::string beforeInput(Contact user);
void saveInputData(Contact user);
void menu(Contact user);
void inputData(Contact user);
void outputPhoneBook();

#endif // PHONEBOOK_H
