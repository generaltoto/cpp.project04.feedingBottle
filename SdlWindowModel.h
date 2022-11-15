#pragma once

#include "Shared.h"
#include <SDL.h>

class SdlWindowModel
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* screenSurface;

public:

	SdlWindowModel();
	~SdlWindowModel();

	/// Returns the window used by SDL 
	SDL_Window* getWindow(void);

	/// Returns the SDL renderer
	SDL_Renderer* getRenderer(void);

	/// Returns the surface contained in the SDL window
	SDL_Surface* getSurface(void);

	/// Creates the SDL window and keeps it open until we press the red cross
	void initSDLWindow(void);

	void drawNavbar(void);

	/// Draws a rectangle
	/// \param - color : rgba color of our rectangle
	/// \param - x : x position of the rectangle
	/// \param - y : y position of the rectangle
	/// \param - width : width of the rectangle
	/// \param - height : height of the rectangle
	void drawRectangle(SDL_Color color, int x, int y, int width, int height);
};

