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



// �������� ������
class Data
{
	//�������� ����� ������
private:
	Initials initials;
	Date date;
	Adress adress;

	//�������� ����� ������
public:
	//������������ ������ ������
	Data();//����������� �� ���������. C������ ����� ������
	Data(Initials initials_, Date date_, Adress adress_);//����������� � �����������
	~Data();//����������

	void Print();
	void DataEntry(Initials initials_, Date date_, Adress adress_);
	
	//����� ������ (�����) �� ������
	Initials GetInitials() { return initials; };
	Date GetDate() { return date; };
	Adress GetAdress() { return adress; };

	Data& operator = (Data d_o);
};