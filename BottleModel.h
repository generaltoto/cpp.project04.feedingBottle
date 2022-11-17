#pragma once
#include <ctime>
#include <string>
#include <list>
#include "Shared.h"

using namespace std;

/// Model of a Feeding Bottle.
class BottleModel {
private:
	int minCapacity = 0, maxCapacity = 330;

public:

	/// Current state of the bottle (TAKEN, SCHEDULED, SPIT OUT)
	BottleState taken;

	/// Hour the bottle is scheduled for.
	time_t takenDate;

	/// Quantity of milk currently in the bottle (in mL).
	ContentTemplate quantityInBottle;

	/// Constructor.
	BottleModel(
		int maxCapacity, 
		time_t date, 
		ContentTemplate ingredients
	);
	/// Destructor.
	~BottleModel();

	/// Updates the bottle's state
	void updateTaken(BottleState state);

	/// Allows you to update the taken date if the baby spit the fedding bottle out.
	void updateTakenDate(time_t date);
};

/// Returns the Nth member of a given list
/// \param list : list to iterate
/// \param position : index of the element we want to return
/// \return it : the BottleModel at the given position
extern BottleModel iterateBottlesList(
	list<BottleModel> list, 
	int position
);