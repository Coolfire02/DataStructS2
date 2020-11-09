#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
	first = last = newNode = nullptr;
	size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
	DLCNode* current = first;
	while (current != nullptr) {
		DLCNode* toDelete = current;
		current = current->next;
		delete toDelete;
	}
}

void DoublyLinkedList::addToFront(int data) {
	(*this).addNode(0, data);
}

void DoublyLinkedList::addToBack(int data) {
	(*this).addNode((*this).size - 1, data);
}

void DoublyLinkedList::removeFromFront() {
	//todo
}

void DoublyLinkedList::removeFromBack() {
	//todo
}

void DoublyLinkedList::removeNode(int index) {

}

int DoublyLinkedList::getSize() {
	return (*this).size;
}

void DoublyLinkedList::printReverse(DLCNode* current) {
	if (current == nullptr) {
		return;
	}
	(*this).printReverse(current->next);
	cout << current->data << endl;
}

int DoublyLinkedList::get(int index) {
	if (first == nullptr || last == nullptr) {
		//throw exception list is empty	
	}
	else if (index >= (*this).size) {
		//throw exception index out of bounds
	}
	DLCNode* current = first;

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

void DoublyLinkedList::addNode(int index, int data) {
	newNode = new DLCNode(data);
	if (index > 0 && index >= this->size)
		index = this->size - 1;
	(*this).size++;

	if (index == 0) { //add to front
		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			newNode->next = first;
			first->back = newNode;
			if (last == nullptr) { //Initializing last if not set
				last = newNode;
			}
			first = newNode;
		}
	}
	else if (index == this->size - 1) {
		if (last == nullptr) {
			first = last = newNode;
		}
		else {
			last->next = newNode;
			newNode->back = last;
			if (first == nullptr) {
				first = newNode;
			}
			last = newNode;
		}
	}
	else {
		DLCNode* current = first;
		DLCNode* prev = nullptr;
		for (int i = 0; i < index; i++) {
			prev = current;
			current = current->next;
		}

		prev->next = newNode;
		newNode->back = prev;
		newNode->next = current;
	}
}