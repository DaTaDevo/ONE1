#include "Action.h"

void Action :: findFile()
{
	cout << "��� ������" << endl;
	cin >> input_name;

	file.open(input_name + ".txt");
	if (!file.is_open())
	{
		cout << "������ �� �������!" << endl;
	}
	else
	{
		cout << "�������!" << endl;

		cout << "1.�������   2.�������" << endl;
		cin >> a;

		if (a == 1)
		{
			string str;
			while (!file.eof())
			{
				str = "";
				getline(file, str);
				cout << str << endl;
			}
		}

	}

}

void Action :: add()
{
	cout << "������� ��� ����� ������ ����� :	";

	cin >> input_name;

	AddDataCar();

	cout << "1.�������� 2.���������" << endl;
	cin >> a;
	if (a == 1)
	{
		AddDataCar();
	}
	else
	{
		
		file_.open(input_name + ".txt");
		file_ << "-------------" << endl;
		file_ << "Name :  " << name << endl;
		file_ << "Price:  " << price << endl;
		file_ << "Number :  " << number << endl;
		file_ << "-------------" << endl;
		file_.close();
	}
	cout << "������� ����������" << endl;


}

void Action :: add_to_file()
{
	cout << "������� ��� ����� ������������� �����(��� ����������)  :  ";

	cin >> input_name;

	AddDataCar();

	cout << "1.�������� 2.���������" << endl;
	cin >> a;
	if (a == 1)
	{
		AddDataCar();
		
	}
	else
	{
		file_.open(input_name + ".txt", ofstream::app);
		file_ << name << endl;
		file_ << price << endl;
		file_ << number << endl;
		file_.close();
	}
	cout << "������� ����������" << endl;
	submenu();
}

void Action :: AddDataCar()
{
	cout << "\n -- ������� ������ � ������ --" << endl;

	cout << "������� ���		:	 ";
	cin >> name;
	cout << "������� ����		:	 ";
	cin >> price;
	cout << "������� �����		:	 ";
	cin >> number;

	cout << "------------" << endl;

	cout << "������	   : " << endl;
	cout << "���	   : " << name << endl;
	cout << "����	   : " << price << endl;
	cout << "�����	   : " << number << endl;

	cout << "------------" << endl;
}

void Action :: menu() 
{

	cout << "\n\n1.�������� ������ \n2.����� ������" << endl;
	cin >> a;

	if (a == 1)
	{
		cout << "\n1.������� ����� ���� ��� ������	 2.�������� � ������������ ���� \n" << endl;
		cin >> a;
		if (a == 1)
		{
			add();
				SaveDataCar.push_back(buy);
			menu();
		}
		else
		{
			add_to_file();
				SaveDataCar.push_back(buy);
			menu();

		}
	}
	else
	{
			findFile();
				SaveDataCar.push_back(buy);
			menu();

	}
}

void Action :: submenu() 
{
	cout << "\n\n1.�������� ��� ������ 2.������� ����� ���� 3.����� � ������� ����" << endl;
	cin >> a;

	if (a == 1)
	{
		AddDataCar();
		MoveDataToFile();
		submenu();
		
	}
	else if (a == 2)
	{
		add();
	}
	else if (a == 3)
	{
		menu();
	}

}

void Action::MoveDataToFile() 
{
	
	file_.open(namereturn + ".txt", ofstream::app);
	file_ << "----------------" << endl;
 	file_ << "Name :" << name << endl;
	file_ << "Price:" << price << endl;
	file_ << "Number :" << number << endl;
	file_ << "----------------" << endl;
	file_.close();
}
