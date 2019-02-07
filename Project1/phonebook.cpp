#include "phonebook.h"
/*
 Note:

*/
Menu::~Menu()
{
    std::cout <<"Closing...";
}

//void Menu::readList()
//{
//    std::ifstream file;
//    file.open(nameFileList);
//    std::string str;
//    while(!file.eof())
//    {
//       str = " ";
//       file >> str;
//       std::cout << str << std::endl;
//    }

//}
//void Menu::outputPage(std::vector <std::string> &vec)
//{
//    // сделать вывод по странично
//    if(vec.size() > 10)
//    {
//        unsigned int counter = 10;
//        while(counter <= vec.size())
//        {
//            for(int i = 0;i<10;i++)
//            {
//                std::cout<<vec.at(i)<<std::endl;
//            }
//            counter+=10;
//            std::cout<< "1.Next Page 2.Close" <<std::endl;
//            int a;
//            std::cin >> a;
//            if(a != 1)
//                return;
//        }
//        for(;counter<vec.size();++counter)
//        {
//            std::cout<<vec.at(counter)<<std::endl;
//        }
//    }
//    else
//    {
//        for (unsigned int i = 0;i<vec.size();i++)
//        {
//            std::cout << vec.at(i) << std::endl;
//        }
//    }
//}
//bool Menu::tryOpenFile(std::string nameFile)
//{
//    std::fstream file;
//    file.open(nameFile+".txt");
//    if(file.is_open() == false)
//    {
//        return false;
//    }
//    return true;
//}
//std::string Menu::chooseNameFile()
//{
//    std::cout << "Type a name of file: ";
//    std::cin >> nameOfFile;
//    std::cout<< std::endl;
//    return nameOfFile;
//}
//std::string Menu::chooseNameFile(int typeFile)
//{
//    std::cout << "Type a name of file: " ;
//    std::cin >> nameOfFile;
//    std::cout << std::endl;

//    if (typeFile == 1)
//    {
//        //create a new file
//        std::fstream file;
//        file.open(nameOfFile+".txt");
//        file.close();
//        //save name of file to file-list
//        std::ofstream oFile;
//        oFile.open(nameFileList);
//        oFile << nameOfFile;
//        oFile.close();
//    }
//    else
//    {
//        //opening old file
//        if(tryOpenFile(nameOfFile)==false)
//        {
//            std::cout<<"Failed is open file"<<std::endl;
//            chooseNameFile(typeFile);
//        }

//    }

//    return nameOfFile;
//}
void ContactList::addContact(Contact& var,std::string nameFile)
{
    std::cout << "Name: " ;
    std::cin >> var.name;
    std::cout << std::endl;
    std::cout << "Number: " ;
    std::cin >> var.number;
    std::cout << std::endl;
    //save to file
    std::ofstream file;
    file.open(nameFile);
    file << var.name << "\n";
    file << var.number << "\n";
    file.close();
}
//void Menu::saveData(std::string name,Contact& var)
//{
//    std::ofstream file;
//    file.open(name+".txt",std::ios::app);
//    file << "Name - " << var.name <<"\n";
//    file << "Number - " << var.number << "\n";
//    file << "\n";
//    file.close();
//}
//void Menu::readFile()
//{
//    readList();
//    chooseNameFile();
//    std::ifstream file;
//    file.open(nameOfFile+".txt");
//    if(!file.is_open())
//    {
//        std::cout<<"error:file not found!"<<std::endl;
//        return;
//    }
//    std::string str;
//    while(!file.eof())
//    {
//        std::getline(file,str);
//        listInfo.push_back(str);
//        str = " ";
//    }
//    file.close();
//    outputPage(listInfo);
//}
//void Menu::openFile(ContactList& varCL)
//{
//    std::cout << "1.Create a new File  2.Open File" << std::endl;
//    int a;
//    std::cin >> a;
//    chooseNameFile(a);
//    varCL.addContact(Contact& var);
//    saveData(nameOfFile);
//}
bool Menu::menu ()
{
    std::cout << "\n\n"
                 "----------------------------------\n"
                       "1.Add New Contact\n"
                       "2.Read File\n"
                       "3.Close\n"
                 "----------------------------------" << std::endl;
    int a;
    std::cin >> a;
    switch (a)
    {
        case 1: newContact(listVar);break;
        case 3: return false;
    }
    return true;
}


//new function
void Menu::openFile(ContactList& var)
{
    std::cout <<"Set Name of File: ";
    std::cin >>nameFile;
    std::ofstream file;
    nameFile = nameFile+".txt";
    file.open(nameFile);
    var.addContact(contactVar,nameFile);
    file.close();
}

void Menu::newContact(ContactList& var)
{
    openFile(var);
}
