#pragma once
#include "D2EnginDefine.h"

class CSprite : public D2EnginSprite
{
public:
	CSprite();
	CSprite(int spriteSheetIndex, int oriX, int oriY, int index, int width, int height, int keyColor,
		int centerPosX, int centerPosY, int delayFrame, const RECT& collision1, const RECT& collision2, int damage);
	~CSprite();

public:
	int m_Index;

	// 원본에서의 위치 
	int m_OriX;
	int m_OriY;
};

