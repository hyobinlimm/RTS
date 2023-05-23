#pragma once

///#define PURE =0 

class D2Engine;

class ICollsionBase
{
	// ������ ������ �����Ѵ�.
public:
	virtual void Draw(D2Engine* pEngine) abstract;

	virtual void MoveHorizontal(float value) = 0;
	virtual void MoveVertical(float value) PURE;

	virtual void CollisionCheck(ICollsionBase* pTarget) abstract;
};