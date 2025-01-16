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
		for (int i = 0; i < numOfResearchers; i++)
		{
			cout << "{" << researchers[i] << "}";

			if (i < numOfResearchers - 1) cout << ", ";
		}
	}

	friend ostream& operator<<(ostream& os, const ResearchCenter& r);


	bool setName(const char* name);
	const char* getName() const { return name; }

};


#endif //__RESEARCH_CENTER_H