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

bool Capp::InitGUI()
{
	// Load Goods Image
	m_Goods = LoadImage(m_Renderer, "Data/GFX/Goods.png");
	if (m_Goods == nullptr)
	{
		Shutdown();

		return false;
	}

	// Load Speechbubbles Image
	m_Speechbubbles = LoadImage(m_Renderer, "Data/GFX/Speechbubbles.png");
	if (m_Speechbubbles == nullptr)
	{
		Shutdown();

		return false;
	}

	m_LiveSrcRect = FillRect(96, 0, 16, 16);
	m_LiveDstRect = FillRect(360, 28, 16, 16);
	m_LivePosition = { 387, 31 };

	m_MoneySrcRect = FillRect(0, 0, 16, 16);
	m_MoneyDstRect = FillRect(360, 49, 16, 16);
	m_MoneyPosition = { 387, 49 };

	m_CigarettsSrcRect = FillRect(16, 0, 16, 16);
	m_CigarettsDstRect = FillRect(360, 70, 16, 16);
	m_CigarettsPosition = { 387, 70 };

	m_MariuhanaSrcRect = FillRect(32, 0, 16, 16);
	m_MariuhanaDstRect = FillRect(360, 91, 16, 16);
	m_MariuhanaPosition = { 387, 91 };

	m_CocaineSrcRect = FillRect(48, 0, 16, 16);
	m_CocaineDstRect = FillRect(360, 112, 16, 16);
	m_CocainePosition = { 387, 112 };

	m_VodkaSrcRect = FillRect(64, 0, 16, 16);
	m_VodkaDstRect = FillRect(360, 133, 16, 16);
	m_VodkaPosition = { 387, 133 };

	m_WiskySrcRect = FillRect(80, 0, 16, 16);
	m_WiskyDstRect = FillRect(360, 154, 16, 16);
	m_WiskyPosition = { 387, 154 };

	return true;
}

void Capp::UpdateGUI(unsigned int elapsedTime)
{

}

void  Capp::RenderGUI(unsigned int elapsedTime)
{
	if (m_Gamestate != Menu && m_Gamestate != Paused && m_Gamestate != Lost)
	{
		// Live
		SDL_RenderCopy(m_Renderer, m_Goods, &m_LiveSrcRect, &m_LiveDstRect);
		InttoText(m_Renderer, m_Font, m_LivePosition, m_Live, 255, 0, 0);

		// Money
		SDL_RenderCopy(m_Renderer, m_Goods, &m_MoneySrcRect, &m_MoneyDstRect);
		InttoText(m_Renderer, m_Font, m_MoneyPosition, m_Money, 255, 0, 0);

		// Cigaretts
		SDL_RenderCopy(m_Renderer, m_Goods, &m_CigarettsSrcRect, &m_CigarettsDstRect);
		InttoText(m_Renderer, m_Font, m_CigarettsPosition, m_Cigaretts, 255, 0, 0);

		// Mariuhana
		SDL_RenderCopy(m_Renderer, m_Goods, &m_MariuhanaSrcRect, &m_MariuhanaDstRect);
		InttoText(m_Renderer, m_Font, m_MariuhanaPosition, m_Mariuhana, 255, 0, 0);

		// Cocaine
		SDL_RenderCopy(m_Renderer, m_Goods, &m_CocaineSrcRect, &m_CocaineDstRect);
		InttoText(m_Renderer, m_Font, m_CocainePosition, m_Cocaine, 255, 0, 0);

		// Vodka
		SDL_RenderCopy(m_Renderer, m_Goods, &m_VodkaSrcRect, &m_VodkaDstRect);
		InttoText(m_Renderer, m_Font, m_VodkaPosition, m_Vodka, 255, 0, 0);
		// Wisky
		SDL_RenderCopy(m_Renderer, m_Goods, &m_WiskySrcRect, &m_WiskyDstRect);
		InttoText(m_Renderer, m_Font, m_WiskyPosition, m_Wisky, 255, 0, 0);

		// Prisoner
		std::vector<Prisoner>::iterator p_it;
		for (p_it = m_PrisonerList.begin(); p_it < m_PrisonerList.end(); p_it++)
		{
			if (p_it->BuyGoods != Nothing)
			{
				// Speech buubles
				SDL_Rect srcRect = { 50, 0, 50, 40 };
				SDL_Rect dstRect = { p_it->BBrect.x, p_it->BBrect.y - 40, 50, 40 };
				SDL_RenderCopy(m_Renderer, m_Speechbubbles, &srcRect, &dstRect);

				// Goods
				srcRect = { 0, 0, 16, 16 };
				if (p_it->BuyGoods == Cigaretts)
					srcRect.x = 16;
				if (p_it->BuyGoods == Weed)
					srcRect.x = 32;
				if (p_it->BuyGoods == Cocaine)
					srcRect.x = 48;
				if (p_it->BuyGoods == Vodka)
					srcRect.x = 64;
				if (p_it->BuyGoods == Wisky)
					srcRect.x = 80;
				dstRect = { p_it->BBrect.x + 14, p_it->BBrect.y - 28, 16, 16 };
				SDL_RenderCopy(m_Renderer, m_Goods, &srcRect, &dstRect);
			}
		}

		// Smuggler
		std::vector<Smuggler>::iterator it;
		for (it = m_SmugglerList.begin(); it < m_SmugglerList.end(); it++)
		{
			if (it->sellGoods != Nothing)
			{
				// Speech buubles
				SDL_Rect srcRect = { 50, 0, 50, 40 };
				SDL_Rect dstRect = { it->dstRect.x, it->dstRect.y - 40, 50, 40 };
				SDL_RenderCopy(m_Renderer, m_Speechbubbles, &srcRect, &dstRect);

				// Goods
				srcRect = { 0, 0, 16, 16 };
				if (it->sellGoods == Cigaretts)
					srcRect.x = 16;
				if (it->sellGoods == Weed)
					srcRect.x = 32;
				if (it->sellGoods == Cocaine)
					srcRect.x = 48;
				if (it->sellGoods == Vodka)
					srcRect.x = 64;
				if (it->sellGoods == Wisky)
					srcRect.x = 80;
				dstRect = { it->dstRect.x + 14, it->dstRect.y - 28, 16, 16 };
				SDL_RenderCopy(m_Renderer, m_Goods, &srcRect, &dstRect);
			}
		}

	}

}