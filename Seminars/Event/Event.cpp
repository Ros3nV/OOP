#include <iostream>
#include "Event.h"



Event::Event()
{
	this->nameOfEvent = new char[8];
	strcpy_s(this->nameOfEvent, 8, "Unknown");

	Time time1;
	this->timeOfEvent = time1;

	DateClass date1;
	this->dateOfEvent = date1;
}

Event::Event(const char* name, DateClass date, Time time)
{
	size_t Len=strlen(name) + 1;
	this->nameOfEvent = new char[Len];
	strcpy_s(this->nameOfEvent, Len, name);
	
	this->timeOfEvent = time;

	
	this->dateOfEvent = date;
}

Event::~Event()
{
	delete[] this->nameOfEvent;
}

Time Event::getTimeOfEvent() const
{
	return this->timeOfEvent;
}
DateClass Event::getDateOfEvent() const
{
	return this->dateOfEvent;
}

size_t Event::getDayOfWeek() const
{
	size_t days = this->dateOfEvent.convertToDays();
	days = (days + 6) % 7;
	if (days == 0)
	{
		return 7;
	}
	return days;

}

void Event::printEvent() const
{
	std::cout << "Name: " << this->nameOfEvent << std::endl;
	this->dateOfEvent.printDate();
	this->timeOfEvent.printTime();
	
}


