#include "LinkedList.h"

LinkedList::LinkedList() {
	first = last = newNode = nullptr;
	size = 0;
}

LinkedList::~LinkedList() {
	CNode* current = first;
	while (current != nullptr) {
		CNode* toDelete = current;
		current = current->next;
		delete toDelete;
	}
}

void LinkedList::addToFront(int data) {
	(*this).addNode(0, data);
}

void LinkedList::addToBack(int data) {
	(*this).addNode((*this).size-1, data);
}

void LinkedList::removeFromFront() {
	//todo
}

void LinkedList::removeFromBack() {
	//todo
}

void LinkedList::removeNode(int index) {

}

int LinkedList::getSize() {
	return (*this).size;
}

void LinkedList::printReverse(CNode* current) {
	if (current == nullptr) {
		return;
	}
	(*this).printReverse(current->next);
	cout << current->data << endl;
}

int LinkedList::get(int index) {
	if (first == nullptr || last == nullptr) {
		//throw exception list is empty	
	}
	else if (index >= (*this).size) {
		//throw exception index out of bounds
	}
	CNode* current = first;

	if (last == first && index == 0) {
		return first->data;
	}
	for (int i = 0; i < (*this).size; i++) {
		if (index == i) {
			return current->data;
		}
		current = current->next;
		
	}
}

void LinkedList::addNode(int index, int data) {
	newNode = new CNode(data);
	if (index > 0 && index >= this->size)
		index = this->size-1;
	(*this).size++;

	if (index == 0) { //add to front
		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			newNode->next = first;
			if (last == nullptr) { //Initializing last if not set
				last = newNode;
			}
			first = newNode;
		}
	}
	else if (index == this->size-1) {
		if (last == nullptr) {
			first = last = newNode;
		}
		else {
			last->next = newNode;
			if (first == nullptr) {
				first = newNode;
			}
			last = newNode;
		}
	}
	else {
		CNode* current = first;
		CNode* prev = nullptr;
		for (int i = 0; i < index; i++) {
			prev = current;
			current = current->next;
		}
		prev->next = newNode;
		newNode->next = current;
	}
}