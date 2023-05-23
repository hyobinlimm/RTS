// D2Engine.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "circle.h"
#include "AxisAlignedBB.h"


D2Engine::D2Engine()
	: m_pObject1(nullptr), m_pObject2(nullptr)
{
	m_hWnd = NULL;

	m_pD2DFactory = nullptr;
	m_pIWICFactory = nullptr;

	m_pRT = nullptr;

	m_pBlackBrush = nullptr;
	m_pYellowGreenBrush = nullptr;
	m_pOrangeRedBrush = nullptr;
	m_pPurpleBrush = nullptr;
	m_pNowBrush = nullptr;

	m_Circle2Pos.x = 300.0f;
	m_Circle2Pos.y = 300.0f;

	m_Radius1 = 100.0f;
	m_Radius2 = 100.0f;


	m_Rectangle1.left = 100;
	m_Rectangle1.top = 100;
	m_Rectangle1.right = 200;
	m_Rectangle1.bottom = 200;

	m_Rectangle2.left = 300;
	m_Rectangle2.top = 300;
	m_Rectangle2.right = 400;
	m_Rectangle2.bottom = 400;

	m_pCircle1 = new Circle(200, 200, 100);
	m_pCircle2 = new Circle(300, 300, 100);

	m_pAABB1 = new AxisAlignedBB(100, 100, 200, 200);
	m_pAABB2 = new AxisAlignedBB(300, 300, 400, 400);


	// 동적으로 사용하고 싶은 객체를 정한다.
	/// 동적 바인딩의 의미. 부모의 포인터로 자식의 객체를 받는다.
	int InputType = 3;
	if (InputType == 1)
	{
		m_pObject1 = new Circle(200, 200, 100);
		m_pObject2 = new Circle(400, 400, 100);
	}
	else if (InputType == 2)
	{
		m_pObject1 = new AxisAlignedBB(100, 100, 200, 200);
		m_pObject2 = new AxisAlignedBB(300, 300, 400, 400);
	}
	else if (InputType == 3)
	{
		/// 이건 뭔가 나는 누구인가... 다형성의 쾌감!
		m_pObject1 = new Circle(200, 200, 100);
		m_pObject2 = new AxisAlignedBB(300, 300, 400, 400);
	}
}

D2Engine::~D2Engine()
{

}

void D2Engine::Initialize(HINSTANCE hinst, HWND hWnd, int screenWidth, int screenHeight)
{
	
	HRESULT _hResult = CoInitialize(NULL);

	m_hWnd = hWnd;

	HRESULT hr = S_OK;

	// 팩토리를 만드는 것. 
	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2DFactory);

	if (SUCCEEDED(hr))
	{
		hr = CoCreateInstance(
		CLSID_WICImagingFactory, NULL,
		CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, 
		reinterpret_cast<void**>(&m_pIWICFactory));
	}

}

void D2Engine::Update()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_Circle1Pos.x -= 10.0f;

		m_Rectangle1.left -= 10.0f;
		m_Rectangle1.right -= 10.0f;

		m_pCircle1->MoveHorizontal(-10.0f);
		m_pAABB1->MoveHorizontal(-10.0f);

		/// 실제 타입이 뭔지 몰라도 작동한다. 인터페이스만 같다면. 다형성!!!
		m_pObject1->MoveHorizontal(-10.0f);
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_Circle1Pos.x += 10.0f;

		m_Rectangle1.left += 10.0f;
		m_Rectangle1.right += 10.0f;

		m_pCircle1->MoveHorizontal(10.0f);
		m_pAABB1->MoveHorizontal(10.0f);

		/// 실제 타입이 뭔지 몰라도 작동한다. 인터페이스만 같다면. Polymorphism!!
		m_pObject1->MoveHorizontal(10.0f);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_Circle1Pos.y -= 10.0f;

		m_Rectangle1.top -= 10.0f;
		m_Rectangle1.bottom -= 10.0f;

		m_pCircle1->MoveVertical(-10.0f);
		m_pAABB1->MoveVertical(-10.0f);

		/// 실제 타입이 뭔지 몰라도 작동한다. 인터페이스만 같다면
		m_pObject1->MoveVertical(-10.0f);
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_Circle1Pos.y += 10.0f;

		m_Rectangle1.top += 10.0f;
		m_Rectangle1.bottom += 10.0f;

		m_pCircle1->MoveVertical(10.0f);
		m_pAABB1->MoveVertical(10.0f);

		/// 실제 타입이 뭔지 몰라도 작동한다. 인터페이스만 같다면
		m_pObject1->MoveVertical(10.0f);
	}
}

void D2Engine::LoadResource()
{
	HRESULT hr = LoadBitmapFromFile(m_pRT, m_pIWICFactory, L"../D2Engine/data/test.PNG", 300, 300, &m_D2Dbitmap);
			hr = LoadBitmapFromFile(m_pRT, m_pIWICFactory, L"../D2Engine/data/sheet.PNG", 300, 300, &m_D2Dbitmap2);
			hr = LoadBitmapFromFile(m_pRT, m_pIWICFactory, L"../D2Engine/data/U_U_Gargoyle.bmp", 300, 300, &m_D2Dbitmap3);
}

void D2Engine::DrawBitmap()
{

	D2D1_RECT_F pos;
	pos.left = 300;
	pos.top = 300;
	pos.right = 500;
	pos.bottom = 500;

	D2D1_RECT_F pos2;
	pos2.left = 600;
	pos2.top = 600;
	pos2.right = 700;
	pos2.bottom = 700;

	D2D1_SIZE_F originalSize = m_D2Dbitmap2->GetSize();
	
	float customWidth = originalSize.width / 4;
	float customHeight = originalSize.height / 4;
	
	//float customWidth2 = originalSize.width;
	//float customHeight2 = originalSize.height;

	D2D1_RECT_F rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = customWidth;
	rect.bottom = customHeight;

	m_pRT->DrawBitmap(m_D2Dbitmap);
	m_pRT->DrawBitmap(m_D2Dbitmap2, pos2, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, rect);
	m_pRT->DrawBitmap(m_D2Dbitmap3, pos, 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, NULL);

}

void D2Engine::DrawBitmap(int index, int posX, int posY)
{
	if (index == 1)
	{
		m_pRT->DrawBitmap(m_D2Dbitmap, D2D1::RectF(posX, posY), 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	}
	else if (index == 2)
	{
		m_pRT->DrawBitmap(m_D2Dbitmap2, D2D1::RectF(posX, posY), 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	}
	else if (index == 3)
	{
		m_pRT->DrawBitmap(m_D2Dbitmap3, D2D1::RectF(posX, posY), 1.0f, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
	}
}

void D2Engine::Render()
{
	/// 구 버전 beginDraw
	/*RECT rc;
	GetClientRect(m_hWnd, &rc);

	HRESULT hr = S_OK;

	/// 랜더 타겟을 설정한다. 
	if (m_pRT == nullptr)
	{
		D2D_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

		if (SUCCEEDED(hr))
		{
			hr = m_pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(m_hWnd, size), &m_pRT);
		}

		if (SUCCEEDED(hr))
		{
			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::Black), &m_pBlackBrush);

			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::GreenYellow), &m_pYellowGreenBrush);

			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::OrangeRed), &m_pOrangeRedBrush);

			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::Purple), &m_pPurpleBrush);
		}
		
	}

	m_pRT->BeginDraw();

	m_pRT->Clear(D2D1::ColorF(D2D1::ColorF::YellowGreen));*/

	D2D_RECT_F pointRec;
	pointRec.left = 200.0f;
	pointRec.top = 200.0f;
	pointRec.right = 400.0f;
	pointRec.bottom = 400.0f;

	D2D1_ELLIPSE testRegion;
	testRegion.point.x = 200;
	testRegion.point.y = 200;
	testRegion.radiusX = 30.0f;
	testRegion.radiusY = 50.0f;


	/// 클래스 사용하지 않는 버전
	/// 

	/*
	// 충돌체크 관련
	m_IsCollided = false;

	if (CircleCollision(m_Circle1Pos, m_Radius1, m_Circle2Pos, m_Radius2) == true)
	{
		m_IsCollided = true;
	}

	if (AABB(m_Rectangle1, m_Rectangle2) == true)
	{
		m_IsCollided = true;
	}

	if (m_IsCollided == true)
	{
		m_pRT->DrawEllipse(D2D1::Ellipse(m_Circle1Pos, m_Radius1, m_Radius1), m_pPurpleBrush);
		m_pRT->DrawEllipse(D2D1::Ellipse(m_Circle2Pos, m_Radius2, m_Radius2), m_pPurpleBrush);

		m_pRT->DrawRectangle(m_Rectangle1, m_pPurpleBrush);
		m_pRT->DrawRectangle(m_Rectangle2, m_pPurpleBrush);
	}
	else
	{
		m_pRT->DrawEllipse(D2D1::Ellipse(m_Circle1Pos, m_Radius1, m_Radius1), m_pOrangeRedBrush);
		m_pRT->DrawEllipse(D2D1::Ellipse(m_Circle2Pos, m_Radius2, m_Radius2), m_pOrangeRedBrush);

		m_pRT->DrawRectangle(m_Rectangle1, m_pOrangeRedBrush);
		m_pRT->DrawRectangle(m_Rectangle2, m_pOrangeRedBrush);
	}
	//m_pRT->FillEllipse(&testRegion, m_pOrangeRedBrush);
	//m_pRT->FillRectangle(&pointRec, m_pPurpleBrush);
	*/

	/// 클래스버전
	/// 
	
	// 1. 충돌감지 버전 a
	// 기존의 충돌감지 함수를 사용한다.
	// 원의 하부 내용이 오픈된다.
	/*
	if (CircleCollision(m_pCircle1->GetPosition(), m_pCircle1->GetRadius(),
		m_pCircle2->GetPosition(), m_pCircle2->GetRadius()) == true)
	{
		m_pCircle1->SetIsCollided(true);
		m_pCircle2->SetIsCollided(true);
	}
	else
	{
		m_pCircle1->SetIsCollided(false);
		m_pCircle2->SetIsCollided(false);
	}
	*/

	// 2. 충돌감지 버전 b
	// 자기 자신이 상대방을 받는다.
	//m_pCircle1->CircleCollisionCheck(*m_pCircle2);		/// 어떻게 다형성으로 해보자..


	// 3. 충돌감지 버전 c
	// 다른 클래스에 위임한다.
	///m_CollisionCheckManager(m_pCircle1, m_pCircle2);



	/// 원 클래스 안으로 엔진의 복잡도를 가져간 버전
	// 이제 자기 자신이 알아서 그린다 (그려진다)
	//m_pCircle1->Draw(this);
	//m_pCircle2->Draw(this);

	/// 복잡도를 D2Engine으로 가져온 버전 1
	//DrawCircle(m_pCircle1->GetPosition(), m_pCircle1->GetRadius(), m_pCircle1->GetIsCollided());
	//DrawCircle(m_pCircle2->GetPosition(), m_pCircle2->GetRadius(), m_pCircle2->GetIsCollided());

	/// 복잡도를 D2Engine으로 가져온 버전 1
	// 함수 안으로 숨긴 버전
	//DrawCircle(m_pCircle1);
	//DrawCircle(m_pCircle2);


	/// 사각형
	// 2. 충돌감지 버전 b
	// 자기 자신이 상대방을 받는다.
	//m_pAABB1->CircleCollisionCheck(*m_pAABB2);


	/// 복잡도를 D2Engine으로 가져온 버전 1
	// 사각형도 마찬가지다..
	//DrawRectangle(m_pAABB1->GetRectangle(), m_pAABB1->GetIsCollided());
	//DrawRectangle(m_pAABB2->GetRectangle(), m_pAABB2->GetIsCollided());


	/// 다형성을 이용한 충돌감지
	/// 내가 누군지 정확히 몰라도 충돌감지 함수를 부른다.
	m_pObject1->CollisionCheck(m_pObject2);

	// circle->CollisionCheck(circle);
	// circle->CollisionCheck(AABB);
	// AABB->CollisionCheck(circle);
	// AABB->CollisionCheck(AABB);


	/// <summary>
	/// 다형성 버전. 멋있게 주석을 쓴다..
	/// 멋있는 다형성! 엘레강스~
	/// </summary>
	m_pObject1->Draw(this);
	m_pObject2->Draw(this);

	LoadResource();
	DrawBitmap();

	/// 구 버전 endDraw;
	//hr = m_pRT->EndDraw();
}

void D2Engine::BeginRender()
{
	RECT rc;
	GetClientRect(m_hWnd, &rc);

	HRESULT hr = S_OK;

	/// 랜더 타겟을 설정한다. 
	if (m_pRT == nullptr)
	{
		D2D_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

		if (SUCCEEDED(hr))
		{
			hr = m_pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
				D2D1::HwndRenderTargetProperties(m_hWnd, size), &m_pRT);
		}

		if (SUCCEEDED(hr))
		{
			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::Black), &m_pBlackBrush);

			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::GreenYellow), &m_pYellowGreenBrush);

			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::OrangeRed), &m_pOrangeRedBrush);

			hr = m_pRT->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::Purple), &m_pPurpleBrush);
		}
		LoadResource();
	}

	m_pRT->BeginDraw();

	m_pRT->Clear(D2D1::ColorF(D2D1::ColorF::YellowGreen));
}

void D2Engine::EndRender()
{
	m_pRT->EndDraw();
}

void D2Engine::DiscardResources()
{
	SafeRelease(&m_pRT);
	SafeRelease(&m_pBlackBrush);
	SafeRelease(&m_pYellowGreenBrush);
	SafeRelease(&m_pOrangeRedBrush);
	SafeRelease(&m_pPurpleBrush);
}

void D2Engine::Finalize()
{
	SafeRelease(&m_pD2DFactory);
	SafeRelease(&m_pRT);
	SafeRelease(&m_pBlackBrush);
	SafeRelease(&m_pYellowGreenBrush);
	SafeRelease(&m_pOrangeRedBrush);
	SafeRelease(&m_pPurpleBrush);
}

bool D2Engine::CircleCollision(POINT circle1, POINT circle2, float radius1, float radius2)
{
	float distance = 0;
	distance = (float)(circle1.x - circle2.x) * (circle1.x - circle2.x)
		+ (float)(circle1.y - circle2.y) * (circle1.y - circle2.y);

	if ((radius1 + radius2) > sqrtf(distance))
	{
		return true;
	}
	return false;
}

bool D2Engine::CircleCollision(D2D_POINT_2F circle1, float radius1, D2D_POINT_2F circle2, float radius2)
{
	float distance = 0;
	distance = (circle1.x - circle2.x) * (circle1.x - circle2.x) + (circle1.y - circle2.y) * (circle1.y - circle2.y);

	if ((radius1 + radius2) > sqrtf(distance))
	{
		return true;
	}
	return false;
}

bool D2Engine::AABBCheck(D2D_RECT_F rectangle1, D2D_RECT_F rectangle2)
{
	if (rectangle1.left < rectangle2.right &&
		rectangle2.left < rectangle1.right &&
		rectangle1.top < rectangle2.bottom &&
		rectangle2.top < rectangle1.bottom)
	{
		return true;
	}

	return false;
}

void D2Engine::DrawCircle(D2D1_POINT_2F circlePos, float radius, bool isCollided)
{
	if (isCollided == true)
	{
		m_pRT->DrawEllipse(D2D1::Ellipse(circlePos, radius, radius), m_pPurpleBrush);
	}
	else
	{
		m_pRT->DrawEllipse(D2D1::Ellipse(circlePos, radius, radius), m_pOrangeRedBrush);
	}
}

void D2Engine::DrawCircle(Circle* pCircle)
{
	if (pCircle->GetIsCollided() == true)
	{
		m_pRT->DrawEllipse(D2D1::Ellipse(pCircle->GetPosition(), pCircle->GetRadius(), pCircle->GetRadius()), m_pPurpleBrush);
	}
	else
	{
		m_pRT->DrawEllipse(D2D1::Ellipse(pCircle->GetPosition(), pCircle->GetRadius(), pCircle->GetRadius()), m_pOrangeRedBrush);
	}
}

void D2Engine::DrawRectangle(D2D1_RECT_F rect, bool isCollided)
{
	if (isCollided == true)
	{
		m_pRT->DrawRectangle(rect, m_pPurpleBrush);
	}
	else
	{
		m_pRT->DrawRectangle(rect, m_pOrangeRedBrush);
	}
}

/// <summary>
/// 상속구조를 가진 오브젝트 계열이 아니면 다형성을 쓸 수 없다.
/// 이 경우는 동적 타입 판별에 따른 케이스 처리를 해야 함.
/// </summary>
void D2Engine::DrawObject(ICollsionBase* object)
{
	/// 1. 타겟이 Circle타입인 경우..
	Circle* _pTargetCircle = dynamic_cast<Circle*>(object);

	if (_pTargetCircle != nullptr)
	{
	}

	/// 2. 타겟이 AABB인 경우...
	/// 
}

HRESULT D2Engine::LoadBitmapFromFile(ID2D1RenderTarget* pRenderTarget, 
	IWICImagingFactory* pIWICFactory, PCWSTR path, 
	UINT destinationWidth, UINT destinationHeight, ID2D1Bitmap** ppBitmap)
{
	HRESULT hr = S_OK;

	IWICBitmapDecoder* pDecoder = nullptr;
	IWICBitmapFrameDecode* pSource = nullptr;
	IWICFormatConverter* pConverter = nullptr;
	IWICBitmapScaler* pScaler = nullptr;


	// 이제부터 길고도 긴 비트맵 로딩이 시작된다.
	// 1. 가장 먼저 하게될 순서는 WICFactory를 통해 이미지를 로딩하는 일이다.
	// 1-2. 당연히 Factory 인터페이스가 필요하며, PCWSTR 형식의 경로를 함수의 매개변수로 넘겨준다.
	// 1-3. 이후 읽기 옵션과 파일 처리를 위한 옵션을 준다.
	// 1-4. 이제 해당 파일에 접근 가능한 Decoder 객체가 생성된다.
	hr = pIWICFactory->CreateDecoderFromFilename(
		path,/*파일을 읽어옴*/ 
		NULL, 
		GENERIC_READ, 
		WICDecodeMetadataCacheOnLoad, 
		&pDecoder);


	// 0번째 이미지를 가져온다. FrameDecode
	if (SUCCEEDED(hr))
	{
		hr = pDecoder->GetFrame(0, &pSource);
	}

	// 비트맵 형식으로 전환
	if (SUCCEEDED(hr))
	{
		hr = pIWICFactory->CreateFormatConverter(&pConverter);
	}

	if (SUCCEEDED(hr))
	{
		if (destinationWidth != 0 || destinationHeight != 0)
		{
			UINT originalWidth, originalHeight;
			hr = pSource->GetSize(&originalWidth, &originalHeight);
			if (SUCCEEDED(hr))
			{
				if (destinationWidth == 0)
				{
					// 목표 크기 / 원래 크기로 비율을 구한 다음, 이를 다시 원래 크기에 곱하는 방식
					FLOAT scalar = static_cast<FLOAT>(destinationHeight) / static_cast<FLOAT>(originalHeight);
					destinationWidth = static_cast<UINT>(scalar * static_cast<FLOAT>(originalWidth));
				}
				else if (destinationHeight == 0)
				{
					FLOAT scalar = static_cast<FLOAT>(destinationWidth) / static_cast<FLOAT>(originalWidth);
					destinationHeight = static_cast<UINT>(scalar * static_cast<FLOAT>(originalHeight));
				}

				hr = pIWICFactory->CreateBitmapScaler(&pScaler);
				if (SUCCEEDED(hr))
				{
					hr = pScaler->Initialize(
						pSource,
						destinationWidth,
						destinationHeight,
						WICBitmapInterpolationModeCubic
					);
				}

				if (SUCCEEDED(hr))
				{
					hr = pConverter->Initialize(
						pScaler, /*우리가 조정한 이미지 값*/
						GUID_WICPixelFormat32bppPBGRA,
						WICBitmapDitherTypeNone,
						NULL,
						0.f,
						WICBitmapPaletteTypeMedianCut
					);
				}
			}
		}

		else
		{
			hr = pConverter->Initialize(
				pSource,
				GUID_WICPixelFormat32bppPBGRA,
				WICBitmapDitherTypeNone,
				NULL,
				0.f,
				WICBitmapPaletteTypeMedianCut
			);
		}
	}

	if (SUCCEEDED(hr))
	{
		hr = pRenderTarget->CreateBitmapFromWicBitmap(
			pConverter,
			NULL,
			ppBitmap
		);
	}

	SafeRelease(&pDecoder);
	SafeRelease(&pSource);
	SafeRelease(&pConverter);
	SafeRelease(&pScaler);

	return hr;

	//return TRUE;
}
