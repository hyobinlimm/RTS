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
	// ��� ������ �ʱ�ȭ ���ִ� �Լ�
	D2Engine();
	~D2Engine();

private:

	/// ID2D1Factory ���� : ����� ���ҽ��� ���� �� ���ִ� ���ҽ� ����� �޼��� ����
	ID2D1Factory* m_pD2DFactory;
	IWICImagingFactory* m_pIWICFactory;

	/// �̹��� ���� ����
	

	/// Create a Direct2D render target
	ID2D1HwndRenderTarget* m_pRT;

	/// �׸� ������ �ڵ�
	HWND m_hWnd;

	/// �귯�� ����
	ID2D1SolidColorBrush* m_pBlackBrush;
	ID2D1SolidColorBrush* m_pYellowGreenBrush;
	ID2D1SolidColorBrush* m_pOrangeRedBrush;
	ID2D1SolidColorBrush* m_pPurpleBrush;
	
	ID2D1SolidColorBrush* m_pNowBrush;			// �ٲ㰡�鼭 ���� �� ������ �뵵

private:
	// ���� �׸��� ���� ����
	D2D_POINT_2F m_Circle1Pos;	// ��1�� ��ġ
	D2D_POINT_2F m_Circle2Pos;	// ��2�� ��ġ

	float m_Radius1;			// ��1�� ������
	float m_Radius2;			// ��2�� ������

	bool m_IsCollided;			// �浹�Ǿ��°�?


	// �簢���� �׸��� ���� ����
	D2D_RECT_F m_Rectangle1;	// �簢��1�� ����
	D2D_RECT_F m_Rectangle2;	// �簢��2�� ����


	// Ŭ������ �̿��ؼ� �����Ϳ� ������ �ϳ���!

	// �̰� �����̴�..
	Circle* m_pCircle1;
	Circle* m_pCircle2;

	// �̰� �簢���̿�
	AxisAlignedBB* m_pAABB1;
	AxisAlignedBB* m_pAABB2;

	/// ������ ������ �� ��
	// ���� ������ ���� ������Ʈ�� �׸��ž�
	ICollsionBase* m_pObject1;
	ICollsionBase* m_pObject2;

public:

	/// �̹��� ����
	ID2D1Bitmap* m_D2Dbitmap;
	ID2D1Bitmap* m_D2Dbitmap2;
	ID2D1Bitmap* m_D2Dbitmap3;


public:

	/// �ʱ�ȭ�� ���ش�.
	void Initialize(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight);

	/// ����Ѵ�.
	void Update();

	void LoadResource();

	void DrawBitmap();
	void DrawBitmap(int index, int posX, int posY);
	
	/// ȭ�鿡 �׸��⸦ �Ѵ�.
	void Render();
	void BeginRender();
	void EndRender();

	/// ���ҽ� ����
	void DiscardResources();

	/// ���� ����
	void Finalize();

	/// ��Ŭ üũ
	bool CircleCollision(POINT cir, POINT cle, float radius1, float radius2);
	bool CircleCollision(D2D_POINT_2F circle1, float radius1, D2D_POINT_2F circle2, float radius2);
	
	/// Axis-Aligned Bounding Box üũ
	bool AABBCheck(D2D_RECT_F rectangle1, D2D_RECT_F rectangle2);


public:
	/// �׸��� �Լ�
	void DrawCircle(D2D1_POINT_2F circlePos, float radius, bool isCollided);
	void DrawCircle(Circle* pCircle);
	void DrawRectangle(D2D1_RECT_F rect, bool isCollided);
	//void DrawRectangle(AABB* pAABB);

	// �������� �̿��� �׸���.. ��� �ؾ� �ұ�?
	void DrawObject(ICollsionBase* object);

	


	HRESULT LoadBitmapFromFile(
		ID2D1RenderTarget* pRenderTarget,
		IWICImagingFactory* pIWICFactory,
		PCWSTR path,
		UINT destinationWidth,
		UINT destinationHeight,
		ID2D1Bitmap** ppBitmap);
};