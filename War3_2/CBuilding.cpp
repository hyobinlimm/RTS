#include "CBuilding.h"

#include "../DRD2DEngine/DRD2DEngine.h"

CBuilding::CBuilding(int posX, int posY, ePlayer playerIndex)
	:ObjectBase(posX, posY)
{

}

CBuilding::~CBuilding()
{
}

void CBuilding::Update()
{
	// 0~9까지 스프라이트 인덱스를 정해준다. 
	if (rand() % 10 == 0) // 랜덤한 값이 나와서 다음 이미지로 넘겨준다. 
	{
		m_NowSpritIndex++;
	}
	if (9 < m_NowSpritIndex)
	{
		m_NowSpritIndex = 0;
	}

	// 도착했는지를 체크한다.
	//CheckIsArrived();

	// 죽음을 체크한다.
	CheckDead();
}

void CBuilding::Render(DRD2DEngine* pEngine)
{
	int _AnimationIndex = 0;

	pEngine->DrawSprite(m_Animations[_AnimationIndex][m_NowSpritIndex],
		(int)m_Position.x, (int)m_Position.y);

	// 현재 상태를 나타내준다.
	// DrawState(pEngine);

	// 선택된 상태인가? 를 그려준다. 
	DrawSelectedCircle(pEngine);

	// HP바를 그린다.
	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);
}
