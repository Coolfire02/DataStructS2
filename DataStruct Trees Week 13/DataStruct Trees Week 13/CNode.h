
#pragma once

class CNode
{
private:
	int data;
	CNode* left, * right;

public:
	CNode();
	CNode(int v);
	~CNode();

	int getData(void);
	void setData(int d);
	CNode* getLeft(void);
	void setLeft(CNode* l);
	CNode* getRight(void);
	void setRight(CNode* r);
};