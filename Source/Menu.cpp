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

bool Capp::InitMenu()
{
	// Load Menu Image
	m_Menu = LoadImage(m_Renderer, "Data/GFX/Menu.png");
	if (m_Menu == nullptr)
	{
		Shutdown();

		return false;
	}
		
	// Load Lost Image
	m_Lost = LoadImage(m_Renderer, "Data/GFX/Lost.png");
	if (m_Lost == nullptr)
	{
		Shutdown();

		return false;
	}

	m_TitelSrcRect = FillRect(0, 0, 584, 67);
	m_TitelDstRect = FillRect(112, 18, 584, 67);

	m_LoseSrcRect = FillRect(0, 286, 335, 67);
	m_LoseDstRect = FillRect(236, 23, 335, 67);

	m_StartSrcRect = FillRect(0, 67, 146, 53);
	m_StartSelectedSrcRect = FillRect(146, 67, 146, 53);
	m_StartDstRect = FillRect(330, 175, 146, 53);

	m_ContinueSrcRect = FillRect(0, 120, 238, 53);
	m_ContinueSelectedSrcRect = FillRect(238, 120, 238, 53);
	m_ContinueDstRect = FillRect(281, 149, 238, 53);

	m_TryAgainSrcRect = FillRect(0, 226, 264, 60);
	m_TryAgainSelectedSrcRect = FillRect(264, 226, 264, 60);
	m_TryAgainDstRect = FillRect(286, 145, 264, 60);

	m_ExitSrcRect = FillRect(0, 173, 110, 53);
	m_ExitSelectedSrcRect = FillRect(110, 173, 110, 53);
	m_ExitDstRect = FillRect(344, 303, 110, 53);

	return true;
}

void Capp::InputMenu()
{
	if (m_Event.type == SDL_KEYDOWN)
	{ 
		switch( m_Event.key.keysym.sym )
		{ 
		case SDLK_UP:
			if (!m_UPpressed)
			{
				if (m_Menustate == Exit)
					m_Menustate = Start;

				m_UPpressed = true;
			}	
			break;
		case SDLK_DOWN:
			if (!m_DOWNpressed)
			{
				if (m_Menustate == Start)
					m_Menustate = Exit;

				m_DOWNpressed = true;
			}
			break;
		case SDLK_RETURN:
			if (m_Menustate == Start)
				if (m_Gamestate == Menu)
				{
					StartGame();
				}
				else if (m_Gamestate == Paused)
				{
					m_Gamestate = Game;
				}
				else if (m_Gamestate == Lost)
				{
					StartGame();
				}
			if (m_Menustate == Exit)
				m_isRunning = false;
			break;
		default: 
			break; 
		}
	}
	if (m_Event.type == SDL_KEYUP)
	{
		switch (m_Event.key.keysym.sym)
		{
		case SDLK_UP:
			m_UPpressed = false;
			break;
		case SDLK_DOWN:
			m_DOWNpressed = false;
			break;
		default:
			break;
		}
	}
}

void Capp::UpdateMenu(unsigned int elapsedTime)
{
	// Nothing to do here ...
}

void Capp::RenderMenu(unsigned int elapsedTime)
{
	if (m_Gamestate == Menu)
	{
		// Title
		SDL_RenderCopy(m_Renderer, m_Menu, &m_TitelSrcRect, &m_TitelDstRect);

		//Start
		if (m_Menustate == Start)
		{
			// Selected
			SDL_RenderCopy(m_Renderer, m_Menu, &m_StartSelectedSrcRect, &m_StartDstRect);
		}
		else
		{
			// Normal
			SDL_RenderCopy(m_Renderer, m_Menu, &m_StartSrcRect, &m_StartDstRect);
		}
		//Exit
		if (m_Menustate == Exit)
		{
			// Selected
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ExitSelectedSrcRect, &m_ExitDstRect);
		}
		else
		{
			// Normal
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ExitSrcRect, &m_ExitDstRect);
		}
	}
	if (m_Gamestate == Paused)
	{
		// Continue
		if (m_Menustate == Start)
		{
			// Selected
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ContinueSelectedSrcRect, &m_ContinueDstRect);
		}
		else
		{
			// Normal
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ContinueSrcRect, &m_ContinueDstRect);
		}

		//Exit
		if (m_Menustate == Exit)
		{
			// Selected
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ExitSelectedSrcRect, &m_ExitDstRect);
		}
		else
		{
			// Normal
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ExitSrcRect, &m_ExitDstRect);
		}
	}
	if (m_Gamestate == Lost)
	{
		// Background
		SDL_RenderCopy(m_Renderer, m_Lost, NULL, NULL);
		SDL_RenderCopy(m_Renderer, m_Menu, &m_LoseSrcRect, &m_LoseDstRect);

		// Try Again
		if (m_Menustate == Start)
		{
			// Selected
			SDL_RenderCopy(m_Renderer, m_Menu, &m_TryAgainSelectedSrcRect, &m_TryAgainDstRect);
		}
		else
		{
			// Normal
			SDL_RenderCopy(m_Renderer, m_Menu, &m_TryAgainSrcRect, &m_TryAgainDstRect);
		}

		//Exit
		if (m_Menustate == Exit)
		{
			// Selected
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ExitSelectedSrcRect, &m_ExitDstRect);
		}
		else
		{
			// Normal
			SDL_RenderCopy(m_Renderer, m_Menu, &m_ExitSrcRect, &m_ExitDstRect);
		}
	}
}