#include "SdlWindowModel.h"
#include "Shared.h"

#include <iostream>

SdlWindowModel::SdlWindowModel()
{
	this->window = NULL;
	this->renderer = NULL;
	this->surface = NULL;
	this->texture = NULL;
	this->font = NULL;
}

SdlWindowModel::~SdlWindowModel() {}

SDL_Window* SdlWindowModel::getWindow(void) { return this->window; }
SDL_Renderer* SdlWindowModel::getRenderer(void) { return this->renderer; }
SDL_Surface* SdlWindowModel::getSurface(void) { return this->surface; }
SDL_Texture* SdlWindowModel::getTexture(void) { return this->texture; }
TTF_Font* SdlWindowModel::getFont(void) { return this->font; }

void SdlWindowModel::initSDLWindow(void)
{
	if (SDL_Init(SDL_INIT_TIMER) < 0) std::cout << "Error initializing SDL : %s\n" << SDL_GetError() << std::endl;
	if (TTF_Init() < 0) std::cout << "Error initializing TTF : %s\n" << TTF_GetError() << std::endl;
	else
	{
		this->window = SDL_CreateWindow("Feeding Bottle Manager", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
		if (!this->renderer || !this->window) std::cout << "Window could not be created!SDL_Error: % s\n" << SDL_GetError() << std::endl;
		this->font = TTF_OpenFont("SourceSerifPro-Light.ttf", 25);
	}
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(this->renderer);
}

void SdlWindowModel::drawNavbar(void)
{
	drawRectangle({ 100,100,100,255 }, { 0, 0, SCREEN_WIDTH, 65 });
	drawText("Baby Feeder", { 255,255,255,255 }, { SCREEN_WIDTH / 3, 0, 50, 25 });

	SDL_RenderPresent(this->renderer);
}

void SdlWindowModel::drawRectangle(SDL_Color color, SDL_Rect rect)
{
	SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(this->renderer);
}

void SdlWindowModel::drawText(const char* text, SDL_Color textColor, SDL_Rect zone)
{
	this->surface = TTF_RenderText_Solid(this->font, text, textColor);
	this->texture = SDL_CreateTextureFromSurface(this->renderer, this->surface);
	SDL_QueryTexture(this->texture, NULL, NULL, &zone.w, &zone.h);
	SDL_RenderCopy(this->renderer, this->texture, NULL, &zone);
}
