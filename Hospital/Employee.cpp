#include "Employee.h"
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)

ostream& operator<<(ostream& os, const Employee& e)
{
    os << (const Person&)e << ", "; // using the person's operator<< by casting 'e' to 'const Person&'
    os << "employee number: " << e.getEmployeeNumber();
    if (typeid(e) != typeid(Employee)) cout << ", ";
    e.toOs(os);
    return os;
}

