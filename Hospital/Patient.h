#ifndef __PATIENT_H
#define __PATIENT_H

#include "Person.h"

class Patient : public Person
{

public:
    friend class Hospital;

private:
    int id;         

    Patient(const Patient& other) : Person(other)  { *this = other; } 
    

public:
    Patient(const Person& p) : Person(p) { id = 100000000 + counter++; }
    virtual ~Patient() { cout << "end patient" << endl; } // consule out for debugging

    
    int getId() const { return id; }
 
    friend ostream& operator<<(ostream& os, const Patient& p);
};

#endif // __PATIENT_H

