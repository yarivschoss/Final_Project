#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H

#include "Researcher.h"

class ResearchCenter
{
public:
	const int DEFAULT_NUM_OF_RESEARCHERS = 7;

private:

	int numOfResearchers, maxNumOfResearchers;
	char* name;
	Researcher** researchers;

	ResearchCenter(const ResearchCenter& other) = delete; // coping a Research Center is not allowed
	void operator=(const ResearchCenter& other) = delete; // coping a Research Center is not allowed

public:

	ResearchCenter(const char* name);
	~ResearchCenter();
	

	bool addResearcher(const Researcher& researcher);
	void showResearchers() const
	{
		cout << "{";
		for (int i = 0; i < numOfResearchers; i++)
		{
			cout << researchers[i]->getName();

			if (i < numOfResearchers - 1) cout << ", ";
		}
		cout << "}";
	}

	const ResearchCenter& operator+=(Researcher& other)
	{
		this->addResearcher(other);
		return *this;
	}
	friend ostream& operator<<(ostream& os, const ResearchCenter& r);
	friend istream& operator>>(istream& in, ResearchCenter& r);

	bool operator()(const char* name);


	bool setName(const char* name);

	const char* getName() const { return name; }
	Researcher* getResearcher(const char* name) const;  //searches through the array of researchers and returns a pointer to the researcher with the specified name
};


#endif //__RESEARCH_CENTER_H