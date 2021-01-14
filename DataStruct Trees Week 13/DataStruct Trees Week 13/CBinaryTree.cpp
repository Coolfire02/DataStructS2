#include <iostream>
#include "CBinaryTree.h"

using namespace std;

CBinaryTree::CBinaryTree()
{
	root = nullptr;
	current = nullptr;
	prev = nullptr;
}

CBinaryTree::~CBinaryTree()
{

}

bool CBinaryTree::remove(int data) {
	current = root;
	CNode* prev = current;
	while (current != nullptr) {
		if (current->getData() == data) break;

		if (current->getLeft() != nullptr && data < current->getData()) {
			prev = current;
			current = current->getLeft();
		}
		else if (current->getRight() != nullptr && data > current->getData()) {
			prev = current;
			current = current->getRight();
		}
		else if (current->getRight() == nullptr && current->getLeft() == nullptr && current->getData() != data){
			return false;
		}
	}

	cout << current->getData() << " ?????? " << endl;

	//Case 1 Leaf Node
	if (current->getLeft() == nullptr && current->getRight() == nullptr) {
		if (current == root) {
			root = nullptr;
		}
		if (current->getData() < prev->getData()) { //Left
			prev->setLeft(nullptr);
			delete current;
		}
		else {
			prev->setRight(nullptr);
			delete current;
		}
	}

	//Case 2 (current var Only 1 Branch - LEFT)
	else if (current->getLeft() != nullptr && current->getRight() == nullptr) {
		if (current->getData() < prev->getData()) {
			prev->setLeft(current->getLeft());
			delete current;
		}
		else {
			prev->setRight(current->getLeft());
			delete current;
		}
	}

	//Case 3 (current var Only 1 Branch - LEFT)
	else if (current->getLeft() == nullptr && current->getRight() != nullptr) {
		if (current->getData() < prev->getData()) {
			prev->setLeft(current->getLeft());
			delete current;
		}
		else {
			prev->setRight(current->getLeft());
			delete current;
		}
	}

	//Case 4 (horror More than 1 branch)
	else {
		cout << "not reached?" << endl;
		CNode* bestOfLeft = nullptr, *bestOfRight = nullptr;
		bestOfLeft = current->getLeft();
		bestOfRight = current->getRight();
		while (bestOfLeft != nullptr) {
			if (bestOfLeft->getRight() != nullptr)
				bestOfLeft = bestOfLeft->getRight();
			else
				break;
		}
		while (bestOfRight != nullptr) {
			if (bestOfRight->getLeft() != nullptr)
				bestOfRight = bestOfRight->getLeft();
			else
				break;
		}

		cout << bestOfLeft->getData() << " dddddd" << endl;
		cout << bestOfRight->getData() << " eeeeeee" << endl;
		cout << current->getData() << " fffffffff" << endl;
		if ( (bestOfRight->getData() - current->getData() ) > (bestOfLeft->getData() - current->getData()) ) { //Left is closer
			int data = bestOfLeft->getData();
			this->remove(bestOfLeft->getData());
			cout << current->getData() << "  dfdd" << endl;
			current->setData(data);
			
		}
		else {
			int data = bestOfRight->getData();
			this->remove(bestOfRight->getData());
			cout << current->getData() << "  dfdd" << endl;
			current->setData(data);
			
		}
	}

	
}



bool CBinaryTree::search(int data) {
	current = root;
	while (current != nullptr) {
		if (current->getLeft() != nullptr && data < current->getData()) {
			current = current->getLeft();
		}
		else if(current->getRight() != nullptr && data > current->getData()) {
			current = current->getRight();
		}
		else {
			break;
		}
		if (current->getData() == data) return true;
	}
	return false;
}

void CBinaryTree::insert(int newVal)
{
	bool done = false;
	CNode* n = new CNode(newVal);

	if (root == nullptr) //bt empty
	{
		root = n;
	}
	else
	{
		current = root;
		while (!done)
		{
			if (newVal < current->getData())
			{
				if (current->getLeft() != nullptr)
				{
					current = current->getLeft();
				}
				else
				{
					current->setLeft(n);
					done = true;
				}
			}
			else
			{
				if (current->getRight() != nullptr)
				{
					current = current->getRight();
				}
				else
				{
					current->setRight(n);
					done = true;
				}
			}
		}
	}
}

void CBinaryTree::inorder(CNode* p)
{
	if (p != NULL)
	{
		inorder(p->getLeft());
		std::cout << p->getData() << std::endl;
		inorder(p->getRight());
	}
}

void CBinaryTree::preorder(CNode* p)
{
	if (p != NULL)
	{
		std::cout << p->getData() << std::endl;
		preorder(p->getLeft());
		preorder(p->getRight());
	}
}

void CBinaryTree::postorder(CNode* p)
{
	if (p != NULL)
	{
		postorder(p->getLeft());
		postorder(p->getRight());
		std::cout << p->getData() << std::endl;
	}
}

CNode* CBinaryTree::getRoot(void)
{
	return root;
}

void CBinaryTree::setRoot(CNode* r)
{
	root = r;
}

CNode* CBinaryTree::getCurrent(void)
{
	return current;
}

void CBinaryTree::setCurrent(CNode* c)
{
	current = c;
}

CNode* CBinaryTree::getPrev(void)
{
	return prev;
}

void CBinaryTree::setPrev(CNode* p)
{
	prev = p;
}