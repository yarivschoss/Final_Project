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
    string purpose;           // Purpose of the visit
    const Department* department;  // Pointer to the department
    Employee* staff;         // Pointer to the staff member (Doctor or Nurse)

public:
    // Constructor
    Visit(Patient* patient, const string& purpose, const Department* department, Employee* staff, time_t visitDate)
        : patient(patient), purpose(purpose), department(department), staff(staff), visitDate(visitDate)
    {
       
    }

    virtual const string& getVisitType() const = 0; // Identifies the visit type
    virtual time_t getVisitDate() const = 0;  


    // Destructor
    virtual ~Visit() { ; }

    // Setters
    bool setVisitDate(time_t date);
    bool setPurpose(const string& purpose);
    bool setDepartment(Department* department);
    bool setStaff(Employee* staff);

    // Getters
     
    const string& getPurpose() const { return purpose; }
    const Department* getDepartmentForPatient(const Patient* patient) const;





    Employee* getStaff() const { return staff;  }
    Patient* getPatient() const { return patient;  }


    int getVisitMonth() const {
        struct tm* timeInfo = localtime(&visitDate);
        return timeInfo->tm_mon + 1; 
    }

    
    int getVisitDay() const {
        struct tm* timeInfo = localtime(&visitDate);
        return timeInfo->tm_mday;  
    }


    // Specific getter for department assigned to a patient
    

    // Display function
    
    virtual void show() const = 0;  // Abstract function to be implemented in derived classes


    // Overloaded operator for output
    friend ostream& operator<<(ostream& os, const Visit& v);
};

#endif // __VISIT_H
