#include "pch.h"
#include "CSprite.h"

CSprite::CSprite()
	: D2EnginSprite(), m_Index(0), m_OriX(0), m_OriY(0)
{

}

CSprite::CSprite(int spriteSheetIndex, int oriX, int oriY, int index, int width, int height, int keyColor, int centerPosX, int centerPosY, int delayFrame, const RECT& collision1, const RECT& collision2, int damage)
	: D2EnginSprite(eSpriteType::ePickPos, index, width, height, keyColor, centerPosX, centerPosY, delayFrame, collision1, collision2, damage),
	m_Index(spriteSheetIndex), m_OriX(oriX), m_OriY(oriY)
{

}

CSprite::~CSprite()
{

}
