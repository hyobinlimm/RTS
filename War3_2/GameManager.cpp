#include "GameManager.h"

GameManager::GameManager()
	:m_ScreenWidth(0), m_ScreenHeight(0),
	m_hWnd(nullptr),
	m_pD2Engine(nullptr), m_pUnitManager(nullptr),
	m_KeyUp(nullptr), m_KeyDown(nullptr), m_KeyLeft(nullptr), m_KeyRight(nullptr)
{

}

GameManager::~GameManager()
{

}

void GameManager::Initialize(HWND hWnd, int screenWidth, int screenHeight)
{
	m_hWnd = hWnd;
	// ȭ�� ũ��
	m_ScreenWidth = screenWidth;
	m_ScreenHeight = screenHeight;

	/// �׷��Ƚ� ���� ����

	// �׷��Ƚ� ���� �ʱ�ȭ
	//m_pD2Engine = new D2Engine();
	m_pD2Engine = new DRD2DEngine();
	m_pD2Engine->Initialize(nullptr, hWnd, screenWidth, screenHeight);

	// �̹��� ����
	m_pSpriteManager = new CSpriteManager(m_pD2Engine);
	m_pSpriteManager->Initialize();

	// ���� ����
	m_pUnitManager = new CUnitManager(m_pD2Engine, hWnd, m_pSpriteManager);

	// �⺻���� ������ ������ ������ش�.
	m_pUnitManager->CreateBuilding(eBuildingType::TreeOfLife, 300, 500, ePlayer::player1, 3000);
}

void GameManager::Update()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8001)
	{
		SendMessage(m_hWnd, WM_DESTROY, 0, 0);
	}

	m_pUnitManager->UpdateAllUnit();
}

void GameManager::Render()
{
	m_pD2Engine->BeginRender();	// �� �ܰ�� ���� 

	m_pSpriteManager->Render();

	m_pUnitManager->RenderAllUnit();
	m_pUnitManager->RenderStatues();

	m_pD2Engine->EndRender();
}
