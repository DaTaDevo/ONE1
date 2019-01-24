#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

 class  Contact
 {
    //Contact info
     std::string name;//переменная хранящая имя контакта
     std::string number;//переменная хранящая номер контакта
    //variables
     std::string nameOfFile;//переменная хранящая имя определенного файла(зависит от кода)
     std::string nameFileList = "listNameFile.txt";//имя файла который хранит существующие файлы
     std::vector <std::string> listInfo;//хранит информацию о контактах которая находиться в файле
    //functions
     void readList();//читает файл со списком существующих файлов
     void createNewPeople();//создает новый контакт
     void readFile();//читает файл(определенный)
     void outputPage(std::vector <std::string> &vec);//вывводит по-странично данные з файла с помощью listInfo
     void openFile();//открывает определенный файл
     bool tryOpenFile(std::string nameFile);//проверяет существует ли такой файл
     std::string chooseNameFile();//ввод имени файла которого нужно в будущем прочитать
     std::string chooseNameFile(int typeFile);//ввод файла которого нужно в будующем открыть
     void saveData(std::string nameFile);//сохранение данных о контакте
 public :
     ~Contact();
     bool menu();//меню
 };


#endif // PHONEBOOK_H
