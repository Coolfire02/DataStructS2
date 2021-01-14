#include "Stack.h"

Stack::Stack(int size) {
	(*this).size = size;
	(*this).index = 0;
	(*this).list = new char[size];
}

Stack::~Stack() {
	delete[] list;
}

bool Stack::push(char data) {
	if (index < size) {
		list[index++] = data;
		return true;
	}
	return false;
}

char Stack::pop() {
	if (index-1 < size && index-1 >= 0) {
		char toRet = list[--index];
		list[index] = ' ';
		return toRet;
	}
	
}

bool Stack::isEmpty() {
	if (index == 0) {
		return true;
	}
	return false;
}

bool Stack::isFull() {
	if (index == size) {
		return true;
	}
	return false;
}
