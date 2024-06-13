// CDecor.cpp
//

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ddraw.h>
#include "def.h"
#include "resource.h"
#include "pixmap.h"
#include "sound.h"
#include "decor.h"
#include "text.h"
#include "misc.h"
#include "DECMOVE.h"
#include "event.h"


////////////////////////////////////////////////////////////////////////////////

#define MAXMOVEOBJECT	200
#define MAXQUART		441
#define SCROLL_SPEED	8
#define SCROLL_MARGX	80
#define SCROLL_MARGY	40

#define BLUPIFLOOR		2
#define BLUPIOFFY		4 + BLUPIFLOOR
#define BLUPISURF		12
#define BLUPISUSPEND	12
#define OVERHEIGHT		80

#define TEXTDELAY	   10 // tooltip popup delay

// Constructor
// Possibly incomplete

CDecor::CDecor()
{
	int i;

	// unknown_library_function_2bd90(m_jauges, sizeof(CJauge), 2, CJauge::CJauge);
	m_hWnd = NULL;
	m_pSound = NULL;
	m_pPixmap = NULL;

	for (i = 0; i < 200; i++)
	{
		m_lastDecorIcon[i] = 0;
	}
	m_time = 0;
	m_bCheatDoors = FALSE;
	m_bSuperBlupi = FALSE;
	m_bDrawSecret = FALSE;
	m_buildOfficialMissions = FALSE;
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
	// unknown_library_function_2be30(m_jauges, sizeof(CJauge), 2, OutputDebug);
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
	m_blupiSpeedX = 0;
	m_bHelicopterFlying = FALSE;
	m_bHelicopterStationary = FALSE;
	m_bCarMoving = FALSE;
	m_bCarStationary = FALSE;
	InitDecor();

	pos.x = 169;
	pos.y = 450;
	m_jauges[0].Create(m_hWnd, m_pPixmap, m_pSound, pos, 1, FALSE);
	m_jauges[0].SetHide(TRUE);
	pos.x += DIMJAUGEX + 2;
	m_jauges[1].Create(m_hWnd, m_pPixmap, m_pSound, pos, 3, FALSE);
	m_jauges[1].SetHide(TRUE);
	FUN_15fa0();
	FlushNotificationMessages();
}

BOOL CDecor::LoadImages()
{
	POINT totalDim, iconDim;
	char filename[52];

	if (m_lastRegion == m_region) return TRUE;
	m_lastRegion = m_region;

	totalDim.x = LXIMAGE;
	totalDim.y = LYIMAGE;
	iconDim.x = 0;
	iconDim.y = 0;
	sprintf(filename, "decor%.3d.blp", m_region);

	return m_pPixmap->Cache1(CHBACK, filename, totalDim, iconDim, 0);
}

void CDecor::InitGamer()
{
	m_nbVies = 3;
	BYTE *ptr = m_doors;
	for (int i = 50; i != 0; i--) {
		*(int *)ptr = 0x01010101;
		ptr += 4;
	}
}

void CDecor::InitDecor()
{
	m_posDecor.x = 0;
	m_posDecor.y = 0;
	m_dimDecor.x = 100;
	m_dimDecor.y = 100;
	m_music = 1;
	m_region = 2;
	m_missionTitle[0] = '\0';
	m_decorAction = 0;
	for (int i = 0; i < MAXCELY; i++)
	{
		for (int j = 0; j < MAXCELX; j++)
		{
			m_decor[i][j].icon = -1;
			m_bigDecor[i][j].icon = -1;
		}
	}
	m_decor[3][4].icon = 40;
	m_decor[4][4].icon = 38;
	m_decor[5][4].icon = 39;
	for (int k = MAXMOVEOBJECT; k != 0; k--)
	{
		m_moveObject[k]->type = 0;
	}
	FlushBalleTraj();
	FlushMoveTraj();
	m_moveObject[0].type = TYPE_TRESOR;
	m_moveObject[0].stepAdvance = 1;
	m_moveObject[0].stepRecede = 1;
	m_moveObject[0].timeStopStart = 0;
	m_moveObject[0].timeStopEnd = 0;
	m_moveObject[0].posStart.x = 258;
	m_moveObject[0].posStart.y = 196;
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
	m_moveObject[1].posStart.x = 450;
	m_moveObject[1].posStart.y = 196;
	m_moveObject[1].posEnd = m_moveObject[1].posStart;
	m_moveObject[1].posCurrent = m_moveObject[1].posStart;
	m_moveObject[1].phase = 0;
	m_moveObject[1].step = STEP_STOPSTART;
	m_moveObject[1].time = 0;
	m_moveObject[1].channel = CHELEMENT;
	m_moveObject[1].icon = 29;
	//TODO: iterate setting blupi fifo positions
	m_blupiStartPos.x = 66;
	m_blupiStartPos.y = 192 + BLUPIOFFY;
	m_blupiStartDir = DIR_RIGHT;
	m_blupiAction = ACTION_STOP;
	m_blupiPhase = 0;
	m_blupiIcon = 0;
	m_blupiChannel = 2;
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
	m_blupiVitesse.x = 0;
	m_blupiVitesse.y = 0;
	m_blupiValidPos = m_blupiStartPos;
	m_blupiEnergyUnused = 100;
	m_blupiFront = FALSE;
	m_blupiBullet = 0;
	m_blupiCle = 0;
	m_blupiPerso = 0;
	m_blupiDynamite = 0;
	m_nbTresor = 0;
	m_totalTresor = 1;
	m_goalPhase = 0;
	m_scrollPoint = m_blupiStartPos;
	m_scrollAdd.x = 0;
	m_scrollAdd.y = 0;
	m_term = 0;
	m_CC20 = -1;
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
	if (bTest)
	{
		m_nbVies = 3;
	}

	if (!m_bMulti) {
		m_blupiPos = m_blupiStartPos;
		m_blupiDir = m_blupiStartDir;
	}
	else
	{
		/* todo: set depending on team
		m_nbVies = 10;
		m_blupiPos = m_blupiStartPos;
		m_blupiDir = m_blupiStartDir;
		*/

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
		if ((m_bMulti != FALSE) &&
			(m_moveObject[i].type == TYPE_CAISSE) ||
			(m_moveObject[i].type == TYPE_GOAL) ||
			(m_moveObject[i].type == TYPE_CLE) ||
			(m_moveObject[i].type == TYPE_BLUPIHELICO) ||
			(m_moveObject[i].type == TYPE_BLUPITANK))
		{
			m_moveObject[i]->type = 0;
		}
	}
	m_goalPhase = 0;
	MoveObjectSort();
	UpdateCaisse();
	m_scrollPoint = m_blupiPos;
	m_scrollAdd.x = 0;
	m_scrollAdd.y = 0;
	m_blupiPosHelico.x = -1;
	m_blupiMotorSound = 0;
	m_nbLinkCaisse = 0;
	m_bHelicopterFlying = FALSE;
	m_bHelicopterStationary = FALSE;
	m_bCarMoving = FALSE;
	m_bCarStationary = FALSE;
	m_blupiFront = FALSE;
	m_blupiNoBarre = 0;
	m_blupiValidPos = m_blupiPos;
	m_blupiFifoNb = 0;
	m_blupiTimeFire = 0;
	FUN_15580();
	FlushNotificationMessages();
	m_voyageIcon = -1;
	m_jauges[0].SetHide(TRUE);
	m_jauges[1].SetHide(TRUE);
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
	m_selectedCelPos.x = -1;
	// field cc20 = -1
	m_time = 0;
	m_bPause = FALSE;
	FUN_15580();
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
		FUN_15d50();
		FUN_161a0();
	}

	if (m_phase == WM_PHASE_BUILD) {
		if (m_keyPress & KEY_RIGHT) {
			m_posDecor.x += 50;
			int max = (m_dimDecor.x > 0) ? (m_dimDecor.x - LXIMAGE) : 0;
			if (m_posDecor.x > max) {
				m_posDecor.x = max;
			}
			m_selectedCelPos.x = -1;
		}
		if (m_keyPress & KEY_LEFT) {
			m_posDecor.x -= 50;
			if (m_posDecor.x < 0) {
				m_posDecor.x = 0;
			}
			m_selectedCelPos.x = -1;
		}
		if (m_keyPress & KEY_DOWN) {
			m_posDecor.y += 50;
			int max = (m_dimDecor.y > 0) ? (m_dimDecor.y - LYIMAGE) : 0;
			if (m_posDecor.y > max) {
				m_posDecor.y = max;
			}
			m_selectedCelPos.x = -1;
		}
		if (m_keyPress & KEY_UP) {
			m_posDecor.x -= 50;
			if (m_posDecor.x < 0) {
				m_posDecor.x = 0;
			}
			m_selectedCelPos.x = -1;
		}
	}
}

int CDecor::GetBlupiChannelStandard()
{
	if (m_bMulti && m_blupiChannel == CHBLUPI && m_team > 0) {
		return m_team + CHBLUPI1 - 1;
	}
	return m_blupiChannel;
}

int CDecor::GetBlupiChannelActual()
{
	if (m_bMulti && m_team > 0) {
		return m_team + CHBLUPI1 - 1;
	}
	return CHBLUPI;
}

int CDecor::GetIconPerso()
{
	if (m_bMulti) {
		return m_team + 108;
	}
	return 108;
}

BOOL CDecor::BlitzActif(int celx, int cely)
{
	POINT pos;
	pos.x = celx * DIMOBJX;
	pos.y = cely * DIMOBJY;

	//TODO: rewrite from ghidra. winphone code is too different
	int num = m_time % 100;

	if (m_decor[celx][cely - 1].icon == 304 && (num == 0 || num == 7 || num == 18 || num == 25 || num == 33 || num == 44) && cely > 0)
	{
		PlaySound(SOUND_BLITZ, pos, 0);
	}
	return num % 2 == 0 && num < 50;
}

void CDecor::Build(RECT rect)
{
	POINT posDecor = DecorNextAction();
	POINT pos;
	pos.x = posDecor.x * 2 / 3;
	pos.y = posDecor.y * 2 / 3;
	int num = 1;
	POINT tinyPoint;
	tinyPoint.x = m_drawBounds.left;
	RECT clipRect;
	rect.left = pos.x % LXIMAGE;
	rect.right = LXIMAGE;

	clipRect = m_pPixmap->GetClipping();
	//TODO: more^

	for (int i = 0; i < 3; i++)
	{
		tinyPoint.y = m_drawBounds.top;
		rect.top = pos.y % LYIMAGE;
		rect.bottom = LYIMAGE;
		for (int j = 0; j < 2; j++)
		{
			m_pPixmap->DrawPart(3, tinyPoint, rect);
			tinyPoint.y += (rect.bottom - rect.top) - num;
			rect.top = 0;
			rect.bottom = LYIMAGE;
		}
		tinyPoint.x += (rect.right - rect.left) - num;
		rect.left = 0;
		rect.right = LXIMAGE;
		if (tinyPoint.x > m_drawBounds.right)
		{
			break;
		}
		tinyPoint.x = m_drawBounds.left - posDecor.x % 64 - 64;
		for (int i = posDecor.x / 64 - 1; i < posDecor.x / 64 + (m_drawBounds.right - m_drawBounds.left) / 64 + 3; i++) {
			tinyPoint.y = m_drawBounds.top - posDecor.y % 64 + 2 - 64;
			for (int j = posDecor.y / 64 - 1; j < posDecor.y / 64 + (m_drawBounds.bottom - m_drawBounds.top) / 64 + 2; j++)
			{
				if (i >= 0 && i < 100 && j >= 0 && j < 100)
				{
					int num2 = m_bigDecor[i, j].icon;
				}
			}
		}
	}
}


void CDecor::DrawInfo()
{
	POINT pos;
	char text[100];

	if (m_phase == WM_PHASE_PLAY || WM_PHASE_PLAYTEST)
	{
		for (int i = 4; i != 0; i--) {
			if (m_messages[i] != '\0') {
				pos.x = 10;
				pos.y = 10;
				DrawText(m_pPixmap, pos, *m_messages[i], 0);
			}
		}

		if (m_nbVies > 0) {
			pos.x = -15;
			for (int i = 0; i < m_nbVies; i++) {
				pos.y = 417;
				m_pPixmap->QuickIcon(GetStandardBlupiChannel(), 48, pos);
				pos.x += 16;
			}
		}

		if (m_blupiBullet > 0) {
			pos.x = -15;
			pos.y = 398;
			for (int i = 0; i < m_blupiBullet; i++) {
				m_pPixmap->QuickIcon(CHELEMENT, 176, pos);
				pos.x += 4;
			}
		}

		//TODO: more
	}
}

POINT CDecor::DecorNextAction()
{
	int num = 0;
	if (m_decorAction == 0 || m_bPause)
	{
		m_posDecor;
	}
	POINT posDecor = m_posDecor;
	while (tables->table_decor_action[num] != 0)
	{
		if (m_decorAction == tables->table_decor_action[num])
	}
}

void CDecor::UpdateCaisse()
{
	m_nbRankCaisse = 0;
	for (int i = 0; i < MAXMOVEOBJECT; i++)
	{
		if (m_moveObject[i]->type == 12)
		{
			m_rankCaisse[m_nbRankCaisse++] = i;
		}
	}
}

BOOL CDecor::TestPushCaisse(int i, POINT pos, BOOL bPop)
{
	POINT move;

	move.x = pos.x - m_moveObject[i]->posCurrent.x;
	move.y = 0;
	SearchLinkCaisse(i, bPop);
	int y = m_moveObject[i]->posCurrent.y;
	for (int j = 0; j < m_nbLinkCaisse; j++)
	{
		i = m_linkCaisse[j];
		if (!TestPushOneCaisse(i, move, y))
		{
			return FALSE;
		}
	}
	for (int j = 0; j < m_nbLinkCaisse; j++)
	{
		i = m_linkCaisse;
		int num = i;
		m_moveObject[num]->posCurrent.x = m_moveObject[num]->posCurrent.x + move.x;
		m_moveObject[num]->posStart.x = m_moveObject[num]->posStart.x + move.x;
		int num2 = i;
		m_moveObject[num]->posEnd.x = m_moveObject[num]->posEnd.x + move.x;
	}
	return TRUE;
}

BOOL CDecor::TestPushOneCaisse(int i, POINT move, int b)
{

}

void CDecor::SearchLinkCaisse(int rank, BOOL bPop)
{
	m_nbLinkCaisse = 0;
	AddLinkCaisse(rank);
	POINT posCurrent = m_moveObject;

	BOOL flag;
	do
	{
		flag = FALSE;
		for (int i = 0; i < m_nbLinkCaisse; i++)
		{
			int num = m_linkCaisse[i];
			if (m_moveObject[num]->posCurrent.y <=
				posCurrent.y && (!bPop || (m_moveObject
					[num]->posCurrent.x >= posCurrent.x - 32 &&
					m_moveObject[num]->posCurrent.x <=
					posCurrent.x + 32)))
			{

			}
		}
	}
}

BOOL CDecor::AddLinkCaisse(int rank)
{

}


BOOL CDecor::LoadImages()
{
	char filename[52];
	POINT totalDim, iconDim;

	if (m_region == m_lastRegion) return TRUE;
	m_lastRegion == m_region;

	totalDim.x = DIMCELX * 2 * 16;
	totalDim.y = DIMCELY * 2 * 6;
	iconDim.x = DIMCELX * 2;
	iconDim.y = DIMCELY * 2;
	sprintf(filename, "image\\decor%.3d.blp", m_region);
	if (!m_pPixmap->Cache(CHFLOOR, filename, totalDim, iconDim, FALSE))
		return FALSE;

	return TRUE;
}




int CDecor::SetBlupiChannel()
{
	if (m_bMulti = 0 ||
		m_blupiChannel == ch_blupi00 ||
		m_team > 0); {
		return m_team + 10;
	}
	return m_blupiChannel;
}

int CDecor::GetBlupiChannel()
{
	int m_blupiChannel = CHBLUPI000;


	if (m_bMulti != 0 ||
		m_team > 0); {
		return m_team + 10;
	}
	return CHBLUPI000;
}



int CDecor::GetIconPerso()
{
	if (m_bMulti) {
		return m_team + ICON_BUTTON_PERSONALBOMBICON;
	}
	return ICON_BUTTON_PERSONALBOMBICON;
}


void CDecor::SetTime(int time)
{
	m_time = time;
}

int CDecor::GetTime()
{
	return m_time;
}

int CDecor::GetTargetLevel(int mission)
{
	m_targetMission = mission;
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

void CDecor::GetDims(POINT* ptr)
{
	ptr->x = m_dimDecor.x;
	ptr->y = m_dimDecor.y;
	return;
}

void CDecor::SetDims(POINT dims)
{
	m_dimDecor.x = dims.x;
	m_dimDecor.y = dims.y;
}

int CDecor::GetLives()
{
	return m_lives;
}

void CDecor::SetLives(int lives)
{
	m_lives = lives;
}

BOOL CDecor::GetInvincible()
{
	return m_bSuperBlupi;
}

void CDecor::SetInvincible(BOOL invincible)
{
	m_bSuperBlupi = invincible;
}

BOOL CDecor::GetShowSecret()
{
	return m_bDrawSecret;
}

void CDecor::SetShowSecret(BOOL secret)
{
	m_bDrawSecret = secret;
}

void CDecor::SetAccessBuild(BOOL build)
{
	m_bAccessBuild = build;
}

BOOL CDecor::GetNetPacked()
{
	return m_bNetPacked;
}

void CDecor::SetNetPacked(BOOL net)
{
	m_bNetPacked = net;
}

BOOL CDecor::GetNetMovePredict()
{
	return m_bNetMovePredict;
}

void CDecor::SetNetMovePredict(BOOL netmove)
{
	m_bNetMovePredict = netmove;
}

BOOL CDecor::GetNetDebug()
{
	return m_bNetDebug;
}

void CDecor::SetMulti(int multi)
{
	m_bMulti = multi;
}

void CDecor::SetTeam(int team)
{
	m_team = team;
}

void CDecor::GetBlupiInfo(BOOL bHelico, BOOL bJeep, BOOL bSkate, BOOL bNage)
{
	bHelico = m_blupiHelico;
	bJeep = (m_blupiJeep | m_blupiTank);
	bSkate = m_blupiSkate;
	bNage = (m_blupiNage | m_blupiSurf);
}

void CDecor::MoveObjectSort()
{
	CDecor.MoveObject src = default(CDecor->MoveObject);
	int num = 0;
	for (int i = 0; i < MAXMOVEOBJECT; i++)
}

int CDecor::GetMissionTitle()
{
	return m_missionTitle;
}

void CDecor::GetMissionsCleared()
{

}

void CDecor::SetDemoState(BOOL demoState)
{
	m_demoState = demoState;
}