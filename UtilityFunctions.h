#pragma once

#include "BottleModel.h"

#include <list>
#include <chrono>

using namespace std::chrono;

/// Returns the Nth member of a given list
/// \param list : list to iterate
/// \param position : index of the element we want to return
/// \return it : the BottleModel at the given position
extern BottleModel iterateBottlesList(std::list<BottleModel> list, int position)
{
	std::list<BottleModel>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

/// Returns the Nth member of a given list
/// \param list : list to iterate
/// \param position : index of the element we want to return
/// \return it : the date at the given position
extern int iterateDatesList(std::list<int> list, int position)
{
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

/// Converts a basic hours (H/Min/Sec) into seconds 
long long convertToSeconds(BasicDate date)
{
	return (date.hours * 3600) + (date.minutes * 60) + date.seconds;
}

/// Converts seconds into a basic hour display (H/Min/Sec)
BasicDate convertToDate(int seconds)
{
	BasicDate date;
	date.hours = seconds / 3600;
	date.minutes = (seconds - (date.hours * 3600)) / 60;
	date.seconds = seconds - (date.hours * 3600) - (date.minutes * 60);
	return date;
}

extern time_t duration_since_midnight(time_point<system_clock> currentTime) {
    using namespace std::chrono;

    time_t tnow = system_clock::to_time_t(currentTime);
    tm* date = std::localtime(&tnow);
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;

    auto midnight = system_clock::from_time_t(std::mktime(date));
	auto h = duration_cast<hours>(currentTime - midnight);
	auto min = duration_cast<minutes>((currentTime - midnight) - h);
	auto s = duration_cast<seconds>((currentTime - midnight) - h - min);

    return convertToSeconds({ h.count(), min.count(), s.count() });
}
