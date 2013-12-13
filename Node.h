//============================================================================
// Name        : LinkedList.h
// Author      : Glen Bray
//============================================================================


#ifndef NODE_H_
#define NODE_H_

#include <cstdlib>

namespace NODE {

template<class T>
class Node {

	private:
		T data;
		Node* previous; //previous node instance
		Node* next; // next node instance

	public:
		//Precondition: None
		//Postcondition: Destroy
		~Node();

		//Precondition: None
		//Postcondition: Creates a node with data
		Node(const T& data);

		//Precondition: None
		//Postcondition: Creates node with data and points to next node
		Node(const T& data, Node<T>* next);

		//Precondition: None
		//Postcondition: Creates node with data and points to the next node and previous node
		Node(const T& data, Node<T>* next, Node<T>* previous);

		//Precondition: node not null
		//Postcondition: returns node data
		T& getData();

		//Precondition: node not null
		//Postcondition: returns node data
		T& getData() const;

		//Precondition: Node not null
		//Postcondition: Returns pointer to previous node
		Node<T>* getPrevious();

		//Precondition: Node not null
		//Postcondition: Returns pointer to next node
		Node<T>* getNext();

		//Precondition: Node not null
		//Postcondition: Update data of node
		void setData(const T& data);

		//Precondition: Node not null
		//Postcondition: Update pointer to previous node
		void setPrevious(Node* node);

		//Precondition: Node not null
		//Postcondition: Update pointer to next node
		void setNext(Node* node);
};

#include "Node.template"
}

#endif
