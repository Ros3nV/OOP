#include "DateClass.h"


DateClass::DateClass()
{
	this->day = 1;
	this->month = 1;
	this->year = 2012;
	this->dayOfWeek = 1;
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
		return this->day + this->monthsToDays() + (numberOfLeapYears - 1) * 366 + (this->year - numberOfLeapYears) * 365 - 397 - 343;
		//Махам от високосните години 1916, и директно смятам днитe и, които са 343, също така махам датата 1.1.1, която се равнява на 397, защото алгоритъма ще ги сметне и тях
	}
	if (this->year < 1916)
	{
		return this->day + this->monthsToDays() + (numberOfLeapYears - 1) * 366 + (this->year - numberOfLeapYears) * 365 -397;
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


void DateClass::setDay(size_t day)
{
	this->day = day;
	bool isRealDate = RealDate();
	while (!isRealDate)
	{
		std::cout << "You have entered a wrong date, please try again!" << std::endl;
		std::cout << "Enter day: ";
		std::cin >> this->day;
		isRealDate = RealDate();
	}
}
void DateClass::setMonth(size_t month)
{
	this->month = month;
	bool isRealDate = RealDate();
	while (!isRealDate)
	{
		std::cout << "You have entered a wrong date, please try again!" << std::endl;
		std::cout << "Enter month: ";
		std::cin >> this->month;
		isRealDate = RealDate();
	}
}
void DateClass::setYear(size_t year)
{
	 this->year=year;
	bool isRealDate = RealDate();
	while (!isRealDate)
	{
		std::cout << "You have entered a wrong date, please try again!" << std::endl;
		std::cout << "Enter year: ";
		std::cin >> this->year;
		isRealDate = RealDate();
	}
}
void DateClass::setDayOfWeek(size_t dayOfWeek)
{
	this->dayOfWeek = dayOfWeek;
	while (this->dayOfWeek < 1 || this->dayOfWeek>7)
	{
		std::cout << "You have entered a wrong day of week, please try again!" << std::endl;
		std::cout << "Enter new day: ";
		std::cin >> this->dayOfWeek;
	}
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
size_t DateClass::getDayOfWeek() const
{
	return this->dayOfWeek;
}


size_t DateClass::getNewDayOfWeek(const DateClass& date) const
{
	size_t numberOfDaysBetweenTwoDates = this->daysBetweenTwoDates(date);
	return (numberOfDaysBetweenTwoDates + this->dayOfWeek) % 7;
}
DateClass DateClass::getNextDay() const
{
	DateClass data = *this;
	if(++data.dayOfWeek>7)
	{ 
		data.dayOfWeek = 1;
	}

	data.day++;

		if ((data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 || data.month == 12) && data.day > 31)
		{
			data.month++;
			data.day = 1;
			if (data.month == 13)
			{
				data.year++; 
			}

			if (data.month == 4 && data.year == 1916)
			{
				data.day = 14;
			}
		}
		if ((data.month == 4 || data.month == 6 || data.month == 9 || data.month == 11) && data.day > 30)
		{
			data.month++;
			data.day = 1;
		}
		
		if (data.month == 2 && ((data.isLeapYear() && data.day > 29) || !data.isLeapYear() && data.day > 28))
		{
			data.month++;
			data.day = 1;
		}
		return data;
	
}
bool DateClass::equalDates(const DateClass& date) const
{
	return (this->day == date.getDay() && this->month == date.getMonth() && this->year == date.getYear());
}
void DateClass::printDate() const
{
	std::cout << "Day: " << this->day << std::endl;
	std::cout << "Month: " << this->month << std::endl;
	std::cout << "Year: " << this->year << std::endl;
	std::cout << "Day Of Week: " << this->dayOfWeek << std::endl;
}
