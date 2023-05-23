#pragma once
#include <vector>
#include "UnitDefine.h"

class DRD2DEngine;
class DRSprite;

/// <summary>
/// 2021.05.01 The Big NearCastle Hyobin
/// 
/// Image Date Load and save, Draw
/// </summary>
class CSpriteManager
{
public:
	CSpriteManager(DRD2DEngine* pD2Engine);
	~CSpriteManager();

private:
	DRD2DEngine* m_pD2Engine;


	/// �̹��� ���� ����
	// �ڽ��� �̹��� ������ ������ ����

	// spriteSheet�� ��� ����
	DRSprite* m_Background;

	int m_Ballista;
	int m_DwarvenDemolitionSquad;
	int m_ElvenArcher;
	int m_Footman;
	int m_Knight;
	int m_Peasant;
	int m_Mage;

	int m_GnomishFlyingMachine;
	int m_GryphonRider;

	int m_BattleShip;
	int m_ElvenDestroyer;
	int m_GnomishSubmarine;
	int m_HumanOilTanker;
	int m_HumanTransport;

	int m_HumanBiuldings;
	int m_HumanBiuldings_Winter;

	int m_Catapult;
	int m_GoblinSappers;
	int m_Grunt;
	int m_Ogre;
	int m_Peon;
	int m_TrollAxethrower;
	int m_DeathKnight;

	int m_Dragon;
	int m_GoblinZeppelin;

	int m_GiantTurtle;
	int m_OgreJuggernaut;
	int m_OrcOilTanker;
	int m_OrcTransport;
	int m_TrollDestroyer;

	int m_Obuilding;
	int m_OrcBuildings_Winter;

public:
	// ��� SpriteSheet Load 
	void Initialize();

	void Render();

	void InputSpriteSet(int motionIndex, int spriteIndex, DRSprite* sprite);

	/// ���� ���� ��������Ʈ ü��
private:
	// ���ֵ��� ��� �������� ��� �ִ� ����
	std::vector<MotionsVector> m_UnitMotions;
	
public:
	// ��� ��������Ʈ�� �о, ��ǵ��� ���ҽ��� �����Ѵ�.
	void LoadAllSprites();

	MotionsVector& GetMotion(int motionIndex);

};
