#include "Employee.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)


Employee::Employee(const Person& e) : Person(e.getName(), e.getBirthYear(), e.getGender()) 
//need to make sure if 2 c'tor for person are being created instead of 1 ***************
{
    employeeNumber = 100000000 + counter++;
}

const Employee& Employee::operator=(const Employee& other)
{
    if (this != &other)
    {
        Person::operator=(other); // using the operator= of person 
        employeeNumber = other.employeeNumber;
        return *this;
    }
}

ostream& operator<<(ostream& os, const Employee& e)
{
    os << (const Person&)e << ", "; // using the person's operator<< by casting 'e' to 'const Person&'
    os << "employee number: " << e.getEmployeeNumber();
    return os;
}
