////////////////////////////////////////////
///
/// WraithOne
/// www.Dark-Abyss.net
///
/// ZFX Action 2014
///
/// Theme: Career, Cell
///
////////////////////////////////////////////

#include <Capp.h>

bool Capp::InitPlayer()
{
	// Load Player Image
	m_Player = LoadImage(m_Renderer, "Data/GFX/Player.png");
	if (m_Player == nullptr)
	{
		Shutdown();

		return false;
	}

	m_PlayerBBox = { 277, 234, 32, 32 };
	m_Playermoves = false;
	m_Playerrotation = 0;

	m_Live =		3;
	m_Money =		10;
	m_Cigaretts =	0;
	m_Mariuhana =	0;
	m_Cocaine =		0;
	m_Vodka =		0;
	m_Wisky =		0;

	return true;
}

void Capp::InputPlayer()
{
	const Uint8* KeyboradStat = SDL_GetKeyboardState(NULL);

	/////////////////////////////////////////////////////////
	// Key Down
	if (KeyboradStat[SDL_SCANCODE_UP])
	{
		m_UPpressed = true;
	}
	if (KeyboradStat[SDL_SCANCODE_DOWN])
	{
		m_DOWNpressed = true;
	}
	if (KeyboradStat[SDL_SCANCODE_LEFT])
	{
		m_LEFTpressed = true;
	}
	if (KeyboradStat[SDL_SCANCODE_RIGHT])
	{
		m_RIGHTpressed = true;
	}
	if (KeyboradStat[SDL_SCANCODE_L])
	{
		m_Gamestate = Lost; // DEBUG
	}
	if (KeyboradStat[SDL_SCANCODE_B])
	{
		m_Bpressed = true;
	}
	if (KeyboradStat[SDL_SCANCODE_S])
	{
		m_Spressed = true;
	}

	////////////////////////////////////////////////////
	// Key Up
	if (!KeyboradStat[SDL_SCANCODE_UP])
	{
		m_UPpressed = false;
	}
	if (!KeyboradStat[SDL_SCANCODE_DOWN])
	{
		m_DOWNpressed = false;
	}
	if (!KeyboradStat[SDL_SCANCODE_LEFT])
	{
		m_LEFTpressed = false;
	}
	if (!KeyboradStat[SDL_SCANCODE_RIGHT])
	{
		m_RIGHTpressed = false;
	}
}

void Capp::UpdatePlayer(unsigned int elapsedTime)
{
	SDL_Rect temp = m_PlayerBBox;
	SDL_Color BBcolor = { 0, 0, 0, 255};
	unsigned int time = elapsedTime - m_lastTime;

	if (time >= 10)
	{
		if (m_UPpressed)
		{
			// Move Up
			temp.y -= 1;

			if (!RectIntersects(m_PrisonBB, temp, BBcolor))
			{
				m_PlayerBBox.y -= 1;
				m_Playerrotation = 0.0f;
				m_Playermoves = true;
			}
		}
		else if (m_DOWNpressed)
		{
			// Move Down
			temp.y += 1;
			if (!RectIntersects(m_PrisonBB, temp, BBcolor))
			{
				m_PlayerBBox.y += 1;
				m_Playerrotation = 180.0f;
				m_Playermoves = true;
			}
		}
		else if (m_LEFTpressed)
		{
			// Move Left
			temp.x -= 1;
			if (!RectIntersects(m_PrisonBB, temp, BBcolor))
			{
				m_PlayerBBox.x -= 1;
				m_Playerrotation = 90.0f;
				m_Playermoves = true;
			}
		}
		else if (m_RIGHTpressed)
		{
			// Move Right
			temp.x += 1;
			if (!RectIntersects(m_PrisonBB, temp, BBcolor))
			{
				m_PlayerBBox.x += 1;
				m_Playerrotation = 270.0f;
				m_Playermoves = true;
			}
		}
		else
		{
			// player doesnt move
			m_Playermoves = false;
		}

		m_lastTime = elapsedTime;
	}
	

	// if Live´s <= 0 the game is lost
	if (m_Live <= 0)
		m_Gamestate = Lost;
}

void Capp::RenderPlayer(unsigned int elapsedTime)
{
	SDL_Rect PlayersrcRect = { 0, 0, 32, 32 };
	if (m_Playermoves)
	{
		unsigned int time = elapsedTime - m_AnimationlastTime;

		if (time >= 10)
		{
			if (PlayersrcRect.x =! 32)
			{
				PlayersrcRect.x = 32;
			}		
			else
			{
				PlayersrcRect.x = 64;
			}
			m_AnimationlastTime = elapsedTime;
		}	
	}
	SDL_RenderCopyEx(m_Renderer, m_Player, &PlayersrcRect, &m_PlayerBBox, m_Playerrotation, NULL, SDL_FLIP_NONE);
}