#pragma once

#include "Shared.h"
#include <SDL.h>
#include <SDL_ttf.h>

class SdlWindowModel
{
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

	/// Creates the SDL window and keeps it open until we press the red cross
	void initSDLWindow(void);

	/// Displays the navbar of the app
	void drawNavbar(void);

	/// Draws a rectangle
	/// \param - color : rgba color of our rectangle
	/// \param - x : x position of the rectangle
	/// \param - y : y position of the rectangle
	/// \param - width : width of the rectangle
	/// \param - height : height of the rectangle
	void drawRectangle(SDL_Color color, SDL_Rect rect);

	/// Draws text on the screen
	/// \param - text : text to draw
	/// \param - textColor : text color
	/// \param - zone : rectangle in which the text is going to be displayed
	void drawText(const char* text, SDL_Color textColor, SDL_Rect zone);
};

