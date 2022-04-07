#pragma once

class DateClass
{
private:
		size_t day;
		size_t month;
		size_t year;

		friend class Event;

		bool RealDate()const;
		bool isLeapYear()const;

		
		size_t daysBetweenTwoDates(const DateClass& date)const;
		size_t numberOfLeapYears() const;
		size_t monthsToDays()const;
		size_t convertToDays() const;

public:
		DateClass(size_t day, size_t month, size_t year);
		DateClass();
		~DateClass();


		size_t getDay()const;
		size_t getMonth()const;
		size_t getYear()const;


		void printDate()const;

	
};

