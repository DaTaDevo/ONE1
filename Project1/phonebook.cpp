#include "phonebook.h"

std::string beforeInput(Contact user)
{
    int a=0;

    std::cout << "1.Open file 2.New file "<<std::endl;
    std::cin >> a;
    if(a == 2)
    {
        std::cout << "Type a name of file, which you wanna create" <<std::endl;
        std::cin >> user.nameOfFile;

        std::fstream newFile;
        newFile.open(user.nameOfFile + ".txt");
        newFile.close();
    }
    else
    {
        std::cout << "Type a name of file, which you wanna open: ";
        std::cin >> user.nameOfFile;
        std::cout<<std::endl;

        std::fstream tempFile;
        tempFile.open(user.nameOfFile + ".txt",std::ios::out);

        if(tempFile.is_open() == false)
        {return user.nameOfFile;
            std::cout<<"Error:File not found!"<<std::endl;
            beforeInput(user);
        }
        tempFile.close();
    }
  return user.nameOfFile;
}

void saveInputData(Contact user)
{

    std::ofstream fileSave;
    fileSave.open(user.nameOfFile, std::ifstream::app);

    if (fileSave.is_open())
    {
        std:: cout << "Saving...." << std::endl;
        fileSave << "----------------------------" << std::endl;
        fileSave << "Name:" << user.name << std::endl;
        fileSave << "Number:" << user.number << std::endl;
        fileSave << "----------------------------" << std::endl;
    }
    else
    {
       std:: cout << "Error: File open feiled" << std::endl;
    }
}

void inputData(Contact user)
{
 //создание или открытия опеределенного файла-контактов пользователем(DONE!)
 int a = 0;

 beforeInput(user);
 std::cout << "Name - ";
 std::cin  >> user.name;

 std::cout << "Number - ";
 std::cin  >> user.number;
 std::cout << std::endl;


 std::cout <<  "Total:"   << std::endl;
 std::cout << "Name - "   << user.name << std::endl
           << "Number - " << user.number << std::endl << std::endl;

 std::cout << "Save ?" << std::endl << "1. Yes   2.No" << std::endl ;

 std::cin  >> a;

 if (a == 1)
 {
     saveInputData(user);
 }
 else
 {
     inputData(user);
 }
}

void outputPhoneBook(Contact user)
{
    //вывод на экран по 10 контактов(для вектора 10 контактов = 40 элементов)(WAIT...)
    std::cout<<"Type a name of file: ";
    std::cin >>user.nameOfFile;
    std::cout<<std::endl;

    std::string strOutput;
    std::ifstream fileOut;

    fileOut.open(user.nameOfFile + ".txt");
    while (!fileOut.eof())
    {
        fileOut >> strOutput;
        user.transfer.push_back(strOutput);
        strOutput = " ";
    }
    fileOut.close();
}

void menu(Contact user)
{
    std::cout << "\n\n1. Add People " << std::endl << "2. Watch Phone Book" << std::endl;

    int a = 0;
    std::cin >> a;

    if (a == 1)
    {
        inputData(user);
    }
    else
    {
        outputPhoneBook();
    }
}
