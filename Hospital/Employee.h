#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
protected:

    int employeeNumber; 

public:

    Employee(const Person& e);
    Employee(const Employee& other): Person(other) { *this = other; } // going to the copy c'tor of the base first
    ~Employee() { cout << "fire employee" << endl; } // console out for debugging

    const int getEmployeeNumber() const { return employeeNumber; }

    friend ostream& operator<<(ostream& os, const Employee& e);

    const Employee& operator=(const Employee& other);

    
};

#endif // __EMPLOYEE_H

