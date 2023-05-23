#pragma once

class DRSprite;
class DRD2DEngine;

class CGroundUnit : public UnitBase
{
public:
	CGroundUnit(int posX, int posY, ePlayer playerIndex);
	~CGroundUnit();

public:
	virtual void Move() override;
	virtual void Attack() override;
	virtual void Update() override;
	virtual void Render(DRD2DEngine* pEngine) override;
	void Render_old(DRD2DEngine* pEngine);


};

