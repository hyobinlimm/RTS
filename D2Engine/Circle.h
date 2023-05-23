#pragma once

#include "ICollsionBase.h"

class D2Engine;

/// <summary>
/// ��
/// 
/// ���� ���� ��� ���� ����
/// 
/// LeHide 2021.01.21
/// </summary>
class Circle : public ICollsionBase
{
public:
	Circle(D2D1_POINT_2F pos, float radius);
	Circle(float x, float y, float radius);

	~Circle();

	// ���� ���� ����
public:
	virtual void Draw(D2Engine* pEngine);	// ù ��° ���� �̽�!
	//void Update(float dTime);

	virtual void UpdatePos(float x, float y);

	virtual void MoveHorizontal(float value);
	virtual void MoveVertical(float value);

	void CircleCollisionCheck(Circle& target);
	
	virtual void CollisionCheck(ICollsionBase* pTarget);



	// ���� �����ϴ� �͵�
private:
	D2D1_POINT_2F m_Position;	// ���� ������ ��ġ
	float m_Radius;				// ������
	bool m_IsCollided;			// (�� �����ӿ� ���) �浹�� �Ǿ��°�?


	// ��ġ �ʴ�? getter / setter �� �����..?
public:
	D2D1_POINT_2F GetPosition() const { return m_Position; }
	float GetRadius() const { return m_Radius; }

	void SetIsCollided(bool val) { m_IsCollided = val; }
	bool GetIsCollided() const { return m_IsCollided; }

};

