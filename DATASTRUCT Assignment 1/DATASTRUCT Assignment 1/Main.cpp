#include <iostream>
#include <Windows.h>
#include "DoublyLinkedList.h"


using namespace std;
void gotoxy(int, int);

int main(void) {

	DoublyLinkedList list;
	for (int i = 0; i < 48; i++) {
		list.addToFront('o');
	}
	list.addToFront('S');
	list.addToBack('E');
	int cursorIndex = 0;

	while (true) {
		gotoxy(0, 0);
		cout << "1-2-3-4-5-6-7-8-9-0-1-2-3-4-5-6-7-8-9-0" << endl;
		cout << "---------------------------------------" << endl;
		int index = 0;
		for (auto& element : list.toVector()) {
			cout << element;
			
			if (index % 20 == 0) {
				cout << endl;
			}
			else {
				cout << "-";
			}

			index++;
		}

		Sleep(50);
	}
	
	return 0;
}



void gotoxy(int x, int y) {
	COORD scrn;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x; scrn.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, scrn);
}