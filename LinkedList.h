//============================================================================
// Name        : LinkedList.h
// Author      : Glen Bray
//============================================================================


#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include  <iostream>

namespace LINKEDLIST {

template<class T>
class LinkedList {
private:
	NODE::Node<T>* head; // head instance
	NODE::Node<T>* tail; // tail instance
	int length; // number of nodes in linkedlist

public:

	typedef std::size_t size_type;

	//Destructor
	~LinkedList();

	//Constructor
	LinkedList();

	//Overloaded constructor: Creates a new node with data
	LinkedList(const T& data);

	//Add a node to the head of the linked list
	void addHead(const T& data);

	//Add a node to the position specified in the linked list: If position is greater than that of the length of the linked list
	//the node will be added to the tail of the list
	//Precondition: Position should be a valid number and data should be a valid type
	//Postcondition: adds a new node filled with data passed in as a parameter at position
	void addPosition(const size_type& position, const T& data);

	//Add a node the the end of the linkedlist
	//Precondition: data should be a value
	//Postcondition: adds an node to the tail of the linked list
	void addTail(const T& data);

	//Precondition: None
	//Postcondition: removes head node
	void removeHead();

	//Precondition: position
	//Postcondition: removes not at position
	void removeAtPosition(const size_type& position);

	//remove all occurrences of data
	//Precondition: data to be removed
	//Postcondition: removes all occurrences of data in list
	void removeAllOccurences(const T& data);

	//Precondition: None
	//Postcondition: Removes tail node from list
	void removeTail();

	//Precondition: None
	//Postcondition: returns data at head if not null
	T* getHeadData() const;

	//Precondition: Position of element in list required
	//Postcondition: returns data at position
	T* getData(const int& position) const;

	//Precondition: None
	//Postcondition: Returns pointer to tail node data
	T* getTailData() const;

	//Precondition: None
	//Postcondition: Returns count of linkedlist elements
	size_type& count() const;

	//Precondition: Linkedlist is not null
	//Postcondition: returns a deep copied linked list
	LinkedList& operator +=(const LinkedList& copy);

};

#include "LinkedList.template"

}

#endif
