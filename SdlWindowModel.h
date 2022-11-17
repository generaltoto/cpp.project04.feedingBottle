#pragma once

#include "Shared.h"
#include "Button.h"
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

	/// Displays the navbar of the app
	void drawNavbar(void);
};

