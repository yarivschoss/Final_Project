#ifndef __SURGERY_VISIT_H
#define __SURGERY_VISIT_H

#include "Visit.h"
#include "Employee.h"  

class SurgeryVisit : public Visit {
private:
    int surgeryRoomNumber;
    bool isFasting;
    time_t visitDate;  

public:
    SurgeryVisit(Patient* patient, const string& purpose, Department* department,
        Employee* staff, time_t visitDate, int room, bool fasting);

    void show() const override;
    virtual const string& getVisitType() const override;

    time_t getVisitDate() const override
    {
        return visitDate;
    }
    int getSurgeryRoomNumber() const;
    bool getIsFasting() const;
};

#endif // __SURGERY_VISIT_H
