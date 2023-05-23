#include "pch.h"

#include "Circle.h"
#include "AxisAlignedBB.h"

Circle::Circle(D2D1_POINT_2F pos, float radius)
	: m_Position(pos), m_Radius(radius)
{
	/*
	// c��Ÿ���� d2d1_��¼�� ����ü�� �׳� �� ��
	m_Position.x = 100.0f;
	m_Position.y = 100.0f;

	// ����� �Լ��� �̿��� ���� ���
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
	// �ణ ���� ���� ���� ������ ���.
	// ������ ���ո����� ������ ���� -> �������� ����
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

// �ڽŰ�, Ÿ�� ���� �浹������ �Ѵ�.
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

/// ���� ���� ���͵� IcollisionBase �������̽��� �����ϸ� �浹������ �õ��Ѵ�.
/// ������ �Ǵ��� �ȵǴ����� ���̽��������̽� ������ �� �ִ��� �ƴѰ��� ���� �ٸ���.
/// ������ ������ �Ѱ�� �� �Լ��� �ñ״�ó�����̴�.
void Circle::CollisionCheck(ICollsionBase* pTarget)
{
	// �θ�κ��� ���� Ÿ���� �˾ƿ´�.
	// �� �������� ������ ��ҿ��� ���� ���¸� �ٲ۴�.
	/// pTarget�� ������ Circle����, AABB���� ����...

	/// RTTI (Run-Time Type Identification) /// ���� ��� : Reflection
	
	/// 1. Ÿ���� CircleŸ���� ���..
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

	/// 2. Ÿ���� AABBŸ���� ���..
	AxisAlignedBB* _pTargetAABB = dynamic_cast<AxisAlignedBB*>(pTarget);

	if (_pTargetAABB != nullptr)
	{
		// ����, ������ �簢���� �浹�� �ߴٸ�, ���� ���� ���̴�.
		int kk = 0;

		/// ���ο� �浹 ���� �ڵ带 ������ �Ѵ�.....
		/// ��� ������ �簢���� �浹������ ��ƴ�..
		
		/// ���� ���� ��¥ ���������� ����, �簢���� ������ ���� �������� ����
		/// ��-�� �浹������ ��¥�� �� ����.
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
