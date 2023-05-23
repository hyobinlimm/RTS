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

	// ��� �ѹ��� ������Ű�� ��
	if (m_Motion[(int)m_NowState].size() <= m_NowSpritIndex)
	{
		m_NowSpritIndex = 0;
	}

	CheckIsArrived();

	switch (GetNowState())
	{
	case eUnitState::StandBy:
	{
		// �����U���Ҹ� �̵��Ѵ�.
		//m_Position.x += (rand() % 10 - rand() % 10);
	}
		break;
	case eUnitState::Moving:
	{
		// ���� ��ġ���� �������� �̵�
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
	
	// ������ üũ
	CheckDead();

}

void CGroundUnit::Render_old(DRD2DEngine* pEngine)
{
	// ���������� �ؾ��ϴ� ��
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

	// �길 �ϴ� ��
	pEngine->DrawSprite(m_Animations[_motionIndex][m_NowSpritIndex], m_Position.x, m_Position.y);

	// ���� ���¸� ��Ÿ���ش�.
	DrawState(pEngine);

	// �̵� ������ �׷��ش�. 
	DrawMoveLine(pEngine);

	// ���� �Ǿ��°�?
	if (GetIsSelected())
	{
		pEngine->DrawEllipse(m_Position.x, m_Position.y, 40);
	}

	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);
}

void CGroundUnit::Render(DRD2DEngine* pEngine)
{
	// ����� ��´�.

	//SpriteVector _nowMotion = m_Motion[m_NowState];


	// �׸��� �κ�
	pEngine->DrawSprite(m_Motion[(int)m_NowState][m_NowSpritIndex], m_Position.x, m_Position.y);



}
