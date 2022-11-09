#pragma once

#ifndef SHARED_H
#define SHARED_H

enum TakenState { TAKEN, SCHEDULED, SPITED };

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/** Template for bottle command. All quantities are in mg */
struct BottleCommandTemplate
{
	float milkQuantity;
	float cocoaQuantity;
	float creatineQuantity;
	float wheyQuantity;
	float CH4quantity;
	time_t deliveryDate;
};

#endif