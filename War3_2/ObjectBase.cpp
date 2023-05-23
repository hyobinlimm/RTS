#include "ObjectBase.h"

#include "../DRD2DEngine/DRD2DEngine.h"

ObjectBase::ObjectBase(int posX, int posY)
	: m_Index(0), m_Name(""), m_pSpecies(nullptr), m_playerIndex(ePlayer::player1),
	m_HP(0), m_HPMax(0),
	m_Position(posX, posY), m_Destination(posX, posY), // 목적지
	m_BuildTime(0),
	m_pTarget(nullptr), m_Range(0),
	m_IsSelected(false),
	// FSM에 쓰이는 state
	m_NowState(eUnitState::StandBy), m_PrevState(eUnitState::StandBy),
	// 이미지 정보
	m_pSprite(nullptr),m_NowSpritIndex(9)
	/*m_Sprites(0), m_Motions(0), m_UnitMotions(0)*/
{
	// 첫 번째 스프라이트들을 담는 그릇 (모션)
	std::vector<DRSprite*> m_Motion1;

	// 두 번째 스프라이트들을 담는 그릇 (모션)
	std::vector<DRSprite*> m_Motion2;

	// 위의 두 개를 모션을 담는 벡터 안에 넣는다.
	//m_Motions.push_back(m_Motion1);
	//m_Motions.push_back(m_Motion2);
}

ObjectBase::ObjectBase(int posX, int posY, ePlayer playerIndex)
	: m_Index(0), m_Name(""), m_pSpecies(nullptr), m_playerIndex(playerIndex),
	m_HP(0), m_HPMax(0),
	m_Position(posX, posY), m_Destination(posX, posY), // 목적지
	m_BuildTime(0),
	m_pTarget(nullptr), m_Range(0),
	m_IsSelected(false),
	// FSM에 쓰이는 state
	m_NowState(eUnitState::StandBy), m_PrevState(eUnitState::StandBy),
	// 이미지 정보
	m_pSprite(nullptr), m_NowSpritIndex(9)
	/*m_Sprites(0), m_Motions(0), m_UnitMotions(0)*/
{
	// 첫 번째 스프라이트들을 담는 그릇 (모션)
	std::vector<DRSprite*> m_Motion1;

	// 두 번째 스프라이트들을 담는 그릇 (모션)
	std::vector<DRSprite*> m_Motion2;

	// 위의 두 개를 모션을 담는 벡터 안에 넣는다.
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
	// 이전 상태를 보관한다. 
	m_PrevState = m_NowState;
	m_NowState = val;
}

void ObjectBase::DrawSelectedCircle(DRD2DEngine* pEngine)
{
	// 선택 된 상태인가? 
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
	pEngine->DrawText(x, y, "이름 : %s", m_Name.c_str());
}

void ObjectBase::CheckDead()
{
	// 일정 확률로 체력을 깎는다.
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
	/// m_HP = MAX(0, m_HP); // 관용적으로 이렇게 사용
}
