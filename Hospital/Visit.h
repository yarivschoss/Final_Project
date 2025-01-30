#ifndef __VISIT_H
#define __VISIT_H

#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Department.h"
#include <ctime>

class Visit
{

protected:
    Patient* patient;        // Pointer to the patient
    time_t visitDate;        // Visit date
    char* purpose;           // Purpose of the visit
    Department* department;  // Pointer to the department
    Employee* staff;         // Pointer to the staff member (Doctor or Nurse)

public:
    // Constructor
    Visit(Patient* patient, const char* purpose, Department* department, Employee* staff, time_t visitDate );
    virtual const char* getVisitType() const = 0; // Identifies the visit type
    virtual time_t getVisitDate() const = 0;  


    // Destructor
    virtual ~Visit();

    // Setters
    bool setVisitDate(time_t date);
    bool setPurpose(const char* purpose);
    bool setDepartment(Department* department);
    bool setStaff(Employee* staff);

    // Getters
     
    const char* getPurpose() const { return purpose; }
    Department* getDepartmentForPatient(const Patient* patient) const 
    {
            if (this->patient == patient)
            {
                return department; // Return the department if the patient matches
            }
            return nullptr; // Return nullptr if no match
        
    }
    Employee* getStaff() const { return staff;  }
    Patient* getPatient() const { return patient;  }

    // Specific getter for department assigned to a patient
    

    // Display function
    
    virtual void show() const = 0;  // Abstract function to be implemented in derived classes


    // Overloaded operator for output
    friend ostream& operator<<(ostream& os, const Visit& v);
};

#endif // __VISIT_H
