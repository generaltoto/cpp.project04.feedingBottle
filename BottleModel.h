#pragma once

#include <ctime>
#include <string>
#include "Shared.h"

/// Model of a Feeding Bottle.
class BottleModel
{
private:
	int minCapacity = 0, maxCapacity = 330;

public:

	/// Current state of the bottle (TAKEN, SCHEDULED, SPIT OUT).
	TakenState taken;

	/// Hour the bottle is scheduled for.
	time_t takenDate;

	/// Quantity of milk currently in the bottle (in mL).
	BottleContent quantityInBottle;

	/// Constructor.
	BottleModel(int maxCapacity, time_t date, BottleContent ingredients);
	/// Destructor.
	~BottleModel();

	/// Updates the bottle's state.
	void updateTaken(TakenState state);

	/// Allows you to update the taken date if the baby spit the fedding bottle out.
	void updateTakenDate(time_t date);
};


