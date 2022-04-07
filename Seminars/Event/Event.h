#pragma once
#include "Time.h"
#include "DateClass.h"

class Event
{
	char* nameOfEvent;
	DateClass dateOfEvent;
	Time timeOfEvent;
public:

		Event();
		Event(const char* name, DateClass date, Time time);
		~Event
		(
		);

		Time getTimeOfEvent()const;
		DateClass getDateOfEvent()const;

		size_t getDayOfWeek()const;

		void printEvent()const;

};

