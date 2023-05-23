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
	// 0~9���� ��������Ʈ �ε����� �����ش�. 
	if (rand() % 10 == 0) // ������ ���� ���ͼ� ���� �̹����� �Ѱ��ش�. 
	{
		m_NowSpritIndex++;
	}
	if (9 < m_NowSpritIndex)
	{
		m_NowSpritIndex = 0;
	}

	// �����ߴ����� üũ�Ѵ�.
	//CheckIsArrived();

	// ������ üũ�Ѵ�.
	CheckDead();
}

void CBuilding::Render(DRD2DEngine* pEngine)
{
	int _AnimationIndex = 0;

	pEngine->DrawSprite(m_Animations[_AnimationIndex][m_NowSpritIndex],
		(int)m_Position.x, (int)m_Position.y);

	// ���� ���¸� ��Ÿ���ش�.
	// DrawState(pEngine);

	// ���õ� �����ΰ�? �� �׷��ش�. 
	DrawSelectedCircle(pEngine);

	// HP�ٸ� �׸���.
	DrawHPBar(pEngine, (float)m_HP / (float)m_HPMax);
}
