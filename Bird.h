/** Bird.h */
#ifndef BIRD
#define BIRD
#include <iostream>
#include <string>
using namespace std;

class Bird
{
friend ostream& operator<<(ostream&, const Bird &);
friend istream& operator>>(istream& , Bird &);

public:
	Bird();
	Bird(string , int );
	Bird(const Bird &);
	void setFlu(bool );
	bool getFluStatus() const;
	string getBirdName() const;
	void setName(string );
	int getBirdID() const;
	void setID(int );
	bool operator==(const Bird &);
	bool operator!=(const Bird &);
	bool operator<(const Bird &);
	bool operator>(const Bird &);
	void operator=(const Bird &); 
	~Bird();

private:
	string birdName;
	bool flu;
	int ID;
};

#endif