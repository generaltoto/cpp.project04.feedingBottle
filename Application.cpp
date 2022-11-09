#include "Application.h"
#include "FeedingBottle.h"
#include "Shared.h"

#include <SDL.h>
#include <stdio.h>

void Application::addBottle(BottleCommandTemplate command, int bottleCapacity = 330)
{
	this->bottleList.push_front(
		FeedingBottle(bottleCapacity, command.deliveryDate, command.content)
	);
}

Uint32 Application::convertToSeconds(int hours, int minutes, int seconds)
{
	return (hours * 3600) + (minutes * 60) + seconds;
}

BasicDate Application::convertToDate(Uint32 seconds)
{
	BasicDate date;
	date.hours = seconds % 3600;
	date.minutes = seconds - (date.hours * 3600);
	date.seconds = seconds - (date.hours * 3600) - (date.minutes * 60);
	return date;
}

void Application::setTimer(FeedingBottle bottle)
{
	time_t currentTime = time(0);
	if (bottle.takenDate > currentTime)
	{
		Uint32 time = currentTime - bottle.takenDate;
		SDL_AddTimer(time, NULL, NULL);
	}
}

void Application::launchCommand(BottleCommandTemplate command)
{
	for (int i = 0; i < this->bottleList.size(); i++)
	{

		std::list<std::string>::iterator it = this->bottleList.begin();
		setTimer(bottleList(i));
	}

}


SDL_Window* Application::getWindow(void) { return this->window; }

SDL_Surface* Application::getSurface(void) { return this->screenSurface; }

void Application::initSDLWindow(void)
{
	if (SDL_Init(SDL_INIT_TIMER) < 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	else
	{
		this->window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (this->window == NULL) printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		else
		{
			this->screenSurface = SDL_GetWindowSurface(this->window);
			SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(this->window);
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}
}