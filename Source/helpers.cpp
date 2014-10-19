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

SDL_Surface* LoadSurface(SDL_Renderer* renderer, const char* fileName)
{
	SDL_Surface* Surf = nullptr;

	// Load the image
	Surf = IMG_Load(fileName);
	if (Surf == nullptr)
	{
		std::cout << "LoadImage Error: " << IMG_GetError() << std::endl;
	}

	return Surf;
}

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

void InttoText(SDL_Renderer* renderer, TTF_Font* font, SDL_Point position, int number, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Texture* tempTex = nullptr;
	SDL_Surface* tempSurf = nullptr;

	std::string text = std::to_string(number);

	SDL_Color color = { r, g, b };

	if (!(tempSurf = TTF_RenderText_Solid(font, text.c_str(), color)))
	{
		std::cout << "InttiText Error: " << TTF_GetError() << std::endl;
	}
	else
	{
		// Create texture from surface
		tempTex = SDL_CreateTextureFromSurface(renderer, tempSurf);
		if (tempTex == nullptr)
		{
			std::cout << "InttiText Error: " << SDL_GetError() << std::endl;
			SDL_FreeSurface(tempSurf);

		}
		else
		{
			SDL_Rect srcRect = tempSurf->clip_rect;
			SDL_Rect dstRect = {position.x,position.y,srcRect.w,srcRect.h};

			SDL_RenderCopy(renderer, tempTex, NULL, &dstRect);
		}

		SDL_FreeSurface(tempSurf);
		SDL_DestroyTexture(tempTex);
	}

}

bool RectIntersects(SDL_Surface* surface, SDL_Rect rect, SDL_Color color)
{
	// Convert to 32bit
	Uint32* pixels = (Uint32*)surface->pixels;
	for (int y = rect.y; y < (rect.y + rect.h); y++)
	{
		for (int x = rect.x; x < (rect.x + rect.w); x++)
		{
			Uint32 temp = pixels[(y * surface->w) + x];
			Uint32 rgba = *((Uint32*)&color);

			if (temp == rgba)
			{
				return true;
			}
		}
	}
	return false;
}

SDL_Color translate_color(Uint32 int_color)
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	SDL_Color color = { (int_color & 0x00ff0000) / 0x10000,
						(int_color & 0x0000ff00) / 0x100,
						(int_color & 0x000000ff),
						0 };
#else
	SDL_Color color = { (int_color & 0x000000ff),
						(int_color &0x0000ff00) / 0x100,
						(int_color & 0x00ff0000) / 0x10000,
						0 };
#endif
	return color;
}