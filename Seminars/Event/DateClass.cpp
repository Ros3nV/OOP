#include "DateClass.h"
#include <iostream>



DateClass::DateClass()
{
	this->day = 1;
	this->month = 1;
	this->year = 2012;
	
}
DateClass::DateClass(size_t day, size_t month, size_t year)
{
	this->day = day;
	this->month = month;
	this->year = year;

	while (!this->RealDate())
	{
		std::cout << "You have entered a wrong date, please try again!" << std::endl;
		std::cout << "Enter day: ";
		std::cin >> this->day;
		std::cout << "Enter month: ";
		std::cin >> this->month;
		std::cout << "Enter year: ";
		std::cin >> this->year;
	}
}
DateClass::~DateClass()
{
}


bool DateClass::RealDate() const
{
	if (this->day == 0 || this->month == 0 || this->month > 12 || this->day > 31)
	{
		return false;
	}

	if (this->year == 1916 && this->month == 4 && this->day < 14)
	{
		return false;
	}

	if (isLeapYear( ))
	{
		if (this->month == 2 && this->day > 29)
			return false;
	}
	else
	{
		if (this->month == 2 && this->day > 28)
			return false;
	}


	if ((this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 || this->month == 8 || this->month == 10 || this->month == 12) && this->day > 31)
	{
		return false;
	}

	if ((this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) && this->day > 30)
	{
		return false;
	}

	return true;
}
bool DateClass::isLeapYear() const
{
	return  ((this->year % 4 == 0) && (this->year % 100 != 0)) || this->year % 400 == 0;
	
}


size_t DateClass::numberOfLeapYears()const
{
	return (this->year / 4) - (this->year / 100) + (this->year / 400);
}
size_t DateClass::monthsToDays() const
{
	size_t days = 0;
	if (this->month == 1) { return 0; }
	if (this->month > 1) { days += 31; }
	if (this->month > 2)
	{
		if (this->isLeapYear())
			days += 29;
		else
			days += 28;
	}

	if (this->month > 3) { days += 31; }
	if (this->month > 4) { days += 30; }
	if (this->month > 5) { days += 31; }
	if (this->month > 6) { days += 30; }
	if (this->month > 7) { days += 31; }
	if (this->month > 8) { days += 31; }
	if (this->month > 9) { days += 30; }
	if (this->month > 10) { days += 31; }
	if (this->month > 11) { days += 30; }

	return days;
}
size_t DateClass::convertToDays() const
{

	size_t numberOfLeapYears = this->numberOfLeapYears();
	size_t numberOfNormalYears = this->year - numberOfLeapYears;

	if (this->isLeapYear())
	{
		numberOfLeapYears--;
	}
	else
	{
		numberOfNormalYears--;
	}

	if (this->year > 1916)
	{
		return this->day + this->monthsToDays() + (numberOfLeapYears - 1) * 366 + (this->year - numberOfLeapYears) * 365 - 365 - 31 - 1 - 343;
	}
	if (this->year < 1916)
	{
		return this->day + this->monthsToDays() + (numberOfLeapYears - 1) * 366 + (this->year - numberOfLeapYears) * 365 - 365 - 31 - 1;
	}

	size_t MissingDaysOf1916 = 0;
	if (this->month >= 4)
	{
		MissingDaysOf1916 = 13;
	}

	return this->day + this->monthsToDays() + (numberOfLeapYears - 1) * 366 + (this->year - numberOfLeapYears) * 365 - 365 - 31 - 1 - MissingDaysOf1916;


}
size_t DateClass::daysBetweenTwoDates(const DateClass& date) const
{
	int days = this->convertToDays() - date.convertToDays();
	return abs(days);
}


size_t DateClass::getDay() const
{
	return this->day;
}
size_t DateClass::getMonth() const
{
	return this->month;
}
size_t DateClass::getYear() const
{
	return this->year;
}


void DateClass::printDate() const
{
	std::cout << "Day: " << this->day << std::endl;
	std::cout << "Month: " << this->month << std::endl;
	std::cout << "Year: " << this->year << std::endl;

}
