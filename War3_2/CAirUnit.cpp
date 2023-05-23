#include "CAirUnit.h"

#include "../DRD2DEngine/DRD2DEngine.h"

CAirUnit::CAirUnit(int posX, int posY, ePlayer playerIndex)
	:UnitBase(posX, posY)
{

}

CAirUnit::~CAirUnit()
{

}

void CAirUnit::Move()
{

}

void CAirUnit::Attack()
{

}

void CAirUnit::Update()
{
	UnitBase::Update();

	CheckIsArrived();

	switch (GetNowState())
	{
	case eUnitState::StandBy:
	{
		// 마린은 오른쪾으롬만 이동한다.
		//m_Position.x += (rand() % 10 - rand() % 10);
	}
	break;
	case eUnitState::Moving:
	{
		// 현재 위치에서 목적지로 이동
		CPoint _moveVec = m_Destination - m_Position;

		_moveVec.Normalize();

		m_Position = m_Position + (_moveVec*m_Speed);
	}
	break;
	case eUnitState::Attack:
	{

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

void CAirUnit::Render(DRD2DEngine* pEngine)
{
	// 공통적으로 해야하는 일
	//UnitBase::Render(pEngine);

	int _motionIndex = 0;

	if ( GetNowState() == eUnitState::StandBy)
	{
		_motionIndex = 0;
	} 
	else if(GetNowState() == eUnitState::Moving)
	{
		_motionIndex = 1;
	}


	////DRSprite** _Animations = m_AnimationsIndex[_AnimationIndex];
	////pEngine->DrawSprite(_Animations[m_NowSpritIndex], m_Position.x, m_Position.y);

	/// 깔끔한 코드
	//pEngine->DrawSprite(this->GetNowSprite(_motionIndex, m_NowSpritIndex), m_Position.x, m_Position.y);

	// 현재 상태를 나타내준다.
	DrawState(pEngine);

	// 이동 라인을 그려준다. 
	DrawMoveLine(pEngine);

	DrawSelectedCircle(pEngine);

	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);
}
