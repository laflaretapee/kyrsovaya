#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace	std;

struct Initials {
	string surname,
		name,
		patrinymic;
};

struct Date
{
	int day,
		month,
		year;
};

struct Adress
{
	string city;
	int home;
};



// Прототип класса
class Data
{
	//закрытая часть класса
private:
	Initials initials;
	Date date;
	Adress adress;

	//открытая часть класса
public:
	//обязательные методы класса
	Data();//конструктор по умолчанию. Cоздает пусто объект
	Data(Initials initials_, Date date_, Adress adress_);//конструктор с параметрами
	~Data();//деструктор

	void Print();
	void DataEntry(Initials initials_, Date date_, Adress adress_);
	
	//вывод данных (полей) из класса
	Initials GetInitials() { return initials; };
	Date GetDate() { return date; };
	Adress GetAdress() { return adress; };

	Data& operator = (Data d_o);
};