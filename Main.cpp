#include <iostream>
#include <ctime>
#include <SDL.h>
#include <stdio.h>

#include "AppManager.h"
#include "SdlWindowModel.h"

using namespace std;

int main(int argc, char* args[])
{
	AppManager app;
	SdlWindowModel window;

	app.initWindow(window);
	app.runInputs();

	return 0;
}