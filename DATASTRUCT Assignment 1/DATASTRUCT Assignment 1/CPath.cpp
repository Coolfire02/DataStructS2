#include "CPath.h"

CPath::CPath() {
	first = last = newNode = nullptr;
	size = 0;
}

CPath::~CPath() {
	DLCNode* current = first;
	while (current != nullptr) {
		DLCNode* toDelete = current;
		current = current->next;
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
				DLCNode* prev = last->back;
				delete last;
				last = prev;
				prev->next = nullptr;
				prev->data = 'E';
				if ((*this).size == 2)
					last->data = 'S';
			}
			// Special case (First entry)
			else if (index == 0) {
				DLCNode* next = first->next;
				delete first;
				first = next;
				next->back = nullptr;
				next->data = 'S';
			}
			else {
				DLCNode* current = first;
				DLCNode* prev = nullptr;
				for (int i = 1; i <= index; i++) {
					prev = current;
					current = current->next;
				}
				if (prev != nullptr) {
					prev->next = current->next;
					if(current->next != nullptr)
						current->next->back = prev;
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

	DLCNode* current = first;
	if (last == first && index == 0) {
		if(first != nullptr) //Should never occur but removes warning for dereferencing null pointer
			return first->data;
	}
	for (int i = 0; i < (*this).size; i++) {
		if (index == i) {
			if(current != nullptr)
				return current->data;
		}
		if(current != nullptr)
			current = current->next;
	}
}

void CPath::addNode(int index, char data) {
	newNode = new DLCNode(data);
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
			first->data = data;
			newNode->next = first;
			first->back = newNode;
			if (last == nullptr) {
				last = newNode;
			}
			first = newNode;
		}
		first->data = 'S';
		if ((*this).size == 1)
			last->data = 'E';
	}
	else if (index == (*this).size) { // Add to back (Always handle back addition)
		if (last == nullptr) {
			first = last = newNode;
		}
		else {
			last->data = data;
			last->next = newNode;
			newNode->back = last;
			if (first == nullptr) {
				first = newNode;
			}
			last = newNode;
		}
		last->data = 'E';
	}
	else { // Add to middle (Always handle middle addition)
		DLCNode* current = first;
		DLCNode* prev = nullptr;
		for (int i = 1; i <= index; i++) {
			prev = current;
			current = current->next;
		}
		if(prev != nullptr)
			prev->next = newNode;
		if(current != nullptr)
			current->back = newNode;
		newNode->back = prev;
		newNode->next = current;
	}
	(*this).size++;
}

vector<char> CPath::toVector() {
	vector<char> a;
	DLCNode* current = first;
	while (current != nullptr) {
		a.push_back(current->data);
		current = current->next;
	}
	//a.push_back('N');
	return a;
}