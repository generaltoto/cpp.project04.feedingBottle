#pragma once

#include "Shared.h"
#include "Button.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <list>
using namespace std;

class SdlWindowModel {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Surface* surface;
	SDL_Texture* texture;
	TTF_Font* font;

public:
	SdlWindowModel();
	~SdlWindowModel();

	SDL_Window* getWindow(void);
	SDL_Renderer* getRenderer(void);
	SDL_Surface* getSurface(void);
	SDL_Texture* getTexture(void);
	TTF_Font* getFont(void);

	void setSurface(SDL_Surface* surface);
	void setTexture(SDL_Texture* texture);
	void setFont(TTF_Font* font);

	/// Creates the SDL window and keeps it open until we press the red cross
	void initSDLWindow(void);

	void drawAppbar(SdlWindowModel& window, DailyButton& daily, StockButton& stock, AddBot& add);

	/// Renders the bottles planning with navbar
	void dispalyDailyView(SdlWindowModel& window, DailyButton& daily, StockButton& stock, AddBot& add);

	/// Renders the page to add a new bottle
	void displayAddBottleView(SdlWindowModel& window, DailyButton& daily, StockButton& stock, AddBot& add);

	/// Renders the stock of ingredients
	void displayStockView(SdlWindowModel& window, DailyButton& daily, StockButton& stock, AddBot& add);
};

