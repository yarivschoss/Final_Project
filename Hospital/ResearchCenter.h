#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H

#include <vector>
#include <string>
#include "ResearcherDoctor.h"

class ResearchCenter
{
public:
	const int DEFAULT_NUM_OF_RESEARCHERS = 7;

private:

	string name;
	vector<Researcher*> researchers;

	ResearchCenter(const ResearchCenter& other) = delete; // coping a Research Center is not allowed
	void operator=(const ResearchCenter& other) = delete; // coping a Research Center is not allowed

public:

	ResearchCenter(const string& name)
	{
			setName(name);
	}
	~ResearchCenter()
	{
		vector<Researcher*>::iterator itr = researchers.begin(); //initillize itr with the first pointer to Researcher
		vector<Researcher*>::iterator itrEnd = researchers.end(); //initillize itrEnd to be the end of the vector

		for (; itr != itrEnd; ++itr) // fire researchers
			delete* itr; // using iterator operator*
	}
	

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

	friend ostream& operator<<(ostream& os, const ResearchCenter& r)
	{
		os << "name: " << r.getName() << ", Number of researchers: " << r.researchers.size();
		return os;
	}
	friend istream& operator>>(istream& in, ResearchCenter& r)
	{
		string name;

		cout << "Enter Research Center name: ";
		getline(in, name);
		r.setName(name);

		return in;
	}


	bool operator()(const string& name)
	{
		if (strcmp(name.c_str(), "name") == 0)
		{
			cout << this->getName();
			return true;
		}

		if (strcmp(name.c_str(), "researchers") == 0)
		{
			this->showResearchers();
			return true;
		}

		return false;
	}

	bool setName(const string& name)
	{
		this->name = name;
		return true;
	}

	const string& getName() const { return name; }
	Researcher* getResearcher(const string& name) const
	{
		if (researchers.size() == 0)
		{
			return nullptr; // Return nullptr if name is invalid or no doctors exist
		}

		vector<Researcher*>::const_iterator itr = researchers.begin(); //initillize itr with the first pointer to Researcher
		vector<Researcher*>::const_iterator itrEnd = researchers.end(); //initillize itrEnd to be the end of the vector

		for (; itr != itrEnd; ++itr) // fire researchers
		{
			if (strcmp((*itr)->getName().c_str(), name.c_str()) == 0)
			{
				return *itr; // Return pointer to the Employee if names match
			}
		}

		return nullptr; // Return nullptr if no matching doctor is found
	}
};


#endif //__RESEARCH_CENTER_H