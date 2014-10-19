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
	temp.Buyposition = { 61, 30 };
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
	temp.Buyposition = { 61, 133 };
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
	temp.Buyposition = { 64, 231 };
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
	temp.Buyposition = { 65, 334 };
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
	temp.Buyposition = { 65, 431 };
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
	temp.Buyposition = { 65, 534 };
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
	temp.Buyposition = { 256, 32 };
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
	temp.Buyposition = { 254, 137 };
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
	temp.Buyposition = {384, 265 };
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
	temp.Buyposition = { 483, 265 };
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
	temp.Buyposition = { 283, 451 };
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
	temp.Buyposition = { 385, 452 };
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
	temp.Buyposition = { 481, 455 };
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
	temp.Buyposition = { 582, 453 };
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
	temp.Buyposition = { 679, 453 };
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