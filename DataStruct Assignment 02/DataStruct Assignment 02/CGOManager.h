#pragma once
#include "CQuad.h"

class CGOManager
{
	CQuad* root;
	int xSize, ySize;

	void PrintTreeInOrder(CQuad*, int, bool);
	void deletePostOrder(CQuad*);
public:
	CGOManager();
	CGOManager(int, int);
	~CGOManager();

	void addCGO(CGO*);

	void PrintTree();
	void PrintNearbyGO(int GO_ID);
};

