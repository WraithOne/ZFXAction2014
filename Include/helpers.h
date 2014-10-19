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
#ifndef HELPERS_H
#define HELPERS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <platform.h>
#include <iostream>
#include <string>

// Loads image and creates a Surface
SDL_Surface* LoadSurface(SDL_Renderer* renderer, const char* fileName);

// Loads image and creates a texture
SDL_Texture* LoadImage(SDL_Renderer* renderer, const char* fileName);

// Fill a SDL_Rect
SDL_Rect FillRect(int x, int y, int w, int h);

// Draw Integer to Text
void InttoText(SDL_Renderer* renderer, TTF_Font* font, SDL_Point position, int number, Uint8 r, Uint8 g, Uint8 b);

// Check if a Rect Intersects with a Color on a surface
bool RectIntersects(SDL_Surface* surface, SDL_Rect rect, SDL_Color color);

// Translate to SDL_Color
SDL_Color translate_color(Uint32 int_color);

#endif
