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

bool Capp::InitSmuggler()
{
	// Load Prisoner Image
	m_Smuggler = LoadImage(m_Renderer, "Data/GFX/Smuggler.png");
	if (m_Smuggler == nullptr)
	{
		Shutdown();

		return false;
	}

	Smuggler temp;

	// Smuggler 1
	temp.dstRect =			{621, 38, 32, 32};
	temp.srcRect =			{0, 0, 32, 32};
	temp.rotation =			0;
	temp.lastDesisiontime =	90;
	temp.sellGoods =		Cigaretts;
	m_SmugglerList.push_back(temp);

	// Smuggler 2
	temp.dstRect =			{595, 140, 32, 32};
	temp.srcRect =			{0, 0, 32, 32};
	temp.rotation =			0;
	temp.lastDesisiontime =	0;
	temp.sellGoods =		Nothing;
	m_SmugglerList.push_back(temp);

	// Smuggler 3
	temp.dstRect =			{724, 127, 32, 32};
	temp.srcRect =			{0, 0, 32, 32};
	temp.rotation =			0;
	temp.lastDesisiontime =	0;
	temp.sellGoods =		Cocaine;
	m_SmugglerList.push_back(temp);


	return true;
}

void Capp::UpdateSmuggler(unsigned int elapsedTime)
{
	std::vector<Smuggler>::iterator it;
	for (it = m_SmugglerList.begin(); it < m_SmugglerList.end(); it++)
	{
		unsigned int time;
		if (it->lastDesisiontime < elapsedTime)
		{
			time = 0;
		}
		else
		{
			time = it->lastDesisiontime - elapsedTime;
		}
		if (time >= 30000)
		{
			int randnr;

			randnr = rand() % 6 + 1;
			if (randnr == 0)
				it->sellGoods = Nothing;
			if (randnr == 1)
				it->sellGoods = Cigaretts;
			if (randnr == 2)
				it->sellGoods = Weed;
			if (randnr == 3)
				it->sellGoods = Cocaine;
			if (randnr == 4)
				it->sellGoods = Vodka;
			if (randnr == 5)
				it->sellGoods = Wisky;

			it->lastDesisiontime = elapsedTime;
		}
	}

}
void Capp::RenderSmuggler(unsigned int elapsedTime)
{
	std::vector<Smuggler>::iterator it;
	for (it = m_SmugglerList.begin(); it < m_SmugglerList.end(); it++)
	{
		SDL_RenderCopyEx(m_Renderer, m_Smuggler, &it->srcRect, &it->dstRect, it->rotation, NULL, SDL_FLIP_NONE);
	}
}