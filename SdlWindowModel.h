#pragma once

#include "Shared.h"
#include "Button.h"
#include "UtilityFunctions.h"
#include "BottleModel.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <list>
using namespace std;

/// Manages the SDL window as a model.
class SdlWindowModel {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Surface* surface;
	SDL_Texture* texture;
	TTF_Font* font;

public:
	/// Constructor.
	SdlWindowModel();
	/// Destructor.
	~SdlWindowModel();

	/// Returns the SDL window.
	SDL_Window* getWindow(void);

	/// Returns the SDL renderer.
	SDL_Renderer* getRenderer(void);

	/// Returns the SDL surface.
	SDL_Surface* getSurface(void);

	/// Returns the SDL texture.
	SDL_Texture* getTexture(void);

	/// Returns the SDL font.
	TTF_Font* getFont(void);

	/// Sets a new SDL surface
	void setSurface(SDL_Surface* surface);

	/// Sets a new SDL texture.
	void setTexture(SDL_Texture* texture);

	/// Sets a new SDL font.
	void setFont(TTF_Font* font);

	/// Creates the SDL window and keeps it open until we press the red cross
	void initSDLWindow(void);

	/// Draws the navbar.
	void drawAppbar(
		DailyButton& daily, 
		StockButton& stock, 
		AddBot& add
		);

	/// Changes the view depending on the given currentView.
	void switchView(
		ContentTemplate content, 
		DisplayView currentView, 
		DailyButton& daily, 
		StockButton& stock, 
		AddBot& add,
		std::list<BottleModel> bottleList
	);

	/// Renders the bottles planning with navbar
	void dispalyDailyView(
		DailyButton& daily, 
		StockButton& stock, 
		AddBot& add, 
		list<BottleModel> bottleList
	);

	/// Renders the page to add a new bottle
	void displayAddBottleView(
		DailyButton& daily, 
		StockButton& stock, 
		AddBot& add
	);

	/// Renders the stock of ingredients
	void displayStockView(
		ContentTemplate content, 
		DailyButton& daily, 
		StockButton& stock, 
		AddBot& add
	);
};

