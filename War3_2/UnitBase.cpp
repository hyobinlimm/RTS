#include "UnitBase.h"
#include <math.h>
#include "../DRD2DEngine/DRD2DEngine.h"


//UnitBase::UnitBase()
//{
//
//}

UnitBase::UnitBase(int PosX, int PosY)
	:ObjectBase(PosX, PosY), 
	m_pUnitType(nullptr), m_MP(0), LV(1), // �⺻ ����	
	m_Speed(0), // �̵�����
	m_Sight(0), m_nightSight(0),
	m_HinPoint(0), m_AttackDamage(0), m_CoolDown(0),
	m_Armor(0)
{

}

UnitBase::UnitBase(int PosX, int PosY, ePlayer playerIndex)
	:ObjectBase(PosX, PosY, playerIndex),
	m_pUnitType(nullptr), m_MP(0), LV(1), // �⺻ ����	
	m_Speed(0), // �̵�����
	m_Sight(0), m_nightSight(0),
	m_HinPoint(0), m_AttackDamage(0), m_CoolDown(0),
	m_Armor(0)
{

}

UnitBase::~UnitBase()
{
	delete m_pUnitType;
}

void UnitBase::Move()
{

}

void UnitBase::Update()
{
	// 0~9���� ��������Ʈ �ε����� �����ش�. 
	if (rand() % 10 == 0)
	{
		m_NowSpritIndex++;
	}
	if ( 9 < m_NowSpritIndex)
	{
		m_NowSpritIndex = 0;
	}

	// �����ߴ����� üũ�Ѵ�.
	CheckIsArrived(m_NowState);

	// Finite State Machine
	switch (m_NowState)
	{
		case eUnitState::StandBy:
		{
			//  �����ϰ� �̵��Ѵ�.
			//m_Position.x += (rand() % 10 - rand() % 10);
			//m_Position.y += (rand() % 10 - rand() % 10);
		}
		break;

		case eUnitState::Moving:
		{
			// ���� ��ġ���� �������� �̵��Ѵ�.
			CPoint _moveVec = m_Destination - m_Position;

			// �븻����� �Ѵ�.
			_moveVec.Normalize();

			// ���� �����ǿ� �̵����͸� ���Ѵ�.
			m_Position = m_Position + (_moveVec * m_Speed);
		}
		break;

		case eUnitState::Attack:
		{
			// ������ �����ε�, Ÿ���� �ִٸ� ������ ����
			if (m_pTarget != nullptr)
			{
				// ���� 1/2�� Ȯ���� ������.
				if (rand() % 2 == 0)
				{
					Attack(m_pTarget);
				}
			}
		}

		default:
		{
		}
		break;
	}

	// ������ üũ�Ѵ�.
	CheckDead();

}

void UnitBase::Render(DRD2DEngine* pEngine)
{
	// �������� �׸��� ������ �ִ´�.
	pEngine->DrawSprite(m_pSprite, m_Position.x, m_Position.y);
	//pEngine->DrawSprite(m_Animations[0][m_NowSpritIndex], m_Position.x, m_Position.y);

	// ���� ���¸� ��Ÿ���ش�.
	DrawState(pEngine);

	// �̵� ������ �׷��ش�. 
	DrawMoveLine(pEngine);

	// ���õǾ��°�?
	DrawSelectedCircle(pEngine);

	// HP �ٸ� �׸���.
	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);

	// �̸��� �׸���.
	DrawName(pEngine, m_Position.x, m_Position.y - 38);
}

void UnitBase::DrawState(DRD2DEngine* pEngine)
{
	// �� ��° �÷��̾��ΰ�?
	if (GetPlayerIndex() == ePlayer::player1)
	{
		pEngine->DrawText(m_Position.x, m_Position.y - 18.0f, "P1");
	}
	else if (GetPlayerIndex() == ePlayer::player2)
	{
		pEngine->DrawText(m_Position.x, m_Position.y - 18.0f, "P2");
	}

	switch (m_NowState)
	{
		case eUnitState::StandBy:
		{
			pEngine->DrawText(m_Position.x + 20.0f, m_Position.y - 18.0f, "������");
		}
			break;
		case eUnitState::Moving:
		{
			pEngine->DrawText(m_Position.x + 20.0f, m_Position.y - 18.0f, "�̵�����");
		}
			break;
		case eUnitState::Attack:
		{
			pEngine->DrawText(m_Position.x + 20.0f, m_Position.y - 18.0f, "������");
		}
			break;
	}
}

void UnitBase::DrawMoveLine(DRD2DEngine* pEngine)
{
	pEngine->DrawLine(m_Position.x, m_Position.y, m_Destination.x, m_Destination.y);
}

void UnitBase::CheckIsArrived(eUnitState& nowStatus)
{
	// ���� ��ġ�� �������� ��ġ�� ���� ����Ѵ�. 
	CPoint _distance = m_Destination - m_Position;

	if (m_NowState == eUnitState::Moving && abs(_distance.Length()) < 2.0f)
	{
		this->SetNowState(eUnitState::StandBy);
	}
}

void UnitBase::Attack(ObjectBase* target)
{
	// Ÿ���� HP
	int _targetHP = target->GetHP();

	// Ÿ���� HP���� �� ���ݷ��� ����. (Ÿ���� �ܿ� HP)
	// ��, HP�� 0���� �Ʒ��� �������� �ȵȴ�. 
	int _remainHP = max(0, _targetHP - m_AttackDamage);

	// Ÿ���� HP�� �������ش�. 
	target->SetHP(_targetHP - m_AttackDamage);

	// ���� �׾����� Ÿ���� �������ش�. 
	if (target->GetNowState() == eUnitState::Dead)
	{
		m_pTarget = nullptr;

		// ������ ���·� ����
		m_NowState = m_PrevState;
	}
}

