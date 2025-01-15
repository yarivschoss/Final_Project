#include <iostream>
using namespace std;

#include "Department.h"
#pragma warning(disable: 4996)



Department::Department(const char* name) :  
maxNumOfDoctors(MAX_DEPARTMENT_SIZE), maxNumOfNurses(MAX_DEPARTMENT_SIZE)
{
	setName(name);

	doctors = new Doctor * [maxNumOfDoctors];
	nurses = new Nurse * [maxNumOfNurses];
}

Department::~Department()
{
	//for (int i = 0; i < maxNumOfDoctors; i++) // fire doctors
	//	delete doctors[i];
	delete[] doctors;

	//for (int i = 0; i < maxNumOfNurses; i++) // fire nurses
	//	delete nurses[i];
	delete[] nurses;

	delete[] name;
	cout << "Destroy Department" << endl;
}

ostream& operator<<(ostream& os, const Department& d)
{
	os << "{name: " << d.getName() << ", ";
	os << "number of doctors: " << d.numOfDoctors << ", ";
	os << "number of nurses: " << d.numOfNurses << ", ";
	os << "doctors capacity: " << d.maxNumOfDoctors << ", ";
	os << "nurses capacity: " << d.maxNumOfNurses << "}" << endl;

	os << "\ndoctors: " << endl; //showing doctors in department
	for (int i = 0; i < d.numOfDoctors; i++)
	{
		os << *d.doctors[i];
		
		if (i < d.numOfDoctors - 1) // Avoid trailing comma
		{
			os << ", ";
		}
	}
	os << endl;

	cout << "nurses: " << endl; //showing nurses in department
	for (int i = 0; i < d.numOfNurses; i++)
	{
		os << *d.nurses[i];

		if (i < d.numOfNurses - 1) // Avoid trailing comma
		{
			os << ", ";
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

bool Department::addDoctor(Doctor& doctor)
{
	if (numOfDoctors < maxNumOfDoctors)
	{
		doctors[numOfDoctors] = &doctor; // allocates the doctor to the department's doctor array
		doctors[numOfDoctors]->setDepartment(this); // allocates the department who called addDoctor (this) to the added doctor 
		numOfDoctors++;
		return true;
	}

	return false;
}

bool Department::addNurse(Nurse& nurse) 
{
	if (numOfNurses < maxNumOfNurses) 
	{
		nurses[numOfNurses] = &nurse; // allocates the nurse to the department's nurse array
		nurses[numOfNurses]->setDepartment(this); // allocates the department who called addNurse (this) to the added nurse
		numOfNurses++;  
		return true;  
	}

	return false;  
}

void Department::showAll() const
{
	cout << "{name: " << name << ", ";
	cout << "number of doctors: " << numOfDoctors << ", ";
	cout << "number of nurses: " << numOfNurses << ", ";
	cout << "doctors capacity: " << maxNumOfDoctors << ", ";
	cout << "nurses capacity: " << maxNumOfNurses << "}" << endl;
	
	cout << "\ndoctors: " << endl; //showing doctors in department
	for (int i = 0; i < numOfDoctors; i++)
	{
		cout << *doctors[i];

		if (i < numOfDoctors - 1)
			cout << ", ";
	}
	cout << endl;

	cout << "nurses: " << endl; //showing nurses in department
	for (int i = 0; i < numOfNurses; i++)
	{
		cout << *nurses[i];

		if (i < numOfNurses - 1)
			cout << ", ";
		
	}
	cout << endl;

}

void Department::showDoctors() const
{
	cout << "doctors: " << "\n" << endl; //showing doctors in department
	cout << "{";
	for (int i = 0; i < numOfDoctors; i++)
	{
		cout << doctors[i]->getName();

		if (i < numOfDoctors - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

void Department::showNurses() const
{
	cout << "nurses: " << "\n" << endl; //showing nurses in hospital
	cout << "{";
	for (int i = 0; i < numOfNurses; i++)
	{
		cout << nurses[i]->getName();

		if (i < numOfNurses - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

