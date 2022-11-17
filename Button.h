#pragma once

#include "Shared.h"

#include <SDL.h>
#include <iostream>

using namespace std;

class SdlWindowModel;

/// Mother class for all buttons in the app.
class Button {
public:

	/// Defines coordonates and size of the button.
	SDL_Rect rect;
	/// Defines the color of the box.
	SDL_Color color;
	/// Defines the text's color.
	SDL_Color textColor;
	/// Stocks the text displayed inside the button.
	const char* text;

	Button();
	~Button();

	/// Draws the button un the SDL window.
	void displayButton(SDL_Renderer* renderer, SdlWindowModel& window);

	/// Checks if the user click in the button surface.
	bool clickOnRect(int x, int y);

	/// Defines the action when you click the button.
	virtual void onClick();
};

/*
	Each button in the app has a specific class to override the "onClick()" function.
	Because each button does something different.
	They are all childrens of the mother and model class "Button".
*/

class DailyButton : public Button {
public:

	DailyButton(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick(DisplayView& view);
};

class StockButton : public Button {
public:

	StockButton(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick(DisplayView& view);
};

class AddBot : public Button {
public:

	AddBot(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick(DisplayView& view);
};

class AddStock : public Button {
public:

	AddStock(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick();
};

class AutoInc : public Button {
public:

	AutoInc(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick(bool& time);
};

class Submit : public Button {
public:

	Submit(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick();
};

class ViewBot : public Button {
public:

	ViewBot(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
		);

	void onClick();
};

class EditBot : public Button {
public:

	EditBot(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick();
};

class TakeState : public Button {
public:

	TakeState(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick();
};

class SchedState : public Button {
public:

	SchedState(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor, 
		const char* text
	);

	void onClick();
};

class SpitState : public Button {
public:

	SpitState(
		SDL_Rect rect, 
		SDL_Color color, 
		SDL_Color textColor,
		const char* text
	);

	void onClick();
};