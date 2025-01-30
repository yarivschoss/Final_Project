#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)
using namespace std;

#include "Hospital.h"
#include "Visit.h"

int const MAX_STRING_SIZE = 100;

Hospital::Hospital(const char* name, ResearchCenter r) :
maxNumOfDepartments(DEFAULT_NUM_OF_DEPARTMENTS), maxNumOfEmployees(DEFAULT_STAFF_SIZE),
maxNumOfPatients(100), maxNumOfVisits(200), numOfPatients(0), numOfVisits(0), researchCenter(r.getName())
{
	setName(name);

	employees = new Employee * [maxNumOfEmployees];
	departments = new Department * [maxNumOfDepartments];
	patients = new Patient * [maxNumOfPatients];
	visits = new Visit * [maxNumOfVisits];
}

Hospital::~Hospital()
{
	for (int i = 0; i < numOfEmployees; i++) // fire employees
		delete employees[i];
	delete[]employees;

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

bool Hospital::addSurgeon(Surgeon& S)
{
	if (maxNumOfEmployees == numOfEmployees)
	{
		maxNumOfEmployees *= 2;
		Employee** temp = new Employee * [maxNumOfEmployees];

		for (int i = 0; i < numOfEmployees; i++)
		{
			temp[i] = employees[i]->clone();
		}

		delete[] employees;
		employees = temp;
	}

	employees[numOfEmployees] = new Surgeon(S);
	numOfEmployees++;
	return true;
}

bool Hospital::addDoctor(Doctor& D)
{
	if(maxNumOfEmployees == numOfEmployees)
	{
		maxNumOfEmployees *= 2;
		Employee** temp = new Employee * [maxNumOfEmployees];

		for (int i = 0; i < numOfEmployees; i++)
		{
			temp[i] = employees[i]->clone();
		}

		delete[] employees;
		employees = temp;
	}

	employees[numOfEmployees] = new Doctor(D);
	numOfEmployees++;
	return true;
}

bool Hospital::addNurse(Nurse& N)
{
	if (maxNumOfEmployees == numOfEmployees)
	{
		maxNumOfEmployees *= 2;
		Employee** temp = new Employee * [maxNumOfEmployees];

		for (int i = 0; i < numOfEmployees; i++)
		{
			temp[i] = employees[i]->clone();
		}

		delete[] employees;
		employees = temp;
	}

	employees[numOfEmployees] = new Nurse(N);
	numOfEmployees++;
	return true;
}

bool Hospital::addResearcherDoctor(ResearcherDoctor& RD)
{
	if (maxNumOfEmployees == numOfEmployees)
	{
		maxNumOfEmployees *= 2;
		Employee** temp = new Employee * [maxNumOfEmployees];

		for (int i = 0; i < numOfEmployees; i++)
		{
			temp[i] = employees[i]->clone();
		}

		delete[] employees;
		employees = temp;
	}

	employees[numOfEmployees] = new ResearcherDoctor(RD);
	numOfEmployees++;
	return true;
}

bool Hospital::addDepartmant(const char* name)
{
	if (!name)
		return false;

	if (maxNumOfDepartments == numOfDepartments)
	{
		maxNumOfDepartments *= 2;
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

bool Hospital::addPatient(const Patient& patient)
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
	return true;
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

Surgeon* Hospital::getSurgeon(const char* name) const
{
	if (!name || numOfEmployees == 0) 
	{
		return nullptr; // Return nullptr if name is invalid or no employees exist
	}

	for (int i = 0; i < numOfEmployees; ++i)
	{
		if (strcmp(employees[i]->getName(), name) == 0 && (typeid(*employees[i]) == typeid(Surgeon)))
		{
			return dynamic_cast<Surgeon*>(employees[i]); // Return pointer to the doctor if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

Doctor* Hospital::getDoctor(const char* name) const
{
	if (!name || numOfEmployees == 0) 
	{
		return nullptr; // Return nullptr if name is invalid or no employees exist
	}

	for (int i = 0; i < numOfEmployees; ++i)
	{
		if (strcmp(employees[i]->getName(), name) == 0 && (typeid(*employees[i]) == typeid(Doctor) || typeid(*employees[i]) == typeid(ResearcherDoctor) || typeid(*employees[i]) == typeid(Surgeon)))
		{
			return dynamic_cast<Doctor*>(employees[i]); // Return pointer to the doctor if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

Nurse* Hospital::getNurse(const char* name) const
{
	if (!name || numOfEmployees == 0)
	{
		return nullptr; // Return nullptr if name is invalid or no employees exist
	}

	for (int i = 0; i < numOfEmployees; ++i)
	{
		if (strcmp(employees[i]->getName(), name) == 0 && typeid(*employees[i]) == typeid(Nurse))
		{
			return dynamic_cast<Nurse*>(employees[i]); // Return pointer to the nurse if names match
		}
	}

	return nullptr; // Return nullptr if no matching doctor is found
}

bool Hospital::addVisit(int patientID, const char* purpose, const char* departmentName,
	const char* staffName, time_t visitDate, bool isSurgery, int room, bool fasting)
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

	// Find the patient by ID
	Patient* patient = findPatientById(patientID);
	if (!patient) return false;

	// Find the department by name
	Department* department = getDepartment(departmentName);
	if (!department) return false;

	// Find the staff member (Doctor, Nurse, or Surgeon)
	Employee* staff = getDoctor(staffName);
	if (!staff) staff = getNurse(staffName);
	if (!staff) staff = getSurgeon(staffName);
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
	for (int i = 0; i < numOfEmployees; i++) 
	{
		if (strcmp(employees[i]->getName(), name) == 0) 
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

ostream& operator<<(ostream& os, const Hospital& h)
{
	os << "{name: " << h.name << ", ";
	os << "number of employees: " << h.numOfEmployees << ", ";
	os << "number of departments: " << h.numOfDepartments << ", ";
	os << "employees capacity: " << h.maxNumOfEmployees << ", ";
	os << "departments capacity: " << h.maxNumOfDepartments << "}" << endl;
	os << "Research Center: " << endl;
	os << "{" << h.researchCenter << "}" << endl;

	os << "\ndepartments: " << "\n" << endl; //showing departments in hospital
	for (int i = 0; i < h.numOfDepartments; i++)
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

	if (strcmp(name, "surgeons") == 0)
	{
		this->showSurgeons();
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

void Hospital::showSurgeons() const
{
	cout << "surgeons: " << "\n" << endl; //showing surgeons in hospital
	cout << "{";
	for (int i = 0; i < numOfEmployees; i++)
	{
		if (typeid(*employees[i]) == typeid(Surgeon))
		{
			cout << employees[i]->getName();

			if (i < numOfEmployees - 1)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

void Hospital::showDoctors() const
{
	cout << "doctors: " << "\n" << endl; //showing doctors in hospital
	cout << "{";
	for (int i = 0; i < numOfEmployees; i++)
	{
		if(typeid(*employees[i]) == typeid(Doctor) || typeid(*employees[i]) == typeid(ResearcherDoctor) || typeid(*employees[i]) == typeid(Surgeon))
		{
			cout << employees[i]->getName();

			if (i < numOfEmployees - 1)
				cout << ", ";
		}
	}
	cout << "}" << endl;
}

void Hospital::showNurses() const
{
	cout << "nurses: " << "\n" << endl; //showing nurses in hospital
	cout << "{";
	for (int i = 0; i < numOfEmployees; i++)
	{
		if (typeid(*employees[i]) == typeid(Nurse))
		{
			cout << employees[i]->getName();

			if (i < numOfEmployees - 1)
				cout << ", ";
		}
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

				cout << ", date of visit: " << ctime(&visitDate)  // Display date of visit
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


	







