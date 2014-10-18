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
					m_Gamestate = Game; // Start
				}
				else if (m_Gamestate == Paused)
				{
					m_Gamestate = Game;
				}
				else if (m_Gamestate == Lost)
				{
					m_Gamestate = Game; // restart
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

void Capp::UpdateMenu()
{
	// Nothing to do here ...
}

void Capp::RenderMenu()
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