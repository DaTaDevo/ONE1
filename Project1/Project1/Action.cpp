#include "Action.h"

void Action :: findFile()
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

		cout << "1.Открыть   2.Закрыть" << endl;
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
	cout << "Введите имя файла нового файла :	";

	cin >> input_name;

	AddDataCar();

	cout << "1.Изменить 2.Сохранить" << endl;
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
	cout << "Успешно сохраннено" << endl;


}

void Action :: add_to_file()
{
	cout << "Введите имя файла существующего файла(без расширения)  :  ";

	cin >> input_name;

	AddDataCar();

	cout << "1.Изменить 2.Сохранить" << endl;
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
	cout << "Успешно сохраннено" << endl;
	submenu();
}

void Action :: AddDataCar()
{
	cout << "\n -- Введите данные о машине --" << endl;

	cout << "Введите имя		:	 ";
	cin >> name;
	cout << "Введите цену		:	 ";
	cin >> price;
	cout << "Введите номер		:	 ";
	cin >> number;

	cout << "------------" << endl;

	cout << "Данные	   : " << endl;
	cout << "Имя	   : " << name << endl;
	cout << "Цена	   : " << price << endl;
	cout << "Номер	   : " << number << endl;

	cout << "------------" << endl;
}

void Action :: menu() 
{

	cout << "\n\n1.Добавить машину \n2.Найти машину" << endl;
	cin >> a;

	if (a == 1)
	{
		cout << "\n1.Создать новый файл для машины	 2.Добавить в существующий файл \n" << endl;
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
	cout << "\n\n1.Добавить еще машину 2.Создать новый файл 3.Выйти в главное меню" << endl;
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
