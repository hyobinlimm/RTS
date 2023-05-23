#include "pch.h"
#include "D2EnginDefine.h"

D2EnginSprite::D2EnginSprite()
	:SpriteType(), Index(), Width(), Height(), KeyColor(),
	CenterPosX(), CenterPosY(), Collision1(), Collision2(), DelayFrame(), Damage()
{

}

D2EnginSprite::D2EnginSprite(eSpriteType spriteType, int index, int width, int height, int keyColor, int centerPosX, int centerPosY, int delayFrame, const RECT& collision1, const RECT& collision2, int damage)
	:SpriteType(spriteType), Index(index), Width(width), Height(height), KeyColor(keyColor),
	CenterPosX(centerPosX), CenterPosY(centerPosY), Collision1(collision1), Collision2(collision2), DelayFrame(delayFrame), Damage(damage)
{

}

D2EnginSprite::~D2EnginSprite()
{

}
