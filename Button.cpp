#include "Button.h"
#include "SdlFunction.h"
using namespace std;

Button::Button(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

Button::~Button() { }

void Button::displayButton(SDL_Renderer* renderer, SdlWindowModel& window) {
	drawRectangle(this->color, this->rect, renderer);
	drawText(this->text, this->textColor, this->rect, window);
	SDL_RenderPresent(renderer);
}

bool Button::clickOnRect(int x, int y) {
	if (x >= this->rect.x && x <= (this->rect.x + this->rect.w) 
		&& y >= this->rect.y && y <= (this->rect.y + this->rect.h)) {
		return true;
	}
	return false;
}

void Button::onClick() {
	cout << "Clic" << endl;
}