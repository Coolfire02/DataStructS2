#include <iostream>

using namespace std;

void toDecendingOrder(int* list, int length) {
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < length - i; j++) {
			if (list[j] < list[j + 1]) {
				int temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}

void toAscendingOrder(int* list, int length) {
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < length - i; j++) {
			if (list[j + 1] < list[j]) {
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}

int main(void) {

	int list[10] = { 34, 45, 12, 2, 456, 78, 103, 423, 67, 4 };
	toDecendingOrder(list, sizeof(list) / sizeof(list[0]));

	for (int i = 0; i < 10; i++) {
		cout << list[i] << " ";
	}


	return 0;
}