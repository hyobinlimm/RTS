#pragma once
#include "ObjectBase.h"

class DRD2Dengine;

class CBuilding : public ObjectBase
{
public:
	CBuilding(int posX, int posY, ePlayer playerIndex);
	~CBuilding();
	
private:
	//ObjectBase* m_pObjectBase;

public:
	//virtual void Move() override;
	//virtual void Attack() override;
	virtual void Update() override;
	virtual void Render(DRD2DEngine* pEngine)override;
};

