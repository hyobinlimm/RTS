#pragma once
#include <windows.h>
#include <string>
#include "UnitDefine.h"
#include "ObjectBase.h"
#include "CSpriteManager.h"

class DRSprite;
class DRD2DEngine;

/// <summary>
/// Unit의 최상위 부모
/// 
/// 2021.05.04 Big Hyobin
/// </summary>
class UnitBase : public ObjectBase
{
public:
	UnitBase(int PosX, int PosY);

	UnitBase(int posX, int posY, ePlayer playerIndex);

	~UnitBase();
	
	int GetAttackDamage() const { return m_AttackDamage; }
	void SetAttackDamage(int val) { m_AttackDamage = val; }
	
protected:

	/// 기본정보 ------
	eUnitType* m_pUnitType;		// enum 클래스로 이름을 가져 올 수 있지 않을까? 

	int LV;

	int m_MP;
	/// ---------------

	/// 이동관련-------
	float m_Speed;
	/// ---------------
	
	/// 공격관련
	int m_HinPoint;
	
	float m_Armor;
	
	float m_Sight;
	float m_nightSight;

	int m_AttackDamage;

	int m_CoolDown;				// 유닛과 건물의 생성 후 재생성 시간 

public:
	virtual void Move();
	virtual void Attack(ObjectBase* target);
	virtual void Update();
	virtual void Render(DRD2DEngine* pEngine);

	/// 이동을 위한 부분----------
	void SetSpeed(float val) { m_Speed = val; }
	/// -------------------------


protected:
	void DrawState(DRD2DEngine* pEngine);
	void DrawMoveLine(DRD2DEngine* pEngine);

	void CheckIsArrived(eUnitState& nowStatus);
};

