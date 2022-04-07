#include "Time.h"
#include <iostream>

Time::Time()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

Time::Time(size_t hours, size_t minutes, size_t seconds)
{
	if (hours > 23) { hours = 0; }
	this->hours = hours;

	if (seconds > 59) { seconds = 0; }
	this->seconds = seconds;

	if (minutes > 59) { minutes = 0; }
	this->minutes = minutes;
}

Time::~Time()
{

}

void Time::printTime() const
{
	std::cout << "Hours: " << this->hours << std::endl;
	std::cout << "Minutes: " << this->minutes << std::endl;
	std::cout << "Seconds: " << this->seconds << std::endl;
}

size_t Time::getMinutes()const
{
	return this->minutes;
}

size_t Time::getSeconds()const
{
	return this->seconds;
}

size_t Time::getHours()const
{
	return this->hours;
}
