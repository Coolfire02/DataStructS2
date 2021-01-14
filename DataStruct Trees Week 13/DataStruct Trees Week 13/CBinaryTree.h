#include "CNode.h"
#pragma once

class CBinaryTree
{
private:
	CNode* root, * current, * prev;
	int count;
	bool search(CNode*, int);

public:
	CBinaryTree();
	~CBinaryTree();

	void insert(int);
	bool search(int);
	bool remove(int);
	void inorder(CNode* p);
	void preorder(CNode* p);
	void postorder(CNode* p);

	CNode* getRoot(void);
	void setRoot(CNode* r);
	CNode* getCurrent(void);
	void setCurrent(CNode* c);
	CNode* getPrev(void);
	void setPrev(CNode* p);
};