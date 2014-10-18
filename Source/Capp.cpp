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
#pragma region systems
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
#pragma endregion

#pragma region LoadFiles
	// Load Prison Image
	m_Prison = LoadImage(m_Renderer, "Data/GFX/Prison.png");
	if (m_Prison == nullptr)
		return false;
	// Load Menu Image
	m_Menu = LoadImage(m_Renderer, "Data/GFX/Menu.png");
	if (m_Menu == nullptr)
		return false;
	// Load Lost Image
	m_Lost = LoadImage(m_Renderer, "Data/GFX/Lost.png");
	if (m_Lost == nullptr)
		return false;
	// Load Goods Image
	m_Goods = LoadImage(m_Renderer, "Data/GFX/Goods.png");
	if (m_Goods == nullptr)
		return false;
	// Load Speechbubbles Image
	m_Speechbubbles = LoadImage(m_Renderer, "Data/GFX/Speechbubbles.png");
	if (m_Speechbubbles == nullptr)
		return false;
	// Load Player Image
	m_Player = LoadImage(m_Renderer, "Data/GFX/Player.png");
	if (m_Player == nullptr)
		return false;
	// Load Prisoner Image
	m_Prisoner = LoadImage(m_Renderer, "Data/GFX/Prisoner.png");
	if (m_Prisoner == nullptr)
		return false;
	// Load Guard Image
	m_Guard = LoadImage(m_Renderer, "Data/GFX/Guard.png");
	if (m_Guard == nullptr)
		return false;

	// Load Font
	m_Font = TTF_OpenFont("Data/Fonts/ace_futurism.ttf", 16);
	if (m_Font == nullptr)
	{
		std::cout << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
		Shutdown();

		return false;
	}
#pragma endregion

#pragma region MenuRects
	m_TitelSrcRect =			FillRect(0, 0, 584, 67);
	m_TitelDstRect =			FillRect(112, 18, 584, 67);

	m_LoseSrcRect =				FillRect(0, 286, 335, 67);
	m_LoseDstRect =				FillRect(236, 23 , 335 , 67);

	m_StartSrcRect =			FillRect(0, 67, 146, 53);
	m_StartSelectedSrcRect =	FillRect(146, 67, 146, 53);
	m_StartDstRect =			FillRect(330, 175, 146, 53);

	m_ContinueSrcRect =			FillRect(0, 120, 238, 53);
	m_ContinueSelectedSrcRect = FillRect(238, 120, 238, 53);
	m_ContinueDstRect =			FillRect(281, 149, 238, 53);

	m_TryAgainSrcRect =			FillRect(0, 226, 264, 60);
	m_TryAgainSelectedSrcRect =	FillRect(264, 226, 264, 60);
	m_TryAgainDstRect =			FillRect(286, 145, 264, 60);

	m_ExitSrcRect =				FillRect(0, 173, 110, 53);
	m_ExitSelectedSrcRect =		FillRect(110, 173, 110, 53);
	m_ExitDstRect =				FillRect(344, 303, 110, 53);
#pragma endregion

#pragma region keys
	m_UPpressed =				false;
	m_DOWNpressed =				false;
	m_LEFTpressed =				false;
	m_RIGHTpressed =			false;
	m_Bpressed =				false;
	m_Spressed =				false;
#pragma endregion

	return true;
}

int Capp::Run()
{
	m_isRunning = true;
	unsigned int lastTime = SDL_GetTicks();

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
		unsigned int elapsedTime = SDL_GetTicks() - lastTime;

		Input();
		Update(elapsedTime);
		Render(elapsedTime);

		lastTime = elapsedTime;
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
		UpdateMenu();
	}

	if (m_Gamestate == Game)
	{
		UpdateGame();
	}
}
void Capp::Render(unsigned int elapsedTime)
{
	// Clear Color
	SDL_SetRenderDrawColor(m_Renderer, 192, 192, 192, 255);
	SDL_RenderClear(m_Renderer);

	// Render Game
	RenderGame();

	// Render Menu
	RenderMenu();

	// Present
	SDL_RenderPresent(m_Renderer);
}

void Capp::Shutdown()
{
	SDL_DestroyTexture(m_Prison);
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