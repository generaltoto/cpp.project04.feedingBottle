#include "SdlFunction.h"

void drawRectangle(
	SDL_Color color, 
	SDL_Rect rect, 
	SDL_Renderer* renderer) 
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

void drawText(
	const char* text, 
	SDL_Color textColor, 
	SDL_Rect zone, 
	SdlWindowModel window) 
{
	window.setSurface(TTF_RenderText_Solid(window.getFont(), text, textColor));
	window.setTexture(SDL_CreateTextureFromSurface(window.getRenderer(), window.getSurface()));
	SDL_QueryTexture(window.getTexture(), NULL, NULL, &zone.w, &zone.h);
	SDL_RenderCopy(window.getRenderer(), window.getTexture(), NULL, &zone);
}