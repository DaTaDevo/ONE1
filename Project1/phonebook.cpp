#include "phonebook.h"

Menu::~Menu()
{
    std::cout << "Closing..." << std::endl;
}

void  ContactList::saveContact(Contact& var,std::string nameFile)
{
    system("cls");
    std::ofstream file;
    file.open(nameFile,std::ios::app);
        file << var.name;
        file << "\n";
        file << var.number;
        file << "\n";
    file.close();
    file.open("database.txt",std::ios::app);
        file << var.name;
        file << "\n";
        file << var.number;
        file << "\n";
    file.close();
}

void ContactList::addContact(Contact var)
{
    system("cls");
    std::string nameFile;
    std::cout << "Name Of File:";
    std::cin >> nameFile;
    nameFile +=".txt";
    std::cout << "Name:";
    std::cin >> var.name;
    std::cout << "Number:";
    std::cin >> var.number;
    saveContact(var,nameFile);
}

void Menu::readFile()
{
    system("cls");
    std::string nameFile;
    std::cout << "Name of File:";
    std::cin >> nameFile;
    nameFile += ".txt";
    std::ifstream file;
    file.open(nameFile);
    std::string str;
    while(!file.eof())
    {
        str =" ";
        getline(file,str);
        std::cout << str<<std::endl;
        listVar.readString.push_back(str);
    }
    file.close();
    listVar.readString.clear();
}
void ContactList::findByName(std::string name)
{
        std::cout << "----------\n";
        unsigned  int i  = 0;
        while(i<=readString.size())
        {
            if(name == readString.at(i))
            {
                std::cout << readString.at(i)<<std::endl;
                std::cout << readString.at(i+1)<<std::endl;
                std::cout << "----------\n";
            }
            i+=2;
         }
}

void ContactList::findByNumber(std::string number)
{
        std::cout << "----------\n";
        unsigned int i = 1;
        while(i<readString.size())
        {
            if(number == readString.at(i))
            {
                std::cout << readString.at(i)<<std::endl;
                std::cout << readString.at(i-1)<<std::endl;
                std::cout << "----------\n";
            }
            i +=2;
        }
}
void Menu::findContact()
{

    system("cls");
    //сбор информации со всех файлов
    std::ifstream file;
    file.open("database.txt");
    std::string str;
    while(!file.eof())
    {
        str =" ";
        getline(file,str);
        listVar.readString.push_back(str);
    }
    file.close();
    //конец
    int a;
    std::cout << "1.Find by Name\n"
                        "2.Find by Number"<< std::endl;
    std::cin >> a;
    if (a == 1)
    {
        system("cls");
        std::string name;
        std::cout << "Name:";
        std::cin >> name;
        listVar.findByName(name);
    }
    else
    {
        system("cls");
        std::string number;
        std::cout << "Number:";
        std::cin >> number;
        listVar.findByNumber(number);
    }
}

bool Menu::menu()
{
    std::cout << "1.Add Contact\n"
                        "2.Read File\n"
                        "3.Find Contact\n"
                        "4.Close\n";
    int a;
    std::cin >> a;
    switch(a)
    {
    case 1 : listVar.addContact(contactVar);break;
    case 2 : readFile();break;
    case 3 : findContact();break;
    case 4 : return false;
    default: return false;
    }
    return true;
}
