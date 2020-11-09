#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(void) {
		
	LinkedList list;
	list.addToFront(1); //index 1
	list.addToFront(15); //index 0
	list.addToBack(7); //index 3
	list.addToBack(8); //index 4
	list.addNode(2, 200); //index 2

	list.printReverse(list.first);

	/*for (int i = 0; i < list.getSize(); i++) {
		cout << list.get(i) << endl;
	}
	*/
	return 0;
}