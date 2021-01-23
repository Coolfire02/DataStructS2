#pragma once
class CPosition //2D
{
	int x, y;
	
public:
	CPosition(int,int);
	CPosition();
	~CPosition();
	void setX(int);
	void setY(int);
	int getX();
	int getY();
};

