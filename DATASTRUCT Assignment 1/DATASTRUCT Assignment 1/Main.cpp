#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(void) {

	DoublyLinkedList list;

	for (int i = 0; i < list.getSize(); i++) {
		cout << list.get(i) << endl;
	}
	
	return 0;
}