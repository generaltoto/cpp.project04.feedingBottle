#pragma once

#include <SDL.h>

#include <iostream>
using namespace std;

class SdlWindowModel;


class Button {
private:
	SDL_Rect rect;
	SDL_Color color;
	SDL_Color textColor;
	const char* text;

public:
	Button(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);
	~Button();

	/// Draws the button un the SDL window.
	void displayButton(SDL_Renderer* renderer, SdlWindowModel& window);

	/// Checks if the user click in the button surface.
	bool clickOnRect(int x, int y);

	/// Defines the action when you click the button.
	virtual void onClick();
};