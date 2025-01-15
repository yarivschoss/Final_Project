#pragma warning(disable: 4996)
#include "Person.h"
#include <string.h>

int Person::counter = 0;

Person::Person(const char* name, int birthYear, char gender) 
{
    setName(name);  // Initialize the name using the setName method
    setBirthYear(birthYear);
    setGender(gender);
}

Person::~Person()
{
    delete[] name;  // Free the allocated memory for the name
    cout << "end person" << endl;
}

bool Person::setName(const char* name)
{
    if (!name) return false;  // Check if the provided name is valid

    delete[] this->name;  // Free previously allocated memory
    this->name = new char[strlen(name) + 1];  // Allocate new memory for the name
    strcpy(this->name, name);  // Copy the name
    return true;
}

bool Person::setBirthYear(int birthYear)
{
    this->birthYear = birthYear;
    return true;
}

bool Person::setGender(char gender)
{
    this->gender = gender;
    return true;
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << "name: " << p.name << ", birth Year: " << p.birthYear << ", gender: " << p.gender;  // Print the name of the person
    return os;
}

const Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        setName(other.name); // sending the name of the R-Value
        setBirthYear (other.birthYear);
        setGender(other.gender);
        return *this;
    }
}

//bool Nurse::operator()(const char* name)
//{
//	if (!name)
//		return false;
//
//	if (strcmp(name, "name") == 0)
//	{
//		cout << name;
//		return true;
//	}
//
//	if (strcmp(name, "id") == 0)
//	{
//		cout << id;
//		return true;
//	}
//
//	if (strcmp(name, "experience") == 0)
//	{
//		cout << experience << " years";
//		return true;
//	}
//
//	if (strcmp(name, "department") == 0)
//	{
//		cout << department->getName();
//		return true;
//	}
//
//	return false;
//}
