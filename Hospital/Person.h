#ifndef __PERSON_H
#define __PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{

protected:

    string name;  
    int birthYear;
    char gender;
    static int counter;

    friend istream& operator>>(istream& in, Person& p)
    {
        string name;

        cout << "Enter name: ";
        getline(in,name);
        p.setName(name);

        cout << "Enter gender(m/f): ";
        in >> p.gender;

        cout << "Enter birth year: ";
        in >> p.birthYear;
        return in;
    }

private:

    bool setBirthYear(int birthYear)
    {
        this->birthYear = birthYear;
        return true;
    }
    bool setGender(char gender)
    {
        this->gender = gender;
        return true;
    }

public:

    Person(const string& name, int birthYear, char gender)  // Constructor to initialize the name
    {
        setName(name);  // Initialize the name using the setName method
        setBirthYear(birthYear);
        setGender(gender);
    }
   
    virtual ~Person()  // Virtual destructor to ensure proper memory management if needed
    {
        ;
    }

    bool setName(const string& name) // Sets the person's name
    {
        this->name = name;
        return true;
    }

    const string& getName() const { return name; } // Gets the person's name
    int getBirthYear() const { return birthYear; }
    char getGender() const { return gender; }

   // bool operator()(const char* name); // prints data according to name
   // operator int() const { return getId(); } // replaces get employeeNumber
    //operator const char* () const { return getName(); } // returns name of Person

    friend ostream& operator<<(ostream& os, const Person& p) // Overloaded stream insertion operator to print Person data
    {
      os << "name: " << p.name << ", birth Year: " << p.birthYear << ", gender: " << p.gender;  // Print the name of the person
      return os;
    }
};

#endif // __PERSON_H
