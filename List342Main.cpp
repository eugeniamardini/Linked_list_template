/** List342Main.cpp */
#include "Bird.h"
#include "Child.h"
#include "List342.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/** TEST CODE */

int main()
{
	Bird b1("eagle" , 123);
	cout << "Bird 1 " << b1 << endl;
	Bird b2;
	cout << "Bird 2 " << b2 << endl;
	b2 =b1;
	cout << "Bird 2 " << b2 << endl;
	Bird b3 = b1;
	cout << "Bird 3 " << b3;
	cout << "Eagle = Eagle " << (b3 == b1) << endl;
	Bird b4("chicken" , 100), b5("seagull", 45), 
		 b6("mockingbird", 1), b7("ostrich", 555);
	List342<Bird>blist;
	blist.Insert(&b1);
	blist.Insert(&b2);
	blist.Insert(&b3);
	List342<Bird>blist1;
	blist1.Insert(&b4);
	List342<Bird>added = blist + blist1;
	cout << "Added: " << added << endl;
	Bird b8("owl", 22), b9("pelican", 33), b10("turkey", 44);
	cout << "blist1 != blist (1)" << (blist != blist1) << 
		    "blist == blist1 (0) " << (blist == blist1) << endl;

	List342<Bird>blist2;
	blist2.Insert(&b8);
	blist2+=added;
	cout << "All birds :" << blist2;
	blist2.Insert(&b9);
	blist1.Insert(&b5);
	blist1.Insert(&b6);
	blist1.Insert(&b7);
	blist2.Insert(&b10);
	blist.Merge(blist, blist);
	cout << "Merged: " << blist << endl;

	string fileName;
	List342<Child>list;
	List342<Bird>list1;
	cout << "Please enter the location of the file with Children: ";
	cin >> fileName;
	list.BuildList(fileName);
	cout << list <<endl;
	cout << "Please enter the location of the file with Birds: ";
	cin >> fileName;
	list1.BuildList(fileName);
	cout << list1 <<endl;
	//testing with integers .txt file
	List342<int> num;
	cout << "Please enter the location of the file with Integers: ";
	cin >> fileName;
	num.BuildList(fileName);
	cout << num <<endl;
	

	/*********Professor Dimpsey's Test Code*******************/
	Child c1("ann", "hanlin", 7), c2("pradnya","dhala", 8);
	Child c3("bill","vollmann", 13), c4("cesar","ruiz", 6);
	Child c5("piqi","tang", 7), c6("pete","rose", 13), c7("hank","aaron", 3);
    Child c8("madison","fife", 7), c9("miles","davis", 65);
    Child c10("john","zorn", 4), c11;
    List342 <Child> class1, class2, soccer, chess;
    int a = 1, b = -1, c = 13;
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	chess.Insert(&c10);
	chess.Insert(&c7);
	cout <<"This is class1: "<< class1 << endl;
	cout <<"This is class2: "<< class2 << endl;
	if(class1 != class2)
	{
		cout <<"class1 is different than class 2"<< endl;
	}
	if(class1.Peek(c2, c11))
	{
	cout << c11 <<" is in class1"<< endl;
	}
	if(class1.Remove(c1, c11))
	{
		class2.Insert(&c11);
		cout << c1 <<" has been removed from class1 and placed in class2"<< endl;
	}
	cout << "class1: "<<class1 << endl;
	cout <<"This is class2: "<< class2 << endl;
	cout <<"This is the chess club: "<< chess << endl;
	chess.ClearList();
	cout << "empty chess class:" << chess << endl;
	chess.Insert(&c9);
	cout <<"this is now the chess club: "<< chess << endl;
	List342<Child> soccer2 = soccer;
	chess.Merge(soccer, class2);
	cout <<"this is now the chess club: "<< chess << endl;
	cout <<"this is now the soccer club after merge " << soccer << endl;
	cout << "this is now the class2 after merge " << class2 << endl;
	if(soccer.isEmpty())
	{
		cout <<"The soccer club is now empty"<< endl;
	}
	cout <<"This is the soccer2 club: "<< soccer2 << endl;
	List342<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout <<"These are the numbers: "<< numbers << endl;
	return 0;
}