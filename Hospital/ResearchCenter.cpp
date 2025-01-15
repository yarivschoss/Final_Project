#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

#include <string.h>
#include "ResearchCenter.h"

ResearchCenter::ResearchCenter(const char* name) 
{
	setName(name);
}

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
	delete[] name;

	cout << "destroy Research Center" << endl;
}