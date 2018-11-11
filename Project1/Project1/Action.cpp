#include "Action.h"
#define NAME 

void Action :: findFile()
{
	cout << "Имя файла:" << endl;
	cin >> input_name;

	file.open(input_name + ".txt");
	if (!file.is_open())
	{
		cout << "Файл не найден!" << endl;
	}
	else
	{
		cout << "Успешно!" << endl;

		cout << "1.Открыть   2.Закрыть" << endl;
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
		SaveDataCar.push_back(buy);
		file_.open(input_name + ".txt");
		file_ << "-------------" << endl;
		file_ << "Name :  " <<buy.name << endl;
		file_ << "Price:  " << buy.price << endl;
		file_ << "Number :  " << buy.number << endl;
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
		SaveDataCar.push_back(buy);
		file_.open(input_name + ".txt", ofstream::app);
		file_ << "Name  :" << buy.name << endl;
		file_ << "Price :" << buy.price << endl;
		file_ << "Number:" << buy.number << endl;
		file_.close();
	}
	cout << "Успешно сохраннено" << endl;
	submenu();
}

void Action :: AddDataCar()
{
	cout << "\n -- Введите данные о машине --" << endl;

	cout << "Введите имя		:	 ";
	cin >> buy.name;
	cout << "Введите цену		:	 ";
	cin >> buy.price;
	cout << "Введите номер		:	 ";
	cin >> buy.number;

	cout << "------------" << endl;

	cout << "Данные	   : " << endl;
	cout << "Имя	   : " << buy.name << endl;
	cout << "Цена	   : " << buy.price << endl;
	cout << "Номер	   : " << buy.number << endl;

	cout << "------------" << endl;
}

void Action :: menu() 
{
#ifdef NAME
		cout << "\n\n1.Добавить машину \n2.Найти машину\n3.Vector" << endl;
#else
	cout << "\n\n1.Добавить машину \n2.Найти машину" << endl;
#endif
	

	cin >> a;

	if (a == 1)
	{
		cout << "\n1.Создать новый файл для машины	 2.Добавить в существующий файл \n" << endl;
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
 	file_ << "Name :" << buy.name << endl;
	file_ << "Price:" << buy.price << endl;
	file_ << "Number :" << buy.number << endl;
	file_ << "----------------" << endl;
	file_.close();
}
