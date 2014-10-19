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
	bool InitMenu();
	void InputMenu();
	void UpdateMenu(unsigned int elapsedTime);
	void RenderMenu(unsigned int elapsedTime);

	// Game
	bool InitGame();
	void StartGame();
	void InputGame();
	void UpdateGame(unsigned int elapsedTime);
	void RenderGame(unsigned int elapsedTime);

	// Player
	bool InitPlayer();
	void InputPlayer();
	void UpdatePlayer(unsigned int elapsedTime);
	void RenderPlayer(unsigned int elapsedTime);

	// Prisoner
	bool InitPrisoner();
	void UpdatePrisoner(unsigned int elapsedTime);
	void RenderPrisoner(unsigned int elapsedTime);

	// Guard
	bool InitGuard();
	void UpdateGuard(unsigned int elapsedTime);
	void RenderGuard(unsigned int elapsedTime);

	// GUI
	bool InitGUI();
	void UpdateGUI(unsigned int elapsedTime);
	void RenderGUI(unsigned int elapsedTime);

	void Shutdown();

private:
	SDL_Window*		m_Window;// Window
	SDL_Renderer*	m_Renderer;// Renderer

	SDL_Texture*	m_Prison;// Background Texture
	SDL_Surface*	m_PrisonBB;//Background Bounding Box
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

	unsigned int	m_lastTime;
	unsigned int	m_AnimationlastTime;
	SDL_Event		m_Event;// Event handle

	// Menu positions
	SDL_Rect		m_TitelSrcRect;
	SDL_Rect		m_TitelDstRect;
	SDL_Rect		m_LoseSrcRect;
	SDL_Rect		m_LoseDstRect;
	SDL_Rect		m_StartSrcRect;
	SDL_Rect		m_StartSelectedSrcRect;
	SDL_Rect		m_StartDstRect;
	SDL_Rect		m_ContinueSrcRect;
	SDL_Rect		m_ContinueSelectedSrcRect;
	SDL_Rect		m_ContinueDstRect;
	SDL_Rect		m_TryAgainSrcRect;
	SDL_Rect		m_TryAgainSelectedSrcRect;
	SDL_Rect		m_TryAgainDstRect;
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

	// Game States
	bool			m_isRunning;// App running state

	// Player States
	SDL_Rect		m_PlayerBBox;
	bool			m_Playermoves;
	float			m_Playerrotation;

	int				m_Live;
	int				m_Money;
	int				m_Cigaretts;
	int				m_Mariuhana;
	int				m_Cocaine;
	int				m_Vodka;
	int				m_Wisky;

	// Gui positions
	SDL_Rect		m_LiveSrcRect;
	SDL_Rect		m_LiveDstRect;
	SDL_Point		m_LivePosition;
	SDL_Rect		m_MoneySrcRect;
	SDL_Rect		m_MoneyDstRect;
	SDL_Point		m_MoneyPosition;
	SDL_Rect		m_CigarettsSrcRect;
	SDL_Rect		m_CigarettsDstRect;
	SDL_Point		m_CigarettsPosition;
	SDL_Rect		m_MariuhanaSrcRect;
	SDL_Rect		m_MariuhanaDstRect;
	SDL_Point		m_MariuhanaPosition;
	SDL_Rect		m_CocaineSrcRect;
	SDL_Rect		m_CocaineDstRect;
	SDL_Point		m_CocainePosition;
	SDL_Rect		m_VodkaSrcRect;
	SDL_Rect		m_VodkaDstRect;
	SDL_Point		m_VodkaPosition;
	SDL_Rect		m_WiskySrcRect;
	SDL_Rect		m_WiskyDstRect;
	SDL_Point		m_WiskyPosition;
};
#endif