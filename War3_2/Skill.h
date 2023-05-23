#pragma once
#include <string>

/// <summary>
/// ������Ʈ ���̽��� ��ġ�°� �ִµ� ��� ������ ���� �����
/// 
/// 2021.05.04 Hyobin
/// </summary>
class Skill
{
public:
	Skill();
	~Skill();

private:

	std::string m_Name;		// ��ų �̸�

	int m_Level;			// ��ų ���� (3���� ����)

	float m_Duration;		// ���ӽð�

	float m_Cooldown;		// ��Ÿ��

	int m_ManaCost;			// ���� �Һ���

	float m_Range;

	int m_AreaOfEffect;

	int m_AllowedTargets;	// ���� ���

	int m_SkillEffect;

	int m_HeroLevelReq;

	bool Upgrade;

public:

	/// ������ų
	void Renew();	// (Auto)
	void Gather();
	void Building();
	void Detonate();

	/// ��ó ��ų
	void Hide();
	void MountHippogryph();

	/// ���͸���
	void ElunesGrace(); // passive
	void Sentinel();
	void MoonGlaive();		// passive

	/// �۷��̺�
	void VorpalBlades();	// passive

	/// ����̾��
	void SlowPoison();		// passive
	void AbolishMagic();	// Auto
	void SpellImmunity();	// passive
	void NightElfForm();
	void Roar();
	void Rejuvenation();
	void BearForm();
	
	///����Ʈ���̾�Ʈ ��ų
	void Taunt();
	void WarClub();
	void HardenedSkin();

};

