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

	// Load BuyArea Image
	m_BuyArea = LoadImage(m_Renderer, "Data/GFX/BuyArea.png");
	if (m_BuyArea == nullptr)
	{
		Shutdown();

		return false;
	}

	// Load Sell Area
	m_SellArea = LoadImage(m_Renderer, "Data/GFX/SellArea.png");
	if (m_SellArea == nullptr)
	{
		Shutdown();

		return false;
	}

	m_LiveSrcRect =				{96, 0, 16, 16};
	m_LiveDstRect =				{360, 28, 16, 16};
	m_LivePosition =			{387, 31};

	m_MoneySrcRect =			{0, 0, 16, 16};
	m_MoneyDstRect =			{360, 49, 16, 16};
	m_MoneyPosition =			{387, 49};

	m_CigarettsSrcRect =		{16, 0, 16, 16};
	m_CigarettsDstRect =		{ 360, 70, 16, 16};
	m_CigarettsPosition =		{387, 70};

	m_MariuhanaSrcRect =		{32, 0, 16, 16};
	m_MariuhanaDstRect =		{360, 91, 16, 16};
	m_MariuhanaPosition =		{387, 91};

	m_CocaineSrcRect =			{48, 0, 16, 16};
	m_CocaineDstRect =			{360, 112, 16, 16};
	m_CocainePosition =			{387, 112};

	m_VodkaSrcRect =			{64, 0, 16, 16};
	m_VodkaDstRect =			{360, 133, 16, 16};
	m_VodkaPosition =			{387, 133};

	m_WiskySrcRect =			{80, 0, 16, 16};
	m_WiskyDstRect =			{360, 154, 16, 16};
	m_WiskyPosition =			{387, 154};

	// Buy Area
	m_BuyAreaRect =				{549, 4, 245, 295};

	// Buy Rect
	m_canBuyAreasrcRect1 =		{0, 90, 90, 90};
	m_canBuyAreasrcRect2 =		{90, 90, 90, 90};

	m_cantBuyAreasrcRect1 =		{0, 0, 90, 90};
	m_cantBuyAreasrcRect2 =		{90, 0, 90, 90};
	

	// Sell Rect
	m_HcanSellAreasrcRect1 =	{0, 45, 96, 45};
	m_HcanSellAreasrcRect2 =	{96, 45, 96, 45};

	m_HcantSellAreasrcRect1 =	{0, 0, 96, 45};
	m_HcantSellAreasrcRect2 =	{96, 0, 96, 45};

	m_VcanSellAreasrcRect1 =	{90, 90, 45, 96};
	m_VcanSellAreasrcRect2 =	{135, 90, 45, 96};

	m_VcantSellAreasrcRect1 =	{0 ,90 ,45 ,96};
	m_VcantSellAreasrcRect2 =	{45, 90, 45, 96};

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

		// Marihuana
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
				SDL_Rect srcRect = { 0, 0, 50, 40 };
				SDL_Rect dstRect = { p_it->BBrect.x, p_it->BBrect.y - 40, 50, 40 };
				SDL_SetTextureAlphaMod(m_Speechbubbles, 125);
				SDL_RenderCopy(m_Renderer, m_Speechbubbles, &srcRect, &dstRect);

				// Goods
				srcRect = { 0, 0, 16, 16 };

				if (p_it->BuyGoods == Cigaretts)
					srcRect.x = 16;	

				if (p_it->BuyGoods == Marihuana)
					srcRect.x = 32;	

				if (p_it->BuyGoods == Cocaine)
					srcRect.x = 48;

				if (p_it->BuyGoods == Vodka)
					srcRect.x = 64;

				if (p_it->BuyGoods == Wisky)
					srcRect.x = 80;

				dstRect = { p_it->BBrect.x + 16, p_it->BBrect.y - 31, 16, 16 };
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
				SDL_SetTextureAlphaMod(m_Speechbubbles, 125);
				SDL_RenderCopy(m_Renderer, m_Speechbubbles, &srcRect, &dstRect);

				// Goods
				srcRect = { 0, 0, 16, 16 };
				if (it->sellGoods == Cigaretts)
					srcRect.x = 16;
				if (it->sellGoods == Marihuana)
					srcRect.x = 32;
				if (it->sellGoods == Cocaine)
					srcRect.x = 48;
				if (it->sellGoods == Vodka)
					srcRect.x = 64;
				if (it->sellGoods == Wisky)
					srcRect.x = 80;
				dstRect = { it->dstRect.x + 16, it->dstRect.y - 31, 16, 16 };
				SDL_RenderCopy(m_Renderer, m_Goods, &srcRect, &dstRect);
			}

		}

	}

}

void Capp::RenderGUIrects()
{
	SDL_SetTextureAlphaMod(m_BuyArea, 100);
	SDL_SetTextureAlphaMod(m_SellArea, 100);

	std::vector<Smuggler>::iterator it;
	for (it = m_SmugglerList.begin(); it < m_SmugglerList.end(); it++)
	{
		if (it->sellGoods != Nothing && RectIntersects(m_PlayerBBox,m_BuyAreaRect))
		{
			if (it->sellGoods == Cigaretts)
			{
				if (m_Money >= 5)
				{
					if (RectIntersects(m_PlayerBBox,it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
				else
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
			}

			if (it->sellGoods == Marihuana)
			{
				if (m_Money >= 15)
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
				else
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
			}
			if (it->sellGoods == Cocaine)
			{
				if (m_Money >= 50)
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
				else
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
			}
			if (it->sellGoods == Vodka)
			{
				if (m_Money >= 20)
				{
					SDL_SetTextureAlphaMod(m_BuyArea, 100);

					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
				else
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
			}
			if (it->sellGoods == Wisky)
			{
				if (m_Money >= 30)
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
				else
				{
					if (RectIntersects(m_PlayerBBox, it->sellRect))
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect2, &it->sellRect);
					else
						SDL_RenderCopy(m_Renderer, m_BuyArea, &m_canBuyAreasrcRect1, &it->sellRect);
				}
			}
		}
	}
	
	std::vector<Prisoner>::iterator pit;
	for (pit = m_PrisonerList.begin(); pit < m_PrisonerList.end(); pit++)
	{
		if (pit->BuyGoods != Nothing && !RectIntersects(m_PlayerBBox, m_BuyAreaRect))
		{
			// Cigaretts
			if (pit->BuyGoods == Cigaretts)
			{
				if (m_Cigaretts >= 1)
				{
					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcanSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcanSellAreasrcRect1, &pit->BuyArea);
					}	
				}
				else
				{
					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcantSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcantSellAreasrcRect1, &pit->BuyArea);
					}
				}
			}
			
			// Marihuana
			if (pit->BuyGoods == Marihuana)
			{
				if (m_Mariuhana >= 1)
				{
					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcanSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcanSellAreasrcRect1, &pit->BuyArea);
					}
				}
				else
				{
					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_VcantSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_SellArea, &m_HcantSellAreasrcRect1, &pit->BuyArea);
					}
				}
			}
			
			// Cocoain
			if (pit->BuyGoods == Cocaine)
			{
				if (m_Cocaine >= 1)
				{
					SDL_SetTextureAlphaMod(m_BuyArea, 100);

					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcanSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcanSellAreasrcRect1, &pit->BuyArea);
					}
				}
				else
				{
					SDL_SetTextureAlphaMod(m_BuyArea, 100);

					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcantSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcantSellAreasrcRect1, &pit->BuyArea);
					}
				}
			}
			
			// Vodka
			if (pit->BuyGoods == Vodka)
			{
				if (m_Vodka >= 1)
				{
					SDL_SetTextureAlphaMod(m_BuyArea, 100);

					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcanSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcanSellAreasrcRect1, &pit->BuyArea);
					}
				}
				else
				{
					SDL_SetTextureAlphaMod(m_BuyArea, 100);

					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcantSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcantSellAreasrcRect1, &pit->BuyArea);
					}
				}
			}
			
			// Wisky
			if (pit->BuyGoods == Wisky)
			{
				if (m_Wisky >= 1)
				{
					SDL_SetTextureAlphaMod(m_BuyArea, 100);

					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcanSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcanSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcanSellAreasrcRect1, &pit->BuyArea);
					}
				}
				else
				{
					SDL_SetTextureAlphaMod(m_BuyArea, 100);

					if (pit->vertical == true)
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_VcantSellAreasrcRect1, &pit->BuyArea);
					}
					else
					{
						if (RectIntersects(m_PlayerBBox, pit->BuyArea))
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcantSellAreasrcRect2, &pit->BuyArea);
						else
							SDL_RenderCopy(m_Renderer, m_BuyArea, &m_HcantSellAreasrcRect1, &pit->BuyArea);
					}
				}
			}
		}
	}
	
}