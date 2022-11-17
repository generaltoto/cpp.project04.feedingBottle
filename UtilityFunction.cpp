#include "UtilityFunctions.h"

extern int iterateDatesList(std::list<int> list, int position)
{
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < position; i++) { ++it; }
	return *it;
}

long long convertToSeconds(BasicDate date)
{
	return (date.hours * 3600) + (date.minutes * 60) + date.seconds;
}

BasicDate convertToDate(int seconds)
{
	BasicDate date;
	date.hours = seconds / 3600;
	date.minutes = (seconds - (date.hours * 3600)) / 60;
	date.seconds = seconds - (date.hours * 3600) - (date.minutes * 60);
	return date;
}

extern time_t duration_since_midnight(time_point<system_clock> currentTime)
{
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

extern std::string convertToString(int number)
{
	std::stringstream convert;
	convert << number;
	auto str = convert.str();
	return convert.str().c_str();
}