#pragma once

#include "BottleModel.h"

#include <list>

/// Returns the Nth member of a given list
/// \param list : list to iterate
/// \param position : index of the element we want to return
/// \return it : the BottleModel at the given position
BottleModel iterateBottlesList(std::list<BottleModel> list, int position)
{
	std::list<BottleModel>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

/// Returns the Nth member of a given list
/// \param list : list to iterate
/// \param position : index of the element we want to return
/// \return it : the date at the given position
int iterateDatesList(std::list<int> list, int position)
{
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}
