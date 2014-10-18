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
#include <helpers.h>


SDL_Texture* LoadImage(SDL_Renderer* renderer, const char* fileName)
{
	SDL_Surface* loadSurf = nullptr;
	SDL_Texture* texture = nullptr;

	// Load the image
	loadSurf = IMG_Load(fileName);
	if (loadSurf == nullptr)
	{
		std::cout << "LoadImage Error: " << IMG_GetError() << std::endl;
		return texture;
	}

	// Create texture from surface
	texture = SDL_CreateTextureFromSurface(renderer, loadSurf);
	if (texture == nullptr)
	{
		std::cout << "LoadImage Error: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(loadSurf);

		return texture;
	}
	SDL_FreeSurface(loadSurf);

	return texture;
}

SDL_Rect FillRect(int x, int y, int w, int h)
{
	SDL_Rect temp;

	temp.x = x;
	temp.y = y;
	temp.w = w;
	temp.h = h;

	return temp;
}