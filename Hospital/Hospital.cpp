#include <iostream>
#include <cstring>
#include <ctime>
#pragma warning(disable: 4996)
using namespace std;

#include "Hospital.h"
#include "Visit.h"

int const MAX_STRING_SIZE = 100;

const Patient* Hospital::addPatient(const Patient& patient)
{
	patients.push_back(patient);
	return &(*(--patients.end()));

}




bool Hospital::addVisit(int patientID, const string& purpose, const string& departmentName,
	const string& staffName, time_t visitDate, bool isSurgery, int room, bool fasting)
{

	Patient* patient = findPatientById(patientID);
	if (!patient) {
		cout << "Error: Patient with ID " << patientID << " not found!" << endl;
		return false;
	}

	Department* department = getDepartment(departmentName);
	if (!department) {
		cout << "Error: Department '" << departmentName << "' not found!" << endl;
		return false;
	}

	
	Employee* staff = getEmployee(staffName);
	if (!staff) {
		cout << "Error: Staff member '" << staffName << "' not found!" << endl;
		return false;
	}


	Visit* visit = nullptr;
	if (isSurgery) {
		visit = new SurgeryVisit(patient, purpose, department, staff, visitDate, room, fasting);
	}
	else {
		visit = new CheckupVisit(patient, purpose, department, staff, visitDate);
	}

	
	if (!visit || visit->getDepartmentForPatient(patient) != department) {
		cout << "Error: Visit department mismatch!" << endl;
		delete visit;
		return false;
	}

	
	visits.push_back(visit);
	cout << "Visit added successfully for department " << department->getName() << endl;
	return true;
}



Visit* Hospital::getVisitByPatientId(int patientID) const 
{
	// Loop through all visits
	for (int i = 0; i < visits.size(); ++i) 
	{
		// Check if the patient ID matches
		if (visits[i] && visits[i]->getPatient()->getId() == patientID) 
		{
			return visits[i]; // Return the visit if found
		}
	}
	return nullptr; // Return nullptr if no visit found
}

Patient* Hospital::findPatientById(int id)
{
	vector<Patient>::iterator itr = patients.begin();
	vector<Patient>::iterator itrEnd = patients.end();

	for (; itr != itrEnd; ++itr) 
	{
		if ((*itr).getId() == id)
		{
			return &(*itr);
		}
	}
	return nullptr;
}



bool Hospital::showPatientsInDepartment(const string& departmentName) const
{
    vector<Visit*>::const_iterator itr = visits.begin();
    vector<Visit*>::const_iterator itrEnd = visits.end();

    
    const Department* department = getDepartment(departmentName);
    if (!department)
        return false;

    cout << "Patients in department: " << departmentName << endl;

    
    for (; itr != itrEnd; ++itr)
    {
        if (*itr && (*itr)->getDepartmentForPatient((*itr)->getPatient()) == department)
        {
            Patient* patient = (*itr)->getPatient();
            if (patient)
            {
                
                int month = (*itr)->getVisitMonth();
                int day = (*itr)->getVisitDay();

               
                struct tm timeStruct = {};
                timeStruct.tm_year = 2025 - 1900;  
                timeStruct.tm_mon = month - 1;     
                timeStruct.tm_mday = day;          

                
                time_t visitDate = mktime(&timeStruct);
                if (visitDate == -1)
                {
                    cout << "  Error: Invalid visit date!" << endl;
                    continue;
                }

               
                cout << "- Name: " << patient->getName()
                    << " | ID: " << patient->getId()
                    << " | Birth Year: " << patient->getBirthYear()
                    << " | Gender: " << (patient->getGender() == 'M' ? "Male" : "Female")
                    << endl;

                cout << "  Purpose: " << (*itr)->getPurpose();

                
                if (typeid(**itr) == typeid(SurgeryVisit))
                    cout << " | Visit Type: Surgery";
                else if (typeid(**itr) == typeid(CheckupVisit))
                    cout << " | Visit Type: Checkup";

               
                cout << " | Visit Date: "
                    << timeStruct.tm_mday << "/"
                    << (timeStruct.tm_mon + 1) << "/"
                    << "2025"; 

               
                cout << " | Staff Member: " << (*itr)->getStaff()->getName() << endl;

                
                SurgeryVisit* surgeryVisit = dynamic_cast<SurgeryVisit*>(*itr);
                if (surgeryVisit)
                {
                    cout << "  Surgery Room: " << surgeryVisit->getSurgeryRoomNumber() << endl;
                    cout << "  Is the patient fasting? " << (surgeryVisit->getIsFasting() ? "Yes" : "No") << endl;
                }

                cout << "------------------------------------------------" << endl;
            }
        }
    }

    return true;
}














	







