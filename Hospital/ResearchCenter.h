#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H

#include <vector>
#include "ResearcherDoctor.h"

class ResearchCenter
{
public:
	const int DEFAULT_NUM_OF_RESEARCHERS = 7;

private:

	char* name;
	vector<Researcher*> researchers;

	ResearchCenter(const ResearchCenter& other) = delete; // coping a Research Center is not allowed
	void operator=(const ResearchCenter& other) = delete; // coping a Research Center is not allowed

public:

	ResearchCenter(const char* name) : name(nullptr)
	{
			setName(name);
	}
	~ResearchCenter();
	

	bool addResearcher(const Researcher& researcher)
	{
		researchers.push_back(researcher.clone()); // using clone so a pointer will be added to researchers
		return true;
	}
	bool addResearcherDoctor(const ResearcherDoctor& researcherDoctor)
	{
		researchers.push_back(researcherDoctor.clone()); // using clone so a pointer will be added to researchers
		return true;
	}
	void showResearchers() const
	{
		vector<Researcher*>::const_iterator itr = researchers.begin(); //initillize itr with the first pointer to Researcher
		vector<Researcher*>::const_iterator itrEnd = researchers.end(); //initillize itrEnd to be the end of the vector

		int size = researchers.size(); // defined outside the for loop for better code efficiency

		cout << "{";
		for (int i = 1; itr != itrEnd; ++itr, ++i)
		{
			cout << (*itr)->getName();

			if (i < size) cout << ", ";
		}
		cout << "}";
	}

	const ResearchCenter& operator+=(Researcher& other)
	{
		this->addResearcher(other);
		return *this;
	}
	const ResearchCenter& operator+=(ResearcherDoctor& other)
	{
		this->addResearcherDoctor(other);
		return *this;
	}
	friend ostream& operator<<(ostream& os, const ResearchCenter& r);
	friend istream& operator>>(istream& in, ResearchCenter& r);

	bool operator()(const char* name);


	bool setName(const char* name);

	const char* getName() const { return name; }
	Researcher* getResearcher(const char* name) const;  //searches through the array of researchers and returns a pointer to the employee with the specified name
};


#endif //__RESEARCH_CENTER_H