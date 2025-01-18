#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#pragma warning(disable: 4996)
#include <iostream>

#include "ResearchCenter.h"
#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Visit.h"


class Hospital 
{

public: 

	int const DEFAULT_NUM_OF_DEPARTMENTS = 7; // Default number of departments
	int const DEFAULT_STAFF_SIZE = DEFAULT_NUM_OF_DEPARTMENTS * 20; // Default size of hospital 
	int numOfPatients, numOfVisits;

private:

	char* name;
	int numOfDoctors, numOfNurses, numOfDepartments;
	int maxNumOfDoctors, maxNumOfNurses, maxNumOfDepartments, maxNumOfPatients, maxNumOfVisits;

	ResearchCenter researchCenter; // need to update initillization values

	Doctor** doctors = nullptr;
	Nurse** nurses = nullptr;
	Department** departments = nullptr;
	Patient** patients;
	Visit** visits;

	Hospital(const Hospital& other) = delete; // coping a hospital is not allowed 
	void operator=(const Hospital& other) = delete; // coping a hospital is not allowed

public:

	Hospital(const char* name, ResearchCenter r);
	~Hospital();
	
	friend ostream& operator<<(ostream& os, const Hospital& h);
	friend istream& operator>>(istream& in, Hospital& h);

	bool operator()(const char* name); // prints data according to name
	//Department* operator[](const char* name) { return getDepartment(name); } // replaces getDepartment - NOT WORKING NEED TO FIND FIX

	operator int const() const { return DEFAULT_STAFF_SIZE; } // returns size of hospital staff
	operator const char* () const { return getName(); } // returns name of hospital

	const Hospital& operator+=(Doctor& other)
	{
		this->addDoctor(other);
		return *this;
	}
	const Hospital& operator+=(Nurse& other)
	{
		this->addNurse(other);
		return *this;
	}

	bool setName(const char* name);

	const char* getName() const { return name; }
	Department* getDepartment(const char* name) const; //searches through the array of departments and returns a pointer to the department with the specified name
	ResearchCenter& getResearchCenter() { return researchCenter; }
	Doctor* getDoctor(const char* name) const; //searches through the array of doctors and returns a pointer to the doctor with the specified name
	Nurse* getNurse(const char* name) const; //searches through the array of nurses and returns a pointer to the nurse with the specified name
	Visit* getVisitByPatientId(int patientID) const;
	int getNumOfPatients() const { return numOfPatients; }
	Patient* getPatient(int index) const;
	Department* getDepartmentForPatient(const char* name) const; // Get Department by name
	Employee* getStaff(const char* name) const; // Get Staff by name


	bool addDoctor(Doctor& doctor);
	bool addNurse(Nurse& nurse);
	bool addDepartmant(const char* name);
	
	// Functions to add patients and visits
	bool addVisit(int patientID, const char* purpose, const char* departmentName, const char* staffName, time_t visitDate);
	int addPatient(const Person& person); // Add Patient

	Patient* findPatientById(int id); // Find Patient by ID


	bool showPatientsInDepartment(const char* departmentName) const;

	void showAll() const;
	void showDepartments() const;
	void showDoctors() const;
	void showNurses() const;
};



#endif //__HOSPITAL_H
