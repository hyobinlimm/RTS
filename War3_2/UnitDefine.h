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
	Siege,	// ����?
	Pierce,	// ����
	Magic,
	Msplash,
};

enum class eArmorType
{
	Unarmored,
	Light,
	Medium,
	Heavy,
	Invulnerable,	// ��������
	Fort,			// ���
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
	StandBy,	// ������ ��� ����
	Moving,		// �̵� ���� ���� 
	Attack,		// ���� ���� ����
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
	// �޸�
	BALLISTA, DWARVENDEMOLITIONSQUAD, ELVENARCHER, FOOTMAN, KNIGHT, PEASANT, MAGE, 
	GNOMISHFLYINGMACHINE, GRYPHONRIDER, 
	BATTLESHIP, ELVENDESTROYER, HUMANOILTANKER, TRANSPORT, 

	// ��ũ
	CATAPULT, GOBLINSAPPERS, GRUNT, OGRE, PEON, TROLLAXETHROWER, DEATHKNIGHT, 
	DRAGON, GOBLINZEPPELIN, 
	GIANTTURTLE, OGREJUGGERNAUT, ORCOILTANKER, ORCTRANSPORT, TROLLDESTROYER, 

	// �𵥵�
	// ����Ʈ ����
	WISP, ARCHER, HUNTRESS, GLAIVETHROWER, 
	DRYAD, DOC_DRUID_FORM, MOUNTAIN_GIANT, HIPPOGRYPH,
	DOT_CROW_FORM, FAERIE_DRAGON, HIPPOGRYPH_RIDER, CHIMAERA, 
	
	// TREANT, AVATAR_OF_VENGEANCE, SPIRIT_OF_VENGEANCE, ��ȯ��
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
	Mbounce,	// ��Ÿ����(��)
	Aline,		//	��Ÿ����(��)
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
	/// ������ų
	Renew,	// (Auto)
	Gather,
	Building,
	Detonate,
	/// ��ó ��ų
	Hide,
	MountHippogryph,
	/// ���͸���
	ElunesGrace, // passive
	Sentinel,
	MoonGlaive,		// passive
	/// �۷��̺�
	VorpalBlades,	// passive
	/// ����̾��
	SlowPoison,		// passive
	AbolishMagic,	// Auto
	SpellImmunity,	// passive /// ���巡��
	/// Ŭ��
	NightElfForm,
	Roar,
	Rejuvenation,
	BearForm,
	///����Ʈ���̾�Ʈ ��ų
	Taunt,
	WarClub,
	/// �׸���
	PickupArcher,
	/// Ż��
	//NightElfForm,
	FearieFire, // auto
	/// �� �巡��
	PhaswShift, // auto
	ManaFlare,
	/// Ű�޶�
	CorrosiveBreath, //(Passive)
	/// ��������
	ManaBurn,
	Immolation,
	Evasion, // �нú�
	Metamorphosis, // �ʻ��
	/// Ű�۱׷κ�
	EntanglingRoots,
	ForceOfNature,
	ThornsAura,
	Tranquility, // �ʻ��
	/// ���� ����
	//Hide,
	Scout,
	SraringArrows, // auto
	TrueshotAura,
	Starfall, // �ʻ��
	/// ����
	//Hide,
	FanofKnives,
	Blink,
	ShadowStrike,
	Vengeance, // �ʻ��



};

enum class UpgradeType
{
	/// �������̴�
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
	/// ���̾�Ʈ����ƾ
	HardenedSkin,
	ResistantSkin,
	/// �׸���, 
	StrengthOftheWild,
	ImprovedStrengthOftheWild, // Ż�е� , ���巡��, Ű�޶�
	AdvancedStrengthOftheWild,
	ReinforcedHides,
	ImprovedReinforcedHides,
	AdvancedReinforcedHides,
	/// Ż��
	CorwForm,
	Cyclone,
	MakeOftheTalon,

};