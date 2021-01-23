#include "CGO.h"

CGO::CGO(int ID, int x, int y) {
	this->ID = ID;
	this->pos = CPosition(x, y);
}

CGO::CGO(int ID, CPosition pos) {
	this->ID = ID;
	this->pos = pos;
}

CGO::~CGO() {
	//Intentionally left blank
}

void CGO::setX(int x) {
	this->pos.setX(x);
}

void CGO::setY(int y) {
	this->pos.setY(y);
}

void CGO::setPos(CPosition pos) {
	this->pos = pos;
}

CPosition CGO::getPos() {
	return this->pos;
}

int CGO::getID() {
	return ID;
}

int CGO::getX() {
	return pos.getX();
}

int CGO::getY() {
	return pos.getY();
}