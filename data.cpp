#include "data.h"

Data::Data()
{

	initials.surname = "";
	initials.name = "";
	initials.patrinymic = "";

	date.day = 0;
	date.month = 0;
	date.year = 0;

	adress.city = "";
	adress.home = 0;

}

Data::Data(Initials initials_, Date date_, Adress adress_)
{

	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	adress.city = adress_.city;
	adress.home = adress_.home;

}

Data::~Data()
{
}


void Data::Print()
{
	cout << "ÔÈÎ: " << initials.surname << " " << initials.name << " " << initials.patrinymic << endl;
	cout << "Äàòà: " << date.day << " " << date.month << " " << date.year << endl;
	cout << "Àäğåññ: " << adress.city << " " << adress.home << endl;
}

void Data::DataEntry(Initials initials_, Date date_, Adress adress_)
{
	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	adress.city = adress_.city;
	adress.home = adress_.home;
}

Data& Data::operator=(Data d_o)
{
	this->initials.surname = d_o.initials.surname;
	this->initials.name = d_o.initials.name;
	this->initials.patrinymic = d_o.initials.patrinymic;
	
	this->date.day = d_o.date.day;
	this->date.month = d_o.date.month;
	this->date.year = d_o.date.year;

	this->adress.city = d_o.adress.city;
	this->adress.home = d_o.adress.home;

	return *this;
}

