#pragma once
#include <windows.h>

#include "CUnitManager.h"
#include "CSpriteManager.h"
#include "d2d1.h"
//#include "../D2Engine/D2Engine.h"
#include "../DRD2DEngine/DRD2DEngine.h"
#include "UnitDefine.h"


#pragma comment(lib, "d2d1")
//#pragma comment(lib, "../Debug/D2Engine.lib")
#pragma comment(lib, "../Debug/DRD2DEngine.lib")



// ���� ������ ��� ��
class GameManager
{
public:
	GameManager();
	~GameManager();

	void Initialize(HWND hWnd, int screenWidth, int screenHeight);
	void Update();
	void Render();

private:

	/// �������� ����
	// ȭ���� ũ��
	int m_ScreenWidth;
	int m_ScreenHeight;

	// ���� ����
	HWND m_hWnd;

	// �׷��Ƚ� ����
	//D2Engine* m_pD2Engine;
	DRD2DEngine* m_pD2Engine;
	CUnitManager* m_pUnitManager;
	CSpriteManager* m_pSpriteManager;

	/// Ű �Է�
	bool m_KeyUp;
	bool m_KeyDown;
	bool m_KeyLeft;
	bool m_KeyRight;

	
};

