#include "phonebook.h"

using namespace std;

#include <vector>

class name
{
public:
    string value1 = "Name ";
    string value2 = "Name2";
};

void func (vector <name> *vec)
{
    unsigned int i;
    for (i = 0; i < i+10; i++)
    {
        cout<<vec->at(i).value1<<endl;
        cout<<vec->at(i).value2<<endl << endl;
    }
}

int main()
{
    name var;
    vector <name> vec;

    vec.push_back(var);
    func(vec);
    /*
    Contact user;
    while (true)
    {
            menu(user);
    }*/
    return 0;
}
