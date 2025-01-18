#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
protected:

    int employeeNumber; 
    Employee(const Employee& other) = default;
    //const Employee& operator=(const Employee& other) = default;

public:

    Employee(const Person& e) : Person(e) { employeeNumber = 100000000 + counter++; }
   
    ~Employee() { cout << "fire employee" << endl; } // console out for debugging

    const int getEmployeeNumber() const { return employeeNumber; }

    friend ostream& operator<<(ostream& os, const Employee& e);

};

#endif // __EMPLOYEE_H

