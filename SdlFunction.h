#pragma once
#include "Shared.h"
#include "SdlWindowModel.h"
#include <iostream>
using namespace std;

#include <SDL.h>

/// Draws a rectangle
/// \param - color : rgba color of our rectangle
/// \param - rect : rectangle with : x, y, width, height
/// \param - renderer : renderer of our app.
void drawRectangle(
	SDL_Color color, 
	SDL_Rect rect, 
	SDL_Renderer* renderer
);

/// Draws text on the screen
/// \param - text : text to draw
/// \param - textColor : text color
/// \param - zone : rectangle in which the text is going to be displayed
/// \param - window : window of our app for context
void drawText(
	const char* text, 
	SDL_Color textColor, 
	SDL_Rect zone, 
	SdlWindowModel window
);