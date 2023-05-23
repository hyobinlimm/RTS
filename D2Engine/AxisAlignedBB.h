#pragma once

#include "ICollsionBase.h"

class D2Engine;

/// <summary>
/// 축 정렬 사각형
/// 
/// 축에 정렬 돼 있는 사각형을 정의
/// 
/// LeHideHyobin's Home
/// </summary>
class AxisAlignedBB : public ICollsionBase
{
public:
	AxisAlignedBB(float left, float top, float right, float bottom);
	AxisAlignedBB(D2D_RECT_F rect);

	~AxisAlignedBB();



	// 사각형의 동작을 정의
public:
	virtual void Draw(D2Engine* pEngine);		// 그림은 마찬가지로 그려야 함
	//void Update(float dTime);

	virtual void UpdatePos(float x, float y);	// 위치 업데이트?

	virtual void MoveHorizontal(float value);	// 이동?
	virtual void MoveVertical(float value);

	// 비 다형적 하드코딩..
	void AABBCollisionCheck(AxisAlignedBB& target);	// 충돌감지?
	
	/// 다형성을 사용한 한방 충돌감지
	virtual void CollisionCheck(ICollsionBase* pTarget);


	// 사각형을 정의하는 것들
private:
	D2D_RECT_F m_Rectangle;	// 사각형의 정보
	bool m_IsCollided;		// (이 프레임에 방금) 충돌이 되었는가?

		
	// 원치 않던? getter / setter 가 생겼다..?
public:
	D2D_RECT_F GetRectangle() const { return m_Rectangle; }
	//void Rectangle(D2D_RECT_F val) { m_Rectangle = val; }
	bool GetIsCollided() const { return m_IsCollided; }
	void SetIsCollided(bool val) { m_IsCollided = val; }
};

