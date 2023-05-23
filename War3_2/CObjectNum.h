#pragma once

enum class Species
{
	Human,
	Orc,
	Undead,
	NightElve,
	Random,
};


enum class ResourceType
{
	Gold,
	Tree,
	food,
};

enum class ArmorType
{
	Unarmored,
	Light,
	Medium,
	Heavy,
	Invulnerable,	// ��������
	Fort,			// ���
};

enum class AttackType
{
	None,
	Normal,
	Siege,	// ����?
	Pierce,	// ����
	Magic,
	Msplash,
};

enum class WanpenType
{
	None,
	Normal,
	Missile,
	Mbounce,	// ��Ÿ����(��)
	Aline,		//	��Ÿ����(��)
};

enum class BuildingType
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

enum class UnitType
{
	Wisp,
	Archer,
	Huntress,
	GlaiveThrower,
	Dryad,
	DruidOfClaw,
	MountainGiant,
	Hippogryph,
	HippogryphRider,
	Chimaera,

};

enum class HeroUnitType
{
	DemonHunter,
	KeeperOftheGrove,
	PriestessOftheMoon,
	Warden,
};

enum class SummonsUnitType
{
	Treant,
	OwlScout,
	AvatarOfVengeance,
	SpiritOfVengeance,

};

enum class SkillType
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
	NightElfForm,
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
	Hide,
	Scout,
	SraringArrows, // auto
	TrueshotAura,
	Starfall, // �ʻ��
	/// ����
	Hide,
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