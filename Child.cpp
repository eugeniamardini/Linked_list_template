/** Child.cpp */
#include "Child.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/** Child class is implemented to create Children objects that have a first 
and last names, and age. The children can be naughty or nice, which will
determine their qualification for Santa's presents.

Assumptions and Implementation:
--constructor takes 3 parameters: first, last names, and age
--default constructor assigns a child to age zero, and behavior "nice"
--user can change the names, age, and behavior of children
--Children are compared by their last names (alphabetically)
--The istream reads the first, then last name, the n age of a child from a
  file, until it reaches the ond of file.
--The overloaded comparison functions are case-sensitive, as they use string's
  compare() function
--overloaded output operator will output children in the following order:
  first name, last name, age, 0/1 for behavior (with no spaces, tabs, commas).
  */

Child::Child()
{
	age = 0;
	nice = true;
}

Child::Child(string fName, string lName, int n)
{
	firstName = fName;
	lastName = lName;
	age = n;
	nice = true;
}
	
Child::Child(const Child &child)
{
	this->firstName = child.firstName;
	this->lastName = child.lastName;
	this->age = child.age;
	this->nice = child.nice;
}

bool Child::getBehavior() const 
{
	return nice;
}

void Child::setBehavior(bool nice)
{
	this->nice = true;
}

string Child::getFirstName() const
{
	return firstName;
}

string Child::getLastName() const
{
	return lastName;
}

void Child::setAge(int n)
{
	age = n;
}

int Child::getAge() const
{
	return age;
}

void Child::setFirstName(string fName)
{
	firstName = fName;
}

void Child::setLastName(string lName)
{
	lastName = lName;
}

void Child::operator=(Child &child)
{
	if (*this == child) return;
	firstName = child.firstName;
	lastName = child.lastName;
	age = child.age;
	nice = child.nice;	
}

bool Child::operator==(const Child &child) const
{
	return ((lastName == child.lastName) && (firstName == child.firstName) 
		&& (age == child.age) && (nice == child.nice));
}

bool Child::operator!=(const Child &child) const
{
	return !(*this == child);
}

bool Child::operator<(const Child &child) 
{
	int lastVal = lastName.compare(child.lastName);
	if(lastVal < 0)
	{
		return true;
	}
	else if (lastVal == 0 && (firstName.compare(child.firstName) < 0))
	{
		return true;
	}
	else
		return false;
}

bool Child::operator>(const Child &child) 
{
	int lastVal = lastName.compare(child.lastName);
	if(lastVal > 0)
	{
		return true;
	}
	else if (lastVal == 0 && (firstName.compare(child.firstName) > 0))
	{
		return true;
	}
	else
		return false;
}

ostream& operator<<(ostream& outStream, const Child &child)
{
	outStream << child.getFirstName() << child.getLastName() << child.getAge()
		<< child.getBehavior();
	return outStream;
}

//overloaded operator>> reads data from the file or user input
istream& operator>>(istream &inStream, Child &child)
{
	string firstName, lastName;
	int age;
	inStream >> firstName >> lastName >> age;
	child.setFirstName(firstName);
	child.setLastName(lastName);
	child.setAge(age);
	return inStream;
}

Child::~Child(void)
{
}
