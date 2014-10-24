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

bool Capp::InitPrisoner()
{
	// Load Prisoner Image
	m_Prisoner = LoadImage(m_Renderer, "Data/GFX/Prisoner.png");
	if (m_Prisoner == nullptr)
	{
		Shutdown();

		return false;
	}
	Prisoner temp;

	// Prisoner 1
	temp.BBrect = { 22, 11, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = { 61, 30 };
	temp.BuyArea = { 101, 2, 45, 96 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Cigaretts;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 2
	temp.BBrect = { 18, 158, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = { 61, 133 };
	temp.BuyArea = { 101, 102, 45, 96 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 72, 127 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 3
	temp.BBrect = { 68, 232, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = {64, 231};
	temp.BuyArea = {101, 202, 45, 96};
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 4
	temp.BBrect = { 16, 363, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = { 65, 334 };
	temp.BuyArea = { 101, 302, 45, 96 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Cigaretts;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 5
	temp.BBrect = { 14, 411, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = { 65, 431 };
	temp.BuyArea = { 101, 402, 45, 96 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 90;
	m_PrisonerList.push_back(temp);

	// Prisoner 6
	temp.BBrect = { 70, 534, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = { 65, 534 };
	temp.BuyArea = { 101, 502, 45, 96 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 7
	temp.BBrect = { 307, 49, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = { 256, 32 };
	temp.BuyArea = { 203, 2, 45, 96 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 90;
	m_PrisonerList.push_back(temp);

	// Prisoner 8
	temp.BBrect = { 253, 137, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = true;
	temp.Buyposition = { 254, 137 };
	temp.BuyArea = { 203, 102, 45, 96 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Cigaretts;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 90;
	m_PrisonerList.push_back(temp);

	// Prisoner 9
	temp.BBrect = { 381, 261, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = false;
	temp.Buyposition = {384, 265 };
	temp.BuyArea = { 351, 301, 96, 45 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 90;
	m_PrisonerList.push_back(temp);

	// Prisoner 10
	temp.BBrect = { 482, 208, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = false;
	temp.Buyposition = { 483, 265 };
	temp.BuyArea = { 451, 301, 96, 45 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Cigaretts;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 11
	temp.BBrect = { 281, 461, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = false;
	temp.Buyposition = { 283, 451 };
	temp.BuyArea = { 251, 402, 96, 45 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 12
	temp.BBrect = { 358, 481, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = false;
	temp.Buyposition = { 385, 452 };
	temp.BuyArea = { 351, 402, 96, 45 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 13
	temp.BBrect = { 480, 466, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = false;
	temp.Buyposition = { 481, 455 };
	temp.BuyArea = { 451, 402, 96, 45 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	// Prisoner 14
	temp.BBrect = { 570, 495, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = false;
	temp.Buyposition = { 582, 453 };
	temp.BuyArea = { 551, 402, 96, 45 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Nothing;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 90;
	m_PrisonerList.push_back(temp);
	
	// Prisoner 15
	temp.BBrect = { 702, 497, 32, 32 };
	temp.srcRect = { 0, 0, 32, 32 };
	temp.Behave = Standing;
	temp.lastDecisiontime = 0;
	temp.vertical = false;
	temp.Buyposition = { 679, 453 };
	temp.BuyArea = { 651, 402, 96, 45 };
	temp.Buyrotation = 90;
	temp.BuyGoods = Cigaretts;
	temp.Walkposition = { 62, 65 };
	temp.walkrotation = 0;
	m_PrisonerList.push_back(temp);

	return true;
}

void Capp::UpdatePrisoner(unsigned int elapsedTime)
{
	std::vector<Prisoner>::iterator it;
	for (it = m_PrisonerList.begin(); it < m_PrisonerList.end(); it++)
	{
		if (it->Behave == Standing)
		{
			it->srcRect.x = 0;
		}
		if (it->Behave == WalkingVertical)
		{
			it->srcRect.x = 32;
			it->walkrotation = 90;
		}
		if (it->Behave == WalkingHorizontal)
		{
			it->srcRect.x = 64;
			it->walkrotation = 0;
		}
		if (it->Behave == Buying)
		{
			it->walkrotation = it->Buyrotation;
		}
	}
}

void Capp::RenderPrisoner(unsigned int elapsedTime)
{
	std::vector<Prisoner>::iterator it;
	for (it = m_PrisonerList.begin(); it < m_PrisonerList.end(); it++)
	{
		SDL_RenderCopyEx(m_Renderer, m_Prisoner, &it->srcRect, &it->BBrect, it->walkrotation, NULL, SDL_FLIP_NONE);
	}
}