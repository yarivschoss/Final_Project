#ifndef __VISIT_H
#define __VISIT_H

#include "Patient.h"
#include "Doctor.h"
#include "Department.h"
#include <ctime>

class Visit
{
private:
    Patient* patient;
    time_t visitDate;
    char* purpose;
    Department* department;
    Doctor* doctor;

public:
    Visit(Patient* patient, const char* purpose, Department* department, Doctor* doctor);
    void setVisitDate(time_t date);
    void show() const;
    friend ostream& operator<<(ostream& os, const Visit& v);
};

#endif // __VISIT_H
