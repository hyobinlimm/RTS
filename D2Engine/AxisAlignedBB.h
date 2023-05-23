#pragma once

#include "ICollsionBase.h"

class D2Engine;

/// <summary>
/// �� ���� �簢��
/// 
/// �࿡ ���� �� �ִ� �簢���� ����
/// 
/// LeHideHyobin's Home
/// </summary>
class AxisAlignedBB : public ICollsionBase
{
public:
	AxisAlignedBB(float left, float top, float right, float bottom);
	AxisAlignedBB(D2D_RECT_F rect);

	~AxisAlignedBB();



	// �簢���� ������ ����
public:
	virtual void Draw(D2Engine* pEngine);		// �׸��� ���������� �׷��� ��
	//void Update(float dTime);

	virtual void UpdatePos(float x, float y);	// ��ġ ������Ʈ?

	virtual void MoveHorizontal(float value);	// �̵�?
	virtual void MoveVertical(float value);

	// �� ������ �ϵ��ڵ�..
	void AABBCollisionCheck(AxisAlignedBB& target);	// �浹����?
	
	/// �������� ����� �ѹ� �浹����
	virtual void CollisionCheck(ICollsionBase* pTarget);


	// �簢���� �����ϴ� �͵�
private:
	D2D_RECT_F m_Rectangle;	// �簢���� ����
	bool m_IsCollided;		// (�� �����ӿ� ���) �浹�� �Ǿ��°�?

		
	// ��ġ �ʴ�? getter / setter �� �����..?
public:
	D2D_RECT_F GetRectangle() const { return m_Rectangle; }
	//void Rectangle(D2D_RECT_F val) { m_Rectangle = val; }
	bool GetIsCollided() const { return m_IsCollided; }
	void SetIsCollided(bool val) { m_IsCollided = val; }
};

