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

bool Capp::InitGame()
{
	// Load Prison Image
	m_Prison = LoadImage(m_Renderer, "Data/GFX/Prison.png");
	if (m_Prison == nullptr)
	{
		Shutdown();

		return false;
	}
	// Load PrisonBB Image
	m_PrisonBB = LoadSurface(m_Renderer, "Data/GFX/PrisonBB.png");
	if (m_PrisonBB == nullptr)
	{
		Shutdown();

		return false;
	}

	m_UPpressed = false;
	m_DOWNpressed = false;
	m_LEFTpressed = false;
	m_RIGHTpressed = false;
	m_Bpressed = false;
	m_Spressed = false;

	return true;
}

void Capp::StartGame()
{
	// Reset Player
	m_PlayerBBox = { 277, 234, 32, 32 };
	m_Playermoves = false;
	m_Playerrotation = 90;

	m_Live = 3;
	m_Money = 10;
	m_Cigaretts = 0;
	m_Mariuhana = 0;
	m_Cocaine = 0;
	m_Vodka = 0;
	m_Wisky = 0;

	m_Gamestate = Game;
}

void Capp::InputGame()
{
	// ESC to enter Menu
	if (m_Event.type == SDL_KEYDOWN)
	{
		switch (m_Event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			m_Gamestate = Paused;
			break;
		default:
			break;
		}
	}

	// Handle Player input
	InputPlayer();
}

void Capp::UpdateGame(unsigned int elapsedTime)
{
	UpdateSmuggler(elapsedTime);
	UpdateGuard(elapsedTime);
	UpdatePrisoner(elapsedTime);
	UpdatePlayer(elapsedTime);
}

void Capp::RenderGame(unsigned int elapsedTime)
{
	// Prison Background
	SDL_RenderCopy(m_Renderer, m_Prison, NULL, NULL);

	// Smuggler
	RenderSmuggler(elapsedTime);

	// Prisoner
	RenderPrisoner(elapsedTime);

	//Guard
	RenderGuard(elapsedTime);

	// Player
	RenderPlayer(elapsedTime);

	// Gui
	RenderGUI(elapsedTime);

}