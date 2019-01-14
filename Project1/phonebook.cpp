#include "phonebook.h"
/*
func createNewPeople()
{
    - input data about people
}
func saveData(NameofFile)
{
    - open file
    - save data to file
}
func readFile()
{
    - open file for read
    -  reading a file
    - all data send to vector
    - hide data in console
}
func openFile()
{
    - new or old file a open
       \            \
       \            ----------->openFile \
       \                                           \
create new file   -------------------
                                        \
                                        \
                                call  func is createNewPeople
                                        \
                                        \
                                call func is saveData
}
*/
void Contact::createNewPeople()
{
    std::cout << "Name: " ;
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "Number: " ;
    std::cin >> number;
    std::cout << std::endl;
}

void Contact::saveData(std::string name)
{
    std::ofstream file;
    file.open(name+".txt",std::ios::app);
    file << "Name - " << name <<"\n";
    file << "Number - " << number << "\n";
    file << "\n";
    file.close();
}

void Contact::readFile()
{
    std::ifstream file;
    std::cout << "Type a name of file: ";
    std:: string name;
    std::cin >> name;
    std::cout<< std::endl;
    file.open(name+".txt");
    std::string str;
    while(!file.eof())
    {
        std::getline(file,str);
        transfer.push_back(str);
        str = " ";
    }
    // сделать вывод по странично
    for (unsigned int i = 0;i<transfer.size();i++)
    {
        std::cout << transfer.at(i) << std::endl;
    }
}

void Contact::openFile()
{
    std::cout << "1.Create a new File  2.Open File" << std::endl;
    int a;
    std::cin >> a;
    if (a == 1)
    {
        std::fstream file;
        std::cout << "Type a name of file: " ;
        std::cin >> newFileName;
        std::cout << std::endl;
        file.open(newFileName+".txt");
        file.close();
        createNewPeople();
        saveData(newFileName);
    }
    else
    {
        std::fstream file;
        std::cout << "Type a name of file: " ;
        std::cin >> oldFileName;
        std::cout << std::endl;
        file.open(oldFileName+".txt");

        if(!file.is_open())
        {
            file.close();
            std::cout<<"error:file not found!"<<std::endl;
        }
        else
        {
              file.close();
              createNewPeople();
              saveData(oldFileName);
        }

    }
}

void Contact::menu ()
{
    std::cout << "\n\n"
                 "----------------------------------"
                       "1.Add New Contact\n"
                        "2.Watch Contact-Book File"
                 "----------------------------------" << std::endl;
    int a;
    std::cin >> a;
    if(a == 1)
    {
        openFile();
    }
    else
    {
        readFile();
    }
}
