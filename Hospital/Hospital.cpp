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
	// Find the patient by ID
	Patient* patient = findPatientById(patientID);
	if (!patient) return false;

	// Find the department by name
	Department* department = getDepartment(departmentName);
	if (!department) return false;

	// Find the staff member (Doctor, Nurse, or Surgeon)
	Employee* staff = getEmployee(staffName);
	if (!staff) return false;

	// Handling Surgery Visit
	if (isSurgery)
	{
		// Ensure the staff is a Surgeon
		if (typeid(*staff) != typeid(Surgeon))
		{
			cout << "Error: Surgery visit must have a Surgeon as staff member." << endl;
			return false;
		}
	
		// Create Surgery Visit
		Visit *sv = new SurgeryVisit(patient, purpose, department, staff, visitDate, room, fasting);
		visits.push_back(sv);
	}
	else
	{
		// Handling Checkup Visit
		// Here we allow Doctor, Nurse, or Surgeon
		if (typeid(*staff) == typeid(Surgeon))
		{
			// Allow Surgeon for a Checkup visit
		}
		// Create Checkup Visit
		Visit* cv = new CheckupVisit(patient, purpose, department, staff, visitDate);
		visits.push_back(cv);
	}

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

	// Find the department by name
	const Department* department = getDepartment(departmentName);
	if (!department)
		return false;

	cout << "Patients in department: " << departmentName << endl;

	// Loop through visits to find patients associated with the department
	for (; itr != itrEnd; ++itr)
	{
		if (*itr && (*itr)->getDepartmentForPatient((*itr)->getPatient()) == department)
		{
			Patient* patient = (*itr)->getPatient(); // Retrieve the patient from the visit

			if (patient)
			{
				// Get visit date
				int month = (*itr)->getVisitMonth();
				int day = (*itr)->getVisitDay();

				struct tm timeStruct = {};
				timeStruct.tm_year = 2025 - 1900;  // Set the year to 2025
				timeStruct.tm_mon = month - 1;     
				timeStruct.tm_mday = day;          
				

				// Convert the date to time_t
				time_t visitDate = mktime(&timeStruct);

				if (visitDate == -1) {
					cout << "Invalid date!" << endl;
					continue;
				}

				// Display patient details and visit purpose
				cout << "- " << patient->getName()
					<< " (ID: " << patient->getId()
					<< ", purpose: " << (*itr)->getPurpose(); // Display purpose of the visit

				// Determine if it's a checkup or surgery visit
				if (typeid(**itr) == typeid(SurgeryVisit)) 
				{
					cout << ", visit type: Surgery";  // Surgery visit
				}
				else if (typeid(**itr) == typeid(CheckupVisit)) 
				{
					cout << ", visit type: Checkup";  // Checkup visit
				}

				// Convert the visit date into a readable format using ctime
				struct tm* timeInfo = localtime(&visitDate);
				cout << ", date of visit: "
					<< timeInfo->tm_mday << "/"  
					<< (timeInfo->tm_mon + 1) << "/"  
					<< (timeInfo->tm_year + 1900)  
					<< ", staff member allocated: " << (*itr)->getStaff()->getName()
					<< ")" << endl;

				// If it's a surgery visit, display additional info
				if (typeid(**itr) == typeid(SurgeryVisit)) 
				{
					SurgeryVisit* surgeryVisit = dynamic_cast<SurgeryVisit*>(*itr);
					cout << "Surgery Room: " << surgeryVisit->getSurgeryRoomNumber() << endl;
					cout << "Is the patient fasting? " << (surgeryVisit->getIsFasting() ? "Yes" : "No") << endl;
				}
			}
		}
	}

	return true;
}



	







