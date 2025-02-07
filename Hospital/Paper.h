#ifndef __PAPER_H
#define __PAPER_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;


class Paper
{ 

public:

	friend class Researcher;

private:

	string name, magazineName;
	time_t publishDate;

public:

	Paper(const string& name, const string& magazineName, time_t publishDate) : publishDate(publishDate)
	{
		setName(name);
		setMagazineName(magazineName);
	}
	~Paper()
	{
		cout << "burning paper" << endl;
	}

	bool setName(const string& name) // Sets the paper's name
	{
		this->name = name;
		return true;
	}
	bool setMagazineName(const string& name) // Sets the paper's name
	{
		this->magazineName = name;
		return true;
	}
	

	const string& getName() const { return name; } // Gets the paper's name
	const string& getMagazineName() const { return magazineName; } // Gets the paper's magazine name
	const time_t getPublishDate() const { return publishDate; } // Gets the paper's published date

	friend ostream& operator<<(ostream& os, const Paper& p) 
	{
		os << "name: " << p.name << ", magazine name: " << p.magazineName << ", publish date: " << ctime(&p.publishDate);
		return os;
	}
	friend istream& operator>>(istream& in, Paper& p)
	{
		string name;

		cout << "Enter paper name: ";
		getline(in,name);
		p.setName(name);

		cout << "Enter published magazine name: ";
		getline(in,name);
		p.setMagazineName(name);

		cout << "Enter publish date (YYYY-MM-DD): ";
		int year, month, day;
		char separator;
		in >> year >> separator >> month >> separator >> day;

		struct tm timeStruct = { 0 };
		timeStruct.tm_year = year - 1900;
		timeStruct.tm_mon = month - 1;
		timeStruct.tm_mday = day;
		p.publishDate = mktime(&timeStruct);

		return in;
	}
};


#endif // __PAPER_H

