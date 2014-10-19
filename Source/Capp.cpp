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

Capp::Capp()
{
	m_Window =			nullptr;
	m_Renderer =		nullptr;

	m_Prison =			nullptr;
	m_PrisonBB =		nullptr;
	m_Menu =			nullptr;
	m_Lost =			nullptr;
	m_Goods =			nullptr;
	m_Speechbubbles =	nullptr;
	m_Player =			nullptr;
	m_Prisoner =		nullptr;
	m_Guard =			nullptr;

	m_Font =			nullptr;

	m_Gamestate =		Menu;
	m_Menustate =		Start;
}
Capp::~Capp()
{

}

bool Capp::Init()
{
	// Create Window
	m_Window = SDL_CreateWindow("ZFX Action V Theme: Career, Cell", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if (m_Window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		Shutdown();

		return false;
	}

	// Create Renderer
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (m_Window == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		Shutdown();

		return false;
	}

	// Init SDL_Image
	int imageFlags = IMG_INIT_PNG;
	if (IMG_Init(imageFlags) != imageFlags)
	{
		std::cout << "IMG_Init failed:" << IMG_GetError() << std::endl;
		Shutdown();

		return false;
	}

	// Init SDL_TTF
	if (TTF_Init() == -1) 
	{
		std::cout << "TTF_Init failed:" << TTF_GetError() << std::endl;
		Shutdown();

		return false;
	}

	// Init SDL_Mixer
	int mixerflag = MIX_INIT_OGG;
	if (Mix_Init(mixerflag) != mixerflag) 
	{
		std::cout << "Mix_Init failed:" << Mix_GetError() << std::endl;
		Shutdown();

		return false;
	}

	// Load Font
	m_Font = TTF_OpenFont("Data/Fonts/ace_futurism.ttf", 16);
	if (m_Font == nullptr)
	{
		std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
		Shutdown();

		return false;
	}

	// Init Menu
	if (!InitMenu())
		return false;

	// Init Game
	if (!InitGame())
		return false;

	// Init Player
	if (!InitPlayer())
		return false;

	// Init Smuggler
	if (!InitSmuggler())
		return false;

	// Init Guard
	if (!InitGuard())
		return false;

	// Init Prisoner
	if (!InitPrisoner())
		return false;

	// Init GUI
	if (!InitGUI())
		return false;

	return true;
}

int Capp::Run()
{
	m_isRunning = true;
	m_lastTime = m_AnimationlastTime = SDL_GetTicks();

	// Game Loop
	while (m_isRunning)
	{
		while (SDL_PollEvent(&m_Event))
		{
			if (m_Event.type == SDL_QUIT || m_Event.type == SDL_WINDOWEVENT_CLOSE)
			{
				m_isRunning = false;
			}
		}
		unsigned int elapsedTime = SDL_GetTicks();

		Input();
		Update(elapsedTime);
		Render(elapsedTime);
	}
	// Shutdown
	Shutdown();

	return 0;
}

void Capp::Input()
{
	if (m_Gamestate == Menu || m_Gamestate == Paused || m_Gamestate == Lost)
	{
		InputMenu();
	}

	if (m_Gamestate == Game)
	{
		InputGame();
	}
}
void Capp::Update(unsigned int elapsedTime)
{
	if (m_Gamestate == Menu || m_Gamestate == Paused || m_Gamestate == Lost)
	{
		UpdateMenu(elapsedTime);
	}

	if (m_Gamestate == Game)
	{
		UpdateGame(elapsedTime);
	}
}
void Capp::Render(unsigned int elapsedTime)
{
	// Clear Color
	SDL_SetRenderDrawColor(m_Renderer, 192, 192, 192, 255);
	SDL_RenderClear(m_Renderer);

	// Render Game
	RenderGame(elapsedTime);

	// Render Menu
	RenderMenu(elapsedTime);

	// Present
	SDL_RenderPresent(m_Renderer);
}

void Capp::Shutdown()
{
	SDL_DestroyTexture(m_Prison);
	SDL_FreeSurface(m_PrisonBB);
	SDL_DestroyTexture(m_Menu);
	SDL_DestroyTexture(m_Lost);
	SDL_DestroyTexture(m_Goods);
	SDL_DestroyTexture(m_Speechbubbles);
	SDL_DestroyTexture(m_Player);
	SDL_DestroyTexture(m_Prisoner);
	SDL_DestroyTexture(m_Guard);

	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}