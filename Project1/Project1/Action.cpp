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

		cout << "1.������� 2.�������" << endl;
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

void Action :: add(car buy)
{
	cout << "-- ������� ������ � ������ --" << endl;

	

	cout << "������� ���: " << endl;
	cin >> buy.name;
	cout << "������� ����: " << endl;
	cin >> buy.price;
	cout << "������� ���������� :" << endl;
	cin >> buy.info;

	cout << "------------" << endl;

	cout << "������ :/n" << endl;
	cout << "���: " << buy.name << endl;
	cout << "����: " << buy.price << endl;
	cout << "����������: " << buy.info << endl;

	cout << "------------" << endl;

	cout << "1.�������� 2.���������" << endl;
	cin >> a;
	if (a == 1)
	{
		add(buy);
	}
	else
	{
		
		file_.open(buy.name + ".txt");
		file_ << "-------------" << endl;
		file_ << buy.name << endl;
		file_ << buy.price << endl;
		file_ << buy.info << endl;;
		file_ << "-------------" << endl;
		file_.close();
	}
	cout << "������� ����������" << endl;


}

void Action :: add_to_file(car buy)
{
	cout << "������� ��� �����(��� ����������)" << endl << endl;;

	cin >> input_name;




	cout << "������� ���: " << endl;
	cin >> buy.name;
	cout << "������� ����: " << endl;
	cin >> buy.price;
	cout << "������� ���������� :" << endl;
	cin >> buy.info;

	cout << "------------" << endl;

	cout << "������ :/n" << endl;
	cout << "���: " << buy.name << endl;
	cout << "����: " << buy.price << endl;
	cout << "����������: " << buy.info << endl;

	cout << "------------" << endl;

	cout << "1.�������� 2.���������" << endl;
	cin >> a;
	if (a == 1)
	{
		add_to_file(buy
);
	}
	else
	{
		file_.open(input_name + ".txt", ofstream::app);
		file_ << buy.name << endl;
		file_ << buy.price << endl;
		file_ << buy.info << endl;
		file_.close();
	}
	cout << "������� ����������" << endl;
}

void Action :: menu(car buy) 
{

	cout << "1.�������� ������ 2.����� ������" << endl;
	cin >> a;

	if (a == 1)
	{
		cout << "1.������� ����� 2.�������� � ����" << endl;
		cin >> a;
		if (a == 1)
		{
			add(buy);
				SaveDataCar.push_back(buy);
			menu(buy);
		}
		else
		{
			add_to_file(buy);
				SaveDataCar.push_back(buy);
			menu(buy);

		}
	}
	else
	{
			findFile();
				SaveDataCar.push_back(buy);
			menu(buy);

	}
}

