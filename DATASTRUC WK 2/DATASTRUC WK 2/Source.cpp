#include <iostream>
#include "CNode.h"
#include "CLinkList.h"

using namespace std;

int main(void) {


	CLinkList list;

	list.addToBack(10);
	list.addToBack(20);
	list.addToBack(15);
	list.addToBack(5);
	list.addToFront(100);
	list.addToBack(300);
	list.deleteBack();
	list.deleteBack();
	list.deleteFront();

	cout << "size of list " << list.size() << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << "index "<< i << " " << list.get(i) << endl;
	}

	return 0;
}