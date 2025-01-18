#ifndef __PAPER_H
#define __PAPER_H

#include <iostream>
#include <ctime>
using namespace std;


class Paper
{ 

public:

	friend class Researcher;

private:

	char* name;
	char* magazineName;
	time_t publishDate;

	Paper(const Paper& other) { *this = other; }
	const Paper& operator=(const Paper& other);

public:

	Paper(const char* name, const char* magazineName, time_t publishDate);
	~Paper();  

	bool setName(const char* name); // Sets the paper's name
	bool setMagazineName(const char* name); // Sets the paper's name
	

	const char* getName() const { return name; } // Gets the paper's name
	const char* getMagazineName() const { return magazineName; } // Gets the paper's magazine name
	const time_t getPublishDate() const { return publishDate; } // Gets the paper's published date

	friend ostream& operator<<(ostream& os, const Paper& p); // Overloaded stream insertion operator to print Person data
	friend istream& operator>>(istream& in, Paper& p);

};


#endif // __PAPER_H

