#include "AppManager.h"
#include "BottleModel.h"
#include "StockModel.h"
#include "Shared.h"

#include <list>
#include <SDL.h>
#include <stdio.h>

const int NUMBER_SECONDS_IN_AN_HOUR = 3600;

/** Utility function used to return the element at the ith position in a list */
BottleModel iterateBottlesList(std::list<BottleModel> list, int position)
{
	std::list<BottleModel>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

Uint32 iterateDatesList(std::list<Uint32> list, int position)
{
	std::list<Uint32>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

AppManager::AppManager() {
	bottleList = {};
	isAutomaticCommand = false;
	window = NULL;
	screenSurface = NULL;
}

AppManager::~AppManager() {}

bool AppManager::addBottle(BottleCommandTemplate command, int bottleCapacity)
{
	if (stock.getMilkStock() >= command.content.milkQuantity) stock.emptyStock(command.content.milkQuantity, 0);
	else
	{
		std::cout << "\nPlus assez de lait !" << std::endl;
		return false;
	}

	if (stock.getCocoaStock() >= command.content.cocoaQuantity) stock.emptyStock(0, command.content.cocoaQuantity);
	else
	{
		std::cout << "\nPlus assez de cacao !" << std::endl; 
		return false;
	}

	this->bottleList.push_back(BottleModel(bottleCapacity, command.deliveryDate, command.content));
	return true;
}

int AppManager::convertToSeconds(BasicDate date)
{
	return (date.hours * 3600) + (date.minutes * 60) + date.seconds;
}

BasicDate AppManager::convertToDate(int seconds)
{
	BasicDate date;
	date.hours = seconds / 3600;
	date.minutes = (seconds - (date.hours * 3600)) / 60;
	date.seconds = seconds - (date.hours * 3600) - (date.minutes * 60);
	return date;
}

void AppManager::setTimer(BottleModel bottle)
{
	std::cout << "\tStarted timer with " << bottle.takenDate << " seconds" << std::endl;
	// SDL_AddTimer(bottle.takenDate, NULL, NULL);
}

void AppManager::launchCommand()
{
	for (int i = 0; i < this->bottleList.size(); i++)
	{
		setTimer(iterateBottlesList(this->bottleList, i));
	}
	this->bottleList = {};
}

void AppManager::runInputs()
{
	std::cout << "Stock de lait : " << stock.getMilkStock() << std::endl;
	std::cout << "Stock de cacao : " << stock.getCocoaStock() << "\n\n";

	bool automatic = true;
	std::cout << "Voulez faire une programation automatique (toutes les 3h) ? Repondre 0 (oui) / 1 (non)" << std::endl;
	std::cin >> automatic;

	int bottleCapacity;
	std::cout << "Quelle est la capacité de la bouteille ? (en mL)" << std::endl;
	std::cin >> bottleCapacity;

	BottleContent content;
	std::cout << "Quelle quantité de lait vouler vous ajouter ? (en mL)" << std::endl;
	std::cout << "Pour rappel, il vous reste : " << stock.getMilkStock() << std::endl;
	std::cin >> content.milkQuantity;

	std::cout << "Quelle quantité de cacao vouler vous ajouter ? (en mg)" << std::endl;
	std::cout << "Pour rappel, il vous reste : " << stock.getCocoaStock() << std::endl;
	std::cin >> content.cocoaQuantity;

	if (automatic == 0)
	{
		int nbBottle;
		std::cout << "Combien de biberons voulez vous programmer ?" << std::endl;
		std::cin >> nbBottle;

		BasicDate date;
		std::cout << "Quand est prévu le premier biberon ? heure puis minutes puis secondes" << std::endl;
		std::cin >> date.hours >> date.minutes >> date.seconds;
		std::cout << "Heure choisie : H = " << date.hours << " MIN = " << date.minutes << " SEC = " << date.seconds << std::endl;

		BottleCommandTemplate bTemplate{ content, convertToSeconds(date) };
		for (Uint32 i = 0; i < nbBottle; i++) {
			if (addBottle({ content, convertToSeconds(date) + (i * 3 * NUMBER_SECONDS_IN_AN_HOUR) }, bottleCapacity) == 1)
			{
				std::cout << "Programmé la " << i+1 << "e bouteille" << std::endl;
				continue;
			}
			else
			{
				std::cout << "Pas assez d'ingrédients" << std::endl; 
				break;
			}
		}
		launchCommand();
		std::cout << "Vos / Votre biberon(s) sont bien programmé(s) !" << std::endl;
	}
	else if (automatic == 1)
	{
		bool addAnother = true;
		std::list<Uint32> datesList = {};

		while (addAnother)
		{
			BasicDate date;
			std::cout << "Quand est prévu le biberon ? heure puis minutes puis secondes" << std::endl;
			std::cin >> date.seconds >> date.minutes >> date.hours;
			datesList.push_back(convertToSeconds(date));

			while (addAnother != true && addAnother != false)
			{
				std::cout << "Ajouter un autre biberon ? Répondre true / false" << std::endl;
				std::cin >> addAnother;
			}
		}
		for (int i = 0; i < datesList.size(); i++)
		{
			if (addBottle({ content, iterateDatesList(datesList, i) }))
			{
				std::cout << "Programmé la " << i+1 << "e bouteille" << std::endl;
				continue;
			}
			else
			{
				std::cout << "Pas assez d'ingrédients" << std::endl;
				break;
			}
		}
		launchCommand();
		std::cout << "Vos / Votre biberon(s) sont bien programmé(s) !" << std::endl;
	}

	return;
}


SDL_Window* AppManager::getWindow(void) { return this->window; }

SDL_Surface* AppManager::getSurface(void) { return this->screenSurface; }

void AppManager::initSDLWindow(void)
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
