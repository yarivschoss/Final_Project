#include "Employee.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)


Employee::Employee(const Person& e) : Person(e) 
//need to make sure if 2 c'tor for person are being created instead of 1 ***************
{
    employeeNumber = 100000000 + counter++;
}

ostream& operator<<(ostream& os, const Employee& e)
{
    os << (const Person&)e << ", "; // using the person's operator<< by casting 'e' to 'const Person&'
    os << "employee number: " << e.getEmployeeNumber();
    return os;
}
