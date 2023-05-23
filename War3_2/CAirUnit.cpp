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
		// ������ �����U���Ҹ� �̵��Ѵ�.
		//m_Position.x += (rand() % 10 - rand() % 10);
	}
	break;
	case eUnitState::Moving:
	{
		// ���� ��ġ���� �������� �̵�
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
	
	// ������ üũ
	CheckDead();
}

void CAirUnit::Render(DRD2DEngine* pEngine)
{
	// ���������� �ؾ��ϴ� ��
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

	/// ����� �ڵ�
	//pEngine->DrawSprite(this->GetNowSprite(_motionIndex, m_NowSpritIndex), m_Position.x, m_Position.y);

	// ���� ���¸� ��Ÿ���ش�.
	DrawState(pEngine);

	// �̵� ������ �׷��ش�. 
	DrawMoveLine(pEngine);

	DrawSelectedCircle(pEngine);

	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);
}
