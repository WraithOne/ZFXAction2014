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
	m_PlayersrcRect =	{0, 0, 32, 32};
	m_PlayerBBox =		{277, 234, 32, 32};
	m_Playermoves =		false;
	m_Playerrotation =	0;

	m_Live =			3;
	m_Money =			10;
	m_Cigaretts =		0;
	m_Mariuhana =		0;
	m_Cocaine =			0;
	m_Vodka =			0;
	m_Wisky =			0;

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
		if (m_Bpressed == false)
		{
			if (Buy())
			{
				m_Bpressed = true;
			}
		}	
	}
	if (KeyboradStat[SDL_SCANCODE_S])
	{
		if (m_Spressed == false)
		{
			if (Sell())
			{
				m_Spressed = true;
			}
		}	
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
	if (!KeyboradStat[SDL_SCANCODE_B])
	{
		m_Bpressed = false;
	}
	if (!KeyboradStat[SDL_SCANCODE_S])
	{
		m_Spressed = false;
	}
}

bool Capp::Buy()
{
	std::vector<Smuggler>::iterator it;
	for (it = m_SmugglerList.begin(); it < m_SmugglerList.end(); it++)
	{
		if (RectIntersects(m_PlayerBBox, it->sellRect))
		{
			if (it->sellGoods != Nothing)
			{
				// Cigaretts
				if (it->sellGoods == Cigaretts && m_Money >= 5)
				{
					m_Money -= 5;
					m_Cigaretts += 1;
					it->sellGoods = Nothing;
					it->lastDesisiontime = SDL_GetTicks();

					return true;
				}
				// Marihuana
				if (it->sellGoods == Marihuana && m_Money >= 15)
				{
					m_Money -= 15;
					m_Mariuhana += 1;
					it->sellGoods = Nothing;
					it->lastDesisiontime = SDL_GetTicks();

					return true;
				}
				if (it->sellGoods == Cocaine && m_Money >= 50)
				{
					m_Money -= 50;
					m_Cocaine += 1;
					it->sellGoods = Nothing;
					it->lastDesisiontime = SDL_GetTicks();

					return true;
				}
				if (it->sellGoods == Vodka && m_Money >= 20)
				{
					m_Money -= 20;
					m_Vodka += 1;
					it->sellGoods = Nothing;
					it->lastDesisiontime = SDL_GetTicks();

					return true;
				}
				if (it->sellGoods == Wisky && m_Money >= 30)
				{
					m_Money -= 30;
					m_Wisky += 1;
					it->sellGoods = Nothing;
					it->lastDesisiontime = SDL_GetTicks();

					return true;
				}
			}
		}	
	}
	return false;
}

bool Capp::Sell()
{
	std::vector<Prisoner>::iterator it;
	for (it = m_PrisonerList.begin(); it < m_PrisonerList.end(); it++)
	{
		if (RectIntersects(m_PlayerBBox, it->BBrect))
		{
			// Cigaretts
			if (it->BuyGoods == Cigaretts && m_Cigaretts >= 1)
			{
				m_Money += 10;
				m_Cigaretts -= 1;
				it->BuyGoods = Nothing;
				it->lastDecisiontime = SDL_GetTicks();

				return true;
			}
			// Marihuana
			if (it->BuyGoods == Marihuana && m_Mariuhana >= 1)
			{
				m_Money += 20;
				m_Mariuhana -= 1;
				it->BuyGoods = Nothing;
				it->lastDecisiontime = SDL_GetTicks();

				return true;
			}
			// Cocaine
			if (it->BuyGoods == Cocaine && m_Cocaine >= 1)
			{
				m_Money += 100;
				m_Cocaine -= 1;
				it->BuyGoods = Nothing;
				it->lastDecisiontime = SDL_GetTicks();

				return true;
			}
			// Vodka
			if (it->BuyGoods == Vodka && m_Vodka >= 1)
			{
				m_Money += 40;
				m_Vodka -= 1;
				it->BuyGoods = Nothing;
				it->lastDecisiontime = SDL_GetTicks();

				return true;
			}
			// Wiskey
			if (it->BuyGoods == Wisky && m_Wisky >= 1)
			{
				m_Money += 60;
				m_Wisky -= 1;
				it->BuyGoods = Nothing;
				it->lastDecisiontime = SDL_GetTicks();

				return true;
			}
		}
	}
	return false;
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

			if (!ColorIntersects(m_PrisonBB, temp, BBcolor))
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
			if (!ColorIntersects(m_PrisonBB, temp, BBcolor))
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
			if (!ColorIntersects(m_PrisonBB, temp, BBcolor))
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
			if (!ColorIntersects(m_PrisonBB, temp, BBcolor))
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
	if (m_Playermoves)
	{
		unsigned int time = elapsedTime - m_AnimationlastTime;

		if (time >= 500)
		{
			if (m_PlayersrcRect.x != 32)
			{
				m_PlayersrcRect.x = 32;
			}
			else
			{
				m_PlayersrcRect.x = 64;
			}
			m_AnimationlastTime = elapsedTime;
		}	
	}
	else
	{
		m_PlayersrcRect.x = 0;
	}
	SDL_RenderCopyEx(m_Renderer, m_Player, &m_PlayersrcRect, &m_PlayerBBox, m_Playerrotation, NULL, SDL_FLIP_NONE);
}