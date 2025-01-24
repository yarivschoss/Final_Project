#include <iostream>
using namespace std;

#include "ResearcherDoctor.h"
#include "Department.h"

const char* ResearcherOccupation[] = { "Pathology", "Dentist", "Psychiatrist", "Neurologist" };

void ResearcherDoctor::toOs(ostream& os) const
{
	os << ", ";
	os << "occupation: " << ResearcherOccupation[(int)this->occupation] << ", " <<
		"department: " << this->department->getName();
}