//============================================================================
// Name        : LStack.h
// Author      : Glen Bray
//============================================================================

#ifndef LSTACK_H
#define LSTACK_H

#include "LinkedList.h"

namespace LSTACK
{

template<class T>
class LStack
{
private:

	//Precondition: NONE
	//Postcondition: List of elements
	LINKEDLIST::LinkedList<T>* ll;

public:

	//Precondition: None
	//Postcondition: Destroy
	~LStack();

	//Precondition: None
	//Postcondition: Allocate memory to ll
	LStack();

	//Precondition: None
	//Postcondition: push data onto stack
	void push(const T& data);

	//Precondition: None
	//Postcondition: Returns top element of stack
	T* top() const;

	//Precondition: None
	//Postcondition: Returns top element of stack then deletes it
	T pop();

	//Precondition: None
	//Postcondition: Returns size of stack
	std::size_t size();

	//Precondition: stack not null
	//Postcondition: deep copies stack into another stack
	LStack& operator +=(const LStack& t);
};

#include "LStack.template"

}



#endif
