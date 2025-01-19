#pragma warning(disable: 4996)
using namespace std;
#include <iostream>

#include "Paper.h"

int const MAX_STRING_SIZE = 100;

Paper::Paper(const char* name, const char* magazineName, time_t publishDate) : name(nullptr), magazineName(nullptr), 
publishDate(publishDate)
{
    setName(name);
    setMagazineName(magazineName);
}

Paper::~Paper()
{
    delete[] name;  // Free the allocated memory for the name
    delete[] magazineName;  // Free the allocated memory for the magazine name
    cout << "burning paper" << endl;
}

bool Paper::setName(const char* name)
{
    if (!name) return false;  // Check if the provided name is valid

    delete[] this->name;  // Free previously allocated memory
    this->name = new char[strlen(name) + 1];  // Allocate new memory for the name
    strcpy(this->name, name);  // Copy the name
    return true;
}

bool Paper::setMagazineName(const char* name)
{
    if (!name) return false;  // Check if the provided name is valid

    delete[] this->magazineName;  // Free previously allocated memory
    this->magazineName = new char[strlen(name) + 1];  // Allocate new memory for the name
    strcpy(this->magazineName, name);  // Copy the name
    return true;
}

ostream& operator<<(ostream& os, const Paper& p)
{
    os << "name: " << p.name << ", magazine name: " << p.magazineName << ", publish date: " << ctime(&p.publishDate);  
    return os;
}

istream& operator>>(istream& in, Paper& p)
{
    char name[MAX_STRING_SIZE];

    cout << "Enter paper name: ";
    in.getline(name, MAX_STRING_SIZE);
    p.setName(name);

    cout << "Enter published magazine name: ";
    in.getline(name, MAX_STRING_SIZE);
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

const Paper& Paper::operator=(const Paper& other)
{
    if (this != &other)
    {
        setName(other.name); // sending the name of the R-Value
        setMagazineName(other.magazineName);
        publishDate = other.publishDate;
        return *this;
    }
}