#pragma once

#include <SDL.h>

#include <iostream>
using namespace std;

class SdlWindowModel;


class Button {
public:

	SDL_Rect rect;
	SDL_Color color;
	SDL_Color textColor;
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

class DailyButton : public Button {
public:

	DailyButton(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class StockButton : public Button {
public:

	StockButton(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class AddBot : public Button {
public:

	AddBot(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class AddStock : public Button {
public:

	AddStock(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class AutoInc : public Button {
public:

	AutoInc(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick(bool* time);
};

class Submit : public Button {
public:

	Submit(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class ViewBot : public Button {
public:

	ViewBot(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class EditBot : public Button {
public:

	EditBot(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class TakenState : public Button {
public:

	TakenState(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class SchedState : public Button {
public:

	SchedState(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};

class SpitState : public Button {
public:

	SpitState(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text);

	void onClick();
};