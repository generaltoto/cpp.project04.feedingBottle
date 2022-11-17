#pragma once
#include <ctime>

#ifndef SHARED_H
#define SHARED_H

/// Fedding Bottle State 
enum BottleState { TAKEN, SCHEDULED, SPITED };

/// Different views of the application
enum DisplayView { DAILY, STOCK, ADD };

/// Menu statement views.
enum View { DAILYVIEW, STOCKVIEW, ADDVIEW };

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 650;

/// Basic date format for dispaly.
struct BasicDate { long long hours, minutes, seconds; };

/// All ingredients contained by something (stock, bottle).
struct ContentTemplate { int milkQuantity, cocoaQuantity; };

/// Template for bottle command. All quantities are in mg.
struct BottleCommandTemplate {
	ContentTemplate content;
	time_t deliveryDate;
};

#endif