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
#ifndef CAPP_H
#define CAPP_H

#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

class Capp
{
public:
	Capp();
	~Capp();

	bool Init();

	int Run();

	void Update(unsigned int elapsedTime);
	void Render(unsigned int elapsedTime);

	void Shutdown();

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

};
#endif