#include "UnitBase.h"
#include <math.h>
#include "../DRD2DEngine/DRD2DEngine.h"


//UnitBase::UnitBase()
//{
//
//}

UnitBase::UnitBase(int PosX, int PosY)
	:ObjectBase(PosX, PosY), 
	m_pUnitType(nullptr), m_MP(0), LV(1), // 기본 정보	
	m_Speed(0), // 이동관련
	m_Sight(0), m_nightSight(0),
	m_HinPoint(0), m_AttackDamage(0), m_CoolDown(0),
	m_Armor(0)
{

}

UnitBase::UnitBase(int PosX, int PosY, ePlayer playerIndex)
	:ObjectBase(PosX, PosY, playerIndex),
	m_pUnitType(nullptr), m_MP(0), LV(1), // 기본 정보	
	m_Speed(0), // 이동관련
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
	// 0~9까지 스프라이트 인덱스를 정해준다. 
	if (rand() % 10 == 0)
	{
		m_NowSpritIndex++;
	}
	if ( 9 < m_NowSpritIndex)
	{
		m_NowSpritIndex = 0;
	}

	// 도착했는지를 체크한다.
	CheckIsArrived(m_NowState);

	// Finite State Machine
	switch (m_NowState)
	{
		case eUnitState::StandBy:
		{
			//  랜덤하게 이동한다.
			//m_Position.x += (rand() % 10 - rand() % 10);
			//m_Position.y += (rand() % 10 - rand() % 10);
		}
		break;

		case eUnitState::Moving:
		{
			// 현재 위치에서 목적지로 이동한다.
			CPoint _moveVec = m_Destination - m_Position;

			// 노말라이즈를 한다.
			_moveVec.Normalize();

			// 현재 포지션에 이동벡터를 구한다.
			m_Position = m_Position + (_moveVec * m_Speed);
		}
		break;

		case eUnitState::Attack:
		{
			// 공격중 상태인데, 타겟이 있다면 실제로 공격
			if (m_pTarget != nullptr)
			{
				// 대충 1/2의 확률로 때린다.
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

	// 죽음을 체크한다.
	CheckDead();

}

void UnitBase::Render(DRD2DEngine* pEngine)
{
	// 공통적인 그리기 구현을 넣는다.
	pEngine->DrawSprite(m_pSprite, m_Position.x, m_Position.y);
	//pEngine->DrawSprite(m_Animations[0][m_NowSpritIndex], m_Position.x, m_Position.y);

	// 현재 상태를 나타내준다.
	DrawState(pEngine);

	// 이동 라인을 그려준다. 
	DrawMoveLine(pEngine);

	// 선택되었는가?
	DrawSelectedCircle(pEngine);

	// HP 바를 그린다.
	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);

	// 이름을 그린다.
	DrawName(pEngine, m_Position.x, m_Position.y - 38);
}

void UnitBase::DrawState(DRD2DEngine* pEngine)
{
	// 몇 번째 플레이어인가?
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
			pEngine->DrawText(m_Position.x + 20.0f, m_Position.y - 18.0f, "대기상태");
		}
			break;
		case eUnitState::Moving:
		{
			pEngine->DrawText(m_Position.x + 20.0f, m_Position.y - 18.0f, "이동상태");
		}
			break;
		case eUnitState::Attack:
		{
			pEngine->DrawText(m_Position.x + 20.0f, m_Position.y - 18.0f, "공격중");
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
	// 현재 위치와 목적지의 위치의 차를 계산한다. 
	CPoint _distance = m_Destination - m_Position;

	if (m_NowState == eUnitState::Moving && abs(_distance.Length()) < 2.0f)
	{
		this->SetNowState(eUnitState::StandBy);
	}
}

void UnitBase::Attack(ObjectBase* target)
{
	// 타겟의 HP
	int _targetHP = target->GetHP();

	// 타겟의 HP에서 내 공격력을 뺀다. (타겟의 잔여 HP)
	// 단, HP는 0보다 아래로 내려가면 안된다. 
	int _remainHP = max(0, _targetHP - m_AttackDamage);

	// 타겟의 HP를 설정해준다. 
	target->SetHP(_targetHP - m_AttackDamage);

	// 적이 죽었따면 타겟을 리셋해준다. 
	if (target->GetNowState() == eUnitState::Dead)
	{
		m_pTarget = nullptr;

		// 이전의 상태로 복귀
		m_NowState = m_PrevState;
	}
}

