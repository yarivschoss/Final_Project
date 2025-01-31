#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#pragma warning(disable: 4996)
#include <iostream>

#include "ResearchCenter.h"
#include "Department.h"
#include "Surgeon.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Visit.h"
#include "CheckupVisit.h"
#include "SurgeryVisit.h"


class Hospital 
{

public: 

	int const DEFAULT_NUM_OF_DEPARTMENTS = 7; // Default number of departments
	int const DEFAULT_STAFF_SIZE = DEFAULT_NUM_OF_DEPARTMENTS * 20; // Default size of hospital 
	

private:

	char* name;
	int numOfPatients, numOfVisits;
	int maxNumOfPatients, maxNumOfVisits;
	ResearchCenter researchCenter; // need to update initillization values

	Employee** employees = nullptr;
	int numOfEmployees, maxNumOfEmployees;

	Department** departments = nullptr;
	int numOfDepartments, maxNumOfDepartments;

	Patient** patients;
	Visit** visits;

	Hospital(const Hospital& other) = delete; // coping a hospital is not allowed 
	void operator=(const Hospital& other) = delete; // coping a hospital is not allowed

public:

	Hospital(const char* name, const char * rcName);
	~Hospital();
	
	friend ostream& operator<<(ostream& os, const Hospital& h);
	friend istream& operator>>(istream& in, Hospital& h);

	bool operator()(const char* name); // prints data according to name
	//Department* operator[](const char* name) { return getDepartment(name); } // replaces getDepartment - NOT WORKING NEED TO FIND FIX

	operator int const() const { return DEFAULT_STAFF_SIZE; } // returns size of hospital staff
	operator const char* () const { return getName(); } // returns name of hospital

	const Hospital& operator+=(Employee& other)
	{
		this->addEmployee(other);
		return *this;
	}

	const Hospital& operator+=(ResearcherDoctor& other)
	{
		this->addResearcherDoctor(other);
		return *this;
	}

	bool setName(const char* name);

	const char* getName() const { return name; }

	const Department* getDepartment(const char* name) const; 
	Department* getDepartment(const char* name);

	ResearchCenter& getResearchCenter() { return researchCenter; }

	const Surgeon* getSurgeon(const char* name) const; 
	Surgeon* getSurgeon(const char* name);

	const Doctor* getDoctor(const char* name) const; 
	Doctor* getDoctor(const char* name);

	const Nurse* getNurse(const char* name) const; 
	Nurse* getNurse(const char* name);

	Visit* getVisitByPatientId(int patientID) const;
	int getNumOfPatients() const { return numOfPatients; }
	Patient* getPatient(int index) const;
	Department* getDepartmentForPatient(const char* name) const; // Get Department by name
	Employee* getStaff(const char* name) const; // Get Staff by name


	bool addEmployee(const Employee& e);
	bool addResearcherDoctor(const ResearcherDoctor& RD);
	bool addDepartmant(const char* name);
	
	
	// Functions to add patients and visits
	bool addVisit (int patientID, const char* purpose, const char* departmentName, const char* staffName,
		time_t visitDate, bool isSurgery, int room = 0, bool fasting = false);
	const Patient* addPatient(const Patient& pateint); // Add Patient
	//Patient* getLastAddedPatient() const;

	Patient* findPatientById(int id); // Find Patient by ID

	bool showPatientsInDepartment(const char* departmentName) const;

	void showDepartments() const;
	void showSurgeons() const;
	void showDoctors() const;
	void showNurses() const;
};



#endif //__HOSPITAL_H
