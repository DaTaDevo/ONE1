#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
# include <fstream>
/*  to fix :
     class Contact : add (name:STRING);
                                                           add (number:STRING);


*/
 class  Contact
 {
 public :
     std::string name;
     std::string number;
 };
void SaveInputData(std::string name,std::string number);
void menu(std::string name,std::string number);
void InputData(std::string name,std::string number);
void OutputPhoneBook();

#endif // PHONEBOOK_H
