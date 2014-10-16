////////////////////////////////////////////
///
/// WraithOne
/// www.Dark-Abyss.net
///
/// ZFX Action 2014
///
/// Theme:
///
////////////////////////////////////////////

#include <Capp.h>
Capp::Capp()
{
	m_Window = nullptr;
	m_Renderer = nullptr;

}
Capp::~Capp()
{

}

bool Capp::Init()
{
	m_Window = SDL_CreateWindow("ZFX Action", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if (m_Window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		Shutdown();

		return false;
	}
	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (m_Window == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		Shutdown();

		return false;
	}
	return true;
}

int Capp::Run()
{
	bool isRunning = true;
	unsigned int lastTime = SDL_GetTicks();


	SDL_Event e;

	while (isRunning)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || e.type == SDL_WINDOWEVENT_CLOSE)
			{
				isRunning = false;
			}
			
		}
		unsigned int elapsedTime = SDL_GetTicks() - lastTime;

		Update(elapsedTime);
		Render(elapsedTime);

		lastTime = elapsedTime;
	}
	Shutdown();

	return 0;
}

void Capp::Update(unsigned int elapsedTime)
{
	// Game logic here ..
}
void Capp::Render(unsigned int elapsedTime)
{
	// Draw here..
}

void Capp::Shutdown()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}