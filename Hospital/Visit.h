#ifndef __VISIT_H
#define __VISIT_H

#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Department.h"
#include <ctime>

class Visit
{
private:
    Patient* patient;        // Pointer to the patient
    time_t visitDate;        // Visit date
    char* purpose;           // Purpose of the visit
    Department* department;  // Pointer to the department
    Employee* staff;         // Pointer to the staff member (Doctor or Nurse)

public:
    // Constructor
    Visit(Patient* patient, const char* purpose, Department* department, Employee* staff, time_t visitDate );

    // Destructor
    ~Visit();

    // Setters
    void setVisitDate(time_t date);
    void setPurpose(const char* purpose);
    void setDepartment(Department* department);
    void setStaff(Employee* staff);

    // Getters
    time_t getVisitDate() const;
    const char* getPurpose() const;
    Department* getDepartmentForPatient(const Patient* patient) const;
    Employee* getStaff() const;
    Patient* getPatient() const;

    // Specific getter for department assigned to a patient
    

    // Display function
    void show() const;


    // Overloaded operator for output
    friend ostream& operator<<(ostream& os, const Visit& v);
};

#endif // __VISIT_H
