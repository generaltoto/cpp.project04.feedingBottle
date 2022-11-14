#include <iostream>
#include <ctime>
#include <SDL.h>
#include <stdio.h>

#include "AppManager.h"

using namespace std;

int main(int argc, char* args[])
{
	AppManager app;

	app.initSDLWindow();
	app.runInputs();

	SDL_DestroyWindow(app.getWindow());
	SDL_Quit();

	return 0;
}