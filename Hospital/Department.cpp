#include <iostream>
using namespace std;

#include "Department.h"
#pragma warning(disable: 4996)



Department::Department(const char* name) :  
maxNumOfEmployees(MAX_DEPARTMENT_SIZE)
{
	setName(name);

	employees = new Employee * [maxNumOfEmployees];
}

Department::~Department()
{
	delete[] employees;

	delete[] name;
	cout << "Destroy Department" << endl;
}

ostream& operator<<(ostream& os, const Department& d)
{
	os << "{name: " << d.getName() << ", ";
	os << "number of employees: " << d.numOfEmployees << ", ";
	os << "employees capacity: " << d.maxNumOfEmployees << "}" << endl;

	os << "\ndoctors: " << endl; //showing doctors in department
	for (int i = 0; i < d.numOfEmployees; i++)
	{
		if (typeid(*d.employees[i]) == typeid(Doctor) || typeid(*d.employees[i]) == typeid(ResearcherDoctor))
		{
			os << *d.employees[i];

			if (i < d.numOfEmployees - 1) // Avoid trailing comma
			{
				os << ", ";
			}
		}
	}
	os << endl;

	cout << "nurses: " << endl; //showing nurses in department
	for (int i = 0; i < d.numOfEmployees; i++)
	{
		if (typeid(*d.employees[i]) == typeid(Nurse))
		{
			os << *d.employees[i];

			if (i < d.numOfEmployees - 1) // Avoid trailing comma
			{
				os << ", ";
			}
		}
	}
	os << endl;

	return os;
}

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

bool Department::setName(const char* name)
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

bool Department::addSurgeon(Surgeon& surgeon)
{
	if (!this) return false;

	if (numOfEmployees < maxNumOfEmployees)
	{
		employees[numOfEmployees] = &surgeon; // allocates the doctor to the department's doctor array
		employees[numOfEmployees]->setDepartment(this); // allocates the department who called addDoctor (this) to the added doctor 
		numOfEmployees++;
		return true;
	}

	return false;
}

bool Department::addDoctor(Doctor& doctor)
{
	if (!this) return false;

	if (numOfEmployees < maxNumOfEmployees)
	{
		employees[numOfEmployees] = &doctor; // allocates the doctor to the department's doctor array
		employees[numOfEmployees]->setDepartment(this); // allocates the department who called addDoctor (this) to the added doctor 
		numOfEmployees++;
		return true;
	}

	return false;
}

bool Department::addNurse(Nurse& nurse) 
{
	if (!this) return false;

	if (numOfEmployees < maxNumOfEmployees)
	{
		employees[numOfEmployees] = &nurse; // allocates the nurse to the department's nurse array
		employees[numOfEmployees]->setDepartment(this); // allocates the department who called addNurse (this) to the added nurse
		numOfEmployees++;
		return true;  
	}

	return false;  
}

void Department::showSurgeons() const
{
	cout << "surgeons: " << "\n" << endl; //showing surgeons in hospital
	cout << "{";
	for (int i = 0; i < numOfEmployees; i++)
	{
		if (typeid(*employees[i]) == typeid(Surgeon))
		{
			cout << employees[i]->getName();

			if (i < numOfEmployees - 1)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

void Department::showDoctors() const
{
	cout << "doctors: " << "\n" << endl; //showing doctors in department
	cout << "{";
	for (int i = 0; i < numOfEmployees; i++)
	{
		if (typeid(*employees[i]) == typeid(Doctor) || typeid(*employees[i]) == typeid(ResearcherDoctor) || typeid(*employees[i]) == typeid(Surgeon))
		{
			cout << employees[i]->getName();

			if (i < numOfEmployees - 1)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

void Department::showNurses() const
{
	cout << "nurses: " << "\n" << endl; //showing nurses in hospital
	cout << "{";
	for (int i = 0; i < numOfEmployees; i++)
	{
		if (typeid(*employees[i]) == typeid(Nurse))
		{
			cout << employees[i]->getName();

			if (i < numOfEmployees - 1)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

