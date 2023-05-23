#pragma once
#include <Windows.h>
#include <vector>
#include "UnitDefine.h"

class ObjectBase;
class UnitBase;
class DRD2DEngine;
class CSpriteManager;

/// <summary>
/// 게임 내의 모든 유닛들을 생성, 삭제, 관리하는 클래스
/// 
/// 2021.05.04 Hyobin
/// </summary>
class CUnitManager
{
public:
	CUnitManager(DRD2DEngine* m_pEngine, HWND hWnd, CSpriteManager* pSpriteManager);
	~CUnitManager();

public:
	// 전체 유닛 처리를 해준다
	void UpdateAllUnit();	// 업데이트
	void RenderAllUnit();	// 그리기
	void RenderStatues();	// 유닛 매니저의 상태를 그린다.

	// 하나의 함수로 다른 유닛을 생성
	void CreateBuilding(eBuildingType type, int posX, int posY, ePlayer playerInder, int HP);

	// 특정 범위에 들어온 유닛들을 선택한다. 
	void SelectUnits_Area(int left, int top, int right, int bottom);
	void MoveToDestination(int x, int y);
	void SelectUnits_All();

private:
	/// CREATE OBJECT

	// 건물생성
	ObjectBase* CreateBuilding1(int posX, int posY);

	void RemoveDeadUnits();
	void RemoveDeadUnits2();

	// 사거리 안에 적이 들어왔는가를 체크한다. 
	UnitBase* CheckEnemyIsSpotted();

	void SetPlayerIndex(UnitBase* nuit ,ePlayer index);

	// render
private:
	void DrawSelectBox();

private:

	void UserInput();

	POINT m_NowMousePos;

	POINT m_DragStartPos;

	bool m_LeftButtonDown;
	bool m_RightButtonDown;

	bool m_IsLeftDragging;

private:
	// 게임 내에 존재하는 모든 유닛 부모의 포인터
	std::vector<ObjectBase*> m_UnitPool; 

	// 그래픽스 엔진을 가지고 있는다.
	DRD2DEngine* m_pEngine;

	// 윈도우 핸들도 가지고 있는다. 
	HWND m_hWnd;

	void Swap(int& a, int& b);
	int GetRand(int base, int randfactor);

	/// 새로 만든 유닛 생성 부분
private:
	CSpriteManager* m_pSpriteManager;

public:
	void CreateUnit_New(eUnitType type, int posX, int posY, float speed, ePlayer playerIndex, int HP);


	/// 유닛의 타입을 이름으로 바꾸는 함수
	static std::string ConvertUnitName(eUnitType type);
};

