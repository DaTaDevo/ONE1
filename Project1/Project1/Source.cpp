#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct car 
{
	string name;
	int price;
	string info;
};

class func 
{
public :
	void find()
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
					 getline(file,str);
					 cout << str << endl;
				}
			}

		}

	}

	void add(car buy)
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

	void add_to_file(car buy)
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
			add_to_file(buy);
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

private :
	int a;
	string input_name;

	ifstream file;
	ofstream file_;
};

int main() 
{
	setlocale(LC_ALL, "rus");
	car buy;
	func func;
	//value for menu 
	int a;
	//menu

	cout << "1.�������� ������ 2.����� ������" << endl;
	cin >> a;

	if (a==1)
	{
		cout << "1.������� ����� 2.�������� � ����" << endl;
		cin >> a;
		if (a == 1)
		{
			func.add(buy);
		}
		else
		{
			func.add_to_file(buy);
		}
	}
	else
	{	
		func.find();
	}


	system("pause");
	return 0; 
}