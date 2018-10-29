#pragma once 
#include "Action.cpp"
#include "Source.cpp"

class Action
{
public:
	void findFile();

	void add(car buy);

	void add_to_file(car buy);

private:
	int a;
	string input_name;

	ifstream file;
	ofstream file_;
};
