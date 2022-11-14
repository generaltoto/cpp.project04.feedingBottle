#include "BottleModel.h"
#include "Shared.h"

BottleModel::BottleModel(int maxCapacity, time_t date, BottleContent ingredients)
{
	this->maxCapacity = maxCapacity;
	this->quantityInBottle = ingredients;
	this->takenDate = date;
}

void BottleModel::updateTaken(TakenState state) { this->taken = state; }

void BottleModel::updateTakenDate(time_t date) { this->takenDate = date; }