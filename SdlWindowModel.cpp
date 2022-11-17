#include "SdlWindowModel.h"
#include "SdlFunction.h"

SdlWindowModel::SdlWindowModel() {
	this->window = NULL;
	this->renderer = NULL;
	this->surface = NULL;
	this->texture = NULL;
	this->font = NULL;
}

SdlWindowModel::~SdlWindowModel() { }

SDL_Window* SdlWindowModel::getWindow(void) { return this->window; }
SDL_Renderer* SdlWindowModel::getRenderer(void) { return this->renderer; }
SDL_Surface* SdlWindowModel::getSurface(void) { return this->surface; }
SDL_Texture* SdlWindowModel::getTexture(void) { return this->texture; }
TTF_Font* SdlWindowModel::getFont(void) { return this->font; }

void SdlWindowModel::setSurface(SDL_Surface* surface) { this->surface = surface; }
void SdlWindowModel::setTexture(SDL_Texture* texture) { this->texture = texture; }
void SdlWindowModel::setFont(TTF_Font* font) { this->font = font; }

void SdlWindowModel::initSDLWindow(void) {
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

void SdlWindowModel::drawNavbar(void) {
	drawRectangle({ 100,100,100,255 }, { 0, 0, SCREEN_WIDTH, 50 }, this->renderer);
	drawText("Baby Feeder", { 255,255,255,255 }, { SCREEN_WIDTH / 3, 0, 50, 25 },*this);
	SDL_RenderPresent(this->renderer);
}