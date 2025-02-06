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
	if (maxNumOfPatients == numOfPatients)
	{
		maxNumOfPatients *= 2;
		Patient** temp = new Patient * [maxNumOfPatients];

		for (int i = 0; i < numOfPatients; i++)
		{
			temp[i] = patients[i];
		}

		delete[] patients;
		patients = temp;
	}

	patients[numOfPatients] = new Patient(patient);
	numOfPatients++;
	return patients[numOfPatients-1];
}

bool Hospital::addVisit(int patientID, const char* purpose, const char* departmentName,
	const char* staffName, time_t visitDate, bool isSurgery, int room, bool fasting)
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

	if (maxNumOfVisits == numOfVisits)
	{
		maxNumOfVisits *= 2;
		Visit** temp = new Visit * [maxNumOfVisits];

		for (int i = 0; i < numOfVisits; i++)
		{
			temp[i] = visits[i];
		}

		delete[] visits;
		visits = temp;
	}

	

	// Handling Surgery Visit
	if (isSurgery)
	{
		// Ensure the staff is a Surgeon
		if (typeid(*staff) != typeid(Surgeon))
		{
			cout << "Error: Surgery visit must have a Surgeon as staff member." << endl;
			return false;
		}
		/*
		else
		{

			if (typeid(*staff) == typeid(Surgeon))                //cancel because we want the surgeon can make check
			{
				cout << "Error: Checkup visit cannot have a Surgeon as staff member." << endl;
				return false;
			}
			*/


		// Create Surgery Visit
		visits[numOfVisits] = new SurgeryVisit(patient, purpose, department, staff, visitDate, room, fasting);
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
		visits[numOfVisits] = new CheckupVisit(patient, purpose, department, staff, visitDate);
	}

	// Increase the number of visits
	numOfVisits++;
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
	for (int i = 0; i < numOfPatients; i++) 
	{
		if (patients[i]->getId() == id) 
		{
			return patients[i];
		}
	}
	return nullptr;
}

Department* Hospital::getDepartmentForPatient(const char* name) const
{
	for (int i = 0; i < numOfDepartments; i++) 
	{
		if (strcmp(departments[i]->getName().c_str(), name) == 0)
		{
			return departments[i];
		}
	}
	return nullptr;
}

Employee* Hospital::getStaff(const char* name) const
{
	for (int i = 0; i < numOfEmployees; i++) 
	{
		if (strcmp(employees[i]->getName().c_str(), name) == 0)
		{
			return employees[i];
		}
	}

	return nullptr;
}

Patient* Hospital::getPatient(int index) const
{
	if (index < 0 || index >= numOfPatients) 
	{
		return nullptr; // Return nullptr if the index is out of bounds
	}
	return patients[index];
}
 
bool Hospital::showPatientsInDepartment(const char* departmentName) const
{
	if (!departmentName)
		return false;

	// Find the department by name
	const Department* department = getDepartment(departmentName);
	if (!department)
		return false;

	cout << "Patients in department: " << departmentName << endl;

	// Loop through visits to find patients associated with the department
	for (int i = 0; i < visits.size(); i++)
	{
		if (visits[i] && visits[i]->getDepartmentForPatient(visits[i]->getPatient()) == department)
		{
			Patient* patient = visits[i]->getPatient(); // Retrieve the patient from the visit

			if (patient)
			{
				// Get visit date
				int month = visits[i]->getVisitMonth(); 
				int day = visits[i]->getVisitDay();

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
					<< ", purpose: " << visits[i]->getPurpose(); // Display purpose of the visit

				// Determine if it's a checkup or surgery visit
				if (typeid(*visits[i]) == typeid(SurgeryVisit)) {
					cout << ", visit type: Surgery";  // Surgery visit
				}
				else if (typeid(*visits[i]) == typeid(CheckupVisit)) {
					cout << ", visit type: Checkup";  // Checkup visit
				}

				// Convert the visit date into a readable format using ctime
				struct tm* timeInfo = localtime(&visitDate);
				cout << ", date of visit: "
					<< timeInfo->tm_mday << "/"  
					<< (timeInfo->tm_mon + 1) << "/"  
					<< (timeInfo->tm_year + 1900)  
					<< ", staff member allocated: " << visits[i]->getStaff()->getName()
					<< ")" << endl;

				// If it's a surgery visit, display additional info
				if (typeid(*visits[i]) == typeid(SurgeryVisit)) {
					SurgeryVisit* surgeryVisit = dynamic_cast<SurgeryVisit*>(visits[i]);
					cout << "Surgery Room: " << surgeryVisit->getSurgeryRoomNumber() << endl;
					cout << "Is the patient fasting? " << (surgeryVisit->getIsFasting() ? "Yes" : "No") << endl;
				}
			}
		}
	}

	return true;
}



	







