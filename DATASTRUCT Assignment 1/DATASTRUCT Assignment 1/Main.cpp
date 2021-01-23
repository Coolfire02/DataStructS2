#include <iostream>
#include <Windows.h>
#include "CPath.h"

using namespace std;
void gotoxy(int, int);
void printUI(CPath&, int&);

int main(void) {

	CPath list;
	for (int i = 0; i < 50; i++) {
		list.addToFront('o');
	}
	int cursorIndex = 0;
	
	printUI(list, cursorIndex);

	while (true) {
		char keyPressed = 0;
		if (GetKeyState('1') & 0x8000)
			keyPressed = '1';
		else if (GetKeyState('2') & 0x8000)
			keyPressed = '2';
		else if (GetKeyState('3') & 0x8000)
			keyPressed = '3';
		else if (GetKeyState('4') & 0x8000)
			keyPressed = '4';

		if (cursorIndex > list.getSize()-1) cursorIndex = (list.getSize() > 0 ? list.getSize()-1 : 0);

		if (keyPressed != 0) { //Improves efficiency of code by not updating map when no new key input is found (As only when there is key input would there be a change in the map)
			if (keyPressed == '1' && cursorIndex > 0) {
				cursorIndex--;
			}
			else if (keyPressed == '2' && cursorIndex < list.getSize() - 1) {
				cursorIndex++;
			}
			else if (keyPressed == '3') {
				list.addNode((cursorIndex > 0 ? cursorIndex+1 : 0), 'w'); //+1 Due to assignment specifications
			}
			else if (keyPressed == '4') {
				list.removeNode(cursorIndex);
			}

			printUI(list, cursorIndex);
			Sleep(75);
		}
	}
	
	return 0;
}

void printUI(CPath &list, int &cursorIndex) {
	//Flush
	gotoxy(0, 0);
	int row = (int) ceil(list.getSize() / 20.0) * 2 + 6;
	for (int i = 0; i < row; i++)
		cout << "                                                   " << endl;

	//Print UI
	gotoxy(0, 0);
	cout << "1-2-3-4-5-6-7-8-9-0-1-2-3-4-5-6-7-8-9-0" << endl;
	cout << "---------------------------------------" << endl;
	int index = 0;
	for (auto& element : list.toVector()) {
		if (cursorIndex >= list.getSize() && cursorIndex > 0)
			cursorIndex = list.getSize() - 1;
		cout << element;
		if ((index + 1) % 20 == 0 || index == list.getSize() - 1) {
			cout << endl;
			int row = (int) floor(index / 20.0) + 1;
			for (int i = 0 + ((row - 1) * 20); i < row * 20; i++) {
				if (i == cursorIndex)
					cout << "^";
				else
					cout << " ";
				if (i != row * 20 - 1)
					cout << " ";
			}
			cout << endl;
		}
		else if ((index + 1) % 20 != 0 && list.getSize() != index + 1) {
			cout << "-";
		}

		index++;
	}
	cout << endl;
	cout << "Choice->Bck(1) Fwd(2) AddNode(3) DelNode(4):";
	//Debug cout << cursorIndex << " " << list.getSize();
}

void gotoxy(int x, int y) {
	COORD scrn;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x; scrn.Y = y;
	SetConsoleCursorPosition(hConsoleOutput, scrn);
}