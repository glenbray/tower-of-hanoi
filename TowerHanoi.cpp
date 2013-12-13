//============================================================================
// Name        : LinkedList.h
// Author      : Glen Bray
//============================================================================

#include "TowerHanoi.h"
#include <sstream>

TowerHanoi::TowerHanoi(const int& height) {

	this->rod1 = new LSTACK::LStack<std::string>();
	this->rod2 = NULL;
	this->rod3 = NULL;
	this->height = height;

	LSTACK::LStack<std::string> tempStack;
	std::string x = "x";
	tempStack.push(x);

	for(int i = 1; i <= this->height - 1; i++) //Create disks for rods
	{
		x.append(2, 'x');
		tempStack.push(x);
	}

	std::string top = *tempStack.top(); // Get top element of temp stack
	this->length = top.size(); // Get the length of x's on top stack

	while(tempStack.size() != 0) // Insert initial x's onto rod1
	{
		this->insertOntoStack(*this->rod1, *tempStack.top());
		tempStack.pop();
	}
}

TowerHanoi::~TowerHanoi() {

	delete this->rod1;
	delete this->rod2;
	delete this->rod3;
}

void TowerHanoi::generateTower() {

	std::string table = "";

	for(int i = 0; i <= this->height - 1; i++) // Iterate through each row in table
	{
		std::string row = "";

		for(int j = 0; j <= 2; j++) // Iterate through each cell in table row
		{
			std::string top = "";
			LSTACK::LStack<std::string> alias;

			if(this->getRod(j, false) == NULL)
				top = "";
			else
			{
				alias += *this->getRod(j, false); // Deep copy of selected rod
				if(alias.top() == NULL)
					top = "";
				else
					top = *alias.top();
			}

			std::string cell = "";
			if(top != "")
			{
				int stackSize = alias.size();
				int currentLevel = this->height - i;

				if(stackSize >= currentLevel)
					cell = this->getRodData(i, alias); // Get element on stack at position

				this->appendWhiteSpace(cell); // Add white spaces around x's
			}
			else
			{
				cell = " ";
				this->appendWhiteSpace(cell);  // Fill with white space
			}
			row += cell; // Add cell to current row
		}
		table += row + "\n"; // Add row to table
	}

	std::string dash, end;
	int length = (this->length + 4) * 3; // Get the length required for table footer
	dash.append(length, '-'); // Append - to the table

	for(int i = 1; i <= 3; i++)
	{
		std::stringstream stream;
		stream << i;
		std::string temp = stream.str();
		this->appendWhiteSpace(temp);
		end += temp;
	}
	table += dash + "\n" + end + "\n"; // Add dashes and column numbers to table

	std::cout << table; // Print table
}

std::string& TowerHanoi::getRodData(const int& position, LSTACK::LStack<std::string>& temp) {

	int counter = 0;

	while(counter != position)
	{
		std::string empty = "";
		if(temp.top() == NULL)
			return empty;

		temp.pop();
		++counter;
	}
	return *temp.top(); // Returns element at position
}

void TowerHanoi::insertOntoStack(LSTACK::LStack<std::string>& rod, const std::string& row) {

	std::string text = row;
	this->appendWhiteSpace(text); // Fill row with white space
	rod.push(text); // Add row to rod
}

void TowerHanoi::appendWhiteSpace(std::string& text) {

	int resize = (this->length - text.size() + 4) / 2; // Determine spacing
	std::string blank = "";
	blank.append(resize, ' '); // create white space of a certain size
	text.insert(0, blank); // Add white space to the front of variable
	text.insert(text.size(), blank); // Add white space to the end of variable
}

void TowerHanoi::fillStackWhiteSpace(LSTACK::LStack<std::string>* rod) {

	int size = rod->size();

	if(size == this->height)
		return;

	std::string text = " ";
	this->appendWhiteSpace(text);

	for(int i = 0; i <= this->height - size - 1; i++)
		rod->push(text); // Push white space onto stack if stack is not of a certain size
}

void TowerHanoi::removeStackWhiteSpace(LSTACK::LStack<std::string>* rod) {

	std::string text;
	while(rod->top() != NULL)
	{
		text = *rod->top();
		int occurences = std::count(text.begin(), text.end() , 'x'); // Check if element contains x

		if(occurences >= 1) // If x is in element return
			return;

		rod->pop();
		occurences = std::count(text.begin(), text.end() , 'x');
	}
}


LSTACK::LStack<std::string>* TowerHanoi::getRod(const int& rod, bool instantiate) {

	LSTACK::LStack<std::string>* alias = NULL;
	switch (rod)
	{
		case 0: // Return rod 1
			if(instantiate)
				this->rod1 = new LSTACK::LStack<std::string>();
			alias = this->rod1;
			break;
		case 1: // Return rod 2
			if(instantiate)
					this->rod2 = new LSTACK::LStack<std::string>();
			alias = this->rod2;
			break;
		case 2: // Return rod 3
			if(instantiate)
					this->rod3 = new LSTACK::LStack<std::string>();
			alias = this->rod3;
			break;
	}
	return alias;
}

bool TowerHanoi::validateAndMove(const int& source, const int& target) {

	LSTACK::LStack<std::string>* sRod = this->getRod(source, false); // Source rod to move disk from
	LSTACK::LStack<std::string>* tRod;

	if(this->getRod(target, false) == NULL)
		tRod = this->getRod(target, true); // Target rod to move disk to
	else
		tRod = this->getRod(target, false);

	if(sRod == NULL) //Check if rod to move from is a empty
		return false;

	if(tRod == NULL)
		tRod = new LSTACK::LStack<std::string>();
	else
		this->removeStackWhiteSpace(tRod);

	this->removeStackWhiteSpace(sRod);

	if(sRod->top() == NULL || sRod->size() < 1 || source == target) // Check for Null and invalid moves
	{
		this->fillStackWhiteSpace(sRod);
		this->fillStackWhiteSpace(tRod);
		return false;
	}

	std::string sourceText = *sRod->top();
	int sourceXCount = std::count(sourceText.begin(), sourceText.end(), 'x'); // Get source rods top disk size
	int targetXCount = 0;

	if(tRod->top() != NULL)
	{
		std::string targetText = "";

		if(tRod->top() != NULL)
			targetText = *tRod->top();

		targetXCount = std::count(targetText.begin(), targetText.end(), 'x'); // Get target rods top disk size
	}

	if(sourceXCount > targetXCount && targetXCount != 0) // Check if move is valid
	{
		this->fillStackWhiteSpace(sRod);
		this->fillStackWhiteSpace(tRod);
		return false;
	}

	this->move(sRod, *tRod); // Move disk from source rod to target rod
	return true;
}

void TowerHanoi::move(LSTACK::LStack<std::string>*& source, LSTACK::LStack<std::string>& target) {

	target.push(source->pop()); // Push source to target rod and pop source

	if(source->size() == 0) // Check if source does not contain elements and set it to null if so
		source = NULL;
	else
		this->fillStackWhiteSpace(source);
	this->fillStackWhiteSpace(&target);
}

bool TowerHanoi::validateSelectedTower(const int& num)
{
	if(num >= 0 && num <= 3) // Check if uses has selected a valid input for rod
		return true;
	return false;
}

bool TowerHanoi::checkWin() {

	if(this->rod3 == NULL) // Return false if rod3 is empty
		return false;

	this->removeStackWhiteSpace(this->rod3);

	if(this->height == (int)this->rod3->size()) // If the height is equal to rod3 size then player has met win condition
		return true;

	this->fillStackWhiteSpace(this->rod3);
	return false;
}
