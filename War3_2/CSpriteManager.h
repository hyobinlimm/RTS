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


	/// 이미지 정보 관련
	// 자신의 이미지 정보를 가지고 있음

	// spriteSheet를 담는 변수
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
	// 모든 SpriteSheet Load 
	void Initialize();

	void Render();

	void InputSpriteSet(int motionIndex, int spriteIndex, DRSprite* sprite);

	/// 새로 만든 스프라이트 체계
private:
	// 유닛들의 모든 움직임이 들어 있는 벡터
	std::vector<MotionsVector> m_UnitMotions;
	
public:
	// 모든 스프라이트를 읽어서, 모션들의 리소스를 구축한다.
	void LoadAllSprites();

	MotionsVector& GetMotion(int motionIndex);

};
