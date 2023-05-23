#pragma once
#include "UnitDefine.h"
#include <vector>
#include <string>

#define spriteMAX		10

class DRD2DEngine;
class DRSprite;

/// <summary>
/// ��� Object�� �ֻ��� �θ�
/// 
/// 2021.05.04 Hyobin
/// </summary>
class ObjectBase
{
public:
	ObjectBase(int posX, int posY);
	ObjectBase(int posX, int posY, ePlayer playerIndex);

	virtual ~ObjectBase();

protected:
	/// ��ΰ� ��� �ִ� �⺻ ����.

	// �̸�
	std::string m_Name;

	// ����, �÷��̾�
	int m_Index; // ����ũ�� �ε���
	eSpecies* m_pSpecies;
	ePlayer m_playerIndex;

	// ü�¹�
	int m_HP;
	int m_HPMax;

	// ��������
	int m_BuildTime;

	// ���� ���� ���� �κ�
	bool m_IsSelected;

	//------------------------------------------
	// ���ݰ���
	ObjectBase* m_pTarget;

	// ����
	float m_Range;
	//------------------------------------------

	//------------------------------------------
	// �̵� �� �ǹ� ���� ������
	CPoint m_Position;

	// ������
	CPoint m_Destination;
	//------------------------------------------

	/// FSM�� ���̴� state
	eUnitState m_NowState;	// ���� �̵� ����

public:
	eUnitState m_PrevState; // ���� ����

	//------------------------------------------
	//------------------------------------------
	// �̹��� ���� ����
	// �ڽ��� �̹��� ������ ������ ����
	DRSprite* m_pSprite;
	DRSprite* m_Animations[3][10]; // ��������Ʈ�� �̷���� �ִϸ��̼�
	int m_NowSpritIndex;

	/// ���� ���� ��������Ʈ ü��
protected:
	MotionsVector m_Motion;

public:
	//MotionsVector GetMotion() const { return m_Motion; }
	void SetMotion(MotionsVector val) { m_Motion = val; }

	void TempCover();

public:
	int GetIndex() const { return m_Index; }
	void SetIndex(int val) { m_Index = val; }

	std::string GetName() const { return m_Name; }
	void SetName(std::string val) { m_Name = val; }

	ePlayer GetPlayerIndex() const { return m_playerIndex; }
	void SetPlayerIndex(ePlayer val) { m_playerIndex = val; }

	int GetHP() const { return m_HP; }
	void SetHP(int val) { m_HP = val; }

	int GetHPMax() const { return m_HPMax; }
	void SetHPMax(int val) { m_HPMax = val; m_HP = m_HPMax; }

	void SetPosition(int x, int y);
	CPoint GetPosition();

	bool GetIsSelected() const { return m_IsSelected; }
	void SetIsSelected(bool val) { m_IsSelected = val; }

	ObjectBase* GetTarget() const { return m_pTarget; }
	void SetTarget(ObjectBase* val) { m_pTarget = val; }

	float GetRange() const { return m_Range; }
	void SetRange(float val) { m_Range = val; }

	void SetDestination(int x, int y);

	eUnitState GetNowState() const { return m_NowState; }
	void SetNowState(eUnitState val); /*{ m_NowState = val; }*/

	virtual void Update() = 0;
	virtual void Render(DRD2DEngine* pEngine) = 0;

	// ���� �Ǿ��°�?
	void DrawSelectedCircle(DRD2DEngine* pEngine);
	
	// ü�¹� �׸���
	void DrawHPBar(DRD2DEngine* pEngine, float value);

	// �̸��� �׸���.
	void DrawName(DRD2DEngine* pEngine, int x, int y);

protected:
	// �׾��°�?
	void CheckDead();

};

