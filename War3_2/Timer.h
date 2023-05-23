#pragma once
#include <windows.h>

/// �ð� ���� Ŭ����
/// ������ ����, 1 ������ �� �ɸ� �ð� 

class Timer
{
public:
	Timer();
	~Timer();

	// quert
private:
	__int64 m_CountsPerSec;
	double m_SecondsPerCount;

	__int64 m_PreviousCount;
	__int64 m_CurrentCount;
	__int64 m_DeltaCount;
	double m_DeltaTime;

public:
	float GetDeltaTimeMS();
	float GetFPS();

	void Update();


	/// �߰� �� ��:
	/// FPS���� ��� ��/����
	/// ����/����
	/// freeze�Ǿ��ٰ� �ٽ� �����ϴ� ��쿡 ���� ó��
	/// ������ �ð�ó��

};

