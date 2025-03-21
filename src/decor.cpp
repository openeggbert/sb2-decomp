// Decor.cpp
//

typedef struct IUnknown IUnknown;


//#include <windows.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
#include <ddraw.h>
#include "def.h"
//#include "resource.h"
#include "pixmap.h"
#include "sound.h"
#include "decor.h"
#include "text.h"
#include "misc.h"
#include "event.h"
#include "dectables.h"
#include "jauge.h"
//#include "network.h"

///////////////////////////////////////////////////////////////////////////////

// Constructor

CDecor::CDecor()
{
	int i;

	// FUN_2bd90(m_jauges, sizeof(CJauge), 2, CJauge::CJauge);
	m_hWnd = NULL;
	m_pSound = NULL;
	m_pPixmap = NULL;

	for (i = 0; i < 200; i++)
	{
		m_lastDecorIndexes[i] = 0;
	}
	m_lastRegion = -1;
	m_iconLift = 0;
	m_time = 0;
	m_bCheatDoors = FALSE;
	m_bSuperBlupi = FALSE;
	m_bDrawSecret = FALSE;
	m_bBuildOfficialMissions = FALSE;
	m_bNetPacked = FALSE;
	m_bNetMovePredict = TRUE;
	m_bNetDebug = FALSE;
	m_bMulti = FALSE;
	m_team = 0;
	m_netPacketsSent = 0;
	m_netPacketsSent2 = 0;
	m_netPacketsReceived = 0;
	m_netPacketsReceived2 = 0;
}

CDecor::~CDecor()
{
	// FUN_2be30(m_jauges, sizeof(CJauge), 2, OutputDebug);
}

void CDecor::Create(HWND hWnd, CSound* pSound, CPixmap* pPixmap, CNetwork* pNetwork)
{
	POINT pos;

	m_hWnd = hWnd;
	m_pSound = pSound;
	m_pPixmap = pPixmap;
	m_pNetwork = pNetwork;
	m_keyPress = 0;
	m_lastKeyPress = 0;
	m_bJoystick = FALSE;
	m_bHelicoMarch = FALSE;
	m_bHelicoStop = FALSE;
	m_bJeepMarch = FALSE;
	m_bJeepStop = FALSE;
	InitDecor();

	m_jauges[JAUGE_AIR].Create(m_hWnd, m_pPixmap, m_pSound, POINT( 169, 450 ), 1, FALSE);
	m_jauges[JAUGE_AIR].SetHide(TRUE);
	m_jauges[JAUGE_POWER].Create(m_hWnd, m_pPixmap, m_pSound, POINT( 171, 450 ), 3, FALSE);
	m_jauges[JAUGE_POWER].SetHide(TRUE);
	NetMessageIndexFlush();
	NotifFlush();
}

BOOL CDecor::LoadImages()
{
	POINT totalDim = { LXIMAGE, LYIMAGE };
	POINT iconDim = { 0, 0 };
	char filename[52];

	if (m_lastRegion == m_region) return TRUE;
	m_lastRegion = m_region;

	sprintf(filename, "decor%.3d.blp", m_region);

	return m_pPixmap->BackgroundCache(CHDECOR, filename, totalDim, iconDim, FALSE);
}

void CDecor::InitGamer()
{
	m_nbVies = 3;
	FillMemory(m_doors, sizeof(m_doors), 1);
}

void CDecor::InitDecor()
{
	int i;
	m_posDecor = POINT( 0, 0 );
	m_dimDecor = POINT( 100, 100 );
	m_music = 1;
	m_region = 2;
	m_missionTitle[0] = '\0';
	m_decorAction = 0;
	for (int x = 0; x < MAXCELX; x++)
	{
		for (int y = 0; y < MAXCELY; y++)
		{
			m_decor[x][y].icon = -1;
			m_bigDecor[x][y].icon = -1;
		}
	}
	m_decor[3][4].icon = 40;
	m_decor[4][4].icon = 38;
	m_decor[5][4].icon = 39;
	for (int k = MAXMOVEOBJECT; k != 0; k--)
	{
		m_moveObject[k].type = 0;
	}
	FlushBalleTraj();
	FlushMoveTraj();
	m_moveObject[0].type = TYPE_TRESOR;
	m_moveObject[0].stepAdvance = 1;
	m_moveObject[0].stepRecede = 1;
	m_moveObject[0].timeStopStart = 0;
	m_moveObject[0].timeStopEnd = 0;
	m_moveObject[0].posStart = POINT( 258, 196 );
	m_moveObject[0].posEnd = m_moveObject[0].posStart;
	m_moveObject[0].posCurrent = m_moveObject[0].posStart;
	m_moveObject[0].phase = 0;
	m_moveObject[0].step = STEP_STOPSTART;
	m_moveObject[0].time = 0;
	m_moveObject[0].channel = CHELEMENT;
	m_moveObject[0].icon = 0;

	m_moveObject[1].type = TYPE_GOAL;
	m_moveObject[1].stepAdvance = 1;
	m_moveObject[1].timeStopStart = 0;
	m_moveObject[1].timeStopEnd = 0;
	m_moveObject[1].posStart = POINT( 322, 196 );
	m_moveObject[1].posEnd = m_moveObject[1].posStart;
	m_moveObject[1].posCurrent = m_moveObject[1].posStart;
	m_moveObject[1].phase = 0;
	m_moveObject[1].step = STEP_STOPSTART;
	m_moveObject[1].time = 0;
	m_moveObject[1].channel = CHELEMENT;
	m_moveObject[1].icon = 29;
	for (i = 0; i < MAXFIFOPOS; i++)
	{
		m_blupiFifoPos[i] = POINT( 0, 0 );
	}
	for (i = 0; i < MAXNETPLAYER; i++)
	{
		m_blupiStartPos[i] = POINT( 194, 192 + BLUPIOFFY );
		m_blupiStartDir[i] = DIR_RIGHT;
	}
	m_blupiAction = ACTION_STOP;
	m_blupiPhase = 0;
	m_blupiIcon = 0;
	m_blupiChannel = CHBLUPI;
	m_blupiFocus = TRUE;
	m_blupiAir = FALSE;
	m_blupiHelico = FALSE;
	m_blupiOver = FALSE;
	m_blupiJeep = FALSE;
	m_blupiTank = FALSE;
	m_blupiSkate = FALSE;
	m_blupiNage = FALSE;
	m_blupiSurf = FALSE;
	m_blupiSuspend = FALSE;
	m_blupiJumpAie = FALSE;
	m_blupiShield = FALSE;
	m_blupiPower = FALSE;
	m_blupiCloud = FALSE;
	m_blupiHide = FALSE;
	m_blupiInvert = FALSE;
	m_blupiBalloon = FALSE;
	m_blupiEcrase = FALSE;
	m_blupiPosHelico.x = -1;
	m_blupiActionOuf = 0;
	m_blupiTimeNoAsc = 0;
	m_blupiTimeMockery = 0;
	m_blupiVitesse = POINT( 0, 0 );
	m_blupiValidPos = m_blupiStartPos[0];
	m_blupiEnergyUnused = 100;
	m_blupiFront = FALSE;
	m_blupiBullet = 0;
	m_blupiCle = 0;
	m_blupiPerso = 0;
	m_blupiDynamite = 0;
	m_nbTresor = 0;
	m_totalTresor = 1;
	m_goalPhase = 0;
	m_scrollPoint = m_blupiStartPos[0];
	m_scrollAdd.x = 0;
	m_scrollAdd.y = 0;
	m_term = 0;
	m_2ndPositionCalculationSlot = -1;
}

void CDecor::SetTime(int time)
{
	m_time = time;
}

int CDecor::GetTime()
{
	return m_time;
}

void CDecor::PlayPrepare(BOOL bTest)
{
	if (bTest) m_nbVies = 3;

	if (m_bMulti)
	{
		m_nbVies = 10;
		m_blupiPos = m_blupiStartPos[m_team];
		m_blupiDir = m_blupiStartDir[m_team];
	}
	else
	{
		m_blupiPos = m_blupiStartPos[0];
		m_blupiDir = m_blupiStartDir[0];
	}

	if (m_blupiDir == DIR_LEFT)
	{
		m_blupiIcon = 4;
	}
	else
	{
		m_blupiIcon = 0;
	}

	m_blupiAction = ACTION_STOP;
	m_blupiPhase = 0;
	m_blupiFocus = TRUE;
	m_blupiAir = FALSE;
	m_blupiHelico = FALSE;
	m_blupiOver = FALSE;
	m_blupiJeep = FALSE;
	m_blupiTank = FALSE;
	m_blupiSkate = FALSE;
	m_blupiNage = FALSE;
	m_blupiSurf = FALSE;
	m_blupiSuspend = FALSE;
	m_blupiJumpAie = FALSE;
	m_blupiShield = FALSE;
	m_blupiPower = FALSE;
	m_blupiCloud = FALSE;
	m_blupiHide = FALSE;
	m_blupiInvert = FALSE;
	m_blupiBalloon = FALSE;
	m_blupiEcrase = FALSE;
	m_blupiActionOuf = 0;
	m_blupiTimeNoAsc = 0;
	m_blupiTimeMockery = 0;
	m_blupiValidPos = m_blupiPos;
	m_blupiEnergyUnused = 100;
	m_blupiBullet = 0;
	m_blupiCle = 0;
	m_blupiPerso = 0;
	m_blupiDynamite = 0;
	m_nbTresor = 0;
	m_totalTresor = 0;
	for (int i = MAXMOVEOBJECT; i != 0; i--)
	{
		if (m_moveObject[i].type == TYPE_TRESOR)
		{
			m_totalTresor++;
		}
		m_moveObject[i].posCurrent = m_moveObject[i].posStart;
		m_moveObject[i].step = STEP_STOPSTART;
		m_moveObject[i].phase = 0;
		m_moveObject[i].time = 0;

		if (m_moveObject[i].type == TYPE_TRESOR ||
			m_moveObject[i].type == TYPE_EGG ||
			m_moveObject[i].type == TYPE_SHIELD ||
			m_moveObject[i].type == TYPE_POWER ||
			m_moveObject[i].type == TYPE_INVERT ||
			m_moveObject[i].type == TYPE_BOMBEDOWN ||
			m_moveObject[i].type == TYPE_BOMBEUP ||
			m_moveObject[i].type == TYPE_BOMBEFOLLOW1 ||
			m_moveObject[i].type == TYPE_BOMBEFOLLOW2)
		{
			m_moveObject[i].phase = rand() % 23;
		}

		if (m_moveObject[i].type == TYPE_BALLE)
		{
			m_moveObject[i].type = 0;
		}

		if (m_bMulti &&
			(m_moveObject[i].type == TYPE_CAISSE ||
			m_moveObject[i].type == TYPE_GOAL ||
			m_moveObject[i].type == TYPE_CLE ||
			m_moveObject[i].type == TYPE_BLUPIHELICO ||
			m_moveObject[i].type == TYPE_BLUPITANK))
		{
			m_moveObject[i].type = 0;
		}
	}
	m_goalPhase = 0;
	MoveObjectSort();
	UpdateCaisse();
	m_scrollPoint = m_blupiPos;
	m_scrollAdd = POINT( 0, 0 );
	m_blupiPosHelico.x = -1;
	m_nbLinkCaisse = 0;
	m_bHelicoMarch = FALSE;
	m_bHelicoStop = FALSE;
	m_bJeepMarch = FALSE;
	m_bJeepStop = FALSE;
	m_blupiFront = FALSE;
	m_blupiNoBarre = 0;
	m_blupiValidPos = m_blupiPos;
	m_blupiFifoNb = 0;
	m_blupiTimeFire = 0;
	NetDataFlush();
	NotifFlush();
	m_voyageIcon = -1;
	m_jauges[JAUGE_AIR].SetHide(TRUE);
	m_jauges[JAUGE_POWER].SetHide(TRUE);
	m_bFoundCle = FALSE;
	m_term = 0;
	m_time = 0;
	m_bPause = FALSE;
}

void CDecor::BuildPrepare()
{
	for (int i = 0; i < MAXMOVEOBJECT; i++)
	{
		m_moveObject[i].posCurrent = m_moveObject[i].posStart;
		m_moveObject[i].step = STEP_STOPSTART;
		m_moveObject[i].time = 0;
		m_moveObject[i].phase = 0;
		if (m_moveObject[i].type == TYPE_BALLE)
		{
			m_moveObject[i].type = 0;
		}
	}
	m_voyageIcon = -1;
	m_posCelHili.x = -1;
	m_2ndPositionCalculationSlot = -1;
	m_time = 0;
	m_bPause = FALSE;
	NetDataFlush();
}

int CDecor::IsTerminated()
{
	return m_term;
}

void CDecor::MoveStep()
{
	MoveObjectStep();

	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST) {
		BlupiStep();
		NetAdjustToLift();
		NotifStep();
	}

	if (m_phase == WM_PHASE_BUILD)
	{
		if (m_keyPress & KEY_RIGHT)
		{
			m_posDecor.x += 50;
			int limit = (m_dimDecor.x != 0) ? (MAXCELX * DIMOBJX - LXIMAGE) : 0;
			if (m_posDecor.x > limit) m_posDecor.x = limit;
			m_posCelHili.x = -1;
		}
		if (m_keyPress & KEY_LEFT)
		{
			m_posDecor.x -= 50;
			if (m_posDecor.x < 0) m_posDecor.x = 0;
			m_posCelHili.x = -1;
		}
		if (m_keyPress & KEY_DOWN)
		{
			m_posDecor.y += 50;
			int limit = (m_dimDecor.y > 0) ? (MAXCELY * DIMOBJY - LYIMAGE) : 0;
			if (m_posDecor.y > limit) m_posDecor.y = limit;
			m_posCelHili.x = -1;
		}
		if (m_keyPress & KEY_UP)
		{
			m_posDecor.y -= 50;
			if (m_posDecor.y < 0) m_posDecor.y = 0;
			m_posCelHili.x = -1;
		}
	}
}

int CDecor::GetIconPerso()
{
	if (m_bMulti) {
		return m_team + 108;
	}
	else {
		return 108;
	}
}

void CDecor::Build(RECT rect)
{
	int num = 1;
	int i, j;
	POINT tinyPoint;
	tinyPoint.x = 0;
	RECT lastClip;

	lastClip = m_pPixmap->GetClipping();
	m_pPixmap->SetClipping(rect);

	POINT posDecor = DecorNextAction();
	POINT pos = { posDecor.x * 2 / 3 % DIMDECORX, posDecor.y * 2 / 3 % DIMDECORY };

	for (i = 0; i < ((DIMDECORX - DIMDECORX / LXIMAGE * LXIMAGE) ? 2 : 1) + LXIMAGE / DIMDECORX; i++)
	{
		tinyPoint.y = 0;
		rect.top = pos.y;
		for (j = 0; j < ((DIMDECORY - DIMDECORY / LYIMAGE * LYIMAGE) ? 2 : 1) + LYIMAGE / DIMDECORY; j++)
		{
			rect.left = i ? 0 : pos.x;
			rect.right = DIMDECORX;
			rect.bottom = DIMDECORY;
			m_pPixmap->DrawPart(-1, CHDECOR, tinyPoint, rect, 1, FALSE);
			tinyPoint.y = DIMDECORY * (j + 1) - pos.y;
			rect.top = 0;
		}
		tinyPoint.x = DIMDECORX * (i + 1) - pos.x;

	}

	tinyPoint.x = -posDecor.x % DIMOBJX - DIMOBJX;
	for (i = posDecor.x / DIMOBJX - 1; i < posDecor.x / DIMOBJX + LXIMAGE / DIMOBJX + 3; i++) {
		tinyPoint.y = -posDecor.y % DIMOBJY + 2 - DIMOBJY;
		for (j = posDecor.y / DIMOBJY - 1; j < posDecor.y / DIMOBJY + LYIMAGE / DIMOBJY + 2; j++)
		{
			if (i >= 0 && i < MAXCELX && j >= 0 && j < MAXCELY)
			{
				int num2 = m_bigDecor[i][j].icon;
				int channel = 9;
				if (num2 != -1)
				{
					pos = tinyPoint;
					if (num2 == 203)
					{
						num2 = table_marine[m_time / 3 % 11];
						channel = 1;
					}
					if (num2 >= 66 && num2 <= 68)
					{
						pos.y -= 13;
					}
					if (num2 >= 87 && num2 <= 89)
					{
						pos.y -= 2;
					}
					m_pPixmap->QuickIcon(channel, num2, pos);
				}
			}
			tinyPoint.y += DIMOBJY;
		}
		tinyPoint.x += DIMOBJX;
	}

	tinyPoint.x = -posDecor.x % DIMOBJX;
	for (i = posDecor.x / DIMOBJX; i < posDecor.x / DIMOBJX + LXIMAGE / DIMOBJX + 2; i++)
	{
		tinyPoint.y = -posDecor.y % DIMOBJY;
		for (j = posDecor.y / DIMOBJY; j < posDecor.y / DIMOBJY + LYIMAGE / DIMOBJY + 2; j++)
		{
			if (i >= 0 && i < MAXCELX && j >= 0 && j < MAXCELY && m_decor[i][j].icon != -1)
			{
				int num2 = m_decor[i][j].icon;
				if (num2 == 384 || num2 == 385)
				{
					m_pPixmap->QuickIcon(CHOBJECT, num2, tinyPoint);
				}
			}
			tinyPoint.y += DIMOBJY;
		}
		tinyPoint.x += DIMOBJX;
	}

	if (m_phase == WM_PHASE_BUILD)
	{
		// draw blupi start positions...
	}

	if (m_bMulti && m_phase != WM_PHASE_BUILD)
	{
		// ...
	}

	m_blupiSec = 0;
	if (!m_blupiFront && m_phase != WM_PHASE_BUILD)
	{
		tinyPoint.x = m_blupiPos.x - posDecor.x;
		tinyPoint.y = m_blupiPos.y - posDecor.y;
		if (m_blupiJeep)
		{
			tinyPoint.y += BLUPIOFFY;
		}
		if (m_blupiShield)
		{
			m_blupiSec = SEC_SHIELD;
			if (m_blupiTimeShield > 25 || m_time % 4 < 2)
			{
				int num2 = table_shield_blupi[m_time / 2 % 16];
				tinyPoint.y -= 2;
				m_pPixmap->QuickIcon(CHELEMENT, num2, tinyPoint);
				tinyPoint.y += 2;
				num2 = table_shieldloop[m_time / 2 % 5];
				m_pPixmap->QuickIcon(CHELEMENT, num2, tinyPoint);
			}
		}
		else if (m_blupiPower)
		{
			m_blupiSec = SEC_POWER;
			if (m_blupiTimeShield > 25 || m_time % 4 < 2)
			{
				int num2 = table_magicloop[m_time / 2 % 5];
				m_pPixmap->QuickIcon(CHELEMENT, num2, tinyPoint);
			}
		}
		else if (m_blupiCloud)
		{
			m_blupiSec = SEC_CLOUD;
			if (m_blupiTimeShield > 25 || m_time % 4 < 2)
			{
				for (int k = 0; k < 3; k++)
				{
					int num2 = 48 + (m_time + k) % 6;
					pos.x = tinyPoint.x - 34;
					pos.y = tinyPoint.y - 34;
					m_pPixmap->QuickIcon(CHEXPLO, num2, pos);
				}
			}
		}
		else if (m_blupiHide)
		{
			m_blupiSec = SEC_HIDE;
			if (m_blupiTimeShield > 25 || m_time % 4 < 2)
			{
				m_pPixmap->DrawIcon(CHTEMP, CHOBJECT, 0xF5, POINT( 0, 0 ), 0, TRUE);
			}
			else
			{
				m_pPixmap->DrawIcon(CHTEMP, GetBlupiChannelStandard(), m_blupiIcon, pos, 1, FALSE);
				m_pPixmap->DrawIcon(CHTEMP, CHOBJECT, 0xED, POINT( 0, 0 ), 0, TRUE);
			}
		}
		m_pPixmap->QuickIcon(GetBlupiChannelStandard(), m_blupiIcon, tinyPoint);
	}

	for (i = 0; i < MAXMOVEOBJECT; i++)
	{
		if (m_moveObject[i].type != 0 && m_moveObject[i].posCurrent.x >= posDecor.x - 64 && m_moveObject[i].posCurrent.y >= posDecor.y - 64 && m_moveObject[i].posCurrent.x <= posDecor.x + LXIMAGE && m_moveObject[i].posCurrent.y <= posDecor.y + LYIMAGE && (m_moveObject[i].type < 8 || m_moveObject[i].type > 11) && (m_moveObject[i].type < 90 || m_moveObject[i].type > 95) && (m_moveObject[i].type < 98 || m_moveObject[i].type > 100) && m_moveObject[i].type != 53 && m_moveObject[i].type != 1 && m_moveObject[i].type != 47 && m_moveObject[i].type != 48)
		{
			tinyPoint.x = m_moveObject[i].posCurrent.x - posDecor.x;
			tinyPoint.y = m_moveObject[i].posCurrent.y - posDecor.y;
			if (m_moveObject[i].type == TYPE_BULLDOZER || m_moveObject[i].type == TYPE_BLUPIHELICO || m_moveObject[i].type == TYPE_BLUPITANK)
			{
				tinyPoint.x += 2;
				tinyPoint.y += BLUPIOFFY;
			}
			if (m_moveObject[i].type == TYPE_CREATURE)
			{
				tinyPoint.y += BLUPIOFFY;
			}
			// get the winphone opacity stuff out of here
			m_pPixmap->QuickIcon(m_moveObject[i].channel, m_moveObject[i].icon, tinyPoint);
			if (m_moveObject[i].type == TYPE_DRINK)
			{
				for (int L = 0; L < sizeof(table_drinkoffset) / sizeof(int); L++)
				{
					int num4 = (m_time + table_drinkoffset[L]) % 50;
					int rank = table_drinkeffect[num4 % 5];
					POINT tinyPoint2 = { tinyPoint.x + 2, tinyPoint.y - num4 * 3 };
					POINT pos2 = tinyPoint2;
					m_pPixmap->QuickIcon(10, rank, pos2);
				}
			}
			if (m_bDrawSecret && m_moveObject[i].type == TYPE_CAISSE && m_moveObject[i].icon != 32 && m_moveObject[i].icon != 33 && m_moveObject[i].icon != 34)
			{
				m_pPixmap->QuickIcon(1, 214, tinyPoint);
			}
		}
	}
	tinyPoint.x = -posDecor.x % 64;
	for (i = posDecor.x / 64; i < posDecor.x / 64 + LXIMAGE / 64 + 2; i++)
	{
		tinyPoint.y = 0 - posDecor.y % 64;
		for (j = posDecor.y / 64; j < posDecor.y / 64 + LYIMAGE / 64 + 2; j++)
		{
			if (i >= 0 && i < 100 && j >= 0 && j < 100 && m_decor[i][j].icon != -1)
			{
				int num2 = m_decor[i][j].icon;
				pos.x = tinyPoint.x;
				pos.y = tinyPoint.y;
				if ((num2 >= 107 && num2 <= 109) || num2 == 157)
				{
					pos.y -= 7;
				}
				if (num2 == 211)
				{
					num2 = table_ressort[(m_time / 2 + i * 7) % 8];
				}
				if (num2 == 214 && !m_bDrawSecret)
				{
					num2 = -1;
				}
				if (num2 == 364)
				{
					pos.y -= 2;
				}
				switch (num2)
				{
				default:
					m_pPixmap->QuickIcon(1, num2, pos);
					break;
				case 68:
				case 91:
				case 92:
				case 110:
				case 111:
				case 112:
				case 113:
				case 114:
				case 115:
				case 116:
				case 117:
				case 118:
				case 119:
				case 120:
				case 121:
				case 122:
				case 123:
				case 124:
				case 125:
				case 126:
				case 127:
				case 128:
				case 129:
				case 130:
				case 131:
				case 132:
				case 133:
				case 134:
				case 135:
				case 136:
				case 137:
				case 305:
				case 317:
				case 324:
				case 373:
				case 378:
				case 384:
				case 385:
				case 404:
				case 410:
					break;
				}
			}
			tinyPoint.y += DIMOBJY;
		}
		tinyPoint.x += DIMOBJX;
	}
	for (int num3 = 0; num3 < MAXMOVEOBJECT; num3++)
	{
		if ((m_moveObject[num3].type == TYPE_ASCENSEUR ||
			m_moveObject[num3].type == TYPE_ASCENSEURs ||
			m_moveObject[num3].type == TYPE_ASCENSEURsi) &&
			m_moveObject[num3].posCurrent.x >= posDecor.x - DIMOBJX &&
			m_moveObject[num3].posCurrent.y >= posDecor.y - DIMOBJY &&
			m_moveObject[num3].posCurrent.x <= posDecor.x + LXIMAGE &&
			m_moveObject[num3].posCurrent.y <= posDecor.y + LYIMAGE)
		{
			tinyPoint.x = 0 + m_moveObject[num3].posCurrent.x - posDecor.x;
			tinyPoint.y = 0 + m_moveObject[num3].posCurrent.y - posDecor.y;
			m_pPixmap->QuickIcon(m_moveObject[num3].channel, m_moveObject[num3].icon, tinyPoint);
		}
	}
	tinyPoint.x = 0 - posDecor.x % DIMOBJX;
	for (i = posDecor.x / DIMOBJX; i < posDecor.x / DIMOBJX + LXIMAGE / DIMOBJX + 2; i++)
	{
		tinyPoint.y = 0 - posDecor.y % DIMOBJY;
		for (j = posDecor.y / DIMOBJY; j < posDecor.y / DIMOBJY + LYIMAGE / DIMOBJY + 2; j++)
		{
			if (i >= 0 && i < MAXCELX && j >= 0 && j < MAXCELY && m_decor[i][j].icon != -1)
			{
				int num2 = m_decor[i][j].icon;
				pos = tinyPoint;
				if (num2 == 68)
				{
					num2 = table_decor_lave[(i * 13 + j * 7 + m_time / 2) % 8];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 373)
				{
					num2 = ((!m_blupiFocus) ? table_decor_piege2[(i * 13 + j * 7 + m_time / 2) % 4] : table_decor_piege1[(i * 13 + j * 7 + m_time / 4) % 16]);
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 404 || num2 == 410)
				{
					num2 = table_decor_goutte[(i * 13 + j * 7 + m_time / 2) % 48];
					pos.y -= 9;
					m_pPixmap->QuickIcon(1, num2, pos);
					if (num2 >= 404 && num2 <= 407)
					{
						m_decor[i][j].icon = 404;
					}
					else
					{
						m_decor[i][j].icon = 410;
					}
				}
				if (num2 == 317)
				{
					num2 = table_decor_ecraseur[m_time / 3 % 10];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 378)
				{
					num2 = table_decor_scie[(i * 13 + j * 7 + m_time / 1) % 6];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 324)
				{
					num2 = table_decor_temp[m_time / 4 % 20];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 92)
				{
					num2 = table_decor_eau1[(i * 13 + j * 7 + m_time / 3) % 6];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 91)
				{
					int num5 = 3 + (i * 17 + j * 13) % 3;
					num2 = table_decor_eau2[(i * 11 + j * 7 + m_time / num5) % 6];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 305 && BlitzActif(POINT( i, j )))
				{
					num2 = rand() % 4 + 305;
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 110)
				{
					num2 = table_decor_ventg[m_time / 1 % 4];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 114)
				{
					num2 = table_decor_ventd[m_time / 1 % 4];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 118)
				{
					num2 = table_decor_venth[m_time / 1 % 4];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 122)
				{
					num2 = table_decor_ventb[m_time / 1 % 4];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 126)
				{
					num2 = table_decor_ventillog[m_time / 2 % 3];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 129)
				{
					num2 = table_decor_ventillod[m_time / 2 % 3];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 132)
				{
					num2 = table_decor_ventilloh[m_time / 2 % 3];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
				if (num2 == 135)
				{
					num2 = table_decor_ventillob[m_time / 2 % 3];
					m_pPixmap->QuickIcon(1, num2, pos);
				}
			}
			tinyPoint.y += DIMOBJY;
		}
		tinyPoint.x += DIMOBJX;
	}
	for (i = 0; i < MAXMOVEOBJECT; i++)
	{
		if (m_moveObject[i].type != 0 &&
			m_moveObject[i].posCurrent.x >= posDecor.x - DIMOBJX &&
			m_moveObject[i].posCurrent.y >= posDecor.y - DIMOBJY &&
			m_moveObject[i].posCurrent.x <= posDecor.x + LXIMAGE &&
			m_moveObject[i].posCurrent.y <= posDecor.y + LYIMAGE &&
			((m_moveObject[i].type >= TYPE_EXPLO1 && m_moveObject[i].type <= TYPE_EXPLO3) ||
			(m_moveObject[i].type >= TYPE_EXPLO5 && m_moveObject[i].type <= TYPE_EXPLO10) ||
			(m_moveObject[i].type >= TYPE_SPLOUTCH1 && m_moveObject[i].type <= TYPE_SPLOUTCH3) ||
			m_moveObject[i].type == TYPE_TENTACULE))
		{
			tinyPoint = m_moveObject[i].posCurrent - posDecor;
			m_pPixmap->QuickIcon(m_moveObject[i].channel, m_moveObject[i].icon, tinyPoint);
		}
		////debug
		if (m_moveObject[i].posCurrent.x >= posDecor.x - 64 && m_moveObject[i].posCurrent.y >= posDecor.y - 64 && m_moveObject[i].posCurrent.x <= posDecor.x + LXIMAGE && m_moveObject[i].posCurrent.y <= posDecor.y + LYIMAGE)
		{
			char str[50];
			sprintf(str, "[%d]: %d", i, m_moveObject[i].type);
			DrawText(m_pPixmap, m_moveObject[i].posCurrent - posDecor, str, FONTLITTLE);
		}
		////
	}
	if (m_blupiFront)
	{
		tinyPoint = m_blupiPos - posDecor;
		m_pPixmap->QuickIcon(m_blupiChannel, m_blupiIcon, tinyPoint);
	}
	DrawInfo();
	VoyageDraw();
	m_time++;
}

void CDecor::DrawInfo()
{
	POINT pos;
	char text[100];
	int i;

	if (m_phase == WM_PHASE_PLAY || m_phase == WM_PHASE_PLAYTEST)
	{
		pos = POINT( 10, 10 );
		for (i = 0; i < MAXNOTIF; i++) {
			if (m_notifText[i][0] != '\0') {
				DrawText(m_pPixmap, pos, m_notifText[i], FONTWHITE);
			}
			pos.y += DIMTEXTY;
		}

		if (m_nbVies > 0) {
			pos = POINT( -15, 417 );
			for (int i = 0; i < m_nbVies; i++) {
				m_pPixmap->QuickIcon(GetBlupiChannelActual(), 48, pos);
				pos.x += 16;
			}
		}

		if (m_blupiBullet > 0) {
			pos = POINT( 398, 442 );
			for (int i = 0; i < m_blupiBullet; i++) {
				m_pPixmap->QuickIcon(CHELEMENT, 176, pos);
				pos.x += 4;
			}
		}

		if (m_blupiPerso > 0) {
			m_pPixmap->QuickIcon(CHBUTTON, GetIconPerso(), POINT( 465, 438 ));
			sprintf(text, "= %d", m_blupiPerso);
			DrawText(m_pPixmap, POINT( 497, 452 ), text, FONTWHITE);
		}

		if (m_blupiDynamite > 0) {
			m_pPixmap->QuickIcon(CHELEMENT, 252, POINT( 505, 414 ));
		}

		if (m_blupiCle & CLE_RED) {
			m_pPixmap->QuickIcon(CHELEMENT, 215, POINT( 520, 418 ));
		}

		if (m_blupiCle & CLE_GREEN) {
			m_pPixmap->QuickIcon(CHELEMENT, 222, POINT( 530, 418 ));
		}

		if (m_blupiCle & CLE_BLUE) {
			m_pPixmap->QuickIcon(CHELEMENT, 229, POINT( 540, 418 ));
		}

		if ((m_mission != 1 && m_mission % 10 != 0) || m_bPrivate)
		{
			sprintf(text, "%d/%d", m_nbTresor, m_totalTresor);
			DrawText(m_pPixmap, POINT( 590, 452 ), text, FONTWHITE);
		}

		for (i = 0; i < 2; i++)
		{
			if (!(m_jauges[i].GetHide())) m_jauges[i].Draw();
		}

		if (m_mission == 10 && m_phase == WM_PHASE_PLAY && !m_bPrivate)
		{
			switch (m_nbTresor)
			{
			case 0:
				if (m_blupiPos.x > 212) m_blupiPos.x = 212;
				break;
			case 1:
				if (m_blupiPos.x > 788) m_blupiPos.x = 788;
				break;
			}
			
			POINT cel = { (m_blupiPos.x + DIMBLUPIX / 2) / DIMOBJX, (m_blupiPos.y + DIMBLUPIY / 2) / DIMOBJY };
			for (i = 0; table_tutorial[i * 6 + 0] != -1; i++)
			{
				if (cel.x >= table_tutorial[i * 6 + 0] &&
					cel.x <= table_tutorial[i * 6 + 1] &&
					cel.y >= table_tutorial[i * 6 + 2] &&
					cel.y <= table_tutorial[i * 6 + 3])
				{
					if (table_tutorial[i * 6 + 4] == -1 || table_tutorial[i * 6 + 4] == m_nbTresor)
					{
						if (m_bJoystick)
						{
							LoadString(table_tutorial[i * 6 + 5] + 100, text, 100);
						}
						else
						{
							LoadString(table_tutorial[i * 6 + 5], text, 100);
						}
						DrawTextCenter(m_pPixmap, POINT(360, 460), text);
						break;
					}
				}
			}
		}
	}
	if (m_phase == WM_PHASE_BUILD)
	{
		if (m_posCelHili.x != -1)
		{
			int icon = 0;
			if (m_2ndPositionCalculationSlot != -1)
			{
				icon = 31;
			}
			if (m_dimCelHili.x > 0)
			{
				pos.x = m_posCelHili.x * DIMOBJX - m_posDecor.x;
				
				int j = 0;
				for (i = 0; i < m_dimCelHili.x; i++)
				{
					pos.y = m_posCelHili.y * DIMOBJY - m_posDecor.y;
					for (j = 0; j < m_dimCelHili.y; j++)
					{
						m_pPixmap->QuickIcon(CHOBJECT, icon, pos);
						pos.y += DIMOBJY;
					}
					pos.x += DIMOBJX;
				}
			}
		}
		if (m_phase == WM_PHASE_BUILD) // again???
		{
			LoadString(0x66, text, 100);
			DrawText(m_pPixmap, POINT(200, 460), text, FONTGOLD);
		}
	}
	if (m_phase == WM_PHASE_PLAYTEST)
	{
		LoadString(0x67, text, 100);
		DrawText(m_pPixmap, POINT(200, 460), text, FONTGOLD);
	}
}

POINT CDecor::DecorNextAction()
{
	int num = 0;
	if (m_decorAction == 0 || m_bPause)
	{
		return m_posDecor;
	}
	POINT posDecor = m_posDecor;
	while (table_decor_action[num] != 0)
	{
		if (m_decorAction == table_decor_action[num])
		{
			if (m_decorPhase < table_decor_action[num + 1])
			{
				posDecor.x += 3 * table_decor_action[num + 2 + m_decorPhase * 2];
				posDecor.y += 3 * table_decor_action[num + 2 + m_decorPhase * 2 + 1];
				int num2;
				if (m_dimDecor.x == 0)
				{
					num2 = 0;
				}
				else
				{
					num2 = DIMOBJX * MAXCELX - LXIMAGE;
				}
				if (posDecor.x < 0)
				{
					posDecor.x = 0;
				}
				if (posDecor.x > num2)
				{
					posDecor.x = num2;
				}
				if (m_dimDecor.y == 0)
				{
					num2 = 0;
				}
				else
				{
					num2 = DIMOBJY * MAXCELY - LYIMAGE;
				}
				if (posDecor.y < 0)
				{
					posDecor.y = 0;
				}
				if (posDecor.y > num2)
				{
					posDecor.y = num2;
				}
				m_decorPhase++;
				break;
			}
			m_decorAction = 0;
			break;
		}
		else
		{
			num += 2 + table_decor_action[num + 1] * 2;
		}
	}
	return posDecor;
}

void CDecor::SetInput(int keys)
{
	m_keyPress = keys;
	if (m_blupiInvert)
	{
		if (keys & KEY_LEFT)
		{
			m_keyPress = keys & ~KEY_LEFT | KEY_RIGHT;
		}
		if (keys & KEY_RIGHT)
		{
			m_keyPress = m_keyPress & ~KEY_RIGHT | KEY_LEFT;
		}
	}
}

void CDecor::SetJoystickEnable(BOOL bJoystick)
{
	m_bJoystick = bJoystick;
}

void CDecor::SetDemoPlay(BOOL param)
{
	m_bDemoPlay = param;
}

void CDecor::PlaySound(int sound, POINT pos, BOOL bLocal)
{
	if (!bLocal) NetPlaySound(sound, pos);

	m_pSound->PlayImage(sound, POINT(pos.x - m_posDecor.x, pos.y - m_posDecor.y), -1);

	switch (sound) {
	case SOUND_HELICOHIGH:
		m_bHelicoMarch = TRUE;
		break;
	case SOUND_HELICOLOW:
		m_bHelicoStop = TRUE;
		break;
	case SOUND_JEEPHIGH:
		m_bJeepMarch = TRUE;
		break;
	case SOUND_JEEPLOW:
		m_bJeepStop = TRUE;
		break;
	}
}

void CDecor::PlaySound(int sound, POINT pos)
{
	PlaySound(sound, pos, FALSE);
}

void CDecor::StopSound(int sound)
{
	m_pSound->StopSound(sound);

	switch (sound) {
	case SOUND_HELICOHIGH:
		m_bHelicoMarch = FALSE;
		break;
	case SOUND_HELICOLOW:
		m_bHelicoStop = FALSE;
		break;
	case SOUND_JEEPHIGH:
		m_bJeepMarch = FALSE;
		break;
	case SOUND_JEEPLOW:
		m_bJeepStop = FALSE;
		break;
	}
}

void CDecor::AdaptMotorVehicleSound(POINT pos)
{
	POINT blupiPos = POINT(pos.x - m_posDecor.x, pos.y - m_posDecor.y);

	if (m_bHelicoMarch) m_pSound->PlayImage(SOUND_HELICOHIGH, blupiPos);
	if (m_bHelicoStop) m_pSound->PlayImage(SOUND_HELICOLOW, blupiPos);
	if (m_bJeepMarch)  m_pSound->PlayImage(SOUND_JEEPHIGH, blupiPos);
	if (m_bJeepStop) m_pSound->PlayImage(SOUND_JEEPLOW, blupiPos);
}

void CDecor::VehicleSoundsPhase(int phase)
{
	m_phase = phase;

	if (phase == WM_PHASE_PLAY || phase == WM_PHASE_PLAYTEST) {
		int channel = -1;
		if (m_bHelicoMarch) channel = SOUND_HELICOHIGH;
		if (m_bHelicoStop) channel = SOUND_HELICOLOW;
		if (m_bJeepMarch) channel = SOUND_JEEPHIGH;
		if (m_bJeepStop) channel = SOUND_JEEPLOW;
		if (channel != -1) m_pSound->PlayImage(channel, POINT( LXIMAGE / 2, LYIMAGE / 2 ), -1);
	}
	else {
		if (m_bHelicoMarch) m_pSound->StopSound(SOUND_HELICOHIGH);
		if (m_bHelicoStop) m_pSound->StopSound(SOUND_HELICOLOW);
		if (m_bJeepMarch) m_pSound->StopSound(SOUND_JEEPHIGH);
		if (m_bJeepStop) m_pSound->StopSound(SOUND_JEEPLOW);
	}
}

int CDecor::GetRegion()
{
	return m_region;
}

void CDecor::SetRegion(int region)
{
	m_region = region;
}

int CDecor::GetMusic()
{
	return m_music;
}

void CDecor::SetMusic(int music)
{
	m_music = music;
}

POINT CDecor::GetDim()
{
	return m_dimDecor;
}

void CDecor::SetDim(POINT dim)
{
	m_dimDecor = dim;
}

int CDecor::GetNbVies()
{
	return m_nbVies;
}

void CDecor::SetNbVies(int nbVies)
{
	m_nbVies = nbVies;
}

BOOL CDecor::GetPause()
{
	return m_bPause;
}

void CDecor::SetPause(BOOL bPause)
{
	m_bPause = bPause;
}

void CDecor::InitializeDoors(BYTE* doors)
{
	for (int i = 0; i < 200; i++)
	{
		doors[i] = m_doors[i];
	}
}

void CDecor::MemorizeDoors(BYTE* doors)
{
	for (int i = 0; i < 200; i++)
	{
		m_doors[i] = doors[i];
	}
}

void CDecor::SetAllMissions(BOOL bAllMissions)
{
	m_bCheatDoors = bAllMissions;
	AdaptDoors(m_bPrivate, m_mission);
	return;
}

void CDecor::CheatAction(int cheat)
{
	MoveObject* mob;
	int i;

	switch (cheat)
	{
	case 2: // cleanall
		for (i = 0; i < MAXMOVEOBJECT; i++)
		{
			mob = &m_moveObject[i];
			switch (mob->type)
			{
			case TYPE_BOMBEDOWN:
			case TYPE_BOMBEUP:
			case TYPE_BOMBEFOLLOW1:
			case TYPE_BOMBEFOLLOW2:
			case TYPE_BULLDOZER:
			case TYPE_BOMBEMOVE:
			case TYPE_POISSON:
			case TYPE_OISEAU:
			case TYPE_GUEPE:
			case TYPE_CREATURE:
			case TYPE_BLUPIHELICO:
			case TYPE_BLUPITANK:
				m_decorAction = 1;
				m_decorPhase = 0;
				mob->type = TYPE_EXPLO1;
				mob->phase = 0;
				mob->posCurrent.x -= 34;
				mob->posCurrent.y -= 34;
				mob->posStart = mob->posCurrent;
				mob->posEnd = mob->posCurrent;
				MoveObjectStepIcon(i);
				PlaySound(SOUND_BOUM, mob->posCurrent, FALSE);
			}
		}
		break;
	case 6: // funskate
		m_blupiAir = FALSE;
		m_blupiHelico = FALSE;
		m_blupiOver = FALSE;
		m_blupiJeep = FALSE;
		m_blupiTank = FALSE;
		m_blupiSkate = TRUE;
		m_blupiNage = FALSE;
		m_blupiSurf = FALSE;
		m_blupiVent = FALSE;
		m_blupiSuspend = FALSE;
		StopVehicleSound();
		break;
	case 7: // givecopter
		m_blupiAir = FALSE;
		m_blupiHelico = TRUE;
		m_blupiOver = FALSE;
		m_blupiJeep = FALSE;
		m_blupiTank = FALSE;
		m_blupiSkate = FALSE;
		m_blupiNage = FALSE;
		m_blupiSurf = FALSE;
		m_blupiVent = FALSE;
		m_blupiSuspend = FALSE;
		StopVehicleSound();
		PlaySound(SOUND_HELICOSTART, m_blupiPos, FALSE);
		PlaySound(SOUND_HELICOLOW, m_blupiPos, TRUE);
		break;
	case 8: // jeepdrive
		m_blupiAir = FALSE;
		m_blupiHelico = FALSE;
		m_blupiOver = FALSE;
		m_blupiJeep = TRUE;
		m_blupiTank = FALSE;
		m_blupiSkate = FALSE;
		m_blupiNage = FALSE;
		m_blupiSurf = FALSE;
		m_blupiVent = FALSE;
		m_blupiSuspend = FALSE;
		StopVehicleSound();
		PlaySound(SOUND_JEEPLOW, m_blupiPos, TRUE);
		break;
	case 9: // alltreasure
		for (i = 0; i < MAXMOVEOBJECT; i++)
		{
			if (m_moveObject[i].type == TYPE_TRESOR)
			{
				m_moveObject[i].type = 0;
				m_nbTresor++;
				OpenDoorsTresor();
				PlaySound(SOUND_TRESOR, m_moveObject[i].posCurrent, FALSE);
			}
		}
		break;
	case 10: // endgoal
		for (i = 0; i < MAXMOVEOBJECT; i++)
		{
			mob = &m_moveObject[i];
			if (mob->type == TYPE_GOAL || mob->type == TYPE_CLE)
			{
				m_blupiPos = mob->posCurrent;
				if (m_nbTresor >= m_totalTresor)
				{
					if (mob->type == TYPE_CLE)
					{
						m_bFoundCle = TRUE;
					}
					StopVehicleSound();
					PlaySound(SOUND_ENDOK, mob->posCurrent, FALSE);
					m_blupiAction = ACTION_WIN;
					m_blupiPhase = 0;
					m_blupiFocus = FALSE;
					m_blupiFront = TRUE;
					m_blupiAir = FALSE;
					m_blupiHelico = FALSE;
					m_blupiOver = FALSE;
					m_blupiJeep = TRUE;
					m_blupiTank = FALSE;
					m_blupiSkate = FALSE;
					m_blupiNage = FALSE;
					m_blupiSurf = FALSE;
					m_blupiVent = FALSE;
					m_blupiSuspend = FALSE;
					m_blupiShield = FALSE;
					m_blupiPower = FALSE;
					m_blupiCloud = FALSE;
					m_blupiHide = FALSE;
					m_blupiInvert = FALSE;
					m_blupiBalloon = FALSE;
					m_blupiEcrase = FALSE;
				}
				else
				{
					PlaySound(SOUND_ENDKO, mob->posCurrent, FALSE);
				}
				m_goalPhase = 50;
			}
		}
		break;
	case 12: // roundshield
		PlaySound(SOUND_STARTSHIELD, m_blupiPos, FALSE);
		m_blupiShield = TRUE;
		m_blupiPower = FALSE;
		m_blupiCloud = FALSE;
		m_blupiHide = FALSE;
		m_blupiTimeShield = 100;
		m_blupiPosMagic = m_blupiPos;
		m_jauges[JAUGE_POWER].SetHide(FALSE);
		break;
	case 13: // quicklollipop
		m_blupiAction = ACTION_SUCETTE;
		m_blupiPhase = 0;
		m_blupiHelico = FALSE;
		m_blupiOver = FALSE;
		m_blupiJeep = FALSE;
		m_blupiTank = FALSE;
		m_blupiSkate = FALSE;
		m_blupiShield = FALSE;
		m_blupiPower = FALSE;
		m_blupiCloud = FALSE;
		m_blupiHide = FALSE;
		m_blupiFocus = FALSE;
		PlaySound(SOUND_SUCETTE, m_blupiPos, FALSE);
		break;
	case 14: // tenbombs
		m_blupiPerso = 10;
		PlaySound(SOUND_PERSOTAKE, m_blupiPos, FALSE);
		break;
	case 15: // birdlime
		m_blupiBullet = 10;
		break;
	case 16: // drivetank
		m_blupiAir = FALSE;
		m_blupiHelico = FALSE;
		m_blupiOver = FALSE;
		m_blupiJeep = FALSE;
		m_blupiTank = TRUE;
		m_blupiSkate = FALSE;
		m_blupiNage = FALSE;
		m_blupiSurf = FALSE;
		m_blupiVent = FALSE;
		m_blupiSuspend = FALSE;
		m_blupiCloud = FALSE;
		m_blupiHide = FALSE;
		PlaySound(SOUND_JEEPLOW, m_blupiPos, TRUE);
		break;
	case 17: // powercharge
		m_blupiAction = ACTION_CHARGE;
		m_blupiPhase = 0;
		m_blupiHelico = FALSE;
		m_blupiOver = FALSE;
		m_blupiJeep = FALSE;
		m_blupiTank = TRUE;
		m_blupiSkate = FALSE;
		m_blupiShield = FALSE;
		m_blupiPower = FALSE;
		m_blupiCloud = FALSE;
		m_blupiHide = FALSE;
		m_blupiJumpAie = FALSE;
		m_blupiFocus = FALSE;
		PlaySound(SOUND_CHARGE, m_blupiPos, FALSE);
		break;
	case 18: // hidedrink
		m_blupiAction = ACTION_DRINK;
		m_blupiPhase = 0;
		m_blupiHelico = FALSE;
		m_blupiOver = FALSE;
		m_blupiJeep = FALSE;
		m_blupiTank = FALSE;
		m_blupiSkate = FALSE;
		m_blupiShield = FALSE;
		m_blupiPower = FALSE;
		m_blupiCloud = FALSE;
		m_blupiHide = FALSE;
		m_blupiJumpAie = FALSE;
		m_blupiFocus = FALSE;
		PlaySound(SOUND_DRINK, m_blupiPos, FALSE);
		break;
	case 22: // iovercraft
		m_blupiAir = FALSE;
		m_blupiHelico = FALSE;
		m_blupiOver = TRUE;
		m_blupiJeep = FALSE;
		m_blupiTank = FALSE;
		m_blupiSkate = FALSE;
		m_blupiNage = FALSE;
		m_blupiSurf = FALSE;
		m_blupiVent = FALSE;
		m_blupiSuspend = FALSE;
		StopVehicleSound();
		PlaySound(SOUND_HELICOSTART, m_blupiPos, FALSE);
		PlaySound(SOUND_HELICOLOW, m_blupiPos, TRUE);
		break;
	case 23: // udynamite
		m_blupiDynamite = 1;
		PlaySound(SOUND_PERSOTAKE, m_blupiPos, FALSE);
		break;
	case 24: // wellkeys
		m_blupiCle |= CLE_RED | CLE_GREEN | CLE_BLUE;
		break;
	}
	if (!m_blupiShield && !m_blupiHide && !m_blupiCloud && !m_blupiPower)
	{
		m_jauges[JAUGE_POWER].SetHide(TRUE);
	}
	if (!m_blupiHelico && !m_blupiOver)
	{
		StopSound(SOUND_HELICOHIGH);
		StopSound(SOUND_HELICOLOW);
	}
	if (m_blupiJeep && m_blupiTank)
	{
		StopSound(SOUND_JEEPHIGH);
		StopSound(SOUND_JEEPLOW);
	}
}

BOOL CDecor::GetSuperBlupi()
{
	return m_bSuperBlupi;
}

void CDecor::SetSuperBlupi(BOOL bSuper)
{
	m_bSuperBlupi = bSuper;
}

BOOL CDecor::GetDrawSecret()
{
	return m_bDrawSecret;
}

void CDecor::SetDrawSecret(BOOL bDrawSecret)
{
	m_bDrawSecret = bDrawSecret;
}

void CDecor::SetBuildOfficialMissions(BOOL bBuild)
{
	m_bBuildOfficialMissions = bBuild;
}

BOOL CDecor::GetNetPacked()
{
	return m_bNetPacked;
}

void CDecor::SetNetPacked(BOOL bNetPacked)
{
	m_bNetPacked = bNetPacked;
}

BOOL CDecor::GetNetMovePredict()
{
	return m_bNetMovePredict;
}

void CDecor::SetNetMovePredict(BOOL bNetMovePredict)
{
	m_bNetMovePredict = bNetMovePredict;
}

BOOL CDecor::GetNetDebug()
{
	return m_bNetDebug;
}

void CDecor::SetNetDebug(BOOL bNetDebug)
{
	m_bNetDebug = bNetDebug;
	//if (bNetDebug) FUN_2bfb0("debug.txt");
}

void CDecor::OutputNetDebug(char* text)
{
	char textbuffer[100];

	if (!m_bNetDebug) return;

	sprintf(textbuffer, "/ snd=%d(%d)_rcv=%d(%d)", m_netPacketsSent, m_netPacketsSent2, m_netPacketsReceived, m_netPacketsReceived2);
	// ...?
}

void CDecor::SetMulti(BOOL multi)
{
	m_bMulti = multi;
}

void CDecor::SetTeam(int team)
{
	m_team = team;
}

POINT CDecor::VoyageGetPosVie(int nbVies)
{
	return POINT( nbVies * 20 - 5, 417 );
}

void CDecor::VoyageInit(POINT start, POINT end, int icon, int channel)
{
	if (m_voyageIcon != -1)
	{
		m_voyagePhase = m_voyageTotal;
		VoyageStep();
	}
	m_voyageStart = start;
	m_voyageEnd = end;
	m_voyageIcon = icon;
	m_voyageChannel = channel;
	int num = abs(end.x - start.x);
	int num2 = abs(end.y - start.y);
	m_voyagePhase = 0;
	m_voyageTotal = (num + num2) / 10;
	if (m_voyageIcon == 48 && m_voyageChannel == CHBLUPI)
	{
		m_voyageTotal = 40;
		m_nbVies--;
		m_pSound->PlayImage(SOUND_NEW, end, -1);
	}
	if (m_voyageIcon == 21 && m_voyageChannel == CHELEMENT)
	{
		m_pSound->PlayImage(SOUND_EGG, start, -1);
	}
	if (m_voyageIcon == 6 && m_voyageChannel == CHELEMENT)
	{
		if (m_nbTresor == m_totalTresor - 1)
		{
			m_pSound->PlayImage(SOUND_LASTTRESOR, start, -1);
		}
		else
		{
			m_pSound->PlayImage(SOUND_TRESOR, start, -1);
		}
	}
	if (m_voyageIcon == 215 && m_voyageChannel == CHELEMENT)
	{
		m_pSound->PlayImage(SOUND_TRESOR, start, -1);
	}
	if (m_voyageIcon == 222 && m_voyageChannel == CHELEMENT)
	{
		m_pSound->PlayImage(SOUND_TRESOR, start, -1);
	}
	if (m_voyageIcon == 229 && m_voyageChannel == CHELEMENT)
	{
		m_pSound->PlayImage(SOUND_TRESOR, start, -1);
	}
	if (m_voyageIcon == 108 && m_voyageChannel == CHBUTTON)
	{
		m_pSound->PlayImage(SOUND_PERSOTAKE, start, -1);
	}
	if (m_voyageIcon == 252 && m_voyageChannel == CHELEMENT)
	{
		m_pSound->PlayImage(SOUND_PERSOTAKE, start, -1);
	}
	if (m_voyageIcon == 177 && m_voyageChannel == CHELEMENT)
	{
		m_pSound->PlayImage(SOUND_TAKEGLU, start, -1);
	}
	if (m_voyageIcon == 230 && m_voyageChannel == CHELEMENT)
	{
		m_voyageTotal = 100;
	}
	if (m_voyageIcon == 40 && m_voyageChannel == CHELEMENT)
	{
		m_voyageTotal = 50;
	}
}

void CDecor::VoyageStep()
{
	int v3; // eax
	LONG y; // ecx
	LONG x; // eax
	LONG v7; // edx
	LONG v8; // eax
	LONG v9; // eax
	LONG v11; // edx
	POINT v12; // [esp-30h] [ebp-34h]
	POINT v13; // [esp-2Ch] [ebp-30h]
	POINT v14; // [esp-28h] [ebp-2Ch]
	POINT v15; // [esp-24h] [ebp-28h]
	POINT v16; // [esp-20h] [ebp-24h]
	POINT v17; // [esp-18h] [ebp-1Ch]
	if (m_voyageIcon != -1)
	{
		if (m_voyagePhase >= m_voyageTotal)
		{
			if (m_voyageIcon == 48 && m_voyageChannel == CDecor::GetBlupiChannelActual())
			{
				m_blupiAction = ACTION_STOP;
				m_blupiPhase = 0;
				m_blupiFocus = 1;
				m_blupiEnergyUnused = 100;
			}
			if (m_voyageIcon == 21 && m_voyageChannel == 10)
			{
				y = m_voyageEnd.y;
				++m_nbVies;
				v17.y = y;
				v17.x = m_voyageEnd.x;
				m_pSound->PlayImage(SOUND_JUMPEND, v17, -1);
			}
			if (m_voyageIcon == 6 && m_voyageChannel == 10)
			{
				++m_nbTresor;
				CDecor::OpenDoorsTresor();
				m_pSound->PlayImage(SOUND_JUMPEND, m_voyageEnd, -1);
			}
			if (m_voyageIcon == 215 && m_voyageChannel == 10)
			{
				x = m_voyageEnd.x;
				m_pSound = m_pSound;
				m_blupiCle |= CLE_RED;
				v16.y = m_voyageEnd.y;
				v16.x = x;
				m_pSound->PlayImage(SOUND_JUMPEND, v16, -1);
			}
			if (m_voyageIcon == 222 && m_voyageChannel == CHELEMENT)
			{
				v7 = m_voyageEnd.x;
				m_blupiCle |= CLE_GREEN;
				v15.y = m_voyageEnd.y;
				v15.x = v7;
				m_pSound->PlayImage(SOUND_JUMPEND, v15, -1);
			}
			if (m_voyageIcon == 229 && m_voyageChannel == CHELEMENT)
			{
				v8 = m_voyageEnd.y;
				m_blupiCle |= CLE_BLUE;
				v14.y = v8;
				v14.x = m_voyageEnd.x;
				m_pSound->PlayImage(SOUND_JUMPEND, v14, -1);
			}
			if (m_voyageIcon == GetIconPerso() && m_voyageChannel == CHBUTTON)
			{
				v9 = m_voyageEnd.x;
				++m_blupiPerso;
				v13.y = m_voyageEnd.y;
				v13.x = v9;
				m_pSound->PlayImage(SOUND_JUMPEND, v13, -1);
			}
			if (m_voyageIcon == 252 && m_voyageChannel == CHELEMENT)
			{
				v11 = m_voyageEnd.x;
				++m_blupiDynamite;
				v12.y = m_voyageEnd.y;
				v12.x = v11;
				m_pSound->PlayImage(SOUND_JUMPEND, v12, -1);
			}
			if (m_voyageIcon == 177 && m_voyageChannel == CHELEMENT)
			{
				m_pSound->PlayImage(SOUND_JUMPEND, m_voyageEnd, -1);
			}
			m_voyageIcon = -1;
		}
		else if (!(m_time % 2) && m_voyageIcon >= 230 && m_voyageIcon <= 241 && m_voyageChannel == CHELEMENT)
		{
			m_voyageIcon = m_voyageIcon + 1;
			if (m_voyageIcon + 1 > 241)
			{
				v3 = m_voyagePhase + 1;
				m_voyageIcon = 230;
				m_voyagePhase = v3;
				return;
			}
		}
		++m_voyagePhase;
	}
}

void CDecor::VoyageDraw()
{
	POINT v5; // ebx
	int v6; // eax
	int v8; // edi
	int v9; // ebx
	int v10; // ecx
	POINT v11; // [esp-14h] [ebp-2Ch]
	LONG pos; // [esp+10h] [ebp-8h]
	const int speed[9] = {
		-8, -6, -1, -1, -1, -4, -1, -1, -1
	};

	if (m_voyageIcon != -1)
	{
		m_voyagePhase = m_voyagePhase;
		if (m_voyageIcon == 40 && m_voyageChannel == 10)
		{
			m_voyagePhase -= 30;
			if (m_voyagePhase < 0)
			{
				m_voyagePhase = 0;
			}
		}
		m_voyageTotal = m_voyageTotal;
		v5.x = m_voyageStart.x + m_voyagePhase * (m_voyageEnd.x - m_voyageStart.x) / m_voyageTotal;
		v6 = m_voyageIcon;
		v5.y = m_voyageStart.y + m_voyagePhase * (m_voyageEnd.y - m_voyageStart.y) / m_voyageTotal;
		if (v6 != 40 || m_voyageChannel != 10 || m_voyagePhase)
		{
			m_pPixmap->QuickIcon(m_voyageChannel, v6, v5);
		}
		if (m_voyageIcon == 40 && m_voyageChannel == 10)
		{
			v8 = m_posDecor.y + v5.y;
			pos = v5.x + m_posDecor.x - 34;
			v9 = speed[Random(0, 6)];
			v10 = Random(-10, 10);
			if (!m_voyagePhase)
			{
				v9 /= 2;
				v10 *= 4;
			}
			v11.y = v10 + v8;
			v11.x = pos;
			ObjectStart(v11, TYPE_EXPLO8, v9, TRUE);
		}
	}
}

BOOL CDecor::DrawMap(BOOL bPlay, int team)
{
	return FALSE;
}

BOOL CDecor::SearchWorld(int world, POINT *cel, POINT *newBlupiPos)
{
	for (int x = 0; x < MAXCELX; x++)
	{
		for (int y = 0; y < MAXCELY; y++)
		{
			int icon = m_decor[x][y].icon;
			if (icon >= Object::Level_1 && icon <= Object::Level_8)
			{
				if (world == icon - Object::Level_1 + 1)
				{
					if (x > 1 && m_decor[x - 1][y].icon == Object::DoorLevel)
					{
						*cel = POINT( x - 1, y );
						*newBlupiPos = POINT( (x - 2) * DIMOBJX + 2, y * DIMOBJY + 6 );
						return TRUE;
					}
					if (x > 2 && m_decor[x - 2][y].icon == Object::DoorLevel)
					{
						*cel = POINT( x - 2, y );
						*newBlupiPos = POINT( (x - 3) * DIMOBJX + 2, y * DIMOBJY + 6 );
						return TRUE;
					}
					if (x < MAXCELX - 1 && m_decor[x + 1][y].icon == Object::DoorLevel)
					{
						*cel = POINT( x + 1, y );
						*newBlupiPos = POINT( (x + 2) * DIMOBJX + 2, y * DIMOBJY + 6 );
						return TRUE;
					}
					if (x < MAXCELX - 2 && m_decor[x + 2][y].icon == Object::DoorLevel)
					{
						*cel = POINT( x + 2, y );
						*newBlupiPos = POINT( (x + 3) * DIMOBJX + 2, y * DIMOBJY + 6 );
						return TRUE;
					}
				}
			}
		}
	}
	return FALSE;
}

BOOL CDecor::SearchDoor(int n, POINT *cel)
{
	for (int y = MAXCELY - 1; y > 0; y--)
	{
		for (int x = MAXCELX - 1; x > 0; x--)
		{
			if (m_decor[x][y].icon == 183)
			{
				cel->x = x;
				cel->y = y;
				return TRUE;
			}
		}
	}
	return FALSE;
}

void CDecor::AdaptDoors(BOOL bPrivate, int mission)
{
	POINT cel;
	int index;
	int icon;
	POINT newPosBlupi;

	m_bPrivate = bPrivate;
	m_mission = mission;
	if (bPrivate == FALSE)
	{
		if (mission == 1)
		{
			for (int i = 0; i < 20; ++i)
			{
				if (SearchDoor(i, &cel))
				{
					if (!m_doors[180 + i] || m_bCheatDoors)
					{
						m_decor[cel.x][cel.y].icon = -1;
						index = MoveObjectFree();
						m_moveObject[index].type = TYPE_DOOR;
						m_moveObject[index].stepAdvance = 50;
						m_moveObject[index].stepRecede = 1;
						m_moveObject[index].timeStopStart = 0;
						m_moveObject[index].timeStopEnd = 0;
						m_moveObject[index].posStart.x = cel.x * DIMOBJX;
						m_moveObject[index].posStart.y = cel.y * DIMOBJY;
						m_moveObject[index].posEnd.x = cel.x * DIMOBJX;
						m_moveObject[index].posEnd.y = cel.y * DIMOBJY - DIMOBJY;
						m_moveObject[index].posCurrent.x = m_moveObject[index].posStart.x;
						m_moveObject[index].posCurrent.y = m_moveObject[index].posStart.y;
						m_moveObject[index].step = STEP_STOPSTART;
						m_moveObject[index].time = 0;
						m_moveObject[index].phase = 0;
						m_moveObject[index].channel = CHOBJECT;
						m_moveObject[index].icon = 0xb7;
						PlaySound(SOUND_DOOR, m_moveObject[index].posStart, FALSE);
					}
				}
			}
			for (int x = MAXCELX - 1; x > 0; x--)
			{
				for (int y = MAXCELY - 1; y > 0; y--)
				{
					int icon = m_decor[x][y].icon;
					if (icon >= Object::World_1 && icon <= Object::World_8 && (!m_doors[icon - Object::World_1 + 1] || m_bCheatDoors))
					{
						m_decor[x][y].icon += 8;
					}
					if (icon == Object::World_9 && (!m_doors[189] || m_bCheatDoors))
					{
						m_decor[x][y].icon = Object::WorldDone_9;
					}
					if (icon >= Object::World_10 && icon <= Object::World_14 && (!m_doors[icon - Object::World_10 + 1] || m_bCheatDoors))
					{
						m_decor[x][y].icon += 5;
					}
				}
			}
		}
		else if (mission % 10 == 0)
		{
			for (int i = 0; i < 10; ++i)
			{
				if (SearchWorld(i, &cel, &newPosBlupi))
				{
					if (!m_doors[mission + i] || m_bCheatDoors)
					{
						OpenDoor(cel);
						for (int j = 0; j < MAXNETPLAYER; j++)
						{
							m_blupiStartPos[j] = newPosBlupi;
							m_blupiStartDir[j] = (m_blupiStartPos[j].x < cel.x * DIMOBJX) ? DIR_RIGHT : DIR_LEFT;
						}
					}
				}
			}
		}
	}
}

void CDecor::OpenDoorsTresor()
{
	for (int x = 0; x < MAXCELX; x++)
	{
		for (int y = 0; y < MAXCELY; y++)
		{
			int icon = m_decor[x][y].icon;
			if (icon >= 0x1a5 && icon <= 0x1a5 + m_nbTresor - 1)
			{
				OpenDoor(POINT( x, y ));
			}
		}
	}
}

void CDecor::OpenDoor(POINT cel)
{
	int icon = m_decor[cel.x][cel.y].icon;
	m_decor[cel.x][cel.y].icon = -1;
	int num = MoveObjectFree();
	m_moveObject[num].type = TYPE_DOOR;
	m_moveObject[num].stepAdvance = 50;
	m_moveObject[num].stepRecede = 1;
	m_moveObject[num].timeStopStart = 0;
	m_moveObject[num].timeStopEnd = 0;
	m_moveObject[num].posStart.x = DIMOBJX * cel.x;
	m_moveObject[num].posStart.y = DIMOBJY * cel.y;
	m_moveObject[num].posEnd.x = DIMOBJX * cel.x;
	m_moveObject[num].posEnd.y = DIMOBJY * (cel.y - 1);
	m_moveObject[num].posCurrent = m_moveObject[num].posStart;
	m_moveObject[num].step = STEP_STOPSTART;
	m_moveObject[num].time = 0;
	m_moveObject[num].phase = 0;
	m_moveObject[num].channel = CHOBJECT;
	m_moveObject[num].icon = icon;
	PlaySound(SOUND_DOOR, m_moveObject[num].posStart, FALSE);
}

void CDecor::OpenDoorsWin()
{
	m_doors[m_mission + 1] = 0;
}

void CDecor::OpenGoldsWin()
{
	m_doors[180 + m_mission / 10] = 0;
}

void CDecor::DoorsLost()
{
	m_nbVies = 3;
	// more...
}



// Winphone functions, likely unnecessary
/*
BOOL CDecor::SearchGold(int n, POINT cel)
{
for (int i = 99; i >= 0; i--)
{
for (int j = 99; j >= 0; j--)
{
if (m_decor[j][i].icon == 183)
{
cel.x = j;
cel.y = i;
return TRUE;
}
}
}
return FALSE;
}

BOOL CDecor::IsFloatingObject(int i)
{
POINT posCurrent = m_moveObject[i]->posCurrent;
int num = (posCurrent.x + 32) / 64;
int num2 = posCurrent.y / 64 + 1;
int icon = m_decor[num, num2]->icon;
return IsPassIcon(icon);
}

BOOL CDecor::IsNormalJump(POINT pos)
{
pos.x += 32;
pos.y -= 32;
if (m_blupiDir == 1)
{
pos.x -= 15;
}
else
{
pos.x += 15;
}
for (int i = 0; i < 2; i++)
{
int num = pos.x / DIMOBJX;
int num2 = pos.y / DIMOBJY;
if (num2 < 0)
{
return FALSE;
}
int icon = m_decor[num, num2]->icon;
if (!IsPassIcon(icon))
{
return FALSE;
}
pos.y -= 64;
}
return TRUE;
}*/