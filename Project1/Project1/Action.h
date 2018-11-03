#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct car
{
	string name;
	int price;
	int number;
};


class Action
{
public:
	Action()
	{

	}

	~Action() 
	{

	}

	void findFile();

	void menu();

	void add();

	void submenu();

	void MoveDataToFile();

	void add_to_file();

	void AddDataCar();

private:
	int a;
	string input_name;
	string &namereturn = input_name;

	ifstream file;
	ofstream file_;

	car buy;

	//link to struct value
	string &name = buy.name;
	int &price   = buy.price;
	int number   = buy.number;

	vector <car> SaveDataCar;
	 
};
