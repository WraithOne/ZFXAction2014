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

#include <platform.h>
#include <iostream>

// Loads image and creates a texture
SDL_Texture* LoadImage(SDL_Renderer* renderer, const char* fileName);

// Fill a SDL_Rect
SDL_Rect FillRect(int x, int y, int w, int h);
#endif
