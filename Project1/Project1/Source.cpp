#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Action.h"

using namespace std;

struct car 
{
	string name;
	int price;
	string info;
};



int main() 
{
	setlocale(LC_ALL, "rus");
	car buy;
	Action Action;

	Action.menu(buy);



	system("pause");
	return 0; 
}