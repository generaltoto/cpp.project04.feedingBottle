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
	bool isAutomaticCommand = false;

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

public:

	/** Adds a bottle to the [bottleList] */
	void addBottle(BottleCommandTemplate command, int bottleCapacity = 330);

	/** Sets a timer with the bottle delivery date depending on the current date */
	void setTimer(FeedingBottle bottle);

	/** Launches a command or an automatic one if selected. */
	void launchCommand(void);

	/** Returns the window used by SDL */
	SDL_Window* getWindow(void);

	/** Returns the surface contained in the SDL window */
	SDL_Surface* getSurface(void);

	/** Creates the SDL window and keeps it open until we press the red cross */
	void initSDLWindow(void);
};