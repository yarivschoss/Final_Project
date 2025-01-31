#ifndef __CHECKUP_VISIT_H
#define __CHECKUP_VISIT_H

#include "Visit.h"
#include "Employee.h"  

class CheckupVisit : public Visit 
{
public:
    CheckupVisit(Patient* patient, const char* purpose, Department* department, Employee* staff, time_t visitDate);

    void show() const override;
    const char* getVisitType() const override;

    time_t getVisitDate() const override
    {
        return visitDate;
    }


private:
    time_t visitDate; 

};


#endif // __CHECKUP_VISIT_H

