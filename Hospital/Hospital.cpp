#include <iostream>
#pragma warning(disable: 4996)
using namespace std;

#include "Hospital.h"


Hospital::Hospital(const char* name) :  
maxNumOfDepartments(DEFAULT_NUM_OF_DEPARTMENTS), maxNumOfDoctors(DEFAULT_STAFF_SIZE), maxNumOfNurses(DEFAULT_STAFF_SIZE), 
researchCenter(nullptr)
{
	setName(name);

	doctors = new Doctor* [maxNumOfDoctors];
	nurses = new Nurse* [maxNumOfNurses];
	departments = new Department* [maxNumOfDepartments];
}

Hospital::~Hospital()
{
	for (int i = 0; i < numOfDoctors; i++) // fire doctors
		delete doctors[i];
	delete[]doctors;

	for (int i = 0; i < numOfNurses; i++) // fire nurses
		delete nurses[i];
	delete[]nurses;

	for (int i = 0; i < numOfDepartments; i++) // destroy departments
		delete departments[i];
	delete[]departments;

	delete[]name;
	cout << "Destroy Hospital" << endl;
}

bool Hospital::setName(const char* name)
{
	if (!name) return false;

	else
	{
		delete[]this->name;
		this->name = new char[strlen(name)+ 1];
		strcpy(this->name, name);
		return true;
	}

}

bool Hospital::addDoctor(Doctor& D)
{

	if(maxNumOfDoctors == numOfDoctors)
	{
		maxNumOfDoctors *= 2;
		Doctor** temp = new Doctor * [maxNumOfDoctors];

		for (int i = 0; i < numOfDoctors; i++)
		{
			temp[i] = doctors[i];
		}

		delete[] doctors;
		doctors = temp;
	}

	doctors[numOfDoctors] = new Doctor(D); 
	numOfDoctors++;
	return true;
}

bool Hospital::addNurse(Nurse& N)
{
	
	if (maxNumOfNurses == numOfNurses)
	{
		maxNumOfNurses *= 2;
		Nurse** temp = new Nurse * [maxNumOfNurses]; // reallocting new nurses array  

		for (int i = 0; i < numOfNurses; i++)
		{
			temp[i] = nurses[i];
		}

		delete[] nurses; 
		nurses = temp;
	}

	nurses[numOfNurses] = new Nurse(N);
	numOfNurses++;
	return true;
}

bool Hospital::addDepartmant(const char* name)
{
	if (!name)
		return false;

	if (maxNumOfDepartments == numOfDepartments)
	{
		maxNumOfDoctors *= 2;
		Department** temp = new Department * [maxNumOfDepartments];

		for (int i = 0; i < numOfDepartments; i++)
		{
			temp[i] = departments[i];
		}

		delete[] departments;
		departments = temp;
	}

	departments[numOfDepartments] = new Department(name);
	numOfDepartments++;
	return true;
}

Department* Hospital::getDepartment(const char* name) const
{
	if (!name || numOfDepartments == 0) 
	{
		return nullptr; // Return nullptr if name is invalid or no departments exist
	}

	for (int i = 0; i < numOfDepartments; ++i) 
	{
		if (strcmp(departments[i]->getName(), name) == 0) {
			return departments[i]; // Return pointer to the department if names match
		}
	}

	return nullptr; // Return nullptr if no matching department is found
}

Doctor* Hospital::getDoctor(const char* name) const
{
	if (!name || numOfDoctors == 0) 
	{
		return nullptr; // Return nullptr if name is invalid or no doctors exist
	}

	for (int i = 0; i < numOfDoctors; ++i) 
	{
		if (strcmp(doctors[i]->getName(), name) == 0) 
		{
			return doctors[i]; // Return pointer to the doctor if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

Nurse* Hospital::getNurse(const char* name) const
{
	if (!name || numOfNurses == 0)
	{
		return nullptr; // Return nullptr if name is invalid or no nurses exist
	}

	for (int i = 0; i < numOfNurses; ++i)
	{
		if (strcmp(nurses[i]->getName(), name) == 0)
		{
			return nurses[i]; // Return pointer to the nurse if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

ostream& operator<<(ostream& os, const Hospital& h)
{
	os << "{name: " << h.name << ", ";
	os << "number of doctors: " << h.numOfDoctors << ", ";
	os << "number of nurses: " << h.numOfNurses << ", ";
	os << "number of departments: " << h.numOfDepartments << ", ";
	os << "doctors capacity: " << h.maxNumOfDoctors << ", ";
	os << "nurses capacity: " << h.maxNumOfNurses << ", ";
	os << "departments capacity: " << h.maxNumOfDepartments << "}" << endl;

	os << "\ndepartments: " << "\n" << endl; //showing departments in hospital
	for (int i = 0; i < h.numOfDoctors; i++)
	{
		os << "department " << i + 1 << ": ";
		os << *h.departments[i];
		os << "\n";
	}

	return os;
} 

bool Hospital::operator()(const char* name)
{
	if (!name)
		return false;

	if (strcmp(name, "name") == 0)
	{
		cout << this->getName();
		return true;
	}
		
	if (strcmp(name, "doctors") == 0)
	{
		this->showDoctors();
		return true;
	}
		
	if (strcmp(name, "departments") == 0)
	{
		this->showDepartments();
		return true;
	}
		
	if (strcmp(name, "nurses") == 0)
	{
		this->showNurses();
		return true;
	}
		
	return false;
}

void Hospital::showAll() const
{
	cout << "{name: " << name << ", ";
	cout << "number of doctors: " << numOfDoctors << ", ";
	cout << "number of nurses: " << numOfNurses << ", ";
	cout << "number of departments: " << numOfDepartments << ", ";
	cout << "doctors capacity: " << maxNumOfDoctors << ", ";
	cout << "nurses capacity: " << maxNumOfNurses << ", ";
	cout << "departments capacity: " << maxNumOfDepartments << "}" << endl;

	cout << "\ndepartments: " << "\n" << endl; //showing departments in hospital
	for (int i = 0; i < numOfDoctors; i++)
	{
		cout << "department " << i + 1 << ": ";
		cout << *departments[i];
		cout << "\n";
	}
}

void Hospital::showDepartments() const
{
	cout << "departments: " << "\n" << endl; //showing departments in hospital
	cout << "{";
	for (int i = 0; i < numOfDepartments; i++)
	{
		cout << departments[i]->getName();
		
		if (i < numOfDepartments - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

void Hospital::showDoctors() const
{
	cout << "doctors: " << "\n" << endl; //showing doctors in hospital
	cout << "{";
	for (int i = 0; i < numOfDoctors; i++)
	{
		cout << doctors[i]->getName();

		if(i < numOfDoctors - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

void Hospital::showNurses() const
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