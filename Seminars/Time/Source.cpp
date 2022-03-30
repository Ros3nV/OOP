#include <iostream>
#include "Time.h"

int main()
{
	int Hours, Minutes, Seconds;

	std::cout << "Enter Hours :";   std::cin >> Hours;
	std::cout << "Enter Minutes :"; std::cin >> Minutes;
	std::cout << "Enter Seconds :"; std::cin >> Seconds;


	Time time(Hours, Minutes, Seconds);

	if (time.isDinnerTime())
	{
		std::cout << "It's dinner time!" << std::endl;
	}
	else
	{
		std::cout << "It's not dinner time yet!" << std::endl;
	}
	
	if (time.isPartyTime())
	{
		std::cout << "It's party time!" << std::endl;
	}
	else
	{
		std::cout << "It's not party time yet!" << std::endl;
	}


	Time test(10, 24, 1);


	std::cout << time.compare(test);

	time.getToMidnight();

	time.print(true);
}
