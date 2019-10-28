#include <model.h>
#include <vector>
#include <fstream>
class Controller  : public Model
{
    std::vector<Model> storage;
  public :
    Controller()
    {
        //fill vector
        std::fstream file;
        file.open("DataStorage.txt",std::ios::out);
        if(!file.is_open())
            return;
        while (file >>Model::name >> Model::num)
        {
            storage.push_back(*Model::get());
        }
        file.close();
    }
    ~Controller()
    {
        //save vector
        std::fstream file;
    }
    int size()
    {
        return static_cast<int>(storage.size());
    }
    Model getModel(unsigned int indx = 0)
    {
       return storage.at(indx);
    }
    void addModel(Model* added)
    {
        storage.push_back(*added);
    }
    void deleteModel(Model* deleted)
    {
        std::vector <Model> newStorage;
        for (Model n : storage)
        {
            if(n != *deleted)
            {
                newStorage.push_back(n);
            }
        }
        storage.clear();
        storage = newStorage;
    }
};
