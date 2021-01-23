#include "CPosition.h"

CPosition::CPosition() {
	x = 0, y = 0;
}

CPosition::CPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

CPosition::~CPosition() {
	//Intentionally left blank
}

void CPosition::setX(int x) {
	this->x = x;
}

void CPosition::setY(int y) {
	this->y = y;
}

int CPosition::getX() {
	return x;
}

int CPosition::getY() {
	return y;
}