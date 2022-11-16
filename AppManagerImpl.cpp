#include "AppManager.h"
#include "BottleModel.h"
#include "StockModel.h"
#include "SdlWindowModel.h"
#include "Shared.h"
#include "UtilityFunctions.h"

using namespace std;

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
		cout << "\nPlus assez de lait !" << endl;
		return false;
	}

	if (stock.getCocoaStock() >= command.content.cocoaQuantity) stock.emptyStock(0, command.content.cocoaQuantity);
	else
	{
		cout << "\nPlus assez de cacao !" << endl; 
		return false;
	}

	this->bottleList.push_back(BottleModel(bottleCapacity, command.deliveryDate, command.content));
	return true;
}



void AppManager::setTimer(BottleModel bottle)
{
	using namespace chrono;
	
	long long timerTime = bottle.takenDate - duration_since_midnight(system_clock::now());
	if (timerTime <= 0) cout << "\tL'heure que vous avez séléctionné est déjà passée." << endl;
	else
	{
		cout << "\tStarted timer with " << timerTime << " seconds" << endl;
		SDL_Delay(timerTime * 1000);
		cout << "\t\tEnd of " << timerTime << " seconds timer" << endl;
	}
}

void AppManager::launchCommand()
{
	for (int i = 0; i < this->bottleList.size(); i++)
	{
		setTimer(iterateBottlesList(this->bottleList, i));
	}
	this->bottleList = {};
}

void checkCinBoolError(bool& variable)
{
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> variable;
		}
		else break;
	}
}

void checkCinIntError(int& variable)
{
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> variable;
		}
		else break;
	}
}

void checkCinFloatError(float& variable) 
{
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> variable;
		}
		else break;
	}
}

void AppManager::runInputs()
{
	SdlWindowModel window;
	initWindow(window);
	window.drawNavbar();

	Button daily = {
	{0, 50, SCREEN_WIDTH / 2, 40},
	{255, 150, 150, 255},
	{255, 255, 255, 255},
	"Daily"
	};
	Button stockView = {
		{SCREEN_WIDTH / 2, 50, SCREEN_WIDTH / 2, 40},
		{150, 255, 150, 255},
		{255, 255, 255, 255},
		"Stock"
	};
	Button add = {
		{SCREEN_WIDTH / 2, 50, SCREEN_WIDTH / 2, 40},
		{150, 255, 150, 255},
		{255, 255, 255, 255},
		"+"
	};
	daily.displayButton(window.getRenderer(), window);
	stockView.displayButton(window.getRenderer(), window);
	SDL_RenderPresent(window.getRenderer());

	SDL_Event e;
	bool quit = false;
	while (quit == false) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) quit = true;

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (daily.clickOnRect(e.motion.x, e.motion.y)) {
					daily.onClick();
				}
				if (stockView.clickOnRect(e.motion.x, e.motion.y)) {
					stockView.onClick();
				}
			}
		}
	}

	return;

	cout << "Stock de lait : " << stock.getMilkStock() << endl;
	cout << "Stock de cacao : " << stock.getCocoaStock() << "\n\n";

	bool automatic = true;
	cout << "Voulez faire une programation automatique (toutes les 3h) ? Repondre 0 (non) / 1 (oui)" << endl;
	cin >> automatic;
	checkCinBoolError(automatic);

	int bottleCapacity;
	cout << "Quelle est la capacité de la bouteille ? (en mL)" << endl;
	cin >> bottleCapacity;
	checkCinIntError(bottleCapacity);

	BottleContent content;
	cout << "Quelle quantité de lait vouler vous ajouter ? (en mL)" << endl;
	cout << "Pour rappel, il vous reste : " << stock.getMilkStock() << endl;
	cin >> content.milkQuantity;
	checkCinFloatError(content.milkQuantity);

	cout << "Quelle quantité de cacao vouler vous ajouter ? (en mg)" << endl;
	cout << "Pour rappel, il vous reste : " << stock.getCocoaStock() << endl;
	cin >> content.cocoaQuantity;
	checkCinFloatError(content.cocoaQuantity);

	if (automatic == 1)
	{
		int nbBottle;
		cout << "Combien de biberons voulez vous programmer ?" << endl;
		cin >> nbBottle;

		BasicDate date;
		cout << "Quand est prévu le premier biberon ? heure puis minutes puis secondes" << endl;
		cin >> date.hours >> date.minutes >> date.seconds;
		cout << "Heure choisie : H = " << date.hours << " MIN = " << date.minutes << " SEC = " << date.seconds << endl;

		BottleCommandTemplate bTemplate{ content, convertToSeconds(date) };
		for (Uint32 i = 0; i < nbBottle; i++) {
			if (addBottle({ content, convertToSeconds(date) + (i * 3 * NUMBER_SECONDS_IN_AN_HOUR) }, bottleCapacity))
			{
				cout << "Programmé la " << i+1 << "e bouteille" << endl;
				continue;
			}
			else
			{
				cout << "Pas assez d'ingrédients" << endl; 
				break;
			}
		}
		launchCommand();
		cout << "Vos / Votre biberon(s) sont bien programmé(s) !" << endl;
	}
	else if (automatic == 0)
	{
		bool addAnother = true;
		list<int> datesList = {};

		while (addAnother)
		{
			BasicDate date;
			cout << "Quand est prévu le biberon ? heure puis minutes puis secondes" << endl;
			cin >> date.hours >> date.minutes >> date.seconds;
			datesList.push_back(convertToSeconds(date));

			do
			{
				cout << "Ajouter un autre biberon ? Répondre true / false" << endl;
				cin >> addAnother;
			} while (addAnother != true && addAnother != false);
		}
		for (int i = 0; i < datesList.size(); i++)
		{
			if (addBottle({ content, iterateDatesList(datesList, i) }))
			{
				cout << "Programmé la " << i+1 << "e bouteille" << endl;
				continue;
			}
			else
			{
				cout << "Pas assez d'ingrédients" << endl;
				break;
			}
		}
		launchCommand();
		cout << "Vos / Votre biberon(s) sont bien programmé(s) !" << endl;
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
