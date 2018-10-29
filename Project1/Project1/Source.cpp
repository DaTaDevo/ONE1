#include <iostream>
#include <string>
#include <fstream>
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
	//value for menu 
	int a;
	//menu

	cout << "1.Добавить машину 2.Найти машину" << endl;
	cin >> a;

	if (a==1)
	{
		cout << "1.Создать новую 2.Добавить в файл" << endl;
		cin >> a;
		if (a == 1)
		{
			Action.add(buy);
		}
		else
		{
			Action.add_to_file(buy);
		}
	}
	else
	{	
		Action.findFile();
	}


	system("pause");
	return 0; 
}