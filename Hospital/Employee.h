#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Person.h"

class Employee : public Person
{
protected:

    int employeeNumber; 
    Employee(const Employee& other) = default;

public:

    Employee(const Person& e) : Person(e) { employeeNumber = 100000000 + counter++; }
   
    virtual ~Employee() { cout << "fire employee" << endl; } // console out for debugging

    const int getEmployeeNumber() const { return employeeNumber; }

    virtual Employee* clone() const { return nullptr; } // might need to move to Person

    friend ostream& operator<<(ostream& os, const Employee& e);

};

#endif // __EMPLOYEE_H

