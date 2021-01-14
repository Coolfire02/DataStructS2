#include "CNode.h"

CNode::CNode()
{
	data = 0;
	left = nullptr;
	right = nullptr;
}

CNode::CNode(int v)
{
	data = v;
	left = nullptr;
	right = nullptr;
}

CNode::~CNode()
{

}

int CNode::getData(void)
{
	return data;
}

void CNode::setData(int d)
{
	data = d;
}

CNode* CNode::getLeft(void)
{
	return left;
}

void CNode::setLeft(CNode* l)
{
	left = l;
}

CNode* CNode::getRight(void)
{
	return right;
}

void CNode::setRight(CNode* r)
{
	right = r;
}