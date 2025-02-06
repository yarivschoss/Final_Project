#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <string>

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

	string name;
	ResearchCenter researchCenter; // need to update initillization values

	vector<Employee*> employees;
	vector<Department*> departments;
	vector<Patient*> patients;
	vector<Visit*> visits;

	Hospital(const Hospital& other) = delete; // coping a hospital is not allowed 
	void operator=(const Hospital& other) = delete; // coping a hospital is not allowed

public:

	Hospital(const string& name, const string& rcName) : researchCenter(rcName)
	{
		setName(name);
	}
	~Hospital()
	{
		vector<Employee*>::iterator employeeitr = employees.begin();
		vector<Employee*>::iterator employeeitrEnd = employees.end();
		for (; employeeitr != employeeitrEnd; ++employeeitr) // fire employees
			delete* employeeitr;

		vector<Department*>::iterator departmentitr = departments.begin();
		vector<Department*>::iterator departmentitrEnd = departments.end();
		for (; departmentitr != departmentitrEnd; ++departmentitr) // destroy departments
			delete* departmentitr;

		vector<Patient*>::iterator patientsitr = patients.begin();
		vector<Patient*>::iterator patientsitrEnd = patients.end();
		for (; patientsitr != patientsitrEnd; ++patientsitr) // Release Patients
			delete* patientsitr;

		vector<Visit*>::iterator visitsitr = visits.begin();
		vector<Visit*>::iterator visitsitrEnd = visits.end();
		for (; visitsitr != visitsitrEnd; ++visitsitr) // End Visits
			delete* visitsitr;

		cout << "Destroy Hospital" << endl;
	}
	
	friend ostream& operator<<(ostream& os, const Hospital& h)
	{
		os << "{name: " << h.name << ", ";
		os << "number of employees: " << h.employees.size() << ", ";
		os << "number of departments: " << h.departments.size() << ", ";
		os << "employees capacity: " << h.employees.capacity() << ", ";
		os << "departments capacity: " << h.departments.capacity() << "}" << endl;
		os << "Research Center: " << endl;
		os << "{" << h.researchCenter << "}" << endl;

		vector<Department*>::const_iterator itr = h.departments.begin();
		vector<Department*>::const_iterator itrEnd = h.departments.end();

		os << "\ndepartments: " << "\n" << endl; //showing departments in hospital
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			os << "department " << i << ": ";
			os << *itr;
			os << "\n";
		}

		return os;
	}
	friend istream& operator>>(istream& in, Hospital& h)
	{
		string name;

		cout << "Enter Hospital name: ";
		in >> name;
		h.setName(name);

		in >> h.researchCenter;

		return in;
	}

	bool operator()(const string& name) // prints data according to name
	{

		if (strcmp(name.c_str(), "name") == 0)
		{
			cout << this->getName();
			return true;
		}

		if (strcmp(name.c_str(), "doctors") == 0)
		{
			this->showDoctors();
			return true;
		}

		if (strcmp(name.c_str(), "surgeons") == 0)
		{
			this->showSurgeons();
			return true;
		}

		if (strcmp(name.c_str(), "departments") == 0)
		{
			this->showDepartments();
			return true;
		}

		if (strcmp(name.c_str(), "nurses") == 0)
		{
			this->showNurses();
			return true;
		}

		return false;
	}
	//Department* operator[](const char* name) { return getDepartment(name); } // replaces getDepartment - NOT WORKING NEED TO FIND FIX

	operator int const() const { return DEFAULT_STAFF_SIZE; } // returns size of hospital staff
	operator const string () const { return getName(); } // returns name of hospital

	const Hospital& operator+=(Employee& other)
	{
		this->addEmployee(other);
		return *this;
	}

	bool setName(const string& name)
	{
		this->name = name;
		return true;
	}

	const string& getName() const { return name; }

	const Department* getDepartment(const string& name) const
	{
		if (departments.size() == 0)
		{
			return nullptr; // Return nullptr if name is invalid or no departments exist
		}

		vector<Department*>::const_iterator itr = departments.begin();
		vector<Department*>::const_iterator itrEnd = departments.end();

		for (; itr != itrEnd; ++itr)
		{
			if (strcmp((*itr)->getName().c_str(), name.c_str()) == 0)
				return *itr; // Return pointer to the department if names match
		}

		return nullptr; // Return nullptr if no matching department is found
	}
	Department* getDepartment(const string& name)
	{
		if (departments.size() == 0)
		{
			return nullptr; // Return nullptr if name is invalid or no departments exist
		}

		vector<Department*>::iterator itr = departments.begin();
		vector<Department*>::iterator itrEnd = departments.end();

		for (; itr != itrEnd; ++itr)
		{
			if (strcmp((*itr)->getName().c_str(), name.c_str()) == 0)
				return *itr; // Return pointer to the department if names match
		}

		return nullptr; // Return nullptr if no matching department is found
	}

	ResearchCenter& getResearchCenter() { return researchCenter; }

	const Employee* getEmployee(const string& name) const
	{
		if (employees.size() == 0)
		{
			return nullptr; // Return nullptr if name is invalid or no employees exist
		}

		vector<Employee*>::const_iterator itr = employees.begin();
		vector<Employee*>::const_iterator itrEnd = employees.end();

		for (; itr != itrEnd; ++itr)
		{
			if (strcmp((*itr)->getName().c_str(), name.c_str()) == 0)
			{
				return *itr; // Return pointer to the doctor if names match
			}
		}

		return nullptr; // Return nullptr if no matching doctor is found
	}
	Employee* getEmployee(const string& name)
	{
		if (employees.size() == 0)
		{
			return nullptr; // Return nullptr if name is invalid or no employees exist
		}

		vector<Employee*>::iterator itr = employees.begin();
		vector<Employee*>::iterator itrEnd = employees.end();

		for (; itr != itrEnd; ++itr)
		{
			if (strcmp((*itr)->getName().c_str(), name.c_str()) == 0)
			{
				return *itr; // Return pointer to the doctor if names match
			}
		}

		return nullptr; // Return nullptr if no matching doctor is found
	}


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
	bool addDepartmant(const string& name)
	{
		Department* D = new Department(name);
		departments.push_back(D);
		return true;
	}
	
	// Functions to add patients and visits
	bool addVisit (int patientID, const char* purpose, const char* departmentName, const char* staffName,
		time_t visitDate, bool isSurgery, int room = 0, bool fasting = false);
	const Patient* addPatient(const Patient& pateint); // Add Patient
	//Patient* getLastAddedPatient() const;

	Patient* findPatientById(int id); // Find Patient by ID

	bool showPatientsInDepartment(const char* departmentName) const;

	void showDepartments() const
	{
		vector<Department*>::const_iterator itr = departments.begin();
		vector<Department*>::const_iterator itrEnd = departments.end();
		int size = departments.size();

		cout << "departments: " << "\n" << endl; //showing departments in hospital
		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			cout << (*itr)->getName();

			if (i < size)
				cout << ", ";
		}
		cout << "}" << endl;
	}
	void showSurgeons() const
	{
		vector<Employee*>::const_iterator itr = employees.begin();
		vector<Employee*>::const_iterator itrEnd = employees.end();
		int size = employees.size();

		cout << "surgeons: " << "\n" << endl; //showing surgeons in hospital
		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(*itr) == typeid(Surgeon))
			{
				cout << (*itr)->getName();

				if (i < size)
					cout << ", ";
			}
		}
		cout << "}" << endl;
	}
	void showDoctors() const
	{
		vector<Employee*>::const_iterator itr = employees.begin();
		vector<Employee*>::const_iterator itrEnd = employees.end();
		int size = employees.size();

		cout << "doctors: " << "\n" << endl; //showing doctors in hospital
		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(*itr) == typeid(Doctor) || typeid(*itr) == typeid(ResearcherDoctor) || typeid(*itr) == typeid(Surgeon))
			{
				cout << (*itr)->getName();

				if (i < size)
					cout << ", ";
			}
		}
		cout << "}" << endl;
	}
	void showNurses() const
	{
		vector<Employee*>::const_iterator itr = employees.begin();
		vector<Employee*>::const_iterator itrEnd = employees.end();
		int size = employees.size();

		cout << "nurses: " << "\n" << endl; //showing nurses in hospital
		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, i++)
		{
			if (typeid(*itr) == typeid(Nurse))
			{
				cout << (*itr)->getName();

				if (i < size)
					cout << ", ";
			}
		}
		cout << "}" << endl;
	}
};



#endif //__HOSPITAL_H
