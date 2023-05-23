#pragma once
#include <string>

/// <summary>
/// 오브젝트 베이스랑 겹치는게 있는데 상속 받을까 말까 고민중
/// 
/// 2021.05.04 Hyobin
/// </summary>
class Skill
{
public:
	Skill();
	~Skill();

private:

	std::string m_Name;		// 스킬 이름

	int m_Level;			// 스킬 레벨 (3까지 제한)

	float m_Duration;		// 지속시간

	float m_Cooldown;		// 쿨타임

	int m_ManaCost;			// 마나 소보량

	float m_Range;

	int m_AreaOfEffect;

	int m_AllowedTargets;	// 공격 대상

	int m_SkillEffect;

	int m_HeroLevelReq;

	bool Upgrade;

public:

	/// 위습스킬
	void Renew();	// (Auto)
	void Gather();
	void Building();
	void Detonate();

	/// 아처 스킬
	void Hide();
	void MountHippogryph();

	/// 헌터리스
	void ElunesGrace(); // passive
	void Sentinel();
	void MoonGlaive();		// passive

	/// 글레이브
	void VorpalBlades();	// passive

	/// 드라이어드
	void SlowPoison();		// passive
	void AbolishMagic();	// Auto
	void SpellImmunity();	// passive
	void NightElfForm();
	void Roar();
	void Rejuvenation();
	void BearForm();
	
	///마운트자이언트 스킬
	void Taunt();
	void WarClub();
	void HardenedSkin();

};

