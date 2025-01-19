#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)
using namespace std;

#include "Hospital.h"
#include "Visit.h"

int const MAX_STRING_SIZE = 100;

Hospital::Hospital(const char* name, ResearchCenter r) :
maxNumOfDepartments(DEFAULT_NUM_OF_DEPARTMENTS), maxNumOfDoctors(DEFAULT_STAFF_SIZE), maxNumOfNurses(DEFAULT_STAFF_SIZE), 
maxNumOfPatients(100), maxNumOfVisits(200), numOfPatients(0), numOfVisits(0), researchCenter(r.getName())
{
	setName(name);

	doctors = new Doctor* [maxNumOfDoctors];
	nurses = new Nurse* [maxNumOfNurses];
	departments = new Department* [maxNumOfDepartments];
	patients = new Patient * [maxNumOfPatients];
	visits = new Visit * [maxNumOfVisits];
}

Hospital::~Hospital()
{
	for (int i = 0; i < numOfDoctors; i++) // fire doctors
		delete doctors[i];
	delete[]doctors;

	for (int i = 0; i < numOfNurses; i++) // fire nurses
		delete nurses[i];
	delete[]nurses;

	for (int i = 0; i < numOfDepartments; i++) // destroy departments
		delete departments[i];
	delete[]departments;

	for (int i = 0; i < numOfPatients; i++) // destroy patients
		delete patients[i];
	delete[]patients;

	for (int i = 0; i < numOfVisits; i++) // destroy visits
		delete visits[i];
	delete[]visits;


	delete[]name;
	cout << "Destroy Hospital" << endl;
}

bool Hospital::setName(const char* name)
{
	if (!name) return false;

	else
	{
		delete[]this->name;
		this->name = new char[strlen(name)+ 1];
		strcpy(this->name, name);
		return true;
	}

}

bool Hospital::addDoctor(Doctor& D)
{
	if(maxNumOfDoctors == numOfDoctors)
	{
		maxNumOfDoctors *= 2;
		Doctor** temp = new Doctor * [maxNumOfDoctors];

		for (int i = 0; i < numOfDoctors; i++)
		{
			temp[i] = doctors[i];
		}

		delete[] doctors;
		doctors = temp;
	}

	doctors[numOfDoctors] = new Doctor(D); 
	numOfDoctors++;
	return true;
}

bool Hospital::addNurse(Nurse& N)
{
	
	if (maxNumOfNurses == numOfNurses)
	{
		maxNumOfNurses *= 2;
		Nurse** temp = new Nurse * [maxNumOfNurses]; // reallocting new nurses array  

		for (int i = 0; i < numOfNurses; i++)
		{
			temp[i] = nurses[i];
		}

		delete[] nurses; 
		nurses = temp;
	}

	nurses[numOfNurses] = new Nurse(N);
	numOfNurses++;
	return true;
}

bool Hospital::addDepartmant(const char* name)
{
	if (!name)
		return false;

	if (maxNumOfDepartments == numOfDepartments)
	{
		maxNumOfDoctors *= 2;
		Department** temp = new Department * [maxNumOfDepartments];

		for (int i = 0; i < numOfDepartments; i++)
		{
			temp[i] = departments[i];
		}

		delete[] departments;
		departments = temp;
	}

	departments[numOfDepartments] = new Department(name);
	numOfDepartments++;
	return true;
}

bool Hospital::addPatient(const Person& person)
{
	if (numOfPatients >= maxNumOfPatients) {
		return false; // Hospital is full
	}

	patients[numOfPatients] = new Patient(person); // Create a new Patient object
	numOfPatients++;
	return true; // Indicate success
}

Patient* Hospital::getLastAddedPatient() const 
{
	if (numOfPatients > 0) 
	{
		return patients[numOfPatients - 1];
	}
	return nullptr; // No patients added
}

Department* Hospital::getDepartment(const char* name) const
{
	if (!name || numOfDepartments == 0) 
	{
		return nullptr; // Return nullptr if name is invalid or no departments exist
	}

	for (int i = 0; i < numOfDepartments; ++i) 
	{
		if (strcmp(departments[i]->getName(), name) == 0) {
			return departments[i]; // Return pointer to the department if names match
		}
	}

	return nullptr; // Return nullptr if no matching department is found
}

Doctor* Hospital::getDoctor(const char* name) const
{
	if (!name || numOfDoctors == 0) 
	{
		return nullptr; // Return nullptr if name is invalid or no doctors exist
	}

	for (int i = 0; i < numOfDoctors; ++i) 
	{
		if (strcmp(doctors[i]->getName(), name) == 0) 
		{
			return doctors[i]; // Return pointer to the doctor if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

Nurse* Hospital::getNurse(const char* name) const
{
	if (!name || numOfNurses == 0)
	{
		return nullptr; // Return nullptr if name is invalid or no nurses exist
	}

	for (int i = 0; i < numOfNurses; ++i)
	{
		if (strcmp(nurses[i]->getName(), name) == 0)
		{
			return nurses[i]; // Return pointer to the nurse if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

bool Hospital::addVisit(int patientID, const char* purpose, const char* departmentName, 
	const char* staffName, time_t visitDate) 
{
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
	
	// Find the patient
	Patient* patient = findPatientById(patientID);
	if (!patient) return false;

	// Find the department
	Department* department = getDepartment(departmentName);
	if (!department) return false;

	// Find the staff (doctor or nurse)
	Employee* staff = getDoctor(staffName);

	if (!staff) staff = getNurse(staffName);
	if (!staff) return false;
	
	// Add the visit with the visit date
	visits[numOfVisits] = new Visit(patient, purpose, department, staff, visitDate);
	numOfVisits++;
	return true;
}

Visit* Hospital::getVisitByPatientId(int patientID) const 
{
	// Loop through all visits
	for (int i = 0; i < numOfVisits; ++i) 
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
		if (strcmp(departments[i]->getName(), name) == 0) 
		{
			return departments[i];
		}
	}
	return nullptr;
}

Employee* Hospital::getStaff(const char* name) const
{
	for (int i = 0; i < numOfDoctors; i++) 
	{
		if (strcmp(doctors[i]->getName(), name) == 0) 
		{
			return doctors[i];
		}
	}

	for (int i = 0; i < numOfNurses; i++) {
		if (strcmp(nurses[i]->getName(), name) == 0) {
			return nurses[i];
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

ostream& operator<<(ostream& os, const Hospital& h)
{
	os << "{name: " << h.name << ", ";
	os << "number of doctors: " << h.numOfDoctors << ", ";
	os << "number of nurses: " << h.numOfNurses << ", ";
	os << "number of departments: " << h.numOfDepartments << ", ";
	os << "doctors capacity: " << h.maxNumOfDoctors << ", ";
	os << "nurses capacity: " << h.maxNumOfNurses << ", ";
	os << "departments capacity: " << h.maxNumOfDepartments << "}" << endl;
	os << "Research Center: " << endl;
	os << "{" << h.researchCenter << "}" << endl;

	os << "\ndepartments: " << "\n" << endl; //showing departments in hospital
	for (int i = 0; i < h.numOfDoctors; i++)
	{
		os << "department " << i + 1 << ": ";
		os << *h.departments[i];
		os << "\n";
	}

	return os;
} 

istream& operator>>(istream& in, Hospital& h)
{
	char name[MAX_STRING_SIZE];

	cout << "Enter Hospital name: ";
	in.getline(name, MAX_STRING_SIZE);
	h.setName(name);

	in >> h.researchCenter;

	return in;
}

bool Hospital::operator()(const char* name)
{
	if (!name)
		return false;

	if (strcmp(name, "name") == 0)
	{
		cout << this->getName();
		return true;
	}
		
	if (strcmp(name, "doctors") == 0)
	{
		this->showDoctors();
		return true;
	}
		
	if (strcmp(name, "departments") == 0)
	{
		this->showDepartments();
		return true;
	}
		
	if (strcmp(name, "nurses") == 0)
	{
		this->showNurses();
		return true;
	}
		
	return false;
}

void Hospital::showAll() const
{
	cout << "{name: " << name << ", ";
	cout << "number of doctors: " << numOfDoctors << ", ";
	cout << "number of nurses: " << numOfNurses << ", ";
	cout << "number of departments: " << numOfDepartments << ", ";
	cout << "doctors capacity: " << maxNumOfDoctors << ", ";
	cout << "nurses capacity: " << maxNumOfNurses << ", ";
	cout << "departments capacity: " << maxNumOfDepartments << "}" << endl;

	cout << "\ndepartments: " << "\n" << endl; //showing departments in hospital
	for (int i = 0; i < numOfDoctors; i++)
	{
		cout << "department " << i + 1 << ": ";
		cout << *departments[i];
		cout << "\n";
	}
}

void Hospital::showDepartments() const
{
	cout << "departments: " << "\n" << endl; //showing departments in hospital
	cout << "{";
	for (int i = 0; i < numOfDepartments; i++)
	{
		cout << departments[i]->getName();
		
		if (i < numOfDepartments - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

void Hospital::showDoctors() const
{
	cout << "doctors: " << "\n" << endl; //showing doctors in hospital
	cout << "{";
	for (int i = 0; i < numOfDoctors; i++)
	{
		cout << doctors[i]->getName();

		if(i < numOfDoctors - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

void Hospital::showNurses() const
{
	cout << "nurses: " << "\n" << endl; //showing nurses in hospital
	cout << "{";
	for (int i = 0; i < numOfNurses; i++)
	{
		cout << nurses[i]->getName();
		
		if (i < numOfNurses - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

bool Hospital::showPatientsInDepartment(const char* departmentName) const
{
	if (!departmentName)
		return false;

	// Find the department by name
	Department* department = getDepartment(departmentName);
	if (!department)
		return false;

	cout << "Patients in department: " << departmentName << endl;

	// Loop through visits to find patients associated with the department
	for (int i = 0; i < numOfVisits; i++)
	{
		if (visits[i] && visits[i]->getDepartmentForPatient(visits[i]->getPatient()) == department)
		{
			Patient* patient = visits[i]->getPatient(); // Retrieve the patient from the visit

			if (patient)
			{
				time_t visitDate = visits[i]->getVisitDate(); // 

				cout << "- " << patient->getName()
					<< " (ID: " << patient->getId()
					<< ", purpose: " << visits[i]->getPurpose()
					<< ", date of visit: " << ctime(&visitDate) // 
					<< ", staff member allocated: " << visits[i]->getStaff()->getName()
					<< ")" << endl;

			}
		}
	}
}







