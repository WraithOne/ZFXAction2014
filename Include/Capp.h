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
#ifndef CAPP_H
#define CAPP_H

// std
#include <iostream>
#include <string>

// SDL2
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

// Application
#include <helpers.h>

enum Gamestate
{
	Menu,
	Paused,
	Game,
	Lost
};

enum Menustate
{
	Start,
	Exit
};

class Capp
{
public:
	Capp();
	~Capp();

	bool Init();

	int Run();

	void Input();
	void Update(unsigned int elapsedTime);
	void Render(unsigned int elapsedTime);

	// Menu
	void InputMenu();
	void UpdateMenu();
	void RenderMenu();

	// Game
	void InputGame();
	void UpdateGame();
	void RenderGame();

	void Shutdown();

private:
	SDL_Window*		m_Window;// Window
	SDL_Renderer*	m_Renderer;// Renderer

	SDL_Texture*	m_Prison;// Background Texture
	SDL_Texture*	m_Menu;// Menu Texture
	SDL_Texture*	m_Lost;// Lost Texture
	SDL_Texture*	m_Goods;// Goods Texture
	SDL_Texture*	m_Speechbubbles;// Speechbubbles Texture
	SDL_Texture*	m_Player;// Player Texture
	SDL_Texture*	m_Prisoner;// Prisoner Texture
	SDL_Texture*	m_Guard;// Guard Texture

	TTF_Font*		m_Font;// Font

	Gamestate		m_Gamestate;// Gamestate
	Menustate		m_Menustate;// Menustate

	SDL_Event		m_Event;

	// Titel position
	SDL_Rect		m_TitelSrcRect;
	SDL_Rect		m_TitelDstRect;

	// Lose position
	SDL_Rect		m_LoseSrcRect;
	SDL_Rect		m_LoseDstRect;

	// Start position
	SDL_Rect		m_StartSrcRect;
	SDL_Rect		m_StartSelectedSrcRect;
	SDL_Rect		m_StartDstRect;

	// Continue position
	SDL_Rect		m_ContinueSrcRect;
	SDL_Rect		m_ContinueSelectedSrcRect;
	SDL_Rect		m_ContinueDstRect;

	// Try Again position
	SDL_Rect		m_TryAgainSrcRect;
	SDL_Rect		m_TryAgainSelectedSrcRect;
	SDL_Rect		m_TryAgainDstRect;

	// Exit position
	SDL_Rect		m_ExitSrcRect;
	SDL_Rect		m_ExitSelectedSrcRect;
	SDL_Rect		m_ExitDstRect;

	//Keydown
	bool			m_UPpressed;
	bool			m_DOWNpressed;
	bool			m_LEFTpressed;
	bool			m_RIGHTpressed;
	bool			m_Bpressed;
	bool			m_Spressed;

	bool			m_isRunning;

};
#endif