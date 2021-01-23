#pragma once
#include "CGO.h"
#include <vector>

enum class QUADTYPE {
	E_ROOT,

	E_TOPL,
	E_TOPR,
	E_BOTL,
	E_BOTR,
};

class CQuad
{	
	int GO_Count;
	CPosition minPos, maxPos; //Min values are inclusive, Max values are exclusive. Considered implementing range checks in GOManager without storing in quad, but this seemed like a better idea.
	const QUADTYPE type;
	CQuad *parent, *TopL, *TopR, *BotL, *BotR;
	std::vector<CGO*> GOList; //Will not have GOs if already > 3, will split into new CQuads.

public:
	void printGOsInside();

	QUADTYPE getType();

	bool isInQuadRange(CPosition pos); //Is position specified in this Quad Range
	void addCGO(CGO*);

	std::vector<CGO*> getCGOList();

	CPosition getMinPos();
	CPosition getMaxPos();

	int getCount();

	void setParent(CQuad*);
	void setTopL(CQuad*);
	void setTopR(CQuad*);
	void setBotL(CQuad*);
	void setBotR(CQuad*);

	CQuad* getParent();
	CQuad* getTopL();
	CQuad* getTopR();
	CQuad* getBotL();
	CQuad* getBotR();

	CQuad(QUADTYPE, CPosition, CPosition);
	~CQuad();
};

