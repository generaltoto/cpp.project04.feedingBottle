#pragma once

#include <iostream>
#include <list>
#include <chrono>
#include <ctime>
#include <SDL.h>
#include <SDL_ttf.h>

#include "Shared.h"
#include "BottleModel.h"
#include "StockModel.h"
#include "SdlWindowModel.h"

/// Manages the entire application, linking controllers to views
class AppManager
{
private:
	std::list<BottleModel> bottleList;
	StockModel stock;
	
	DisplayView currentView;
	bool isAutomaticCommand;

public:

	/// Contructor.
	AppManager();
	/// Destructor.
	~AppManager();

	/// Adds a bottle to the [bottleList]
	bool addBottle(BottleCommandTemplate command, int bottleCapacity = 330);

	/// Sets a timer with the bottle delivery date depending on the current date 
	void setTimer(BottleModel bottle);

	/// Launches a command or an automatic one if selected.
	void launchCommand();

	/// Runs all inputs of the app 
	void run();

	/// Initiates the SDL window of our application
	void initWindow(SdlWindowModel& window);

	/// Closes the SDL window of our application
	void destroyWindow(SdlWindowModel& window);
};