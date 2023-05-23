#pragma once
#include <Windows.h>
#include <vector>
#include "UnitDefine.h"

class ObjectBase;
class UnitBase;
class DRD2DEngine;
class CSpriteManager;

/// <summary>
/// ���� ���� ��� ���ֵ��� ����, ����, �����ϴ� Ŭ����
/// 
/// 2021.05.04 Hyobin
/// </summary>
class CUnitManager
{
public:
	CUnitManager(DRD2DEngine* m_pEngine, HWND hWnd, CSpriteManager* pSpriteManager);
	~CUnitManager();

public:
	// ��ü ���� ó���� ���ش�
	void UpdateAllUnit();	// ������Ʈ
	void RenderAllUnit();	// �׸���
	void RenderStatues();	// ���� �Ŵ����� ���¸� �׸���.

	// �ϳ��� �Լ��� �ٸ� ������ ����
	void CreateBuilding(eBuildingType type, int posX, int posY, ePlayer playerInder, int HP);

	// Ư�� ������ ���� ���ֵ��� �����Ѵ�. 
	void SelectUnits_Area(int left, int top, int right, int bottom);
	void MoveToDestination(int x, int y);
	void SelectUnits_All();

private:
	/// CREATE OBJECT

	// �ǹ�����
	ObjectBase* CreateBuilding1(int posX, int posY);

	void RemoveDeadUnits();
	void RemoveDeadUnits2();

	// ��Ÿ� �ȿ� ���� ���Դ°��� üũ�Ѵ�. 
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
	// ���� ���� �����ϴ� ��� ���� �θ��� ������
	std::vector<ObjectBase*> m_UnitPool; 

	// �׷��Ƚ� ������ ������ �ִ´�.
	DRD2DEngine* m_pEngine;

	// ������ �ڵ鵵 ������ �ִ´�. 
	HWND m_hWnd;

	void Swap(int& a, int& b);
	int GetRand(int base, int randfactor);

	/// ���� ���� ���� ���� �κ�
private:
	CSpriteManager* m_pSpriteManager;

public:
	void CreateUnit_New(eUnitType type, int posX, int posY, float speed, ePlayer playerIndex, int HP);


	/// ������ Ÿ���� �̸����� �ٲٴ� �Լ�
	static std::string ConvertUnitName(eUnitType type);
};

