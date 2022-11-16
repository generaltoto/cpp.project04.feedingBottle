#pragma once
#include "Shared.h"
#include "SdlWindowModel.h"
#include <iostream>
using namespace std;

#include <SDL.h>

/// Draws a rectangle
/// \param - color : rgba color of our rectangle
/// \param - x : x position of the rectangle
/// \param - y : y position of the rectangle
/// \param - width : width of the rectangle
/// \param - height : height of the rectangle
void drawRectangle(SDL_Color color, SDL_Rect rect, SDL_Renderer* renderer);

/// Draws text on the screen
/// \param - text : text to draw
/// \param - textColor : text color
/// \param - zone : rectangle in which the text is going to be displayed
void drawText(const char* text, SDL_Color textColor, SDL_Rect zone, SdlWindowModel window);