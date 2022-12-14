#include "Button.h"
#include "SdlFunction.h"
using namespace std;

Button::Button() { /* Empty constructor */ }

Button::~Button() { /* Empty destructor */ }

void Button::displayButton(SDL_Renderer* renderer, SdlWindowModel& window) {
	drawRectangle(this->color, this->rect, renderer);
	drawText(this->text, this->textColor, this->rect, window);
	SDL_RenderPresent(renderer);
}

bool Button::clickOnRect(int x, int y) {
	//Checks if the tested coordonates are in the button's rect
	if (x >= this->rect.x && x <= (this->rect.x + this->rect.w) 
		&& y >= this->rect.y && y <= (this->rect.y + this->rect.h)) {
		return true;
	}
	return false;
}

void Button::onClick() { }


DailyButton::DailyButton(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void DailyButton::onClick(DisplayView& view) { view = DAILY; }



StockButton::StockButton(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void StockButton::onClick(DisplayView& view) { view = STOCK; }


AddBot::AddBot(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void AddBot::onClick(DisplayView& view) { view = ADD; }


AddStock::AddStock(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void AddStock::onClick() {
	cout << "Clic add stock" << endl;
}


AutoInc::AutoInc(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void AutoInc::onClick(bool& time) {
	time = !time;
	cout << "Clic auto increment" << endl;
}


Submit::Submit(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void Submit::onClick() {
	cout << "Clic submit" << endl;;
}


ViewBot::ViewBot(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void ViewBot::onClick() {
	cout << "Clic viewbot" << endl;;
}


EditBot::EditBot(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void EditBot::onClick() {
	cout << "Clic editbot" << endl;;
}


TakeState::TakeState(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void TakeState::onClick() {
	cout << "Clic taken" << endl;;
}


SchedState::SchedState(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void SchedState::onClick() {
	cout << "Clic taken" << endl;;
}


SpitState::SpitState(SDL_Rect rect, SDL_Color color, SDL_Color textColor, const char* text) {
	this->rect = rect;
	this->color = color;
	this->textColor = textColor;
	this->text = text;
}

void SpitState::onClick() {
	cout << "Clic spit out" << endl;;
}