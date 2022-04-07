
#include "Event.h"
#include "DateClass.h"
#include "Time.h"
#include <iostream>

int main()
{
	Time timeOfEvent(15, 15, 0);
	DateClass dateOfEvent (7, 4, 2022);

	Event newEvent("OOP lesson", dateOfEvent,timeOfEvent);


	std::cout <<"D: " << newEvent.getDateOfEvent().getDay() << std::endl;
	std::cout <<"M: " << newEvent.getDateOfEvent().getMonth() << std::endl;
	std::cout << "Y: " << newEvent.getDateOfEvent().getYear();

	std::cout << std::endl << std::endl;

	std::cout << "H: " << newEvent.getTimeOfEvent().getHours() << std::endl;
	std::cout <<"M: " <<newEvent.getTimeOfEvent().getMinutes() << std::endl;
	std::cout << "S: "<<newEvent.getTimeOfEvent().getSeconds();

	std::cout << std::endl << std::endl;


	std::cout << "Day of Week: " << newEvent.getDayOfWeek();

	std::cout << std::endl << std::endl;

	newEvent.printEvent();




}