#include "pch.h"

#include "Circle.h"
#include "AxisAlignedBB.h"

Circle::Circle(D2D1_POINT_2F pos, float radius)
	: m_Position(pos), m_Radius(radius)
{
	/*
	// c스타일의 d2d1_어쩌고 구조체를 그냥 쓸 때
	m_Position.x = 100.0f;
	m_Position.y = 100.0f;

	// 도우미 함수를 이용한 쉬운 방법
	m_Position = D2D1::Point2F(100.0f, 100.0f);
	*/
	m_IsCollided = false;
}

Circle::Circle(float x, float y, float radius)
	: m_Position(D2D1::Point2F(x,y)), m_Radius(radius)
{
	m_Position.x = x;
	m_Position.y = y;

	m_IsCollided = false;
}

Circle::~Circle()
{

}

void Circle::Draw(D2Engine* pEngine)
{
	// 약간 이중 구조 같은 느낌이 든다.
	// 구조의 불합리함을 느끼기 시작 -> 구조놀이 시작
	pEngine->DrawCircle(m_Position, m_Radius, m_IsCollided);
}

void Circle::UpdatePos(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Circle::MoveHorizontal(float value)
{
	m_Position.x += value;
}

void Circle::MoveVertical(float value)
{
	m_Position.y += value;
}

// 자신과, 타겟 원의 충돌감지를 한다.
void Circle::CircleCollisionCheck(Circle& target)
{
	float distance = 0;
	distance = (m_Position.x - target.GetPosition().x) * (m_Position.x - target.GetPosition().x)
		+ (m_Position.y - target.GetPosition().y) * (m_Position.y - target.GetPosition().y);

	if ((m_Radius + target.GetRadius()) > sqrtf(distance))
	{
		m_IsCollided = true;
		target.SetIsCollided(true);
	}
	else
	{
		m_IsCollided = false;
		target.SetIsCollided(false);
	}
}

/// 이제 뭐가 들어와도 IcollisionBase 인터페이스만 유지하면 충돌감지를 시도한다.
/// 실제로 되는지 안되는지는 케이스바이케이스 구현이 돼 있느냐 아닌가에 따라 다르다.
/// 다형적 동작의 한계는 이 함수의 시그니처까지이다.
void Circle::CollisionCheck(ICollsionBase* pTarget)
{
	// 부모로부터 실제 타입을 알아온다.
	// 이 시점에서 다형적 요소에서 실제 형태를 바꾼다.
	/// pTarget이 실제로 Circle인지, AABB인지 몰라...

	/// RTTI (Run-Time Type Identification) /// 다음 기술 : Reflection
	
	/// 1. 타겟이 Circle타입인 경우..
	Circle* _pTargetCircle = dynamic_cast<Circle*>(pTarget);

	if (_pTargetCircle != nullptr)
	{
		float distance = (m_Position.x - _pTargetCircle->GetPosition().x) * (m_Position.x - _pTargetCircle->GetPosition().x)
			+ (m_Position.y - _pTargetCircle->GetPosition().y) * (m_Position.y - _pTargetCircle->GetPosition().y);

		if ((m_Radius + _pTargetCircle->GetRadius()) > sqrtf(distance))
		{
			m_IsCollided = true;
			_pTargetCircle->SetIsCollided(true);
		}
		else
		{
			m_IsCollided = false;
			_pTargetCircle->SetIsCollided(false);
		}

		return;
	}

	/// 2. 타겟이 AABB타입인 경우..
	AxisAlignedBB* _pTargetAABB = dynamic_cast<AxisAlignedBB*>(pTarget);

	if (_pTargetAABB != nullptr)
	{
		// 만약, 원형이 사각형에 충돌을 했다면, 여기 들어올 것이다.
		int kk = 0;

		/// 새로운 충돌 감지 코드를 만들어야 한다.....
		/// 사실 원형과 사각형의 충돌감지는 어렵다..
		
		/// 가로 폭을 가짜 반지름으로 간주, 사각형의 중점을 원의 중점으로 간주
		/// 원-원 충돌감지를 가짜로 해 보자.
		float _fakeRadius = _pTargetAABB->GetRectangle().right - _pTargetAABB->GetRectangle().left;
		float _centerX = (_pTargetAABB->GetRectangle().left + _pTargetAABB->GetRectangle().right) * 0.5f;
		float _centerY = (_pTargetAABB->GetRectangle().top + _pTargetAABB->GetRectangle().bottom) * 0.5f;

		float distance = (m_Position.x - _centerX) * (m_Position.x - _centerX)
			+ (m_Position.y - _centerY) * (m_Position.y - _centerY);

		if ((m_Radius + _fakeRadius) > sqrtf(distance))
		{
			m_IsCollided = true;
			_pTargetAABB->SetIsCollided(true);
		}
		else
		{
			m_IsCollided = false;
			_pTargetAABB->SetIsCollided(false);
		}

		return;
	}
}
