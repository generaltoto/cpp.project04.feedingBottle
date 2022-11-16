#include "AppManager.h"
#include "BottleModel.h"
#include "StockModel.h"
#include "SdlWindowModel.h"
#include "Shared.h"
#include "UtilityFunctions.h"

const int NUMBER_SECONDS_IN_AN_HOUR = 3600;

AppManager::AppManager() {
	bottleList = {};
	isAutomaticCommand = false;
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



void AppManager::setTimer(BottleModel bottle)
{
	using namespace std::chrono;
	
	const time_point<system_clock> now = system_clock::now();
	auto curTime = system_clock::to_time_t(now);
	long long end = curTime + (bottle.takenDate - duration_since_midnight(now));
	long long timerTime = end - curTime;

	std::cout << "\tStarted timer with " << timerTime << " seconds" << std::endl;
	SDL_Delay(timerTime * 1000);
	std::cout << "\t\tEnd of " << timerTime << " seconds timer" << std::endl;
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
	SdlWindowModel window;
	/*initWindow(window);
	window.drawNavbar();

	SDL_Event e;
	bool quit = false;
	while (quit == false) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) quit = true;
		}
	}

	return;*/

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
		std::list<int> datesList = {};

		while (addAnother)
		{
			BasicDate date;
			std::cout << "Quand est prévu le biberon ? heure puis minutes puis secondes" << std::endl;
			std::cin >> date.hours >> date.minutes >> date.seconds;
			datesList.push_back(convertToSeconds(date));

			do
			{
				std::cout << "Ajouter un autre biberon ? Répondre true / false" << std::endl;
				std::cin >> addAnother;
			} while (addAnother != true && addAnother != false);
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

void AppManager::initWindow(SdlWindowModel& window) { window.initSDLWindow(); }

void AppManager::destroyWindow(SdlWindowModel& window)
{
	SDL_DestroyWindow(window.getWindow());
	SDL_FreeSurface(window.getSurface());
	SDL_DestroyTexture(window.getTexture());
	TTF_CloseFont(window.getFont());
	TTF_Quit();
	SDL_Quit();
}
