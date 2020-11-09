#pragma once
class CNode
{
public:
	int info;
	CNode* link;

	CNode();
	~CNode();
	CNode(int info);
};

