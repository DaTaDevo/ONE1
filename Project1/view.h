#include <model.h>
#include <iostream>
#include <string>
typedef std::string msg_t;
class View
{
public:
    std::string direction = "View::Menu";//чтобы при старте программы открывалась меню
    std::string answr = "";// для избежание непредведенных значний;
    void print(std::string text)
    {
        std::cout <<text;
    }
    int commands()
    {
        if(answr == "back")
        {
            system("cls");
            direction = "View::Menu";
            return 1;
        }
        else if (answr == "exit")
        {
            system("cls");
            direction = "Exit";
            return 1;
        }
        return 0;
    }
    int checkrInput(bool name = false)
    {
        if (name == false)
        {
            if (answr[0] == '+')
            {
                if (answr.size() > 12)
                {
                    system("cls");
                    print("Too many numbers(number limits 12)!\n");
                    answr = "";
                    direction = "View::Menu";
                    return 1;
                }
                else if (answr.size() < 12)
                {
                    system("cls");
                    print("Too small numbers(number limits 12)!\n");
                    answr = "";
                    direction = "View::Menu";
                    return 1;
                }
            }
            else if (commands() == 0)
            {
                direction = "Menu";
                print("Incorrect input!");
                return 1;
            }
            else
            {
                return 1;
            }
        }
        else if (commands() == 1)
        {
            return 1;
        }
        return 0;
    }
    void m_start()
    {
        std::cout <<"1.Add Contact\n"
                    "2.Find Contact\n"
                    "3.Show Contacts\n"
                    "4.Delete Contact\n"
                    "5.Exit"<< std::endl;
        int temp;
        std::cin >> temp;
        switch(temp)
        {
        case 1: {direction = "View::Add"; break;}
        case 2: {direction = "View::Find";break;}
        case 3: {direction = "Show";break;}
        case 4: {direction = "View::Delete";break;}
        case 5: {direction = "Exit";break;}
        }
    }
     void m_addContact(Model &contact)
    {
        system("cls");
        do
        {
            if (answr == "2")
            {
                system("cls");
                direction = "View::Menu";
                return;
            }
            print("Name:");
            std::cin >> answr;
            if (checkrInput(true))
            return;
            contact.setName(answr);
            print("Number:");
            std::cin >> answr;
            if(checkrInput())
                return;
            contact.setNumber(answr);
            print("What you want to do with this contact:\n");
            print("0.Save\n1.Change\n2.Exit\n");
            std::cin >> answr;
            if(checkrInput(true))
                return;
        }while(answr == "1");
        system("cls");
        if (answr == "2")
            direction = "View::Menu";
        else
            direction = "Add";
    }
    void m_findContact()
    {
        system("cls");
        print("Find with:\n");
        print("1.Name\n2.Number\n");
        std::cin >> answr;
        if(checkrInput(true))
            return;
        else if (answr == "1")
        {
            print("Set name:");
            std::cin >> answr;
            if(checkrInput(true))
                return;
        }
        else if (answr == "2")
        {
            print("Set number:");
            std::cin >> answr;
            if(checkrInput(true))
                return;
        }
        else
        {
            print("Incorrect Input!!!");
        }
        direction = "Find";
    }
    void m_deleteContact(Model& deletedContact)
    {
        print("Set name:");
        std::cin >> answr;
        if(checkrInput(true))
            return;
        deletedContact.setName(answr);
        print("If you set only name, then  all contacts with this name will delete, do you want to set number? \n "
              "'y' - yes, 'n' - no\n");
        std::cin >> answr;
        if(checkrInput(true))
            return;
        else if(answr == "y")
        {
            print("Set number:");
            std::cin >> answr;
            if(checkrInput())
                return;
            if(checkrInput() != 0) return;
            deletedContact.setNumber(answr);
        }
        else
        {
            deletedContact.setNumber("blank");
        }
        system("cls");
        direction = "Delete";
    }

};
