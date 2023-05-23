#pragma once

#include "ICollsionBase.h"

class D2Engine;

/// <summary>
/// 원
/// 
/// 원에 대한 모든 것을 정의
/// 
/// LeHide 2021.01.21
/// </summary>
class Circle : public ICollsionBase
{
public:
	Circle(D2D1_POINT_2F pos, float radius);
	Circle(float x, float y, float radius);

	~Circle();

	// 원에 대한 동작
public:
	virtual void Draw(D2Engine* pEngine);	// 첫 번째 구조 이슈!
	//void Update(float dTime);

	virtual void UpdatePos(float x, float y);

	virtual void MoveHorizontal(float value);
	virtual void MoveVertical(float value);

	void CircleCollisionCheck(Circle& target);
	
	virtual void CollisionCheck(ICollsionBase* pTarget);



	// 원을 정의하는 것들
private:
	D2D1_POINT_2F m_Position;	// 원의 중점의 위치
	float m_Radius;				// 반지름
	bool m_IsCollided;			// (이 프레임에 방금) 충돌이 되었는가?


	// 원치 않던? getter / setter 가 생겼다..?
public:
	D2D1_POINT_2F GetPosition() const { return m_Position; }
	float GetRadius() const { return m_Radius; }

	void SetIsCollided(bool val) { m_IsCollided = val; }
	bool GetIsCollided() const { return m_IsCollided; }

};

