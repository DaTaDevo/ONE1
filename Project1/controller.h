#include <view.h>
#include <fstream>
#include <vector>
typedef unsigned int u_int;
class Controller : public Model
{
    View v;
    Model m;
    std::vector <Model> storage;
    void read()
    {
        std::ifstream file;
        file.open(v.answr);
        if (!file.is_open())
        {
            system("cls");
            v.print("File Has NOT Open!\n");
            v.direction = "View::Menu";
            return;
        }
        system("cls");
        while(getline(file,v.answr))
        v.print(v.answr+"\n");
        file.close();
        v.direction = "View::Menu";
    }
    void saveContact()
    {
        storage.push_back(m);
        v.direction = "View::Menu";
    }
    void find()
    {
        system("cls");
        bool found = false;
        if(v.answr[0] == '+')
        {
            for (u_int i = 0; i < storage.size();i++)
            {
                if (storage.at(i).getNum() == v.answr)
                {
                    found = true;
                    v.print(storage[i]);
                }
            }
        }
        else
        {
            for (u_int i = 0; i < storage.size();i++)
            {
                if (storage.at(i).getName() == v.answr)
                {
                    found = true;
                    v.print(storage[i]);
                }
            }
        }
        if(!found)
        {
            v.print("This Contact Has Not Found!\n");
        }
        v.direction = "View::Menu";
    }
    void deleteContact()
    {
//        show();
        //check input
        std::vector<Model> updateStorage;
        for (u_int i =0;i<storage.size();i++)
        {
            if (m.getName() == storage.at(i).getName())
            {
                if (m.getNum() == storage.at(i).getNum() || m.getNum() == "blank")
                    continue;
                else
                    updateStorage.push_back(storage.at(i));
            }
            else
                updateStorage.push_back(storage.at(i));
        }
        // updatedStorage сейчас должен быть заполнен не удаленными данными(данными котороые не попали под категорию удалить)
        storage.clear();//чистим старые данные
        for (u_int i = 0; i<updateStorage.size(); i++)
        {
            storage.push_back(updateStorage.at(i));
        }
        v.direction = "View::Menu";
        system("cls");
    }
    void show()
    {
        system("cls");
        for (u_int i = 0;i < storage.size();i++)
        {
            v.print(storage.at(i));
        }
        v.direction = "View::Menu";
    }

public:
    void direct()
    {
        //даем direction "ключ" для звызова нужной функции
        // таблица "ключей" читайте в README.txt
        while (true)
        {
            if (v.direction == "Add")
            {
                saveContact();
            }
            else if (v.direction == "Find")
            {
                find();
            }
            else if (v.direction == "Show")
            {
                show();
            }
            else if (v.direction == "Delete")
            {
                deleteContact();
            }
            else if (v.direction == "Read")
            {
                read();
            }
            else if (v.direction == "Quit")
            {
                return;
            }
            else if (v.direction == "View::Menu")
            {
                v.m_start();
            }
            else if (v.direction == "View::Add")
            {
                v.m_addContact(m);
            }
            else if (v.direction == "View::Find")
            {
                v.m_findContact();
            }
            else if (v.direction == "View::Delete")
            {
                show();
                v.m_deleteContact(m);
            }
            else if (v.direction == "View::Help")
            {
                v.help();
            }
            else
            {
                v.print("Error in getting direction!!!");
                v.direction = "Error";
                return;
            }
        }
    }

    Controller()
    {
        std::ifstream file;
        file.open("DataStorage.txt");
        while (file >> name >> num)
        {
            m.set(name,num);//устанавливаем данные для нашей переменной m
            storage.push_back(m);
        }
        if(storage.size()==0)
            v.print("Storage is empty\n");
        file.close();
    }
    ~Controller()
    {
        if (v.direction != "Error")
        system("cls");
        std::ofstream file;
        file.open("DataStorage.txt");
        for (u_int i = 0; i < storage.size(); i++)
        {
            file << storage.at(i).getName() <<"\t"<< storage.at(i).getNum() << "\n";
        }
    }
};
