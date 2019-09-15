//#include <model.h>
#include <view.h>
#include <assert.h>
#include <fstream>
#include <vector>
typedef unsigned int u_int;
class Controller : public Model
{
    View v;
    Model m;
    std::vector <Model> storage;
    void fillStorage()
    {
        system("cls");
        std::ifstream file;
        file.open("DataStorage.txt");
//        if (!file.is_open())
//            return v.print("Storage is empty");
        while (file >> name >> num)
        {
            m.set(name,num);//устанавливаем данные для нашей переменной m
            storage.push_back(m);
        }
        if(storage.size()==0)
            return v.print("Storage is empty\n");
        file.close();
    }
    void saveStorage()
    {
        system("cls");
        std::ofstream file;
        file.open("DataStorage.txt");
        for (u_int i = 0; i < storage.size(); i++)
        {
            file << storage.at(i).getName() <<"\t"<< storage.at(i).getNum() << "\n";
        }
    }
public:
    void start()
    {
        fillStorage();
        while(true)
        {
        v.m_start();
        int cmd = v.answr;
        if (cmd==1)     saveContact();
        if (cmd==2)     find();
        if (cmd==3)     show();
        if (cmd==4)     deleteContact();
        if (cmd==5)     {saveStorage(); return;}
        }
    }
private: 
    void saveContact()
    {
        int err = v.m_addContact(m);
        if (err == 1)
            return;
        storage.push_back(m);
    }
    void find()
    {
        system("cls");
        std::string str = v.m_findContact();
//        std::ifstream dstrg;
//        dstrg.open("DataStorage.txt");
        bool found = false;
        for (u_int i = 0; i < storage.size();i++)
        {
            if (storage.at(i).getName() == str)
            {
                found = true;
                v.showContact(storage[i]);
            }
        }
        if(!found)
        {
            v.print("This Contact Has Not Found!\n");
        }
//        dstrg.close();
    }
    void deleteContact()
    {
        show();
        v.m_deleteContact(m);
        if (m.getNum() == "blank")
        {
            v.answr = 2;
        }
        else
        {
            v.answr = 0;
        }
        std::vector<Model> updateStorage;
        for (u_int i =0;i<storage.size();i++)
        {
            if (m.getName() == storage.at(i).getName())
            {
                switch (v.answr)
                {
                case 0 :
                    if (m.getNum() != storage.at(i).getNum())
                        updateStorage.push_back(storage.at(i));
                    break;
                case 2 : break;
                }
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

        system("cls");
    }
    void show()
    {
        system("cls");
        for (u_int i = 0;i < storage.size();i++)
        {
            v.showContact(storage.at(i));
        }
    }
};
