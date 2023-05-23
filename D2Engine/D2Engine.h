#pragma once

//#include "pch.h"
#include "d2d1.h"
#include "ICollsionBase.h"
#include "wincodec.h"
#pragma comment(lib, "windowscodecs")



class Circle;
class AxisAlignedBB;

class D2Engine
{
public:
	// 멤버 변수를 초기화 해주는 함수
	D2Engine();
	~D2Engine();

private:

	/// ID2D1Factory 생성 : 드로잉 리소스를 생성 할 수있는 리소스 만들기 메서드 집합
	ID2D1Factory* m_pD2DFactory;
	IWICImagingFactory* m_pIWICFactory;

	/// 이미지 관련 변수
	

	/// Create a Direct2D render target
	ID2D1HwndRenderTarget* m_pRT;

	/// 그릴 윈도우 핸들
	HWND m_hWnd;

	/// 브러쉬 생성
	ID2D1SolidColorBrush* m_pBlackBrush;
	ID2D1SolidColorBrush* m_pYellowGreenBrush;
	ID2D1SolidColorBrush* m_pOrangeRedBrush;
	ID2D1SolidColorBrush* m_pPurpleBrush;
	
	ID2D1SolidColorBrush* m_pNowBrush;			// 바꿔가면서 여러 번 재사용의 용도

private:
	// 원을 그리기 위한 변수
	D2D_POINT_2F m_Circle1Pos;	// 원1의 위치
	D2D_POINT_2F m_Circle2Pos;	// 원2의 위치

	float m_Radius1;			// 원1의 반지름
	float m_Radius2;			// 원2의 반지름

	bool m_IsCollided;			// 충돌되었는가?


	// 사각형을 그리기 위한 변수
	D2D_RECT_F m_Rectangle1;	// 사각형1의 정보
	D2D_RECT_F m_Rectangle2;	// 사각형2의 정보


	// 클래스를 이용해서 데이터와 동작을 하나로!

	// 이건 원형이다..
	Circle* m_pCircle1;
	Circle* m_pCircle2;

	// 이건 사각형이요
	AxisAlignedBB* m_pAABB1;
	AxisAlignedBB* m_pAABB2;

	/// 다형성 적용의 한 예
	// 뭔진 모르지만 나는 오브젝트를 그릴거야
	ICollsionBase* m_pObject1;
	ICollsionBase* m_pObject2;

public:

	/// 이미지 변수
	ID2D1Bitmap* m_D2Dbitmap;
	ID2D1Bitmap* m_D2Dbitmap2;
	ID2D1Bitmap* m_D2Dbitmap3;


public:

	/// 초기화를 해준다.
	void Initialize(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight);

	/// 계산한다.
	void Update();

	void LoadResource();

	void DrawBitmap();
	void DrawBitmap(int index, int posX, int posY);
	
	/// 화면에 그리기를 한다.
	void Render();
	void BeginRender();
	void EndRender();

	/// 리소스 제거
	void DiscardResources();

	/// 엔진 종류
	void Finalize();

	/// 서클 체크
	bool CircleCollision(POINT cir, POINT cle, float radius1, float radius2);
	bool CircleCollision(D2D_POINT_2F circle1, float radius1, D2D_POINT_2F circle2, float radius2);
	
	/// Axis-Aligned Bounding Box 체크
	bool AABBCheck(D2D_RECT_F rectangle1, D2D_RECT_F rectangle2);


public:
	/// 그리기 함수
	void DrawCircle(D2D1_POINT_2F circlePos, float radius, bool isCollided);
	void DrawCircle(Circle* pCircle);
	void DrawRectangle(D2D1_RECT_F rect, bool isCollided);
	//void DrawRectangle(AABB* pAABB);

	// 다형성을 이용한 그리기.. 어떻게 해야 할까?
	void DrawObject(ICollsionBase* object);

	


	HRESULT LoadBitmapFromFile(
		ID2D1RenderTarget* pRenderTarget,
		IWICImagingFactory* pIWICFactory,
		PCWSTR path,
		UINT destinationWidth,
		UINT destinationHeight,
		ID2D1Bitmap** ppBitmap);
};