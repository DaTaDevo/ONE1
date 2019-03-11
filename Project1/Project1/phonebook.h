#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>


 class Contact
 {
 public:
    //Contact info
     std::string name;//переменная хранящая имя контакта
     std::string number;//переменная хранящая номер контакта

 };

 class ContactList
 {
   void saveContact(Contact& var,std::string nameFile);
 public:
   std::vector<std::string>readString;
   void addContact(Contact var);
   void deleteContact(Contact& var);
   void filterTurn();//create!
   void findByName(std::string name);
   void findByNumber(std::string number);
 };

 class Menu
 {
     Contact contactVar;
     ContactList listVar;
     std::vector<std::string> pages;
 public :
     std::string nameFile;
     ~Menu();
     void readFile();
     void inputByPages(std::string fileName);
     void findContact();
     bool menu();//меню
 };


#endif // PHONEBOOK_H
