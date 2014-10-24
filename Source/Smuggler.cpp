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
	temp.sellRect =			{590, 12, 90, 90};
	temp.srcRect =			{0, 0, 32, 32};
	temp.rotation =			90;
	temp.lastDesisiontime =	0;
	temp.sellGoods =		Cigaretts;
	m_SmugglerList.push_back(temp);

	// Smuggler 2
	temp.dstRect =			{595, 140, 32, 32};
	temp.sellRect =			{567, 113, 90, 90};
	temp.srcRect =			{0, 0, 32, 32};
	temp.rotation =			0;
	temp.lastDesisiontime =	4000;
	temp.sellGoods =		Nothing;
	m_SmugglerList.push_back(temp);

	// Smuggler 3
	temp.dstRect =			{724, 127, 32, 32};
	temp.sellRect =			{697,97,90,90};
	temp.srcRect =			{0, 0, 32, 32};
	temp.rotation =			0;
	temp.lastDesisiontime =	8000;
	temp.sellGoods =		Cocaine;
	m_SmugglerList.push_back(temp);


	return true;
}

void Capp::UpdateSmuggler(unsigned int elapsedTime)
{
	std::vector<Smuggler>::iterator it;
	unsigned int time  =  0;

	for (it = m_SmugglerList.begin(); it < m_SmugglerList.end(); it++)
	{
		if (it->lastDesisiontime == 0)
		{
			it->lastDesisiontime = elapsedTime;
		}
		else
		{
			time = elapsedTime - it->lastDesisiontime;
		}
		

 		if (time >= 10000)
		{
			int randnr;

			randnr = rand() % 6 + 1;
			if (randnr == 0)
				it->sellGoods = Nothing;
			if (randnr == 1)
				it->sellGoods = Cigaretts;
			if (randnr == 2)
				it->sellGoods = Marihuana;
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