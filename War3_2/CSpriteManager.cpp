#include "CSpriteManager.h"

#include "../DRD2DEngine/DRD2DEngine.h"

CSpriteManager::CSpriteManager(DRD2DEngine* pD2Engine)
	: m_pD2Engine(pD2Engine), m_Background(nullptr), 
	m_Ballista(0), m_DwarvenDemolitionSquad(0), m_ElvenArcher(0), m_Footman(0), m_Knight(0), m_Peasant(0), m_Mage(0),
m_GnomishFlyingMachine(0), m_GryphonRider(0), m_BattleShip(0), m_ElvenDestroyer(0), m_GnomishSubmarine(0), m_HumanOilTanker(0), m_HumanTransport(0),
m_HumanBiuldings(0), m_HumanBiuldings_Winter(0), m_Catapult(0), m_GoblinSappers(0), m_Grunt(0), m_Ogre(0), m_Peon(0), m_TrollAxethrower(0),
m_DeathKnight(0), m_Dragon(0), m_GoblinZeppelin(0), m_GiantTurtle(0), m_OgreJuggernaut(0), m_OrcOilTanker(0), m_OrcTransport(0), m_TrollDestroyer(0),
m_Obuilding(0), m_OrcBuildings_Winter(0)
{
	
}

CSpriteManager::~CSpriteManager()
{

}

void CSpriteManager::Initialize()
{
	/// 스프라이트 시트를 로드
	// 배경 
	m_pD2Engine->LoadSpriteSheet((char*)"../DRD2DEngine/data/Background.jpg");

	// Human Sprites - Ground// ------- 1번 부터 -------
	m_Ballista = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/Ballista.png");
	m_DwarvenDemolitionSquad = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/DwarvenDemolitionSquad.png");
	m_ElvenArcher = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/ElvenArcher.png");
	m_Footman = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/Footman.png");
	m_Knight = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/Knight.png");
	m_Peasant = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/Peasant.png");
	m_Mage = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/Mage.png");	// 영웅
	// Human Sprites - Air
	m_GnomishFlyingMachine = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/GnomishFlyingMachine.png");
	m_GryphonRider = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/GryphonRider.png");
	// Human Sprites - Sea
	m_BattleShip = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/BattleShip.png");
	m_ElvenDestroyer = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/ElvenDestroyer.png");
	m_GnomishSubmarine = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/GnomishSubmarine.png");
	m_HumanOilTanker = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/HumanOilTanker.png");
	m_HumanTransport = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/HumanTransport.png");
	// Human Sprites - Building
	m_HumanBiuldings = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/HumanBiuldings.png");
	m_HumanBiuldings_Winter = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Human/HumanBiuldings_Winter.png"); // 겨울

	// Orc Sprites - Ground
	m_Catapult = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/Catapult.png");
	m_GoblinSappers = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/GoblinSappers.png");
	m_Grunt = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/Grunt.png");
	m_Ogre = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/Ogre.png");
	m_Peon = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/Peon.png");
	m_TrollAxethrower = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/TrollAxethrower.png");
	m_DeathKnight = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/DeathKnight.png"); // 영웅
	// Orc Sprites - Air
	m_Dragon = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/Dragon.png");
	m_GoblinZeppelin = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/GoblinZeppelin.png");
	// Orc Sprites - Sea
	m_GiantTurtle = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/GiantTurtle.png");
	m_OgreJuggernaut = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/OgreJuggernaut.png");
	m_OrcOilTanker = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/OrcOilTanker.png");
	m_OrcTransport = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/OrcTransport.png");
	m_TrollDestroyer = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/TrollDestroyer.png");
	// Orc Sprites - Building
	m_Obuilding = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/Obuilding.png"); // 겨울
	m_OrcBuildings_Winter = m_pD2Engine->LoadSpriteSheet(L"../DRD2DEngine/data/Orc/OrcBuildings_Winter.png");

	// 배경 초기화
	m_Background = m_pD2Engine->LoadSpriteFromSheet(0, 0, 0, 1920, 1080, 1);

	// 모션을 모두 넣어주는 함수
	LoadAllSprites();
}

void CSpriteManager::Render()
{
	m_pD2Engine->DrawSprite(m_Background, 0, 0);
}

void CSpriteManager::InputSpriteSet(int motionIndex, int spriteIndex, DRSprite* sprite)
{
	/*SpriteVector& _nowMotion = m_Motions[motionIndex];

	_nowMotion.push_back(sprite);*/
}

void CSpriteManager::LoadAllSprites()
{
	/// 캐릭터 하나에다가, 특정 모션들의 셋트를 넣어준다.

#pragma region Ballista
	
	// Ballista
	MotionsVector _BallistaMotionSet;

	// 대기 및 움직임
	SpriteVector _BallistaMove;
	
	// Move 0˚
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 2, 0, 58, 59, 1));
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 2, 66, 58, 58, 1));

	// Move 15˚
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 68, 1, 61, 60, 1));
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 68, 67, 61, 59, 1));

	// Move 30˚
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 133, 1, 62, 54, 1));
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 133, 67, 62, 54, 1));

	// Move 45˚
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 200, 0, 62, 62, 1));
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 200, 66, 62, 62, 1));

	// Move 60˚
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 269, 0, 55, 60, 1));
		_BallistaMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 269, 66, 55, 60, 1));

	// 대기 및 움직임
	SpriteVector _BallistaAttack;

	// Attack 0˚
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 6, 133, 52, 57, 1));
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 2, 199, 60, 57, 1));

	// Attack 15˚
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 68, 133, 62, 59, 1));
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 68, 198, 62, 60, 1));

	// Attack 30˚
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 133, 135, 62, 52, 1));
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 133, 198, 62, 55, 1));

	// Attack 45˚
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 200, 132, 62, 62, 1));
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 200, 198, 62, 62, 1));

	// Attack 60˚
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 268, 132, 57, 59, 1));
		_BallistaAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Ballista, 268, 198, 57, 59, 1));

	_BallistaMotionSet.push_back(_BallistaMove);
	_BallistaMotionSet.push_back(_BallistaAttack);

	m_UnitMotions.push_back(_BallistaMotionSet);

#pragma endregion

#pragma region DwarvenDemolitionSquad

	MotionsVector _DwarvenDemolitionSquadSet;

	SpriteVector _DwarvenDemolitionSquadMove;
	// 0˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 5, 8 + (47 * i), 44, 47 * (i + 1), 1));
	}
	// 15˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 63, 9 + (47 * i), 45, 47 * (i + 1), 1));
	}
	// 30˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 120, 3 + (48 * i), 51, 48 * (i + 1), 1));
	}
	// 45˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 179, 5 + (49 * i), 47, 49 * (i + 1), 1));
	}
	// 60˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 243, 6 + (48 * i), 41, 48 * (i + 1), 1));
	}
	
	SpriteVector _DwarvenDemolitionSquadAttack;
	// 0˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 12, 202 + (51 * i), 36, 51 * (i + 1), 1));
	}
	// 15˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 68, 212 + (49 * i), 47, 49 * (i + 1), 1));
	}
	// 30˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 124, 203 + (50 * i), 49, 50 * (i + 1), 1));
	}
	// 45˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 181, 206 + (50 * i), 50, 50 * (i + 1), 1));
	}
	// 60˚
	for (int i = 0; i < 4; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 243, 209 + (50 * i), 40, 50 * (i + 1), 1));
	}
	
	SpriteVector _DwarvenDemolitionSquadDead;
	for (int i = 0; i < 5; i++)
	{
		_DwarvenDemolitionSquadMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_DwarvenDemolitionSquad, 4 + (71 * i), 410 , 71 * (i + 1), 51, 1));
	}

	_DwarvenDemolitionSquadSet.push_back(_DwarvenDemolitionSquadMove);
	_DwarvenDemolitionSquadSet.push_back(_DwarvenDemolitionSquadAttack);
	_DwarvenDemolitionSquadSet.push_back(_DwarvenDemolitionSquadDead);

	m_UnitMotions.push_back(_DwarvenDemolitionSquadSet);

#pragma endregion

#pragma region ElvenArcher

	MotionsVector _ElvenArcherSet;

	SpriteVector _ElvenArcherMove;
	// 0˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 5, 11 + (68 * i), 42, 68 * (i + 1), 1));
	}
	
	// 15˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 65, 12 + (66 * i), 44, 66 * (i + 1), 1));
	}
	
	// 30˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 128, 16 + (66 * i), 40, 66 * (i + 1), 1));
	}
	
	// 45˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 183, 17 + (64 * i), 47, 64 * (i + 1), 1));
	}
	
	// 60˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 239, 17 + (66 * i), 46, 66 * (i + 1), 1));
	}

	SpriteVector _ElvenArcherAttack;
	// 0˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 5, 308 + (64 * i), 50, 64 * (i + 1), 1));
	}
	
	// 15˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 67, 306 + (66 * i), 43, 66 * (i + 1), 1));
	}
	
	// 30˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 128, 312 + (61 * i), 46, 61 * (i + 1), 1));
	}
	
	// 45˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 237, 312 + (63 * i), 48, 63 * (i + 1), 1));
	}
	
	// 60˚
	for (int i = 0; i < 4; i++)
	{
		_ElvenArcherAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 237, 312 + (63 * i), 46, 63 * (i + 1), 1));
	}

	SpriteVector _ElvenArcherDead;
	for (int i = 0; i < 5; i++)
	{
		_ElvenArcherDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 10 + (54 * i), 525 , 54 * (i + 1), 50, 1));
	}
		_ElvenArcherDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenArcher, 9, 587 , 46, 45, 1));


	_ElvenArcherSet.push_back(_ElvenArcherMove);
	_ElvenArcherSet.push_back(_ElvenArcherAttack);
	_ElvenArcherSet.push_back(_ElvenArcherDead);

	m_UnitMotions.push_back(_ElvenArcherSet);

#pragma endregion

#pragma region BattleShip
	
	MotionsVector _BattleShipMotionSet;

	// 대기 및 움직임
	SpriteVector _BatteleShipMove;
	
	// 0˚ ~ 45˚
	for (int i = 0; i < 4; i++)
	{
		_BatteleShipMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 19, 0, 85 * i, 88, 1));
	}

	// 60˚
		_BatteleShipMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 18, 93, 52, 88, 1));

	// 파괴되는 모션
	SpriteVector _BatteleShipdestructed;

	// 0˚
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 111, 106, 54, 68, 1));
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 201, 209, 63, 63, 1));

	// 15˚
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 190, 103, 73, 75, 1));
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 279, 220, 74, 48, 1));

	// 30˚
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 279, 114, 72, 59, 1));
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 5, 311, 66, 47, 1));

	// 45˚
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 11, 189, 77, 84, 1));
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 113, 290, 62, 69, 1));

	// 60˚
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 111, 195, 56, 68, 1));
	_BatteleShipdestructed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_BattleShip, 202, 280, 61, 80, 1));

	_BattleShipMotionSet.push_back(_BatteleShipMove);
	_BattleShipMotionSet.push_back(_BatteleShipdestructed);

	m_UnitMotions.push_back(_BattleShipMotionSet);
	
#pragma endregion

#pragma region ElvenDestroyer

	MotionsVector _ElvenDestroyerSet;

	SpriteVector _ElvenDestroyerMove;
	// 0˚ ~ 60˚
	for (int i = 0; i < 5; i++)
	{
		_ElvenDestroyerMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenDestroyer, 4 + (69 * i), 5, 69 * (i + 1), 85, 1));
	}

	SpriteVector _ElvenDestroyerDestroyed;
	// 0˚
	for (int i = 0; i < 2; i++)
	{
		_ElvenDestroyerDestroyed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenDestroyer, 4, 92 + (81 * i), 54, 81 * (i + 1), 1));
	}

	// 15˚
	for (int i = 0; i < 2; i++)
	{
		_ElvenDestroyerDestroyed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenDestroyer, 69, 108 + (71 * i), 62, 71 * (i + 1), 1));
	}

	// 30˚
	for (int i = 0; i < 2; i++)
	{
		_ElvenDestroyerDestroyed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenDestroyer, 136, 116 + (68 * i), 80, 68 * (i + 1), 1));
	}

	// 45˚
	for (int i = 0; i < 2; i++)
	{
		_ElvenDestroyerDestroyed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenDestroyer, 221, 114 + (73 * i), 63, 73 * (i + 1), 1));
	}

	// 60˚
	for (int i = 0; i < 2; i++)
	{
		_ElvenDestroyerDestroyed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_ElvenDestroyer, 294, 96 + (81 * i), 54, 81 * (i + 1), 1));
	}

	_ElvenDestroyerSet.push_back(_ElvenDestroyerMove);
	_ElvenDestroyerSet.push_back(_ElvenDestroyerDestroyed);

	m_UnitMotions.push_back(_ElvenDestroyerSet);


#pragma endregion

#pragma region Footman

	MotionsVector _FootmanSet;

	SpriteVector _FootmanMove;
	// 0˚
	for (int i = 0; i < 5; i++)
	{
		_FootmanMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 22, 10 + (52 * i), 31, 52 * (i + 1), 1));
	}

	// 15˚
	for (int i = 0; i < 5; i++)
	{
		_FootmanMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 94, 10 + (51 * i), 39, 51 * (i + 1), 1));
	}

	// 30˚
	for (int i = 0; i < 5; i++)
	{
		_FootmanMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 168, 12 + (50 * i), 45, 50 * (i + 1), 1));
	}

	// 45˚
	for (int i = 0; i < 5; i++)
	{
		_FootmanMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 240, 13 + (49 * i), 44, 49 * (i + 1), 1));
	}

	// 60˚
	for (int i = 0; i < 5; i++)
	{
		_FootmanMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 315, 12 + (52 * i), 34, 52 * (i + 1), 1));
	}

	SpriteVector _FootmanAttack;
	// 0˚
	for (int i = 0; i < 4; i++)
	{
		_FootmanAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 2, 287 + (43 * i), 56, 43 * (i + 1), 1));
	}

	// 15˚
	for (int i = 0; i < 4; i++)
	{
		_FootmanAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 77, 286 + (43 * i), 69, 43 * (i + 1), 1));
	}

	// 30˚
	for (int i = 0; i < 4; i++)
	{
		_FootmanAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 151, 275 + (45 * i), 69, 45 * (i + 1), 1));
	}

	// 45˚
	for (int i = 0; i < 4; i++)
	{
		_FootmanAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 233, 275 + (45 * i), 61, 45 * (i + 1), 1));
	}

	// 60˚
	for (int i = 0; i < 4; i++)
	{
		_FootmanAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 312, 285 + (47 * i), 53, 47 * (i + 1), 1));
	}

	SpriteVector _FootmanDead;
	for (int i = 0; i < 4; i++)
	{
		_FootmanDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 24 + (65 * i), 522, 65 * (i + 1), 53 , 1));
	}
		_FootmanDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_Footman, 20, 582, 39, 34 , 1));


	_FootmanSet.push_back(_FootmanMove);
	_FootmanSet.push_back(_FootmanAttack);
	_FootmanSet.push_back(_FootmanDead);

	m_UnitMotions.push_back(_FootmanSet);

#pragma endregion

#pragma region GnomishFlyingMachine

	MotionsVector _GnomishFlyingMachineSet;

	SpriteVector _GnomishFlyingMachineMove;
	// 0˚
	for (int i = 0; i < 2; i++)
	{
		_GnomishFlyingMachineMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GnomishFlyingMachine, 11, 11 + (70 * i), 60, 70 * (i + 1), 1));
	}

	// 15˚
	for (int i = 0; i < 2; i++)
	{
		_GnomishFlyingMachineMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GnomishFlyingMachine, 86, 11 + (66 * i), 60, 66 * (i + 1), 1));
	}

	// 30˚
	for (int i = 0; i < 2; i++)
	{
		_GnomishFlyingMachineMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GnomishFlyingMachine, 159, 11 + (69 * i), 68, 69 * (i + 1), 1));
	}

	// 45˚
	for (int i = 0; i < 2; i++)
	{
		_GnomishFlyingMachineMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GnomishFlyingMachine, 234, 11 + (70 * i), 64, 70 * (i + 1), 1));
	}

	// 60˚
	for (int i = 0; i < 2; i++)
	{
		_GnomishFlyingMachineMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GnomishFlyingMachine, 304, 5 + (70 * i), 67, 70 * (i + 1), 1));
	}


	SpriteVector _GnomishFlyingMachineDestroyed;

	// 0˚ ~ 60˚
	for (int i = 0; i < 2; i++)
	{
		_GnomishFlyingMachineDestroyed.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GnomishFlyingMachine, 11 + (71 * i), 156, 71 * (i + 1), 72, 1));
	}

	
	_GnomishFlyingMachineSet.push_back(_GnomishFlyingMachineMove);
	_GnomishFlyingMachineSet.push_back(_GnomishFlyingMachineDestroyed);

	m_UnitMotions.push_back(_GnomishFlyingMachineSet);


#pragma endregion

#pragma region GryphonRider

	MotionsVector _GryphonRiderSet;

	SpriteVector _GryphonRiderMove;
	// 0˚
	for (int i = 0; i < 4; i++)
	{
		_GryphonRiderMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 5, 12 + (80 * i), 80, 80 * (i + 1), 1));
	}

	// 15˚
	for (int i = 0; i < 4; i++)
	{
		_GryphonRiderMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 89, 6 + (82 * i), 70, 82 * (i + 1), 1));
	}

	// 30˚
	for (int i = 0; i < 4; i++)
	{
		_GryphonRiderMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 169, 6 + (82 * i), 78, 82 * (i + 1), 1));
	}

	// 45˚
	for (int i = 0; i < 4; i++)
	{
		_GryphonRiderMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 253, 8 + (80 * i), 74, 80 * (i + 1), 1));
	}

	// 60˚
	for (int i = 0; i < 4; i++)
	{
		_GryphonRiderMove.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 333, 6 + (80 * i), 80, 80 * (i + 1), 1));
	}

	SpriteVector _GryphonRiderAttack;
	// 0˚
	for (int i = 0; i < 3; i++)
	{
		_GryphonRiderAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 5, 339 + (79 * i), 80, 79 * (i + 1), 1));
	}

	// 15˚
	for (int i = 0; i < 3; i++)
	{
		_GryphonRiderAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 89, 348 + (76 * i), 72, 76 * (i + 1), 1));
	}

	// 30˚
	for (int i = 0; i < 3; i++)
	{
		_GryphonRiderAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 169, 338 + (80 * i), 80, 80 * (i + 1), 1));
	}

	// 45˚
	for (int i = 0; i < 3; i++)
	{
		_GryphonRiderAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 254, 337 + (79 * i), 77, 79 * (i + 1), 1));
	}

	// 60˚
	for (int i = 0; i < 3; i++)
	{
		_GryphonRiderAttack.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 333, 334 + (75 * i), 80, 75 * (i + 1), 1));
	}

	SpriteVector _GryphonRiderDead;
	for (int i = 0; i < 3; i++)
	{
		_GryphonRiderDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 14 + (74 * i), 586, 74 * (i + 1), 62, 1));
	}
	_GryphonRiderDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 248, 594, 67, 62, 1));
	_GryphonRiderDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 327, 592, 69, 65, 1));
	_GryphonRiderDead.push_back(m_pD2Engine->LoadSpriteFromSheet(m_GryphonRider, 10, 657, 72, 37, 1));

	_GryphonRiderSet.push_back(_GryphonRiderMove);
	_GryphonRiderSet.push_back(_GryphonRiderAttack);
	_GryphonRiderSet.push_back(_GryphonRiderDead);

	m_UnitMotions.push_back(_GryphonRiderSet);

#pragma endregion

}

/// <summary>
/// 미리 모두 로드 해 놓은 리소스(스프라이트-모션-모션세트)를 리턴한다.
/// 
/// 지금은 1개의 모션을 리턴한다.
/// </summary>
MotionsVector& CSpriteManager::GetMotion(int motionIndex)
{
	return m_UnitMotions[motionIndex];
}



