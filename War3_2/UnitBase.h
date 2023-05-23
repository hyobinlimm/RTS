#pragma once
#include <windows.h>
#include <string>
#include "UnitDefine.h"
#include "ObjectBase.h"
#include "CSpriteManager.h"

class DRSprite;
class DRD2DEngine;

/// <summary>
/// Unit�� �ֻ��� �θ�
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

	/// �⺻���� ------
	eUnitType* m_pUnitType;		// enum Ŭ������ �̸��� ���� �� �� ���� ������? 

	int LV;

	int m_MP;
	/// ---------------

	/// �̵�����-------
	float m_Speed;
	/// ---------------
	
	/// ���ݰ���
	int m_HinPoint;
	
	float m_Armor;
	
	float m_Sight;
	float m_nightSight;

	int m_AttackDamage;

	int m_CoolDown;				// ���ְ� �ǹ��� ���� �� ����� �ð� 

public:
	virtual void Move();
	virtual void Attack(ObjectBase* target);
	virtual void Update();
	virtual void Render(DRD2DEngine* pEngine);

	/// �̵��� ���� �κ�----------
	void SetSpeed(float val) { m_Speed = val; }
	/// -------------------------


protected:
	void DrawState(DRD2DEngine* pEngine);
	void DrawMoveLine(DRD2DEngine* pEngine);

	void CheckIsArrived(eUnitState& nowStatus);
};

