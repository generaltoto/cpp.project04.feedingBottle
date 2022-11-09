#include "FeedingBottle.h"
#include "Shared.h"

FeedingBottle::FeedingBottle(int maxCapacity, int quantity)
{
	this->maxCapacity = maxCapacity;
	this->quantityInBottle = quantity;
}

void FeedingBottle::updateTaken(TakenState state) { this->taken = state; }

void FeedingBottle::updateTakenDate(tm date) { this->takenDate = date; }