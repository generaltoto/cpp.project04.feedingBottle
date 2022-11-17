#include "BottleModel.h"
#include "Shared.h"

BottleModel::BottleModel(int maxCapacity, time_t date, ContentTemplate ingredients)
{
	this->maxCapacity = maxCapacity;
	this->quantityInBottle = ingredients;
	this->takenDate = date;
	this->taken = SCHEDULED;
}

BottleModel::~BottleModel() { }

void BottleModel::updateTaken(BottleState state) { this->taken = state; }

void BottleModel::updateTakenDate(time_t date) { this->takenDate = date; }

extern BottleModel iterateBottlesList(std::list<BottleModel> list, int position) {
	std::list<BottleModel>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}