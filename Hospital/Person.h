#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
using namespace std;

class Person
{

protected:

    char* name;  
    int birthYear;
    char gender;
    static int counter;

    Person(const Person& other) : name(nullptr) { *this = other; }
    const Person& operator=(const Person& other);

private:

    bool setBirthYear(int birthYear);
    bool setGender(char gender);

public:

    Person(const char* name, int birthYear, char gender);  // Constructor to initialize the name
   
    virtual ~Person();  // Virtual destructor to ensure proper memory management if needed

    bool setName(const char* name); // Sets the person's name

    const char* getName() const { return name; } // Gets the person's name
    int getBirthYear() const { return birthYear; }
    char getGender() const { return gender; }

   // bool operator()(const char* name); // prints data according to name
   // operator int() const { return getId(); } // replaces get employeeNumber
    //operator const char* () const { return getName(); } // returns name of Person

    friend ostream& operator<<(ostream& os, const Person& p); // Overloaded stream insertion operator to print Person data
};

#endif // __PERSON_H
