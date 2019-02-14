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
 public:
   void addContact(Contact& var, std::string nameFile);
   void deleteContact(Contact& var);
   void filterTurn();//create!
   void findForName(std::string name);//create!
   void findForNumber(std::string number);//create!
 };

 class Menu
 {
     Contact contactVar;
     ContactList listVar;

    std::string nameFile;//переменная хранящая имя определенного файла(зависит от кода)
//     std::string nameFileList = "listNameFile.txt";//имя файла который хранит существующие файлы
//     std::vector <std::string> listInfo;//хранит информацию о контактах которая находиться в файле
//    //functions
//     void readList();//читает файл со списком существующих файлов
//     void readFile();//читает файл(определенный)
//     void outputPage(std::vector <std::string> &vec);//вывводит по-странично данные з файла с помощью listInfo
//     void openFile(ContactList& varLC);//открывает определенный файл
//     bool tryOpenFile(std::string nameFile);//проверяет существует ли такой файл
//     std::string chooseNameFile();//ввод имени файла которого нужно в будущем прочитать
//     std::string chooseNameFile(int typeFile);//ввод файла которого нужно в будующем открыть
//     void saveData(std::string nameFile,Contact& var);//сохранение данных о контакте
     void newContact(ContactList& var);
     void findContact(Contact& var);
     void openFile(ContactList& var);
     void readFile();
     void saveContact(Contact& var, std::string& file);
//     void saveContact(ContactList& var);
 public :
     ~Menu();
     bool menu();//меню
 };


#endif // PHONEBOOK_H
