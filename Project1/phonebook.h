#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

 class  Contact
 {
     std::string name;
     std::string number;

     std::string nameOfFile;
     std::vector <std::string> transfer;
     std::string newFileName;
     std::string oldFileName;

     void createNewPeople();
     void readFile();
     void openFile();
     void  saveData(std::string name);
 public :
     void menu();
 };


#endif // PHONEBOOK_H
