#include "CGOManager.h"

int main(void) {
	CGOManager manager(200,200);
	manager.addCGO(new CGO(1, 25, 120));
	manager.addCGO(new CGO(2, 20, 99));
	manager.addCGO(new CGO(3, 50, 75));
	manager.addCGO(new CGO(5, 30, 30));
	manager.addCGO(new CGO(6, 35, 35));
	manager.addCGO(new CGO(4, 55, 60));
	manager.PrintTree();

	return 0;
}