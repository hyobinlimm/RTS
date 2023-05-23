#pragma once
#include "UnitBase.h"

class DRSprite;
class DRD2DEngine;

class CAirUnit : public UnitBase
{
public:
	CAirUnit(int posX, int posY, ePlayer playerIndex);
	~CAirUnit();
	
public:
	virtual void Move() override;
	virtual void Attack() override;
	virtual void Update() override;
	virtual void Render(DRD2DEngine* pEngine) override;

};

