#pragma once

#include <ctime>
#include <string>
#include "Shared.h"

class BottleModel
{
private:
	int minCapacity = 0, maxCapacity = 330;

public:

	/**
	 * Defines the state of the bottle
	 * "taken" if the bottle has been taken
	 * "scheduled" if the bottle is still planned
	 * "spit out" if the baby spit it out
	 */
	TakenState taken;

	/**
	 * Hour the registerd feeding bottle was taken or have been taken.
	 * If the date is after the current date, it has been taken
	 * If the date is before the current date, we set a reminder
	 */
	time_t takenDate;

	/** Quantity of milk currently in the bottle (in mL) */
	BottleContent quantityInBottle;

	BottleModel(int maxCapacity, time_t date, BottleContent ingredients);

	/** Updates the bottle's taken state */
	void updateTaken(TakenState state);

	/** Allows you to update the taken date if the baby spit the fedding bottle out */
	void updateTakenDate(time_t date);
};


