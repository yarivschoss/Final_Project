#ifndef __RESEARCH_CENTER_H
#define __RESEARCH_CENTER_H

class ResearchCenter
{
public:

private:

	char* name;

public:

	ResearchCenter(const char* name);
	~ResearchCenter();
	ResearchCenter(const ResearchCenter& other) = delete; // coping a Research Center is not allowed

	void operator=(const ResearchCenter& other) = delete; // coping a Research Center is not allowed
	friend ostream& operator<<(ostream& os, const ResearchCenter& r);


	bool setName(const char* name);
	const char* getName() const { return name; }

	void show() const { ; }
};


#endif //__RESEARCH_CENTER_H