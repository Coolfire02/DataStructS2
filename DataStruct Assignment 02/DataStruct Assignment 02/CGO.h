#pragma once
#include "CPosition.h"

class CGO
{
	CPosition pos;
	int ID;

public:
	CGO(int ID, int x, int y);
	CGO(int ID, CPosition pos);
	~CGO();
	void setX(int);
	void setY(int);
	void setPos(CPosition);
	int getID();
	int getX();
	int getY();
	CPosition getPos();
};

