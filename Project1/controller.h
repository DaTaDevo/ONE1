//#include <model.h>
#include <view.h>
#include <assert.h>
#include <fstream>
#include <vector>
class Controller : public Model
{
    View v;
    Model m;
    enum menu
    {
        AddContact = 1,
        FindContact,
        ShowContact,
        DeleteContact,
        Exit
    };
    void read(/*std::string file_name = "DataStorage"*/)
    {
        system("cls");
        std::ifstream file;
        file.open("DataStorage.txt");
        if (!file.is_open())
            return v.print("File Not Found!\n");
        while (file >> name >> num /*>> id_file*/)
        {
            m.set(name,num/*,id_file*/);//устанавливаем данные для нашей переменной m
            v.showContact(m);
        }
        file.close();
    }
public:
    void start()
    {
        while (true)
        {
            v.m_start();
            switch (v.answr)
            {
            case AddContact     : saveContact();break;
            case FindContact    : find();break;
            case ShowContact    : read()/*contactList()*/;break;
            case DeleteContact  : deleteContact();break;
            case Exit           : return;
            }
        }
    }
    void saveContact()
    {
        int err = v.m_addContact(m);
        if (err == 1)
            return;
        std::ofstream file;
//        file.open(m.getId()+".txt",std::ios::app);
//        file << m.getName() <<"\t" << m.getNum() << "\t" << m.getId() << "\n";
//        file.close();
        file.open("DataStorage.txt",std::ios::app);
        file << m.getName() <<"\t" << m.getNum()/* << "\t" << m.getId()*/ << "\n";
        file.close();
    }
    void find()
    {
        system("cls");
        std::string str = v.m_findContact();
//        int count = 0;
//        Model *storage = new Model [count];
        std::ifstream dstrg;
        dstrg.open("DataStorage.txt");
        bool found = false;
        while (dstrg >> Model::name >> Model::num /*>> Model::id_file*/)
        {
            m.set(Model::name,Model::num/*,Model::id_file*/);//устанавливаем данные для нашей переменной m
            if (Model::name == str)
            {
                found = true;
                v.showContact(m);
            }
        }
        if(!found)
        {
            v.print("This Contact Has Not Found!\n");
        }
        dstrg.close();
    }
//    void contactList()
//    {
//        system("cls");
//        std::string answr = v.m_showContacts();//получаем переменную answr;
//        if (answr == "")
//            read();
//        else if (answr == "Incorect input")
//            v.print(answr+"\n");
//        else
//            read(answr);
//    }
    bool checkInput(char inputed, std::string array)
    {
        for (unsigned int i = 0; i < array.size(); i++)
        {
            if(inputed == array[i])
                return  false;
        }
        return true;
    }
    void deleteContact()
    {
        read();
        v.m_deleteContact(&m);
        //just checky
//        if(m.getNum() == "blank" && m.getId() == "blank")
//        {
//           v.answr = 3;
//        }
        if (m.getNum() == "blank")
        {
            v.answr = 2;
        }
//        else if (m.getId() == "blank")
//        {
//             v.answr = 1;
//        }
        else
        {
            v.answr = 0;
        }
        //the way will be working until i'll get the Interet connection
        std::ifstream file;
//        int count = 0;
        std::vector<Model> updateStorage;
        file.open("DataStorage.txt");
        while (file >> Model::name >> Model::num/* >> Model::id_file*/)
        {
            if (m.getName() == Model::name)
            {
                switch (v.answr)
                {
                case 0 :
                    if (m.getNum() != Model::num)
                        updateStorage.push_back(*this);
                    break;
//                case 1 :
//                    if (m.getNum() != Model::num)
//                        updateStorage.push_back(*this);
//                    break;
//                case 2 :
//                    if (m.getId() != Model::id_file)
//                        updateStorage.push_back(*this);
//                    break;
                case 2 : break;
                }
            }
            else
                updateStorage.push_back(*this);
        }
        file.close();
        // updatedStorage сейчас должен быть заполнен не удаленными данными(данными котороые не попали под категорию удалить)
        std::ofstream new_file;
        new_file.open("DataStorage.txt");

        for (unsigned int i = 0; i<updateStorage.size(); i++)
        {
            new_file << updateStorage[i].getName() << "\t" << updateStorage[i].getNum()/* << "\t" << updateStorage[i].getId()*/ << "\n";
        }

        new_file.close();
        system("cls");
    }
};
