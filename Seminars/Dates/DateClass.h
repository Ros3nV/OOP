#pragma once
#include <iostream>

class DateClass
{
private:
		size_t day;
		size_t month;
		size_t year;
		size_t dayOfWeek;

		bool RealDate()const;
		bool isLeapYear()const;

		size_t convertToDays() const;
		size_t daysBetweenTwoDates(const DateClass& date)const;
		size_t numberOfLeapYears() const;
		size_t monthsToDays()const;
		
public:

		DateClass();
		~DateClass();


		void setDay(size_t day);
		void setMonth(size_t month);
		void setYear(size_t year);
		void setDayOfWeek(size_t dayOfWeek);


		size_t getDay()const;
		size_t getMonth()const;
		size_t getYear()const;
		size_t getDayOfWeek()const;


		size_t getNewDayOfWeek(const DateClass& date) const;
		DateClass getNextDay()const;
		bool equalDates(const DateClass& date)const;
		void printDate()const;

};

