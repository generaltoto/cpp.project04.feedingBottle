#pragma once

#include "Shared.h"

#include <chrono>
#include <list>
#include <sstream>

using namespace std::chrono;

/// Returns the Nth member of a given list
/// \param list : list to iterate
/// \param position : index of the element we want to return
/// \return it : the date at the given position
extern int iterateDatesList(std::list<int> list, int position);

/// Converts a basic hours (H/Min/Sec) into seconds 
long long convertToSeconds(BasicDate date);

/// Converts seconds into a basic hour display (H/Min/Sec)
BasicDate convertToDate(int seconds);

/// Computes the time that past between midnight and a given time_point
extern time_t duration_since_midnight(time_point<system_clock> currentTime);

/// Converts a given Int into a char chain
extern std::string convertToString(int number);
