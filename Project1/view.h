#include <model.h>
#include <iostream>
#include <string>
class View
{
public:
    void print(std::string text)
    {
        std::cout <<text;
    }
    int answr;
    char c_answr;
    bool checkNumberInput(std::string number)
    {
        if (number.size() > 12)
        {
            system("cls");
            print("Too many numbers(number limits 12)!\n");
            return false;
        }
        else if (number.size() < 12)
        {
            system("cls");
            print("Too small numbers(number limits 12)!\n");
            return false;
        }
        return true;
    }
    void m_start()
    {
        std::cout <<"1.Add Contact\n"
                    "2.Find Contact\n"
                    "3.Show Contacts\n"
                    "4.Delete Contact\n"
                    "5.Exit"<< std::endl;
         std::cin >> answr;
    }
     int m_addContact(Model &contact)
    {
        system("cls");
        std::string temp_name,temp_num/*,temp_id*/;
        answr = 0;
        do
        {
            if (answr == 2)
            {
                system("cls");
                return 1;
            }
            print("Name:");
            std::cin >> temp_name;
            print("Number:");
            contact.setName(temp_name);
            std::cin >> temp_num;
            contact.setNumber(temp_num);
            if(!checkNumberInput(temp_num))
            {
                return 1;
            }
//            std::cout <<temp_num.size()<< std::endl;
            print("What you want to do with this contact:\n");
            print("0.Save\n1.Change\n2.Exit\n");
            std::cin >> answr;
        }while(answr);

//        print("Set file:");
//        std::cin >> temp_id;
//        contact.setId_file(temp_id);
        system("cls");
        return  0;
    }
    std::string m_findContact()
    {
        std::string f_name;
        print("Set name:");
        std::cin >> f_name;
        return f_name;
    }
    //    std::string m_showContacts()
    //    {
    //        print("1.All Contacts/t")/*2.Choose File\n")*/;
    //        std::cin >> answr;
    //        if (answr == 1)
    //        {
    //            std::cout <<"Name\tNumber\tFile"<<  std::endl;
    //            system("cls");
    //            return "";
    //        }
    //        else if (answr == 2)
    //        {
    //            std::string str;
    //            print("Set File:");
    //            std::cin >> str;
    //            system("cls");
    //            return str;
    //        }
    //        system("cls");
    //        return "Incorect input";
    //    }
    void showContact(Model& mdl)
    {
        std::cout <<mdl.getName() <<"\t" <<mdl.getNum()/* <<"\t"<<mdl.getId()*/<< std::endl;
    }
    void m_deleteContact(Model* deletedContact) /* меню удаление контакта (Примечание : используется когда уже ввыведен DataStorage.txt
                            с помощью функции Controller::read(View::showContact))*/
    {
        print("Set name:");
        std::string temp_name;
        std::cin >> temp_name;
        deletedContact->setName(temp_name);
        print("If you set only name, then  all contacts with this name will delete, do you want to set number? \n "
              "'y' - yes, 'n' - no\n");
        std::cin >> c_answr;
        if(c_answr == 'y')
        {
            std::string temp_number;
            print("Set number:");
            std::cin >> temp_number;
            if(!checkNumberInput(temp_number))
            {
                return;
            }
            deletedContact->setNumber(temp_number);
        }
        else if (c_answr == 'n')
        {
            deletedContact->setNumber("blank");
        }
        else
            return;

//        print("If you do not set file, then all contact with this (number and ) name will delete, do you want to set file?\n ");
//        print("'y' - yes, 'n' - no\n");
//        std::cin >> c_answr;
//        if (c_answr == 'y')
//        {
//            std::string temp_file;
//            print("Set file:");
//            std::cin >> temp_file;
//            deletedContact->setId_file(temp_file);
//        }
//        else if (c_answr == 'n')
//        {
//            deletedContact->setId_file("blank");
//        }
//        else
//            return;
    }
};
