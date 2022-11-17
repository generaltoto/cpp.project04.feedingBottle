#pragma once
#include <ctime>

#ifndef SHARED_H
#define SHARED_H

/// Fedding Bottle States.
enum TakenState { TAKEN, SCHEDULED, SPITED };

/// Menu statement views.
enum View { DAILYVIEW, STOCKVIEW, ADDVIEW };

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 650;

/// Basic date format for dispaly.
struct BasicDate { long long hours, minutes, seconds; };

/// All ingredients contained in the bottle.
struct BottleContent { float milkQuantity, cocoaQuantity; };

/// Template for bottle command. All quantities are in mg.
struct BottleCommandTemplate
{
	BottleContent content;
	time_t deliveryDate;
};

#endif