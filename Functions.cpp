#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	//временные переменные 
	Initials initials;
	Date date;
	Adress adress;

	cout << "Введите размер массива: ";
	cin >> n;

	//выделяем память для массива данных
	d = new Data[n];

	//вводим данные
	for (int i = 0; i < n; i++)
	{
		cout << "Введите ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Введите дату: ";
		cin >> date.day >> date.month >> date.year;

		cout << "Введите адрес: ";
		cin >> adress.city >> adress.home;

		//добавляем новые данные в элемент массива объект класса
		d[i].DataEntry(initials, date, adress);

		cout << "_______________________________________________\n";
	}
}

void DataReading(Data* (&d), int& n, string fileName)
{
	//создаем поток для данных
	ifstream reading(fileName);

	if (reading)
	{
		//временные переменные
		Initials initials;
		Date date;
		Adress adress;

		reading >> n;

		//выделяем память для массива данных 
		d = new Data[n];


		//считываем данные
		for (int i = 0; i < n; i++)
		{
			reading >> initials.surname >> initials.name >> initials.patrinymic;
			reading >> date.day >> date.month >> date.year;
			reading >> adress.city >> adress.home;

			//Добавляем данные
			d[i].DataEntry(initials, date, adress);
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данные №" << i + 1 << endl;

		d[i].Print();
		cout << "______________________________________________________\n";
	}
}

void DataChange(Data* d, int n)
{
	//временные переменные
	Initials initials;
	Date date;
	Adress adress;
	int _n;

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		cout << "Введите новую ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patrinymic;

		cout << "Введите новую дату: ";
		cin >> date.day >> date.month >> date.year;

		cout << "Введите новый адрес: ";
		cin >> adress.city >> adress.home;

		d[_n].DataEntry(initials, date, adress);
	}
	else
		cout << "Номер введен не верно!" << endl;
}

void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void AddData(Data* (&d), int& n)
{
	//временные переменные
	Initials initials;
	Date date;
	Adress adress;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите новую ФИО: ";
	cin >> initials.surname >> initials.name >> initials.patrinymic;

	cout << "Введите новую дату: ";
	cin >> date.day >> date.month >> date.year;

	cout << "Введите новый адрес: ";
	cin >> adress.city >> adress.home;

	d[size].DataEntry(initials, date, adress);

	cout << "Данные добавлены!" << endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++)
		{
			if (i != n)
			{
				d[q] = buf[i];
				q++;
			}
		}

		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введен не верно!" << endl;

	delete[]buf;
}

void SortingData(Data* d, int n)
{
	Data buf;
	int numOfSorted = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (d[i].GetInitials().surname > d[j].GetInitials().surname)
			{
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numOfSorted++;
			}
		}
	}

	cout << "Данные отсортированы!\nКоличество сортировок: " << numOfSorted << endl;
}

void SaveData(Data* d, int n, string fileName)
{
	ofstream record(fileName);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patrinymic<<endl;
			record << d[i].GetDate().day << " " << d[i].GetDate().month << " " << d[i].GetDate().year<<endl;
			record << d[i].GetAdress().city << " " << d[i].GetAdress().home<<endl;

			if (i < n - 1)
				record << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	cout << "Даннные сохранены в файл: " << fileName << endl;

	record.close();
}

