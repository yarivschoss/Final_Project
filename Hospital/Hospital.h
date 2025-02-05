#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#pragma warning(disable: 4996)
#include <iostream>
#include <vector>

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
	ResearchCenter researchCenter; // need to update initillization values

	vector<Employee*> employees;
	vector<Department*> departments;
	vector<Patient*> patients;
	vector<Visit*> visits;

	Hospital(const Hospital& other) = delete; // coping a hospital is not allowed 
	void operator=(const Hospital& other) = delete; // coping a hospital is not allowed

public:

	Hospital(const char* name, const char* rcName) : researchCenter(rcName)
	{
		setName(name);
	}
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

	/*const Hospital& operator+=(ResearcherDoctor& other)
	{
		this->addEmployee(other);
		return *this;
	}*/

	bool setName(const char* name);

	const char* getName() const { return name; }

	const Department* getDepartment(const char* name) const; 
	Department* getDepartment(const char* name);

	ResearchCenter& getResearchCenter() { return researchCenter; }

	const Employee* getEmployee(const char* name) const;
	Employee* getEmployee(const char* name);


	Visit* getVisitByPatientId(int patientID) const;
	int getNumOfPatients() const { return patients.size(); }
	Patient* getPatient(int index) const;
	Department* getDepartmentForPatient(const char* name) const; // Get Department by name
	Employee* getStaff(const char* name) const; // Get Staff by name


	bool addEmployee(const Employee& e)
	{
			employees.push_back(e.clone());
			return true;
	}
	bool addDepartmant(const char* name)
	{
		departments.push_back(&Department(name));
		return true;
	}
	
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
