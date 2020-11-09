#include "CLinkList.h"
#include <iostream>

using namespace std;

CLinkList::CLinkList() {
	first = nullptr;
	last = nullptr;
	newNode = nullptr;
}

CLinkList::~CLinkList() {
	CNode* current = first;
	while (current != nullptr) {
		CNode* next = current->link;
		delete current;
		current = next;
	}
}

void CLinkList::addToBack(int value) {
	newNode = new CNode;
	newNode->info = value;
	newNode->link = nullptr;
	if(last != nullptr)
		last->link = newNode;
	if (first == nullptr) {
		first = newNode;
	}

	last = newNode;
}

void CLinkList::addToFront(int value) {
	newNode = new CNode;
	newNode->info = value;
	newNode->link = nullptr;
	if (first != nullptr) {
		newNode->link = first;
	}
	if (last == nullptr) {
		last = newNode;
	}

	first = newNode;
}

void CLinkList::deleteBack() {
	if (first == last && first != nullptr) {
		first = nullptr;
		delete last;
		last = nullptr;
	}
	else {
		CNode* current = first;
		CNode* prev = nullptr;
		while (current->link != nullptr) {
			prev = current;
			current = current->link;
		}
		prev->link = nullptr;
		delete current;
	}
}

void CLinkList::deleteFront() {
	if (first == last && first != nullptr) {
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else {
		CNode* currentFirst = first;
		first = currentFirst->link;
		delete currentFirst;
	}
}

int CLinkList::get(int index) {
	CNode* current = first;
	for (int i = 0; i < index; i++) {
		current = current->link;
	}
	return current->info;
}

int CLinkList::size() {
	CNode* current = first;
	int size = 0;
	while (current != nullptr) {
		size++;
		current = current->link;
	}
	return size;
}