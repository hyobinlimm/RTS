#include "UnitBase.h"
#include "CGroundUnit.h"

#include "../DRD2DEngine/DRD2DEngine.h"

CGroundUnit::CGroundUnit(int posX, int posY, ePlayer playerIndex)
	:UnitBase(posX, posY)
{

}

CGroundUnit::~CGroundUnit()
{
}

void CGroundUnit::Move()
{

}

void CGroundUnit::Attack()
{

}

void CGroundUnit::Update()
{
	UnitBase::Update();

	// 모션 넘버를 증가시키는 것
	if (m_Motion[(int)m_NowState].size() <= m_NowSpritIndex)
	{
		m_NowSpritIndex = 0;
	}

	CheckIsArrived();

	switch (GetNowState())
	{
	case eUnitState::StandBy:
	{
		// 오른쪾으롬만 이동한다.
		//m_Position.x += (rand() % 10 - rand() % 10);
	}
		break;
	case eUnitState::Moving:
	{
		// 현재 위치에서 목적지로 이동
		CPoint _moveVec = m_Destination - m_Position;

		_moveVec.Normalize();

		m_Position = m_Position + (_moveVec * m_Speed);
	}
	break;

	default:
	{
	}
	break;
	}
	
	// 죽음을 체크
	CheckDead();

}

void CGroundUnit::Render_old(DRD2DEngine* pEngine)
{
	// 공통적으로 해야하는 일
	//UnitBase::Render(pEngine);
	
	int _motionIndex = 0;

	if (GetNowState() == eUnitState::StandBy)
	{
		_motionIndex = 0;
	} 
	else if(GetNowState() == eUnitState::Moving)
	{
		_motionIndex = 1;
	}

	// 얘만 하는 일
	pEngine->DrawSprite(m_Animations[_motionIndex][m_NowSpritIndex], m_Position.x, m_Position.y);

	// 현재 상태를 나타내준다.
	DrawState(pEngine);

	// 이동 라인을 그려준다. 
	DrawMoveLine(pEngine);

	// 선택 되었는가?
	if (GetIsSelected())
	{
		pEngine->DrawEllipse(m_Position.x, m_Position.y, 40);
	}

	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);
}

void CGroundUnit::Render(DRD2DEngine* pEngine)
{
	// 모션을 얻는다.

	//SpriteVector _nowMotion = m_Motion[m_NowState];


	// 그리는 부분
	pEngine->DrawSprite(m_Motion[(int)m_NowState][m_NowSpritIndex], m_Position.x, m_Position.y);



}
