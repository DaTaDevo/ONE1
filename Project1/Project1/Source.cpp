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
		cout << "Имя машины" << endl;
		cin >> input_name;

		file.open(input_name + ".txt");
		if (!file.is_open())
		{
			cout << "Машина не найдена!" << endl;
		}
		else
		{
			cout << "Успешно!" << endl;

			cout << "1.Открыть 2.Закрыть" << endl;
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
		cout << "-- Введите данные о машине --" << endl;


		cout << "Введите имя: " << endl;
		cin >> buy.name;
		cout << "Введите цену: " << endl;
		cin >> buy.price;
		cout << "Введите информацию :" << endl;
		cin >> buy.info;

		cout << "------------" << endl;

		cout << "Данные :/n" << endl;
		cout << "Имя: " << buy.name << endl;
		cout << "Цена: " << buy.price << endl;
		cout << "Информация: " << buy.info << endl;

		cout << "------------" << endl;
		 
		cout << "1.Изменить 2.Сохранить" << endl;
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
		cout << "Успешно сохраннено" << endl;


	}

	void add_to_file(car buy)
	{
		cout << "Введите имя файла(без расширения)" << endl << endl;;

		cin >> input_name;


		 

		cout << "Введите имя: " << endl;
		cin >> buy.name;
		cout << "Введите цену: " << endl;
		cin >> buy.price;
		cout << "Введите информацию :" << endl;
		cin >> buy.info;

		cout << "------------" << endl;

		cout << "Данные :/n" << endl;
		cout << "Имя: " << buy.name << endl;
		cout << "Цена: " << buy.price << endl;
		cout << "Информация: " << buy.info << endl;

		cout << "------------" << endl;

		cout << "1.Изменить 2.Сохранить" << endl;
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
		cout << "Успешно сохраннено" << endl;
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

	cout << "1.Добавить машину 2.Найти машину" << endl;
	cin >> a;

	if (a==1)
	{
		cout << "1.Создать новую 2.Добавить в файл" << endl;
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