//============================================================================
// Name        : LinkedList.h
// Author      : Glen Bray
//============================================================================

#ifndef TOWERHANOI_H_
#define TOWERHANOI_H_

#include "LStack.h"

class TowerHanoi {

private:
	LSTACK::LStack<std::string>* rod1; // First tower
	LSTACK::LStack<std::string>* rod2; // Second tower
	LSTACK::LStack<std::string>* rod3; // Third tower

	int height; // Height of tower
	int length; // Length of each row

	//Precondition: Rod is not null
	//Postcondition: Fills stack with white space to height of each stack
	void fillStackWhiteSpace(LSTACK::LStack<std::string>* rod);

	//Precondition: Rod is not null
	//Postcondition: Removes all white spaces from a stack
	void removeStackWhiteSpace(LSTACK::LStack<std::string>* rod);

	//Precondition: None
	//Postcondition: Add white space to the beginning and end of a string
	void appendWhiteSpace(std::string& text);

	//Precondition: None
	//Postcondition: Move top element of stack to another stack
	void move(LSTACK::LStack<std::string>*& source, LSTACK::LStack<std::string>& target);

	//Precondition: None
	//Postcondition: returns rod1, rod2, or rod3 depending on the input
	LSTACK::LStack<std::string>* getRod(const int& rod, bool instantiate);

	//Precondition: None
	//Postcondition: Get string at position in rod
	std::string& getRodData(const int& position, LSTACK::LStack<std::string>& rod);

	//Precondition: Rod not null
	//Postcondition: Push string onto rod
	void insertOntoStack(LSTACK::LStack<std::string>& rod, const std::string& row);

public:
	//Precondition: None
	//Postcondition: Generates game with stack height
	TowerHanoi(const int& height);

	//Precondition: None
	//Postcondition: Destroy
	~TowerHanoi();

	//Precondition: None
	//Postcondition: Generates Tower of Hanoi
	void generateTower();

	//Precondition: None
	//Postcondition: validates if move is allowed if allowed move source to target then return true, otherwise return false
	bool validateAndMove(const int& source, const int& target);

	//Precondition: None
	//Postcondition: Check if selected tower is valid and return true, otherwise return false
	bool validateSelectedTower(const int& num);

	//Precondition: None
	//Postcondition: Check if Disks have been moved to the last rod if so returns true otherwise returns false
	bool checkWin();
};

#endif /* TOWERHANOI_H_ */
