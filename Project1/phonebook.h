#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

 class  Contact
 {

     std::string nameFile;
     std::string number;

     std::string nameOfFile;
     std::vector <std::string> transfer;
     std::string newFileName;
     std::string oldFileName;

     void createNewPeople();
     void readFile();
     void outputPage(std::vector <std::string> &vec);
     void openFile();
     bool tryOpenFile(std::string nameFile);
     std::string    chooseNameFile();
     std::string chooseNameFile(int typeFile);
     void saveData(std::string nameFile);
 public :
     ~Contact();
     bool menu();
 };


#endif // PHONEBOOK_H
