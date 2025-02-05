#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

#include <string.h>
#include "ResearchCenter.h"

int const MAX_STRING_SIZE = 100;

bool ResearchCenter::setName(const char* name)
{
	if (!name) return false;

	else
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		return true;
	}
}

ResearchCenter::~ResearchCenter()
{
	vector<Researcher*>::iterator itr = researchers.begin(); //initillize itr with the first pointer to Researcher
	vector<Researcher*>::iterator itrEnd = researchers.end(); //initillize itrEnd to be the end of the vector

	for (; itr != itrEnd; ++itr) // fire researchers
		delete *itr; // using iterator operator*

	delete[] name;

	cout << "destroy Research Center" << endl;
}

Researcher* ResearchCenter::getResearcher(const char* name) const
{
	if (!name || researchers.size() == 0)
	{
		return nullptr; // Return nullptr if name is invalid or no doctors exist
	}

	vector<Researcher*>::const_iterator itr = researchers.begin(); //initillize itr with the first pointer to Researcher
	vector<Researcher*>::const_iterator itrEnd = researchers.end(); //initillize itrEnd to be the end of the vector

	for (; itr != itrEnd; ++itr) // fire researchers
	{
		if (strcmp((*itr)->getName(), name) == 0) 
		{
			return *itr; // Return pointer to the Employee if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

ostream& operator<<(ostream& os, const ResearchCenter& r)
{
	os << "name: " << r.getName() << ", Number of researchers: " << r.researchers.size();
	return os;
}

istream& operator>>(istream& in, ResearchCenter& r)
{
	char name[MAX_STRING_SIZE];

	cout << "Enter Research Center name: ";
	in.getline(name, MAX_STRING_SIZE);
	r.setName(name);

	return in;
}

bool ResearchCenter::operator()(const char* name)
{
	if (!name)
		return false;

	if (strcmp(name, "name") == 0)
	{
		cout << this->getName();
		return true;
	}

	if (strcmp(name, "researchers") == 0)
	{
		this->showResearchers();
		return true;
	}

	return false;
}
