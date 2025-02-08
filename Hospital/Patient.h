#ifndef __PATIENT_H
#define __PATIENT_H

#include "Person.h"

class Patient : public Person
{

public:

    //friend class Department;

private:
    int id;         

   // unable to use default c'tor as private member due to C2248 error (visual studio/C++ bug)
   // Patient(const Patient& other) : Person(other)  { *this = other; } 
    

public:
    Patient(const Person& p) : Person(p) { id = 100000000 + counter++; }
    virtual ~Patient() { ; } // consule out for debugging

    
    int getId() const { return id; }
 
    friend ostream& operator<<(ostream& os, const Patient& p);

    friend class Hospital;
};

#endif // __PATIENT_H

