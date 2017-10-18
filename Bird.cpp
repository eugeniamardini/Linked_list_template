/** Bird.cpp */
#include "Bird.h"
#include "List342.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/** Bird class is implemented to create Bird objects that have a species name,
and an ID. The birds can have flu. 

Assumptions and Implementation:
--constructor takes 2 parameters: string name, and int ID. 
--default constructor assigns a bird's ID to 0, and sets flu status to false
--user can change the names, ID, and flu status of birds
--birds are compared by their ID
--The istream reads the bird's name, then the ID from a file,
  until it reaches the ond of file.
--Hence, it is assumed the file contains info in the right order
--overloaded output operator will output the birds in the order: name, ID, and
  flu status (no commas, spaces, tabs).
*/

Bird::Bird()
{
	ID = 0;
	flu = false;
}

Bird::Bird(string name, int n)
{
	birdName = name;
	ID = n;
	flu = false;
}

Bird::Bird(const Bird &b)
{
	this->flu = b.flu;
	this->birdName = b.birdName;
	this->ID = b.ID;
}

string Bird::getBirdName() const
{
	return birdName;
}

int Bird::getBirdID() const
{
	return ID;
}

void Bird::setName(string name)
{
	birdName = name;;
}

void Bird::setID(int id)
{
	ID = id;
}

void Bird::setFlu(bool flu)
{
	flu = true;
}

bool Bird::getFluStatus() const
{
	return flu;
}

ostream& operator<<(ostream& outStream, const Bird &bird)
{
	outStream << bird.getBirdName() <<bird.getBirdID() << bird.getFluStatus();
	return outStream;
}

bool Bird::operator==(const Bird &b)
{
	return ((birdName == b.birdName) && (ID = b.ID) && (flu == b.flu));
}

bool Bird::operator!=(const Bird &b)
{
	return !(*this == b);
}

bool Bird::operator<(const Bird &b)
{
	if (ID < b.ID)
	{
		return true;
	}
	else
		return false;
}

bool Bird::operator>(const Bird &b)
{
	if (ID > b.ID)
	{
		return true;
	}
	else 
		return false;
}

void Bird::operator=(const Bird &b)
{
	if (this==&b) return;
	this->birdName = b.birdName;
	this->ID = b.ID;
	this->flu = b.flu;
}

//overloaded operator>> to read data from file or user input
istream& operator>>(istream &inStream, Bird &bird)
{
	string birdName;
	int ID;
	inStream >> birdName >> ID;
	bird.setName(birdName);
	bird.setID(ID);
	return inStream;
}

Bird::~Bird()
{
}
