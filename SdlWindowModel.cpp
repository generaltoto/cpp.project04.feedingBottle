#include "SdlWindowModel.h"
#include "SdlFunction.h"

SdlWindowModel::SdlWindowModel() {
	this->window = NULL;
	this->renderer = NULL;
	this->surface = NULL;
	this->texture = NULL;
	this->font = NULL;
}

SdlWindowModel::~SdlWindowModel() { }

SDL_Window* SdlWindowModel::getWindow(void) { return this->window; }
SDL_Renderer* SdlWindowModel::getRenderer(void) { return this->renderer; }
SDL_Surface* SdlWindowModel::getSurface(void) { return this->surface; }
SDL_Texture* SdlWindowModel::getTexture(void) { return this->texture; }
TTF_Font* SdlWindowModel::getFont(void) { return this->font; }

void SdlWindowModel::setSurface(SDL_Surface* surface) { this->surface = surface; }
void SdlWindowModel::setTexture(SDL_Texture* texture) { this->texture = texture; }
void SdlWindowModel::setFont(TTF_Font* font) { this->font = font; }

void SdlWindowModel::initSDLWindow(void) {
	/* Initializing the SDL window for the first time */
	if (SDL_Init(SDL_INIT_TIMER) < 0) std::cout << "Error initializing SDL : %s\n" << SDL_GetError() << std::endl;
	if (TTF_Init() < 0) std::cout << "Error initializing TTF : %s\n" << TTF_GetError() << std::endl;
	else
	{
		this->window = SDL_CreateWindow("Feeding Bottle Manager", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
		if (!this->renderer || !this->window) std::cout << "Window could not be created!SDL_Error: % s\n" << SDL_GetError() << std::endl;
		this->font = TTF_OpenFont("SourceSerifPro-Light.ttf", 25);
	}
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(this->renderer);
}

void SdlWindowModel::drawAppbar(DailyButton& daily, StockButton& stock, AddBot& add) {
	/* Drawing the menu */
	drawRectangle({ 100,100,100,255 }, { 0, 0, SCREEN_WIDTH, 50 }, this->renderer);
	drawText("Baby Feeder", { 255,255,255,255 }, { SCREEN_WIDTH / 3, 0, 50, 25 }, *this);

	daily.displayButton(this->renderer, *this);
	stock.displayButton(this->renderer, *this);
	add.displayButton(this->renderer, *this);

	SDL_RenderPresent(this->renderer);
}

void SdlWindowModel::switchView(
	ContentTemplate content, 
	DisplayView currentView, 
	DailyButton& daily, 
	StockButton& stock, 
	AddBot& add,
	std::list<BottleModel> bottleList) {
	/* Changing the selected view */
	switch (currentView) {
	case DAILY:
		dispalyDailyView(daily, stock, add, bottleList);
		break;
	case STOCK:
		displayStockView(content, daily, stock, add);
		break;
	case ADD:
		displayAddBottleView(daily, stock, add);
		break;
	default:
		break;
	}
}

void SdlWindowModel::dispalyDailyView(DailyButton& daily, StockButton& stock, AddBot& add, std::list<BottleModel> bottleList) {
	/* Clearing and rendering the menu */
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderClear(this->renderer);
	drawAppbar(daily, stock, add);
	int navbarHeight = 90;
	drawRectangle({ 210,210,210,255 }, { 40, 40 + navbarHeight, SCREEN_WIDTH - 80, SCREEN_HEIGHT - navbarHeight - 80 }, this->renderer);

	/* Displaying the feeding bottles of the day */
	this->font = TTF_OpenFont("SourceSerifPro-Light.ttf", 15);
	for (int i = 0; i < bottleList.size(); i++) {
		drawRectangle({ 100,100,255,255 }, { 50, (50 + navbarHeight) + (70*i), SCREEN_WIDTH - 100, 50}, this->renderer);
		string bottleIndexText = "Biberon N° " + convertToString(i+1);
		drawText(bottleIndexText.c_str(), {0,0,0,255}, {50, (50 + navbarHeight) + (70 * i), SCREEN_WIDTH - 100, 50}, *this);
		auto date = convertToDate(iterateBottlesList(bottleList, i).takenDate);
		string text = convertToString(date.hours) + "h "+ convertToString(date.minutes) +"min";
		drawText(text.c_str(), {0,0,0,255}, {70, (70 + navbarHeight) + (70 * i), SCREEN_WIDTH - 100, 50}, *this);
	}
}

void SdlWindowModel::displayAddBottleView(DailyButton& daily, StockButton& stock, AddBot& add) {
	/* Clearing and rendering the menu */
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderClear(this->renderer);
	drawAppbar(daily, stock, add);
}

void SdlWindowModel::displayStockView(ContentTemplate content, DailyButton& daily, StockButton& stock, AddBot& add) {
	/* Clearing and rendering the menu */
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderClear(this->renderer);
	drawAppbar(daily, stock, add);

	this->font = TTF_OpenFont("SourceSerifPro-Light.ttf", 18);

	/* Creating the display zone */
	int navbarHeight = 90;
	int stockElHeight = 50;
	int margin = 40;
	SDL_Rect displayZone = { margin, margin + navbarHeight, SCREEN_WIDTH - margin*2, SCREEN_HEIGHT - navbarHeight - margin*2 };
	drawRectangle({ 210,210,210,255 }, displayZone, this->renderer);

	/* Displaying the milk powder quantity */
	SDL_Rect milkStockZone = { displayZone.x + margin/2, displayZone.y + margin/2, displayZone.w - margin, stockElHeight };
	drawRectangle({ 150,150,170,255 }, milkStockZone, this->renderer);
	SDL_Rect milkTitleZone = { milkStockZone.x + margin / 4, milkStockZone.y + margin / 4, milkStockZone.w / 2, milkStockZone.h };
	drawText("Milk Qty ", { 0,0,0,255 }, milkTitleZone, *this);
	SDL_Rect milkQtyZone = { milkTitleZone.x + milkTitleZone.w, milkTitleZone.y, milkStockZone.w / 2, milkStockZone.h };
	drawText(convertToString(content.milkQuantity).c_str(), {0,0,0,255}, milkQtyZone, *this);

	/* Displaying the cocoa powder quantity */
	SDL_Rect cocoaStockZone = { milkStockZone.x, milkStockZone.y + milkStockZone.h + margin / 2, milkStockZone.w, milkStockZone.h };
	drawRectangle({ 150,150,170,255 }, cocoaStockZone, this->renderer);
	SDL_Rect cocoaTitleZone = { cocoaStockZone.x + margin / 4, cocoaStockZone.y + margin / 4, cocoaStockZone.w / 2, cocoaStockZone.h };
	drawText("Cocoa Qty ", { 0,0,0,255 }, cocoaTitleZone, *this);
	SDL_Rect cocoaQtyZone = { cocoaTitleZone.x + cocoaTitleZone.w, cocoaTitleZone.y, cocoaStockZone.w / 2, cocoaStockZone.h };
	drawText(convertToString(content.cocoaQuantity).c_str(), { 0,0,0,255 }, cocoaQtyZone, *this);

	this->font = TTF_OpenFont("SourceSerifPro-Light.ttf", 25);
}