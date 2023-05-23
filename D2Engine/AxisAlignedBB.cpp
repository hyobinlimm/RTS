#include "pch.h"
#include "AxisAlignedBB.h"


AxisAlignedBB::AxisAlignedBB(float left, float top, float right, float bottom)
//	: m_Rectangle(D2D1::Rect(left, top, right, bottom))
{
	m_Rectangle.left = left;
	m_Rectangle.right = right;
	m_Rectangle.top = top;
	m_Rectangle.bottom = bottom;
}

AxisAlignedBB::AxisAlignedBB(D2D_RECT_F rect)
{

}

AxisAlignedBB::~AxisAlignedBB()
{

}

void AxisAlignedBB::Draw(D2Engine* pEngine)
{
	pEngine->DrawRectangle(m_Rectangle, m_IsCollided);
}

void AxisAlignedBB::UpdatePos(float x, float y)
{

}

void AxisAlignedBB::MoveHorizontal(float value)
{
	m_Rectangle.left += value;
	m_Rectangle.right += value;
}

void AxisAlignedBB::MoveVertical(float value)
{
	m_Rectangle.top += value;
	m_Rectangle.bottom += value;
}

/// <summary>
/// 뭔가 무시무시한 2개 이상의 컴비네이션이 들어간 기술...
/// </summary>
void AxisAlignedBB::CollisionCheck(ICollsionBase* pTarget)
{
	// 부모로부터 실제 타입을 알아온다.
	// 이 시점에서 다형적 요소에서 실제 형태를 바꾼다.
	/// RTTI (Run-Time Type Identification) /// 다음 기술 : Reflection
	AxisAlignedBB* _pTargetAABB = dynamic_cast<AxisAlignedBB*>(pTarget);

	if (m_Rectangle.left < _pTargetAABB->GetRectangle().right &&
		_pTargetAABB->GetRectangle().left < m_Rectangle.right &&
		m_Rectangle.top < _pTargetAABB->GetRectangle().bottom &&
		_pTargetAABB->GetRectangle().top < m_Rectangle.bottom)
	{
		m_IsCollided = true;
		_pTargetAABB->SetIsCollided(true);
	}
	else
	{
		m_IsCollided = false;
		_pTargetAABB->SetIsCollided(false);
	}
}

void AxisAlignedBB::AABBCollisionCheck(AxisAlignedBB& target)
{
	if (m_Rectangle.left < target.GetRectangle().right &&
		target.GetRectangle().left < m_Rectangle.right &&
		m_Rectangle.top < target.GetRectangle().bottom &&
		target.GetRectangle().top < m_Rectangle.bottom)
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
