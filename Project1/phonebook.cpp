#include "phonebook.h"

Menu::~Menu()
{
    std::cout << "Closing..." << std::endl;
}

void  ContactList::saveContact(Contact& var,std::string nameFile)
{
    std::ofstream file;
    file.open(nameFile);
        file << var.name;
        file << "\n";
        file << var.number;
        file << "\n";
    file.close();
}

void ContactList::addContact(Contact var)
{
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
}
void ContactList::findByName(std::string name)
{
        unsigned int i;
        while(i<=readString.size())
        {
            if(name == readString.at(i))
            {
                std::cout << readString.at(i)<<std::endl;
                std::cout << readString.at(i+1)<<std::endl;
                std::cout << "\n\n";
            }
            i =+2;
        }
}

void ContactList::findByNumber(std::string number)
{
        unsigned int i = 1;
        while(i<=readString.size())
        {
            if(number == readString.at(i))
            {
                std::cout << readString.at(i)<<std::endl;
                std::cout << readString.at(i-1)<<std::endl;
                std::cout << "\n\n";
            }
            i =+2;
        }
}
void Menu::findContact()
{
    int a;
    std::cout << "1.Find by Name\n"
                        "2.Find by Number"<< std::endl;
    std::cin >> a;
    if (a == 1)
    {
        system("cls");
        std::string name;
        std::cout << "Name:  \n";
        std::cin >> name;
        listVar.findByName(name);
    }
    else
    {
        system("cls");
        std::string number;
        std::cout << "Name:  \n";
        std::cin >> number;
        listVar.findByNumber(number);
    }
}

bool Menu::menu()
{
    std::cout << "1.Add Contact\n"
                        "2.Read File\n"
                        "3.Find Contact\n"
                        "4.Close";
    int a;
    std::cin >> a;
    switch(a)
    {
    case 1 : listVar.addContact(contactVar);break;
    case 2 : readFile();break;
    case 3 : findContact();
    case 4 : return false;
    }
    return true;
}
