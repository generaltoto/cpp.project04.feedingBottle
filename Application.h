#pragma once

#include <iostream>
#include <list>
#include <SDL.h>

#include "Shared.h"
#include "FeedingBottle.h"
#include "Stock.h"

class Application
{
private:
	std::list<FeedingBottle> bottleList = {};
	MilkStock milkStock;
	CocoaStock cocoaStock;
	
	bool isAutomaticCommand = false;

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

public:

	Application();
	~Application();

	/// Adds a bottle to the [bottleList]
	bool addBottle(BottleCommandTemplate command, int bottleCapacity = 330);

	/// Converts a basic hours (H/Min/Sec) into seconds 
	Uint32 convertToSeconds(BasicDate date);

	/// Converts seconds into a basic hour display (H/Min/Sec)
	BasicDate convertToDate(Uint32 seconds);

	/// Sets a timer with the bottle delivery date depending on the current date 
	void setTimer(FeedingBottle bottle);

	/// Launches a command or an automatic one if selected.
	void launchCommand();

	/// Runs all inputs of the app 
	void runInputs();


	/// Returns the window used by SDL 
	SDL_Window* getWindow(void);

	/// Returns the surface contained in the SDL window
	SDL_Surface* getSurface(void);

	/// Creates the SDL window and keeps it open until we press the red cross
	void initSDLWindow(void);
};