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
	string info;
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

	void menu(car buy);

	void add(car buy);

	void add_to_file(car buy);

private:
	int a;
	string input_name;

	ifstream file;
	ofstream file_;

	vector <car> SaveDataCar;
	 
};
