#include <iostream>
using namespace std;

#include "Department.h"
#pragma warning(disable: 4996)

bool Department::operator()(const char* name)
{
	if (!name)
		return false;

	if (strcmp(name, "name") == 0)
	{
		cout << name;
		return true;
	}

	if (strcmp(name, "doctors") == 0)
	{
		showDoctors();
		return true;
	}

	if (strcmp(name, "nurses") == 0)
	{
		showNurses();
		return true;
	}

	return false;
}
