#pragma once

#include <iostream>
#include <list>
#include <SDL.h>

#include "Shared.h"
#include "FeedingBottle.h"

class Application
{
private:
	std::list<FeedingBottle> bottleList;

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

public:

	/** Returns the window used by SDL */
	SDL_Window* getWindow(void);

	/** Returns the surface contained in the SDL window */
	SDL_Surface* getSurface(void);

	/** Creates the SDL window and keeps it open until we press the red cross */
	void initSDLWindow(void);
};