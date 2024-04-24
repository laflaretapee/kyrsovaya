#include "Functions.h"
using namespace std;

int _stateMenu;

void Menu()
{
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод данных" << endl
		<< "(3) Изменение данных" << endl
		<< "(4) Добавление данных" << endl
		<< "(5) Удаление данных" << endl
		<< "(6) Сортировка данных" << endl
		<< "(7) Сохранение данных" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

void main()
{
	//руссификация консоли ввода/вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu();
	int _actions;
	string fileName;

	int _size = 0;
	Data* d = new Data[_size];

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");//очистка

			cout << "Ввести данные вручную или считать из файла?: ";
			cin >> _actions;

			system("cls");//очистка

			if (_actions == 1)
			{
				DataEntry(d, _size);//вручную
			}
			else
			{
				cout << "Введите название файла: ";
				cin >> fileName;//Input.txt

				DataReading(d, _size, fileName);
			}
			system("pause");
			system("cls");
			Menu();
			break;
		////////////////////////////////////////////////////////////
		case 2:
			system("cls");

			if (_size != 0)
				Print(d, _size);
			else
				cout << "Данные пусты!" << endl;
			
			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////////////////
		case 3:
			system("cls");

			if (_size != 0)
				DataChange(d, _size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////////////////
		case 4:
			system("cls");

			if (_size != 0)
				AddData(d, _size);
			else
				cout << "Данные пусты!" << endl;
			
			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////////////////
		case 5:
			system("cls");

			if (_size != 0)
				DeleteData(d, _size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////////////////
		case 6:
			system("cls");

			if (_size != 0)
				SortingData(d, _size);
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////////////////
		case 7:
			system("cls");

			if (_size != 0)
			{
				cout << "Введите название файла: ";
				cin >> fileName;//Out.txt

				SaveData(d, _size, fileName);
			}
				
			else
				cout << "Данные пусты!" << endl;

			system("pause");
			system("cls");
			Menu();
			break;
		///////////////////////////////////////////////////////////
		default:
			cout << "Пункт меню введен не верно!" << endl;
			system("cls");
			Menu();
			break;
		}


	}
	system("cls");
	cout << "Работа завершена!" << endl;
	system("pause");
}