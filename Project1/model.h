#include <string>
class Model
{
protected:
    std::string name,num/*,id_file*/;
public:
    Model()
    {

    }
    Model operator = (Model* m)
    {
        this->name      = m->name;
        this->num       = m->num;
//        this->id_file   = m->id_file;
        return *this;
    }
    Model(std::string s_name,std::string s_num) : name(s_name), num(s_num)
    {

    }
    void set(std::string s_name,std::string s_num/*,std::string s_id*/)
    {
        this->name      = s_name;
        this->num       = s_num;
//        this->id_file   = s_id;
    }
    void setName(std::string s_name)
    {
        this->name = s_name;
    }
    void setNumber(std::string s_num)
    {
        this->num = s_num;
    }
//    Model* get()
//    {
//        return this;
//    }
    std::string getName()
    {
        return this->name;
    }
    std::string getNum()
    {
        return this->num;
    }
//    void setId_file(std::string id)
//    {
//        this->id_file = id;
//    }
//    std::string getId()
//    {
//        return  this->id_file;
//    }
};
