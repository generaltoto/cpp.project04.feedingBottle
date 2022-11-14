#include "Application.h"
#include "FeedingBottle.h"
#include "Stock.h"
#include "Shared.h"

#include <list>
#include <SDL.h>
#include <stdio.h>

const int NUMBER_SECONDS_IN_AN_HOUR = 1080000;

/** Utility function used to return the element at the ith position in a list */
FeedingBottle iterateBottlesList(std::list<FeedingBottle> list, int position)
{
	std::list<FeedingBottle>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

Uint32 iterateDatesList(std::list<Uint32> list, int position)
{
	std::list<Uint32>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

Application::Application() : milkStock(MilkStock(1000)) {};

bool Application::addBottle(BottleCommandTemplate command, int bottleCapacity)
{
	if (milkStock.getStock() > command.content.milkQuantity) milkStock.emptyStock(command.content.milkQuantity);
	else std::cout << "not enough milk, please buy some more"; return false;


	if (cocoaStock.getStock() > command.content.cocoaQuantity) cocoaStock.emptyStock(command.content.cocoaQuantity);
	else std::cout << "not enough cocoa, please buy some more"; return false;

	this->bottleList.push_back(FeedingBottle(bottleCapacity, command.deliveryDate, command.content));
	return true;
}

Uint32 Application::convertToSeconds(BasicDate date)
{
	return (date.hours * 3600) + (date.minutes * 60) + date.seconds;
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
	if ((bottle.takenDate > currentTime))
	{
		Uint32 time = currentTime - bottle.takenDate;
		std::cout << "\tStarted timer with " << time << " seconds" << std::endl;
		SDL_AddTimer(time, NULL, NULL);
	}
}

void Application::launchCommand()
{
	for (int i = 0; i < this->bottleList.size(); i++)
	{
		setTimer(iterateBottlesList(this->bottleList, i));
	}
	this->bottleList = {};
}

void Application::runInputs()
{
	std::cout << "Stock de lait : " << milkStock.getStock() << std::endl;
	std::cout << "Stock de cacao : " << cocoaStock.getStock() << "\n\n";

	bool automatic = true;

	std::cout << "Voulez faire une programation automatique (toutes les 3h) ? Repondre true / false" << std::endl;
	std::cin >> automatic;

	int bottleCapacity;
	std::cout << "Quelle est la capacité de la bouteille ? (en mL)" << std::endl;
	std::cin >> bottleCapacity;

	BottleContent content;
	std::cout << "Quelle quantité de lait vouler vous ajouter ? (en mL)" << std::endl;
	std::cout << "Pour rappel, il vous reste : " << milkStock.getStock() << std::endl;
	std::cin >> content.milkQuantity;

	std::cout << "Quelle quantité de cacao vouler vous ajouter ? (en mg)" << std::endl;
	std::cout << "Pour rappel, il vous reste : " << cocoaStock.getStock() << std::endl;
	std::cin >> content.cocoaQuantity;

	if (automatic == true)
	{
		int nbBottle;
		std::cout << "Combien de biberons voulez vous programmer ?" << std::endl;
		std::cin >> nbBottle;

		BasicDate date;
		std::cout << "Quand est prévu le premier biberon ? ex : 'heure,minutes,secondes'" << std::endl;
		std::cin >> date.hours, date.minutes, date.seconds;

		BottleCommandTemplate bTemplate{ content, convertToSeconds(date) };
		for (Uint32 i = 0; i < nbBottle; i++) {
			if (addBottle({ content, convertToSeconds(date) + (i * 3 * NUMBER_SECONDS_IN_AN_HOUR) }, bottleCapacity)) continue;
			else std::cout << "Pas assez d'ingrédients" << std::endl; break;
		}
		launchCommand();
		std::cout << "Vos / Votre biberon(s) sont bien programmé(s) !" << std::endl;
	}
	else if (automatic == false)
	{
		bool addAnother = true;
		std::list<Uint32> datesList = {};

		while (addAnother)
		{
			BasicDate date;
			std::cout << "Quand est prévu le biberon ? ex : 'heure,minutes,secondes'" << std::endl;
			std::cin >> date.hours, date.minutes, date.seconds;
			datesList.push_back(convertToSeconds(date));

			while (addAnother != true && addAnother != false)
			{
				std::cout << "Ajouter un autre biberon ? Répondre true / false" << std::endl;
				std::cin >> addAnother;
			}
		}
		for (int i = 0; i < datesList.size(); i++)
		{
			if (addBottle({ content, iterateDatesList(datesList, i) })) continue;
			else std::cout << "Pas assez d'ingrédients" << std::endl; break;
		}
		launchCommand();
		std::cout << "Vos / Votre biberon(s) sont bien programmé(s) !" << std::endl;
	}

	return;
}


SDL_Window* Application::getWindow(void) { return this->window; }

SDL_Surface* Application::getSurface(void) { return this->screenSurface; }

void Application::initSDLWindow(void)
{
	if (SDL_Init(SDL_INIT_TIMER) < 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	/*else
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
	}*/
}