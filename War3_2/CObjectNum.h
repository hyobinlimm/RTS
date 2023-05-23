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
	Invulnerable,	// 무적상태
	Fort,			// 요새
};

enum class AttackType
{
	None,
	Normal,
	Siege,	// 포위?
	Pierce,	// 관통
	Magic,
	Msplash,
};

enum class WanpenType
{
	None,
	Normal,
	Missile,
	Mbounce,	// 일타쌍피(옆)
	Aline,		//	일타쌍피(뒤)
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
	NightElfForm,
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
	Hide,
	Scout,
	SraringArrows, // auto
	TrueshotAura,
	Starfall, // 필살기
	/// 워덴
	Hide,
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