#include "FeedingBottle.h"
#include "Shared.h"

FeedingBottle::FeedingBottle(int maxCapacity, time_t date, BottleContent ingredients)
{
	this->maxCapacity = maxCapacity;
	this->quantityInBottle = ingredients;
	this->takenDate = date;
}

void FeedingBottle::updateTaken(TakenState state) { this->taken = state; }

void FeedingBottle::updateTakenDate(time_t date) { this->takenDate = date; }