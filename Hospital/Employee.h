#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Person.h"

class Department; // forward declaration that employee will be able to point to department

class Employee : public Person
{
protected:

    int employeeNumber; 
    Employee(const Employee& other) = default;

public:

    Employee(const Person& e) : Person(e) { employeeNumber = 100000000 + counter++; }
   
    virtual ~Employee() { cout << "fire employee" << endl; } // console out for debugging

    const int getEmployeeNumber() const { return employeeNumber; }

    virtual bool setDepartment(Department* department) { return false; } // need to allocate this method in Doctor and Nurse

    virtual Employee* clone() const { return nullptr; } // might need to move to Person

    virtual void toOs(ostream& os) const { ; } // so Doctor and Nurse will be using their operator <<
    friend ostream& operator<<(ostream& os, const Employee& e);

};

#endif // __EMPLOYEE_H

