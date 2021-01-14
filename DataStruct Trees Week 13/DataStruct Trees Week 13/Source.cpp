//50,91,16,57,12,72,82,78,86,96,36,9,6,45,3
#include <iostream>
#include "CBinaryTree.h"

using namespace std;

int main(void)
{
	int input;
	CBinaryTree* bt = new CBinaryTree;

	bt->insert(50);
	bt->insert(30);
	bt->insert(53);
	bt->insert(35);
	bt->insert(57);
	bt->insert(32);
	bt->insert(40);
	bt->insert(48);

	bt->remove(50);

	cout << "Search 6" << endl;
	cout << "===================" << endl;

	cout << bt->search(6) << endl;

	cout << "Inorder traversal" << endl;
	cout << "===================" << endl;

	bt->inorder(bt->getRoot());

	cout << endl;
	cout << endl;

	cout << "Preorder traversal" << endl;
	cout << "===================" << endl;

	bt->preorder(bt->getRoot());

	cout << endl;
	cout << endl;

	cout << "Postorder traversal" << endl;
	cout << "===================" << endl;

	bt->postorder(bt->getRoot());



	return 0;
}