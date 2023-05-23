#pragma once
#include "../DRD2DEngine/DRD2DEngine.h"

typedef std::vector<DRSprite*> SpriteVector;
typedef std::vector<SpriteVector> MotionsVector;

enum class eSpecies
{
	Human,
	Orc,
	Undead,
	NightElve,
	Random,
};

enum class eAttackType
{
	None,
	Normal,
	Siege,	// 포위?
	Pierce,	// 관통
	Magic,
	Msplash,
};

enum class eArmorType
{
	Unarmored,
	Light,
	Medium,
	Heavy,
	Invulnerable,	// 무적상태
	Fort,			// 요새
};

class CPoint
{
public:
	CPoint();
	CPoint(float px, float py);
	~CPoint();
	
	CPoint operator+(const CPoint& r);
	CPoint operator-(const CPoint& r);
	CPoint operator*(const float& f);

	void Normalize();
	float Length();

	float x; 
	float y;
};

enum class eUnitState
{
	StandBy,	// 유닛의 대기 상태
	Moving,		// 이동 중인 상태 
	Attack,		// 공격 중인 상태
	//Hold,
	//Stop,
	Dead,
};

enum class ePlayer
{
	player1,
	player2
};

enum class eUnitType
{
	// 휴먼
	BALLISTA, DWARVENDEMOLITIONSQUAD, ELVENARCHER, FOOTMAN, KNIGHT, PEASANT, MAGE, 
	GNOMISHFLYINGMACHINE, GRYPHONRIDER, 
	BATTLESHIP, ELVENDESTROYER, HUMANOILTANKER, TRANSPORT, 

	// 오크
	CATAPULT, GOBLINSAPPERS, GRUNT, OGRE, PEON, TROLLAXETHROWER, DEATHKNIGHT, 
	DRAGON, GOBLINZEPPELIN, 
	GIANTTURTLE, OGREJUGGERNAUT, ORCOILTANKER, ORCTRANSPORT, TROLLDESTROYER, 

	// 언데드
	// 나이트 엘프
	WISP, ARCHER, HUNTRESS, GLAIVETHROWER, 
	DRYAD, DOC_DRUID_FORM, MOUNTAIN_GIANT, HIPPOGRYPH,
	DOT_CROW_FORM, FAERIE_DRAGON, HIPPOGRYPH_RIDER, CHIMAERA, 
	
	// TREANT, AVATAR_OF_VENGEANCE, SPIRIT_OF_VENGEANCE, 소환수
};

enum class SummonsUnitType
{
	Treant,
	OwlScout,
	AvatarOfVengeance,
	SpiritOfVengeance,

};

enum class HeroUnitType
{
	DemonHunter,
	KeeperOftheGrove,
	PriestessOftheMoon,
	Warden,
};

enum class eResourceType
{
	Gold,
	Tree,
	food,
};

enum class eWanpenType
{
	None,
	Normal,
	Missile,
	Mbounce,	// 일타쌍피(옆)
	Aline,		//	일타쌍피(뒤)
};

enum class eBuildingType
{
	TreeOfLife,
	TreeOfAges,
	TreeOfEternity,
	AncientOfWar,
	AncientOfLore,
	AncientOfWind,
	ChimaeraRoost,

	MAX_Building

};


enum class eSkillType
{
	/// 위습스킬
	Renew,	// (Auto)
	Gather,
	Building,
	Detonate,
	/// 아처 스킬
	Hide,
	MountHippogryph,
	/// 헌터리스
	ElunesGrace, // passive
	Sentinel,
	MoonGlaive,		// passive
	/// 글레이브
	VorpalBlades,	// passive
	/// 드라이어드
	SlowPoison,		// passive
	AbolishMagic,	// Auto
	SpellImmunity,	// passive /// 페어리드래곤
	/// 클로
	NightElfForm,
	Roar,
	Rejuvenation,
	BearForm,
	///마운트자이언트 스킬
	Taunt,
	WarClub,
	/// 그리폰
	PickupArcher,
	/// 탈론
	//NightElfForm,
	FearieFire, // auto
	/// 페어리 드래곤
	PhaswShift, // auto
	ManaFlare,
	/// 키메라
	CorrosiveBreath, //(Passive)
	/// 데몬헌터
	ManaBurn,
	Immolation,
	Evasion, // 패시브
	Metamorphosis, // 필살기
	/// 키퍼그로브
	EntanglingRoots,
	ForceOfNature,
	ThornsAura,
	Tranquility, // 필살기
	/// 달의 여제
	//Hide,
	Scout,
	SraringArrows, // auto
	TrueshotAura,
	Starfall, // 필살기
	/// 워덴
	//Hide,
	FanofKnives,
	Blink,
	ShadowStrike,
	Vengeance, // 필살기



};

enum class UpgradeType
{
	/// 히포라이더
	ImprovedBows,
	Marksmanship,
	StrengthOftheMoon,
	ImprovedStrengthOftheMoon,
	AdvancedStrengthOftheMoon,
	MoonArmor,
	ImprovedMoonArmor,
	AdvancedMoonArmor,
	DruidofClawAdeptTraining,
	DruidofClawMasterTraining,
	MarkOftheClaw,
	/// 자이언트마운틴
	HardenedSkin,
	ResistantSkin,
	/// 그리폰, 
	StrengthOftheWild,
	ImprovedStrengthOftheWild, // 탈론도 , 페어리드래곤, 키메라
	AdvancedStrengthOftheWild,
	ReinforcedHides,
	ImprovedReinforcedHides,
	AdvancedReinforcedHides,
	/// 탈론
	CorwForm,
	Cyclone,
	MakeOftheTalon,

};