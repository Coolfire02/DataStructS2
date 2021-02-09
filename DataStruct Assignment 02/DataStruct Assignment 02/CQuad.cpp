#include "CQuad.h"
#include <iostream>

CQuad::CQuad(QUADTYPE type, CPosition minPos, CPosition maxPos) : 
	type(type), BotL(nullptr), BotR(nullptr), TopL(nullptr), TopR(nullptr),
	minPos(minPos), GO_Count(0), maxPos(maxPos), parent(nullptr)
{
}

CQuad::~CQuad() {
	if (!GOList.empty()) {
		for (auto p : GOList) {
			delete p;
		}
		GOList.clear();
	}
}

int CQuad::getCount() {
	return GO_Count;
}

CPosition CQuad::getMinPos() {
	return minPos;
}

CPosition CQuad::getMaxPos() {
	return maxPos;
}

/*
This function should only be called when you are a the correct CQuad. Finding the correct CQuad should be handled by CGOManager
*/
void CQuad::addCGO(CGO* cgo) {
	if (GO_Count++ <= 3) {
		this->GOList.push_back(cgo);
		if (GO_Count == 4) { //Starting splitting

			for (auto& entry : GOList) {
				CPosition maxPos, minPos;
				maxPos = this->maxPos;
				minPos = this->minPos;
				int xSize = (maxPos.getX() - minPos.getX());
				int ySize = (maxPos.getY() - minPos.getY());
				int xOffset = xSize % 2;
				int yOffset = ySize % 2;

				int xMid = minPos.getX() + (xSize / 2);
				int yMid = minPos.getY() + (ySize / 2);

				//Top Left
				if (entry->getX() < xMid && entry->getY() < yMid) {
					maxPos.setX(xMid);
					maxPos.setY(yMid);
					if (TopL == nullptr)
						TopL = new CQuad(QUADTYPE::E_TOPL, minPos, maxPos);
					TopL->addCGO(entry);
				} //Top Right
				else if (entry->getX() >= xMid && entry->getY() < yMid) {
					minPos.setX(xMid);
					maxPos.setY(yMid);
					if (TopR == nullptr)
						TopR = new CQuad(QUADTYPE::E_TOPR, minPos, maxPos);
					TopR->addCGO(entry);
				} //Bottom Left
				else if (entry->getX() < xMid && entry->getY() >= yMid) {
					maxPos.setX(xMid);
					minPos.setY(yMid);
					if (BotL == nullptr)
						BotL = new CQuad(QUADTYPE::E_BOTL, minPos, maxPos);
					BotL->addCGO(entry);
				} //Bottom Right
				else if (entry->getX() >= xMid && entry->getY() >= yMid) {
					minPos.setX(xMid);
					minPos.setY(yMid);
					if (BotR == nullptr)
						BotR = new CQuad(QUADTYPE::E_BOTR, minPos, maxPos);
					BotR->addCGO(entry);
				}
			}
			GOList.clear(); //Not needed anymore as all will be distributed into smaller cells
		}
	}
}



bool CQuad::isInQuadRange(CPosition pos) {
	if (minPos.getX() >= pos.getX() && pos.getX() < maxPos.getX()
		&& minPos.getY() >= pos.getY() && pos.getY() < maxPos.getY())
		return true;
	return false;
}

void CQuad::printGOsInside() {
	
}

std::vector<CGO*> CQuad::getCGOList() {
	return GOList;
}

void CQuad::setParent(CQuad* quad) {
	this->parent = quad;
}

void CQuad::setTopL(CQuad* quad) {
	this->TopL = quad;
}

void CQuad::setTopR(CQuad* quad) {
	this->TopR = quad;
}

void CQuad::setBotR(CQuad* quad) {
	this->BotR = quad;
}

void CQuad::setBotL(CQuad* quad) {
	this->BotL = quad;
}

CQuad* CQuad::getParent() {
	return this->parent;
}

CQuad* CQuad::getTopL() {
	return this->TopL;
}

CQuad* CQuad::getBotL() {
	return this->BotL;
}

CQuad* CQuad::getTopR() {
	return this->TopR;
}

CQuad* CQuad::getBotR() {
	return this->BotR;
}

QUADTYPE CQuad::getType() {
	return this->type;
}
