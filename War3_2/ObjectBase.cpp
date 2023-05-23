#include "ObjectBase.h"

#include "../DRD2DEngine/DRD2DEngine.h"

ObjectBase::ObjectBase(int posX, int posY)
	: m_Index(0), m_Name(""), m_pSpecies(nullptr), m_playerIndex(ePlayer::player1),
	m_HP(0), m_HPMax(0),
	m_Position(posX, posY), m_Destination(posX, posY), // ������
	m_BuildTime(0),
	m_pTarget(nullptr), m_Range(0),
	m_IsSelected(false),
	// FSM�� ���̴� state
	m_NowState(eUnitState::StandBy), m_PrevState(eUnitState::StandBy),
	// �̹��� ����
	m_pSprite(nullptr),m_NowSpritIndex(9)
	/*m_Sprites(0), m_Motions(0), m_UnitMotions(0)*/
{
	// ù ��° ��������Ʈ���� ��� �׸� (���)
	std::vector<DRSprite*> m_Motion1;

	// �� ��° ��������Ʈ���� ��� �׸� (���)
	std::vector<DRSprite*> m_Motion2;

	// ���� �� ���� ����� ��� ���� �ȿ� �ִ´�.
	//m_Motions.push_back(m_Motion1);
	//m_Motions.push_back(m_Motion2);
}

ObjectBase::ObjectBase(int posX, int posY, ePlayer playerIndex)
	: m_Index(0), m_Name(""), m_pSpecies(nullptr), m_playerIndex(playerIndex),
	m_HP(0), m_HPMax(0),
	m_Position(posX, posY), m_Destination(posX, posY), // ������
	m_BuildTime(0),
	m_pTarget(nullptr), m_Range(0),
	m_IsSelected(false),
	// FSM�� ���̴� state
	m_NowState(eUnitState::StandBy), m_PrevState(eUnitState::StandBy),
	// �̹��� ����
	m_pSprite(nullptr), m_NowSpritIndex(9)
	/*m_Sprites(0), m_Motions(0), m_UnitMotions(0)*/
{
	// ù ��° ��������Ʈ���� ��� �׸� (���)
	std::vector<DRSprite*> m_Motion1;

	// �� ��° ��������Ʈ���� ��� �׸� (���)
	std::vector<DRSprite*> m_Motion2;

	// ���� �� ���� ����� ��� ���� �ȿ� �ִ´�.
	//m_Motions.push_back(m_Motion1);
	//m_Motions.push_back(m_Motion2);
}

ObjectBase::~ObjectBase()
{
	m_Name.clear();

	delete m_pSpecies;
	delete m_pTarget;
	delete m_pSprite;

	for(int i = 0; i < 3; ++i)
	{
		delete[] m_Animations[i];
	}
	delete[] m_Animations;
}


void ObjectBase::TempCover()
{
	m_pSprite = m_Motion[0][0];
}

void ObjectBase::SetPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}

CPoint ObjectBase::GetPosition()
{
	return m_Position;
}

void ObjectBase::SetDestination(int x, int y)
{
	m_Destination.x = x;
	m_Destination.y = y;
}

void ObjectBase::SetNowState(eUnitState val)
{
	// ���� ���¸� �����Ѵ�. 
	m_PrevState = m_NowState;
	m_NowState = val;
}

void ObjectBase::DrawSelectedCircle(DRD2DEngine* pEngine)
{
	// ���� �� �����ΰ�? 
	if (m_IsSelected)
	{
		if (m_playerIndex == ePlayer::player1)
		{
			pEngine->SetBrushColor(DRCOLOR_RED);

			pEngine->DrawEllipse(m_Position.x + m_pSprite->Width * 0.5f,
				m_Position.y + m_pSprite->Height * 0.5f, m_pSprite->Width * 0.5f);
		}
		else if (m_playerIndex == ePlayer::player2)
		{
			pEngine->SetBrushColor(DRCOLOR_GREEN);

			pEngine->DrawEllipse(m_Position.x + m_pSprite->Width * 0.5f,
				m_Position.y + m_pSprite->Height * 0.5f, m_pSprite->Width * 0.5f);
		}

	}
}

void ObjectBase::DrawHPBar(DRD2DEngine* pEngine, float value)
{
	float _widttHPBar = (float)m_pSprite->Width * value;

	pEngine->DrawRectangle(m_Position.x, m_Position.y - 32.0f,
		m_Position.x + _widttHPBar, m_Position.y - 30.0f, RGB(0, 255, 0));

	pEngine->DrawRectangle(m_Position.x, m_Position.y - 35.0f,
		m_Position.x + _widttHPBar, m_Position.y - 33.0f, RGB(0, 255, 0));
}

void ObjectBase::DrawName(DRD2DEngine* pEngine, int x, int y)
{
	pEngine->DrawText(x, y, "�̸� : %s", m_Name.c_str());
}

void ObjectBase::CheckDead()
{
	// ���� Ȯ���� ü���� ��´�.
	//if (rand() % 3 == 0)
	//{
	//	m_HP--;
	//
	//}

	if (m_HP <= 0)
	{
		m_HP = 0;
		SetNowState(eUnitState::Dead);
	}
	/// m_HP = MAX(0, m_HP); // ���������� �̷��� ���
}
