/** Child.h */
#ifndef CHILD
#define CHILD
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Child
{
friend ostream& operator<<(ostream&, const Child &);
friend istream& operator>>(istream &, Child &);

public:
	Child();
	Child(string , string , int );
	Child(const Child &);
	void setBehavior(bool );
	bool getBehavior() const;
	string getFirstName() const;
	string getLastName() const;
	int getAge() const;
	void setFirstName(string );
	void setLastName(string );
	void setAge(int );
	bool operator==(const Child &) const;
	bool operator!=(const Child &) const;
	bool operator<(const Child &);
	bool operator>(const Child &);
	void operator=(Child &);
	~Child();

private:
	string firstName;
	string lastName;
	int age;
	bool nice;
};

#endif