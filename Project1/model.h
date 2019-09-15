#include <string>
class Model
{
protected:
    std::string name,num;
public:
    Model()
    {

    }
    Model operator = (Model* m)
    {
        this->name      = m->name;
        this->num       = m->num;
        return *this;
    }
    Model(std::string s_name,std::string s_num) : name(s_name), num(s_num)
    {

    }
    void set(std::string s_name,std::string s_num)
    {
        this->name      = s_name;
        this->num       = s_num;
    }
    void setName(std::string s_name)
    {
        this->name = s_name;
    }
    void setNumber(std::string s_num)
    {
        this->num = s_num;
    }
    std::string getName()
    {
        return this->name;
    }
    std::string getNum()
    {
        return this->num;
    }
};
