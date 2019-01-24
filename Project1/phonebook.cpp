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
Contact::~Contact()
{
    std::cout <<"Closing...";
}

void Contact::readList()
{
    std::ifstream file;
    file.open(nameFileList);
    std::string str;
    while(!file.eof())
    {
       str = " ";
       file >> str;
       std::cout << str << std::endl;
    }

}
void Contact::outputPage(std::vector <std::string> &vec)
{
    // сделать вывод по странично
    if(vec.size() > 10)
    {
        unsigned int counter = 10;
        while(counter <= vec.size())
        {
            for(int i = 0;i<10;i++)
            {
                std::cout<<vec.at(i)<<std::endl;
            }
            counter+=10;
            std::cout<< "1.Next Page 2.Close" <<std::endl;
            int a;
            std::cin >> a;
            if(a != 1)
                return;
        }
        for(;counter<vec.size();++counter)
        {
            std::cout<<vec.at(counter)<<std::endl;
        }
    }
    else
    {
        for (unsigned int i = 0;i<vec.size();i++)
        {
            std::cout << vec.at(i) << std::endl;
        }
    }
}
bool Contact::tryOpenFile(std::string nameFile)
{
    std::fstream file;
    file.open(nameFile+".txt");
    if(file.is_open() == false)
    {
        return false;
    }
    return true;
}
std::string Contact::chooseNameFile()
{
    std::cout << "Type a name of file: ";
    std::cin >> nameOfFile;
    std::cout<< std::endl;
    return nameOfFile;
}
std::string Contact::chooseNameFile(int typeFile)
{
    std::cout << "Type a name of file: " ;
    std::cin >> nameOfFile;
    std::cout << std::endl;

    if (typeFile == 1)
    {
        //create a new file
        std::fstream file;
        file.open(nameOfFile+".txt");
        file.close();
        //save name of file to file-list
        std::ofstream oFile;
        oFile.open(nameFileList);
        oFile << nameOfFile;
        oFile.close();
    }
    else
    {
        //opening old file
        if(tryOpenFile(nameOfFile)==false)
        {
            std::cout<<"Failed is open file"<<std::endl;
            chooseNameFile(typeFile);
        }

    }

    return nameOfFile;
}
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
    readList();
    chooseNameFile();
    std::ifstream file;
    file.open(nameOfFile+".txt");
    if(!file.is_open())
    {
        std::cout<<"error:file not found!"<<std::endl;
        return;
    }
    std::string str;
    while(!file.eof())
    {
        std::getline(file,str);
        listInfo.push_back(str);
        str = " ";
    }
    file.close();
    outputPage(listInfo);
}
void Contact::openFile()
{
    std::cout << "1.Create a new File  2.Open File" << std::endl;
    int a;
    std::cin >> a;
    chooseNameFile(a);
    createNewPeople();
    saveData(nameOfFile);
}
bool Contact::menu ()
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
        case 1: openFile();break;
        case 2: readFile();break;
        case 3: return false;
    }
    return true;
}
