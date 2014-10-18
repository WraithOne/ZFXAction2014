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

void Capp::InputGame()
{
	if (m_Event.type == SDL_KEYDOWN)
	{
		switch (m_Event.key.keysym.sym)
		{
		case SDLK_UP:
			break;
		case SDLK_DOWN:
			break;
		case SDLK_RETURN:
			break;
		case SDLK_l:
			m_Gamestate = Lost;
			break;
		case SDLK_ESCAPE:
			m_Gamestate = Paused;
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
			break;
		case SDLK_DOWN:
			break;
		default:
			break;
		}
	}
}
void Capp::UpdateGame()
{

}
void Capp::RenderGame()
{
	// Prison Background
	SDL_RenderCopy(m_Renderer, m_Prison, NULL, NULL);
}