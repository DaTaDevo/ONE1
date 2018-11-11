#include "Action.h"
#define NAME 

void Action :: findFile()
{
	cout << "��� �����:" << endl;
	cin >> input_name;

	file.open(input_name + ".txt");
	if (!file.is_open())
	{
		cout << "���� �� ������!" << endl;
	}
	else
	{
		cout << "�������!" << endl;

		cout << "1.�������   2.�������" << endl;
		cin >> a;

		if (a == 1)
		{
			file >> buy.name;
			file >> buy.number;
			file >> buy.price;

			cout << buy.name << endl << buy.number << endl << buy.price << endl;
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
		SaveDataCar.push_back(buy);
		file_.open(input_name + ".txt");
		file_ << "-------------" << endl;
		file_ << "Name :  " <<buy.name << endl;
		file_ << "Price:  " << buy.price << endl;
		file_ << "Number :  " << buy.number << endl;
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
		SaveDataCar.push_back(buy);
		file_.open(input_name + ".txt", ofstream::app);
		file_ << "Name  :" << buy.name << endl;
		file_ << "Price :" << buy.price << endl;
		file_ << "Number:" << buy.number << endl;
		file_.close();
	}
	cout << "������� ����������" << endl;
	submenu();
}

void Action :: AddDataCar()
{
	cout << "\n -- ������� ������ � ������ --" << endl;

	cout << "������� ���		:	 ";
	cin >> buy.name;
	cout << "������� ����		:	 ";
	cin >> buy.price;
	cout << "������� �����		:	 ";
	cin >> buy.number;

	cout << "------------" << endl;

	cout << "������	   : " << endl;
	cout << "���	   : " << buy.name << endl;
	cout << "����	   : " << buy.price << endl;
	cout << "�����	   : " << buy.number << endl;

	cout << "------------" << endl;
}

void Action :: menu() 
{
#ifdef NAME
		cout << "\n\n1.�������� ������ \n2.����� ������\n3.Vector" << endl;
#else
	cout << "\n\n1.�������� ������ \n2.����� ������" << endl;
#endif
	

	cin >> a;

	if (a == 1)
	{
		cout << "\n1.������� ����� ���� ��� ������	 2.�������� � ������������ ���� \n" << endl;
		cin >> a;
		if (a == 1)
		{
			add();
			menu();
		}
		else
		{
			add_to_file();
			menu();

		}
		
	}
	else if (a == 2)
	{
			findFile();
			menu();

	}
	else if (a == 3)
	{
		cout << SaveDataCar.size() << endl;
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
 	file_ << "Name :" << buy.name << endl;
	file_ << "Price:" << buy.price << endl;
	file_ << "Number :" << buy.number << endl;
	file_ << "----------------" << endl;
	file_.close();
}
