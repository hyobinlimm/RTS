#pragma once
#include "UnitDefine.h"
#include <vector>
#include <string>

#define spriteMAX		10

class DRD2DEngine;
class DRSprite;

/// <summary>
/// 모든 Object의 최상위 부모
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
	/// 모두가 들고 있는 기본 정보.

	// 이름
	std::string m_Name;

	// 종족, 플레이어
	int m_Index; // 유니크한 인덱스
	eSpecies* m_pSpecies;
	ePlayer m_playerIndex;

	// 체력바
	int m_HP;
	int m_HPMax;

	// 생성관련
	int m_BuildTime;

	// 유닛 선택 관련 부분
	bool m_IsSelected;

	//------------------------------------------
	// 공격관련
	ObjectBase* m_pTarget;

	// 범위
	float m_Range;
	//------------------------------------------

	//------------------------------------------
	// 이동 및 건물 생성 포지션
	CPoint m_Position;

	// 목적지
	CPoint m_Destination;
	//------------------------------------------

	/// FSM에 쓰이는 state
	eUnitState m_NowState;	// 현재 이동 상태

public:
	eUnitState m_PrevState; // 이전 상태

	//------------------------------------------
	//------------------------------------------
	// 이미지 정보 관련
	// 자신의 이미지 정보를 가지고 있음
	DRSprite* m_pSprite;
	DRSprite* m_Animations[3][10]; // 스프라이트로 이루어진 애니메이션
	int m_NowSpritIndex;

	/// 새로 만든 스프라이트 체계
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

	// 선택 되었는가?
	void DrawSelectedCircle(DRD2DEngine* pEngine);
	
	// 체력바 그리기
	void DrawHPBar(DRD2DEngine* pEngine, float value);

	// 이름을 그린다.
	void DrawName(DRD2DEngine* pEngine, int x, int y);

protected:
	// 죽었는가?
	void CheckDead();

};

