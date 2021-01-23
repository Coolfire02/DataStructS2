#include "CGOManager.h"
#include <iostream>
#include <vector>

CGOManager::CGOManager() {
	root = nullptr;
	xSize = 200;
	ySize = 200;
}

CGOManager::CGOManager(int x, int y) {
	root = nullptr;
	xSize = x;
	ySize = y;
}

CGOManager::~CGOManager() { //call to delete since uhfo in source
	//deletePostOrder(root);
	this->PrintTree();
}

void CGOManager::deletePostOrder(CQuad* quad) {
	if (quad != nullptr) {
		deletePostOrder(quad->getTopL());
		deletePostOrder(quad->getTopR());
		deletePostOrder(quad->getBotL());
		deletePostOrder(quad->getBotR());
		if(quad != root) //dont forget to remove
			delete quad;
	}
}

void CGOManager::addCGO(CGO* cgo) {
	if (root == nullptr)
		root = new CQuad(QUADTYPE::E_ROOT, CPosition(0,0), CPosition(xSize,ySize));

	//Handles insertion here
	CQuad* quad = root;

	CPosition minPos, maxPos;
	minPos = quad->getMinPos();
	maxPos = quad->getMaxPos();
	int count = quad->getCount();
	while (count > 3) { 
		int xSize = (maxPos.getX() - minPos.getX());
		int ySize = (maxPos.getY() - minPos.getY());
		if (xSize <= 1 || ySize <= 1) break;

		quad->addCGO(cgo); //add to Current Quad since this function will only ++ GO_Count in that quad and not add to it

		int xOffset = xSize % 2;
		int yOfferset = ySize % 2;
		
		CQuad* moveQuad = nullptr;

		//Top Left
		if (cgo->getX() < xSize / 2 && cgo->getY() < ySize / 2) {
			maxPos.setX(xSize / 2);
			maxPos.setY(ySize / 2);
			if (quad->getTopL() == nullptr)
				quad->setTopL(new CQuad(QUADTYPE::E_TOPL, minPos, maxPos));
			moveQuad = quad->getTopL();

		} //Top Right
		else if (cgo->getX() >= xSize / 2 && cgo->getY() < ySize / 2) {
			minPos.setX(xSize / 2);
			maxPos.setY(ySize / 2);
			if (quad->getTopR() == nullptr)
				quad->setTopR(new CQuad(QUADTYPE::E_TOPR, minPos, maxPos));
			moveQuad = quad->getTopR();
		} //Bottom Left
		else if (cgo->getX() < xSize / 2 && cgo->getY() >= ySize / 2) {
			maxPos.setX(xSize / 2);
			minPos.setY(ySize / 2);
			if (quad->getBotL() == nullptr)
				quad->setBotL(new CQuad(QUADTYPE::E_BOTL, minPos, maxPos));
			moveQuad = quad->getBotL();
		} //Bottom Right
		else if (cgo->getX() >= xSize / 2 && cgo->getY() >= ySize / 2) {
			minPos.setX(xSize / 2);
			minPos.setY(ySize / 2);
			if (quad->getBotR() == nullptr)
				quad->setBotR(new CQuad(QUADTYPE::E_BOTR, minPos, maxPos));
			moveQuad = quad->getBotR();
		}
		if (moveQuad == nullptr)
			break;
		
		quad = moveQuad;
		count = quad->getCount(); //Used moveQuad to debug code earlier as there was stackoverflow error, this code seems fine so I'll keep it.
	}
	quad->addCGO(cgo); //Add to the "Correct Quad" that dosen't have enough to split just yet. If it reaches 4 CGOs after this addition, the split is then handled at CQuad.cpp.
}

void CGOManager::PrintTree() {
	PrintTreeInOrder(root, 0, true);
}

void CGOManager::PrintTreeInOrder(CQuad* quad, int row, bool showIndividualCGO) {
	if (quad != nullptr) {
		for (int i = 0; i < row; i++)
			std::cout << " ";
		std::cout << row << "-";
		switch (quad->getType()) {
		case QUADTYPE::E_ROOT:
			std::cout << "Root";
			break;
		case QUADTYPE::E_TOPL:
			std::cout << "TopL";
			break;
		case QUADTYPE::E_TOPR:
			std::cout << "TopR";
			break;
		case QUADTYPE::E_BOTL:
			std::cout << "BotL";
			break;
		case QUADTYPE::E_BOTR:
			std::cout << "BotR";
			break;
		}
		std::cout << " (" << quad->getCount() << ")";
		if (showIndividualCGO && quad->getCount() < 4) {
			std::cout << " IDs:[";
			std::vector<CGO*> cgos = quad->getCGOList();
			std::vector<CGO*>::iterator iter, end;
			for (iter = cgos.begin(), end = cgos.end(); iter != end; ++iter) {
				std::cout << (*iter)->getID() << (iter+1 != end ? ", ":"");
			}
			std::cout << "]";
		}
		std::cout << std::endl;
			
		PrintTreeInOrder(quad->getTopL(), row + 1, showIndividualCGO);
		PrintTreeInOrder(quad->getTopR(), row + 1, showIndividualCGO);
		PrintTreeInOrder(quad->getBotL(), row + 1, showIndividualCGO);
		PrintTreeInOrder(quad->getBotR(), row + 1, showIndividualCGO);
	}
}




