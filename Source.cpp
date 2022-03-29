#include <iostream>
#include "Time.h"

int main()
{
	Time time(23, 59, 0);

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


	time.getToMidnight();

	time.print(true);

	time.~Time();

}


