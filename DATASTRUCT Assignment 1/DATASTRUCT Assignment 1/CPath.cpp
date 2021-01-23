#include "CPath.h"

CPath::CPath() {
	first = last = newNode = nullptr;
	size = 0;
}

CPath::~CPath() {
	CNode* current = first;
	while (current != nullptr) {
		CNode* toDelete = current;
		current = current->getNext();
		delete toDelete;
	}
}

void CPath::addToFront(char data) {
	(*this).addNode(0, data);
}

void CPath::addToBack(char data) {
	(*this).addNode( (*this).size , data);
}

bool CPath::removeFromFront() {
	return removeNode(0);
}

bool CPath::removeFromBack() {
	return removeNode((*this).size - 1);
}

bool CPath::removeNode(int index) {
	if (first != nullptr && last != nullptr) {
		if (index >= 0 && index < (*this).size) {
			// Special case (Single entry)
			if (first == last) {
				delete first;
				first = nullptr;
				last = nullptr;
			}
			// Special case (Last entry) - Can assume > 1 entry, allowing this statement to not be contradicted by the one below
			else if (index == (*this).size - 1) {
				CNode* prev = last->getBack();
				delete last;
				last = prev;
				prev->setNext(nullptr);
				prev->setData('E');
				if ((*this).size == 2)
					last->setData('S');
			}
			// Special case (First entry)
			else if (index == 0) {
				CNode* next = first->getNext();
				delete first;
				first = next;
				next->setBack(nullptr);
				next->setData('S');
			}
			else {
				CNode* current = first;
				CNode* prev = nullptr;
				for (int i = 1; i <= index; i++) {
					prev = current;
					current = current->getNext();
				}
				if (prev != nullptr) {
					prev->setNext(current->getNext());
					if(current->getNext() != nullptr)
						current->getNext()->setBack(prev);
					delete current;
				}
			}

			(*this).size--;
			return true;
		}
	}
	return false;
}

int CPath::getSize() {
	return (*this).size;
}

char CPath::get(int index) {
	if (first == nullptr || last == nullptr) {
		//throw exception
		throw "Illegal State Exception! List was empty!";
	}
	else if (index >= (*this).size || index < 0) {
		//throw exception index out of bounds
		throw "Index Out Of Bounds Exception! Tried accessing Index: " + (index);
	}

	CNode* current = first;
	if (last == first && index == 0) {
		if(first != nullptr) //Should never occur but removes warning for dereferencing null pointer
			return first->getData();
	}
	for (int i = 0; i < (*this).size; i++) {
		if (index == i) {
			if(current != nullptr)
				return current->getData();
		}
		if(current != nullptr)
			current = current->getNext();
	}
	throw "End of get Function, this should never occur!";
}

void CPath::addNode(int index, char data) {
	newNode = new CNode(data);
	if (index > 0 && index > this->size)
		index = (*this).size;

	if (index == 0) { // Add to front (Always handle front addition)
		if (first == nullptr) {
			first = newNode;
			last = newNode;
			
		}
		else {
			if (first == last) {
				last = first;
			}
			first->setData(data);
			newNode->setNext(first);
			first->setBack(newNode);
			if (last == nullptr) {
				last = newNode;
			}
			first = newNode;
		}
		first->setData('S');
		if ((*this).size == 1)
			last->setData('E');
	}
	else if (index == (*this).size) { // Add to back (Always handle back addition)
		if (last == nullptr) {
			first = last = newNode;
		}
		else {
			last->setData(data);
			last->setNext(newNode);
			newNode->setBack(last);
			if (first == nullptr) {
				first = newNode;
			}
			last = newNode;
		}
		last->setData('E');
	}
	else { // Add to middle (Always handle middle addition)
		CNode* current = first;
		CNode* prev = nullptr;
		for (int i = 1; i <= index; i++) {
			prev = current;
			current = current->getNext();
		}
		if(prev != nullptr)
			prev->setNext(newNode);
		if(current != nullptr)
			current->setBack(newNode);
		newNode->setBack(prev);
		newNode->setNext(current);
	}
	(*this).size++;
}

vector<char> CPath::toVector() {
	vector<char> a;
	CNode* current = first;
	while (current != nullptr) {
		a.push_back(current->getData());
		current = current->getNext();
	}
	//a.push_back('N');
	return a;
}