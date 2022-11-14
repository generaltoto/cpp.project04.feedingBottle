#pragma once

#ifndef SHARED_H
#define SHARED_H

/// Fedding Bottle State 
enum TakenState { TAKEN, SCHEDULED, SPITED };

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/// Basic date format for dispaly
struct BasicDate { int hours, minutes, seconds; };

/// All ingredients contained in the bottle
struct BottleContent { float milkQuantity, cocoaQuantity; };

/// Template for bottle command. All quantities are in mg
struct BottleCommandTemplate
{
	BottleContent content;
	time_t deliveryDate;
};

#endif