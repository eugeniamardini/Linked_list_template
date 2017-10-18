/** List342.h */
#ifndef LIST_342
#define LIST_342
#include "Bird.h"
#include "Child.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/** List342 is a class that builds a fully ordered list. The class is templatized so
that different types of objects can be stored in it.
List342<string> aListofStrings;
List342<int> aListofInts; 

Assumptions and Implementation:
--the user must enter a correct file name, otherwise will be prompted to reenter
--the user must a file name for the Object requested (if Child is requested, enter
  a filename where the children list is etc.)
*/

template<class ItemType> // indicates the template definition
class List342
{
friend ostream& operator<<(ostream& outStream, const List342<ItemType>& list) 
{
	Node* current = list.head;
    while(current != NULL) 
	{ 
		outStream << *current->data;
        current = current->next;
    }
    return outStream;
}

public:
	List342();
	List342(const ItemType &);
	bool BuildList(string );
	bool Insert (ItemType *);
	bool Remove(ItemType , ItemType &);
	bool Peek (ItemType , ItemType &);
	bool isEmpty() const;
	bool Merge (List342 &, List342 &);
    List342 operator+(const List342 &) const;  
	List342& operator+=(const List342 &);
	bool operator==(const List342 &) const;
	bool operator!=(const List342 &) const;
	void operator=(const List342 &);
	void ClearList();
	virtual ~List342();
	
private:
	struct Node
	{
		ItemType *data;
		Node *next;
	};
	Node *head;
	void MergeHelper(List342 &); //helper method
};

template<class ItemType>
List342<ItemType>::List342()
{
	head = NULL;
}

template<class ItemType>
List342<ItemType>::List342(const ItemType &theItem)
{
	this->head = NULL;
	*this = theItem;
}

//BuildList() takes a string which represents a file, opens the file,
//reads the objects from file, and builds an ordered list. 
template<class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
	string file = fileName;
	ifstream infile(file.c_str());
	//makes sure that the file opened properly
    while (infile.fail())
	{ 
		cout << "The file at location " << file << " failed to open" << endl;
		cout << "Please enter the location of the file: ";
		cin >> file;
		infile.open(file.c_str());   
    }
	//extracts data from the file
	for (;;)
	{
		ItemType *p = new ItemType;
		infile >> *p;
		if (infile.eof())
		{
			delete p;
			p = NULL;
			return false;
		}
        Insert(p);
	}
	return true;
}

//Inserts an object in the list in the correct place. Returns true or false
//depending on whether the insert was successful. Allows duplicates.
template<class ItemType>
bool List342<ItemType>::Insert(ItemType *obj)
{
	Node *insNode = new Node;
	if(insNode == NULL) return false;  //out of memory
	insNode->data = obj;
	if(isEmpty() || *insNode->data < *head->data)
	{
		insNode->next = head;
		head = insNode;
	}
	else
	{
	Node *current = head->next;
	Node *prevNode = head;
    while (current != NULL && (*current->data < *insNode->data))
		{
			prevNode = current;
			current = current->next;
		}
		insNode->next = current;
		prevNode->next = insNode;
	}
	return true;	
}

//Removes an instance of the target item from the list. Returns the item using
//a second parameter that is passed in by reference. If the item was found and
//removed return true, else return false. 
template<class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType &result) 
{
	Node *currentPtr;
	Node *dNode  = new Node;
	if(head == NULL)
	{
		return false;
	}
	if (*head->data == target)
	{
		dNode = head;
		head = head->next;
		result = *dNode->data;
		delete dNode;
		dNode = NULL;
		return true;
	}
	currentPtr = head;
	while(currentPtr->next != NULL)
	{
		if(*currentPtr->next->data == target)
		{
			dNode = currentPtr->next;
		    currentPtr->next = currentPtr->next->next;
			result = *dNode->data;
			delete dNode;
			dNode = NULL;
			return true;
		}
		currentPtr = currentPtr->next;
	}
	return false;
}

//Returns the item using a second parameter that is passed in by reference. 
//If the item was found, return true, else return false. 
template<class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType &result)
{
	Node *currentPtr;
	if(head == NULL)
	{
		return false;
	}
	if (*head->data == target)
	{
		result = *head->data;
		return true;
	}
	currentPtr = head;
	while (currentPtr->next != NULL)
	{
		if(*currentPtr->next->data == target)
		{
			result = *currentPtr->next->data;
			return true;
		}
		currentPtr = currentPtr->next;
	}
	return false;
}

template<class ItemType>
bool List342<ItemType>::isEmpty() const
{
	return head == NULL;
}

//removes all items from the list
template<class ItemType>
void List342<ItemType>::ClearList()
{
	Node *t = new Node;
	t = head;
	while(t != NULL)
	{
		t = head->next;
		head = NULL;
		head = t;
	}
	delete t;
	t = NULL;	
}

//Takes two sorted lists and merge them into one. At termination of function,
//the two parameter lists are empty unless one is also the current object. 
template<class ItemType>
bool List342<ItemType>::Merge(List342<ItemType> &l1, List342<ItemType> &l2)
{
	if ( &l1 != &l2)
	{
		if (this == &l2)
		{
			this->MergeHelper(l1);
		}
		else if (this == &l1)
		{
			this->MergeHelper(l2);
		}
		else
		{
			this->MergeHelper(l1);
			this->MergeHelper(l2);
		}
	}
	if(&l1 == &l2)
	{
		if(this != &l1 && this != &l2)
		{
			this->MergeHelper(l1);
		}
		else
		{
			return false; //the lists are equal, no merging occurred
		}
	}
    return true;
}

//MergeHelper() is a helper function to Merge()
template<class ItemType>
void List342<ItemType>::MergeHelper(List342<ItemType> &l)
{
	if(!isEmpty() && ((*l.head->data < *head->data) || 
		             (*l.head->data == *head->data)))
	{
		Node *temp = l.head->next;
		l.head->next = head;
		head = l.head;
		l.head = temp;
	}
	while (l.head != NULL)
	{
		Node *current = head;
		Node *temp;
		while (current->next != NULL && 
			((*current->next->data < *l.head->data) || 
			(*current->next->data == *l.head->data)))
		{
			current = current->next;
		}
		temp = l.head->next;
		l.head->next = current->next;
		current->next = l.head;
		l.head = temp;
	}
	l.head = NULL;
}

//overloaded operator+ adds two lists together, allowing duplicates
template<class ItemType>
List342<ItemType> List342<ItemType>::operator+(const List342<ItemType> &list) const
{
	List342<ItemType> temp;
	Node *a, *b;
	a = head;
	b = list.head;
	while(a != NULL && b != NULL)
	{
		if(*a->data < *b->data ||  *a->data == *b->data)
		{
			temp.Insert(a->data);
			a = a->next;
		}
		else
		{
			temp.Insert(b->data);
			b = b->next;
		}
	}
	while(b != NULL)
	{
		temp.Insert(b->data);
		b = b->next;
	}

	while(a != NULL)
	{
		temp.Insert(a->data);
		a = a->next;
	}
	return temp;
}

//overloaded operator+= adds two lists together, allowing duplicates
template<class ItemType>
List342<ItemType>& List342<ItemType>::operator+=(const List342<ItemType> &list)
{
	Node *a, *b;
	a = head;
	b = list.head;
	while(b != NULL)
	{
		this->Insert(b->data);
		b = b->next;
	}
	return *this;
}

//assignment operator
template<class ItemType>
void List342<ItemType>::operator=(const List342<ItemType> &list)
{
	Node *sNode, *dNode, *insNode;
	if(this == &list) 
	{
		return;
	}
	this->ClearList();
	if (list.head == NULL) 
	{
		return;
	}
	dNode = new Node;
	*dNode->data = *list.head->data;
	this->head = dNode;
	sNode = list.head->next;
	while(sNode != NULL)
	{
		insNode = new Node;
		*insNode->data = *sNode->data;
		dNode->next = insNode;
		dNode = dNode->next;
		sNode = sNode->next;
	}
}

template<class ItemType>
bool List342<ItemType>::operator!=(const List342 &list) const
{
	return !(*this == list);
}

template<class ItemType>
bool List342<ItemType>::operator==(const List342 &list) const
{
	Node *a = head, *b = list.head;
	//returns 1 if linked lists a and b are identical, otherwise 0 
	while(1)
	{
		if(a == NULL && b == NULL)    
		{  
			return 1; 
		}
		if(a == NULL && b != NULL) 
		{  
			return 0; 
		}
		if(a != NULL && b == NULL) 
		{  
			return 0; 
		}
		if(*a->data != *b->data)
		{  
			return 0; 
		}
		//here a and b are not NULL and their data is same, 
		//so move to next nodes in both lists
		a = a->next;
        b = b->next;
	}  
}

template<class ItemType>
List342<ItemType>::~List342()
{
	this->ClearList();
}

#endif