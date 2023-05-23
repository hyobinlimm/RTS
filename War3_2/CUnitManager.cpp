#include "../DRD2DEngine/DRD2DEngine.h"

#include "CUnitManager.h"
#include "CSpriteManager.h"
#include "UnitBase.h"
#include "CBuilding.h"


CUnitManager::CUnitManager(DRD2DEngine* pEngine, HWND hWnd, CSpriteManager* pSpriteManager)
	: m_pSpriteManager(pSpriteManager), m_RightButtonDown(false), m_LeftButtonDown(false), m_pEngine(pEngine), m_hWnd(hWnd), m_NowMousePos(), m_IsLeftDragging(false),
	m_DragStartPos()
{

}

CUnitManager::~CUnitManager()
{

}

void CUnitManager::UpdateAllUnit()
{
	UserInput();

	// ���� ��Ÿ� �ȿ� ���Դ°��� üũ�Ѵ�
	CheckEnemyIsSpotted();
	
	for (unsigned int i = 0; i < m_UnitPool.size(); i++)
	{
		// �θ��� �����ͷ� ������ �ִ�.
		ObjectBase* _nowUnit = m_UnitPool[i];

		_nowUnit->Update();
	}

	// ���� ������ ����
	RemoveDeadUnits();
}

void CUnitManager::RenderAllUnit()
{
	for (unsigned int i = 0; i < m_UnitPool.size(); i++)
	{
		// �θ��� �����ͷ� ������ �ֵ�.
		ObjectBase* _nowUnit = m_UnitPool[i];

		_nowUnit->Render(m_pEngine);

		//m_pEngine->DrawSprite(_nowUnit->m_pSprite, _nowUnit->SetPosition());

	}
	///CAirUnit* _newAirUnit = new CAirUnit(posX, posY);
	this->DrawSelectBox();
}


void CUnitManager::RenderStatues()
{
	m_pEngine->DrawText(0, 0, "UnitPool : %d", m_UnitPool.size());
}

ObjectBase* CUnitManager::CreateBuilding1(int posX, int posY)
{
	ObjectBase* _newBuilding = new CBuilding(posX, posY, ePlayer::player1);

	_newBuilding->m_Animations[0][0] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][1] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][2] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][3] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][4] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][5] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][6] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][7] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][8] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);
	_newBuilding->m_Animations[0][9] = m_pEngine->LoadSpriteFromSheet(4, 398, 14, 128, 128, 1);

	// ���� ������ �ڵ�
	_newBuilding->m_pSprite = _newBuilding->m_Animations[0][0];

	//m_UnitPool.push_back(_newBuilding);
	m_UnitPool.push_back(_newBuilding);

	return _newBuilding;
}

void CUnitManager::RemoveDeadUnits()
{
	std::vector<ObjectBase*>::iterator it_unit;
	it_unit = m_UnitPool.begin();

	//for (it_unit = m_UnitPool.begin(); it_unit != m_UnitPool.end();)
	for (unsigned int i = 0; i < m_UnitPool.size(); )
	{
		if (m_UnitPool[i]->GetNowState() == eUnitState::Dead)
		{
			delete m_UnitPool[i];

			m_UnitPool.erase(m_UnitPool.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

void CUnitManager::RemoveDeadUnits2()
{
	std::vector<ObjectBase*>::iterator it_unit;

	for (it_unit = m_UnitPool.begin(); it_unit != m_UnitPool.end();)
	{
		ObjectBase* _nowUnit = *it_unit;
		if (_nowUnit->GetNowState() == eUnitState::Dead)
		{
			delete _nowUnit;

			it_unit = m_UnitPool.erase(it_unit);
		}
		else
		{
			it_unit++;
		}
	}
}

/// ���� �� ���� ������ ���Դ°�?
UnitBase* CUnitManager::CheckEnemyIsSpotted()
{
	// ��ü ������ ���鼭 ���� ���,
	/// ���� ���� ����
	for (ObjectBase* nowUnit : m_UnitPool)
	{
		
		// ��ü ��� ������ ���鼭
		for (ObjectBase* targetUnit : m_UnitPool)
		{
			/// ���� ���� �������̶�� �н�
			if (nowUnit->GetNowState() == eUnitState::Attack)
			{
				continue;
			}

			// ��� ������ ���� ���
			if (nowUnit->GetPlayerIndex() != targetUnit->GetPlayerIndex() )
			{
				// ���� ��ġ ���Ϳ� ���� ��ġ������ ���� ������ ���.
				CPoint _disVec = nowUnit->GetPosition() - targetUnit->GetPosition();
				float _distance = abs(_disVec.Length());

				// ���� ������ ������ ���
				if (_distance <= nowUnit->GetRange())
				{
					// �� ���¸� ���� ������ �ٲ�
					nowUnit->SetNowState(eUnitState::Attack);

					// �� ���� �����͸� ����. �ٷ� �ο���.
					nowUnit->SetTarget(targetUnit);
					
				}
			}				
		}
	}
	// ��� ���Ҵµ� �� ã���� ���
	// nullptr ����
	return nullptr;
 }

void CUnitManager::CreateBuilding(eBuildingType type, int posX, int posY, ePlayer playerIndex, int HP)
{
	ObjectBase* _pBuild = nullptr;

	switch (type)
	{
	case eBuildingType::TreeOfLife:
	{
		_pBuild = CreateBuilding1(posX, posY);
		_pBuild->SetPlayerIndex(playerIndex);
		_pBuild->SetHPMax(HP);
		_pBuild->SetRange(200);
		//_pBuild->SetGroundAttackDamage(30);
	}
		break;
	case eBuildingType::TreeOfAges:
		break;
	case eBuildingType::TreeOfEternity:
		break;
	case eBuildingType::AncientOfWar:
		break;
	case eBuildingType::AncientOfLore:
		break;
	case eBuildingType::AncientOfWind:
		break;
	case eBuildingType::ChimaeraRoost:
		break;
	case eBuildingType::MAX_Building:
		break;
	default:
		break;
	}
}

void CUnitManager::CreateUnit_New(eUnitType type, int posX, int posY, float speed, ePlayer playerIndex, int HP)
{
	UnitBase* _newUnit = new UnitBase(posX, posY, playerIndex);
	_newUnit->SetName(CUnitManager::ConvertUnitName(type));

	_newUnit->SetHPMax(HP);
	_newUnit->SetRange(150);
	_newUnit->SetAttackDamage(10);
	_newUnit->SetSpeed(speed);

	_newUnit->SetMotion(m_pSpriteManager->GetMotion((int)type));

	// ���� ������ �ڵ�
	_newUnit->TempCover();

	m_UnitPool.push_back(_newUnit);
}

std::string CUnitManager::ConvertUnitName(eUnitType type)
{
	switch (type)
	{
	case eUnitType::BALLISTA:
		return "Ballista";

	case eUnitType::DWARVENDEMOLITIONSQUAD:
		return "DwarvenDemolitionSquad";

	case eUnitType::ELVENARCHER:
		return "lvenArcher";

	case eUnitType::FOOTMAN:
		return "Footman";

	case eUnitType::KNIGHT:
		return "Knight";

	case eUnitType::PEASANT:
		return "Peasant";

	case eUnitType::MAGE:
		return "Mage";

	case eUnitType::GNOMISHFLYINGMACHINE:
		return "GnomishFlyingMachine";

	case eUnitType::GRYPHONRIDER:
		return "GryphonRider";

	case eUnitType::BATTLESHIP:
		return "BattleShip";

	case eUnitType::ELVENDESTROYER:
		return "ElvenDestroyer";

	case eUnitType::HUMANOILTANKER:
		return "HumanOilTanker";

	case eUnitType::TRANSPORT:
		return "Transport";

	case eUnitType::CATAPULT:
		return "Catapult";

	case eUnitType::GOBLINSAPPERS:
		return "GoblinSappers";
	
	case eUnitType::GRUNT:
		return "Grunt";
	
	case eUnitType::OGRE:
		return "Ogre";

	case eUnitType::PEON:
		return "Peon";
	case eUnitType::TROLLAXETHROWER:
		return "TrollAxethrower";

	case eUnitType::DEATHKNIGHT:
		return "DeathKnight";

	case eUnitType::DRAGON:
		return "Dragon";

	case eUnitType::GOBLINZEPPELIN:
		return "GoblinZeppelin";

	case eUnitType::GIANTTURTLE:
		return "GiantTurtle";

	case eUnitType::OGREJUGGERNAUT:
		return "OgreJuggernaut";

	case eUnitType::ORCOILTANKER:
		return "OrcOilTanker";

	case eUnitType::ORCTRANSPORT:
		return "OrcTransport";

	case eUnitType::TROLLDESTROYER:
		return "TrollDestroyer";

	case eUnitType::WISP:
		return "Wisp";

	case eUnitType::ARCHER:
		return "Archer";

	case eUnitType::HUNTRESS:
		return "Huntress";

	case eUnitType::GLAIVETHROWER:
		return "Glaivethrower";

	case eUnitType::DRYAD:
		return "Dryad";

	case eUnitType::DOC_DRUID_FORM:
		return "Doc_Druid_Form";

	case eUnitType::MOUNTAIN_GIANT:
		return "Mountain_Giant";

	case eUnitType::HIPPOGRYPH:
		return "Hippogryph";

	case eUnitType::DOT_CROW_FORM:
		return "Dot_Crow_Form";

	case eUnitType::FAERIE_DRAGON:
		return "Faerie_Dragon";

	case eUnitType::HIPPOGRYPH_RIDER:
		return "Hippogryph_Rider";

	case eUnitType::CHIMAERA:
		return "Chimaera";
	default:
		break;
	}

	return "noname";
}

void CUnitManager::SelectUnits_Area(int left, int top, int right, int bottom)
{
	int _temp = 0;

	if (right < left) { Swap(left, right); }
	if (bottom < top) { Swap(top, bottom); }

	for (unsigned int i = 0; i < m_UnitPool.size(); i++)
	{
		ObjectBase* nuit = m_UnitPool[i];

		if (left <= nuit->GetPosition().x && nuit->GetPosition().x <= right
			&& top <= nuit->GetPosition().y && nuit->GetPosition().y <= bottom)
		{
			nuit->SetIsSelected(true);
		}
		else
		{
			nuit->SetIsSelected(false);
		}
	}

	//for(UnitBase* nuit : m_UnitPool)
	//{
	//	if (left <= nuit->GetPosition().x && nuit->GetPosition().x <= right
	//		&& top <= nuit->GetPosition().y && nuit->GetPosition().y <= bottom)
	//	{
	//		nuit->SetIsSelected(true);
	//	}
	//	else
	//	{
	//		nuit->SetIsSelected(false);
	//	}
		//}
}

void CUnitManager::MoveToDestination(int x, int y)
{
	// ������ ����ִ� �ڷᱸ���� ��ȸ �Ѵ�. 
	for (unsigned int i = 0; i < m_UnitPool.size(); i++)
	{
		ObjectBase* _nowUnit = m_UnitPool[i];

		if (_nowUnit->GetIsSelected() == true)
		{
			_nowUnit->SetDestination(x + rand() % 100 - rand() % 100,
			y + rand() % 100 - rand() % 100);

			_nowUnit->SetNowState(eUnitState::Moving);
		}
	}
}

void CUnitManager::SelectUnits_All()
{
	for (unsigned int i = 0; i < m_UnitPool.size(); i++)
	{
		ObjectBase* _nowUnit = m_UnitPool[i];

		_nowUnit->SetIsSelected(true);
	}
}

void CUnitManager::SetPlayerIndex(UnitBase* nuit, ePlayer index)
{
	nuit->SetPlayerIndex(index);
}

void CUnitManager::DrawSelectBox()
{
	if (m_IsLeftDragging)
	{
		m_pEngine->DrawRectangle(m_DragStartPos.x, m_DragStartPos.y,
			m_NowMousePos.x, m_NowMousePos.y, RGB(0, 255, 0));
	}
}

void CUnitManager::UserInput()
{
	// ���콺 �Է��� �޴´�.
	GetCursorPos(&m_NowMousePos);

	RECT rt;
	GetWindowRect(m_hWnd, &rt);
	m_NowMousePos.x -= rt.left + 5;
	m_NowMousePos.y -= rt.top + 23;

	if (GetAsyncKeyState('1') & 0x0001)
	{
		CreateUnit_New(eUnitType::BALLISTA, GetRand(500, 300), GetRand(500, 300), 3.0f, ePlayer::player1, 50);
	}

	if (GetAsyncKeyState('2') & 0x0001)
	{
		CreateUnit_New(eUnitType::DWARVENDEMOLITIONSQUAD, GetRand(500, 300), GetRand(500, 300), 10.0f, ePlayer::player1, 150);
	}

	if (GetAsyncKeyState('3') & 0x0001)
	{
		CreateUnit_New(eUnitType::ELVENARCHER, GetRand(600, 300), GetRand(600, 300),
			3.0f, ePlayer::player1, 50);
	}

	if (GetAsyncKeyState('4') & 0x0001)
	{
		CreateUnit_New(eUnitType::BALLISTA, GetRand(500, 300), GetRand(500, 300),
			3.0f, ePlayer::player2, 50);
	}

	if (GetAsyncKeyState('5') & 0x0001)
	{
		CreateUnit_New(eUnitType::DWARVENDEMOLITIONSQUAD, GetRand(500, 300), GetRand(500, 300),
			3.0f, ePlayer::player2, 50);
	}

	if (GetAsyncKeyState('6') & 0x0001)
	{
		CreateUnit_New(eUnitType::ELVENARCHER, GetRand(600, 300), GetRand(600, 300),
			3.0f, ePlayer::player2, 50);
	}

	// ::�Ͻ������� �ƹ��͵� �ƴϴٶ�� �ǹ�? 
	if (::GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		// ������ ����ִ� �ڷᱸ���� ��ȸ �Ѵ�. 
		for (unsigned int i = 0; i < m_UnitPool.size(); i++)
		{
			ObjectBase* _nowUnit = m_UnitPool[i];
			_nowUnit->SetPosition(500, 500);
		}
	}

	if (::GetAsyncKeyState(VK_RETURN) & 0x8001)
	{
		// ������ ����ִ� �ڷᱸ���� ��ȸ �Ѵ�. 
		for (unsigned int i = 0; i < m_UnitPool.size(); i++)
		{
			ObjectBase* _nowUnit = m_UnitPool[i];
			_nowUnit->SetPosition(500, 500);
		}
	}

	if (::GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		// ������ ����ִ� �ڷᱸ���� ��ȸ �Ѵ�. 
		MoveToDestination(m_NowMousePos.x, m_NowMousePos.y);
	}

	if (GetAsyncKeyState(VK_F2) & 0x8000)
	{
		SelectUnits_All();
	}

	/// ���콺 �Է��� �� �� ����ȭ �Ѵ�.
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		// ���� ����

		// ������ �� ���� �ִٰ� �̹� �����ӿ� ���� ��
		if (m_RightButtonDown == false)
		{
		}

		m_RightButtonDown = true;
	}
	else
	{
		// �� ���� ����

		// ������ ������ �ִٰ� �̹� �����ӿ� ������ ��
		if (m_RightButtonDown == true)
		{

		}

		m_RightButtonDown = false;
	}

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		// ���� ����

		// ������ �� ���� �ִٰ� �̹� �����ӿ� ���� ��
		if (m_LeftButtonDown == false)
		{
			m_DragStartPos = m_NowMousePos;
			m_IsLeftDragging = true;
		}

		m_LeftButtonDown = true;

	}
	else
	{
		// �� ���� ����

		// ������ ������ �ִٰ� �̹� �����ӿ� ������ ��
		if (m_LeftButtonDown == true)
		{
			SelectUnits_Area(m_DragStartPos.x, m_DragStartPos.y, m_NowMousePos.x, m_NowMousePos.y);
		}

		m_LeftButtonDown = false;

		m_IsLeftDragging = false;
	}

}

void CUnitManager::Swap(int& a, int& b)
{
	int temp = a; 

	a = b;
	b = temp;

}

int CUnitManager::GetRand(int base, int randfactor)
{
	return base - (rand() % randfactor) + (rand() % randfactor);
}

