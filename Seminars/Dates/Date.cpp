#include "DateClass.h"

int main()
{
	DateClass Date1, Date2;
	
	Date1.setDay(31);
	Date1.setMonth(3);
	Date1.setYear(1916);
	Date1.setDayOfWeek(7);

	Date2.setDay(15);
	Date2.setMonth(4);
	Date2.setYear(1916);
	Date2.setDayOfWeek(2);


// Oт обекта от който викаме функцията се взема избрания ден за седмица, а от обекта който е извикан като аргумент се взима датата
	std::cout<<Date1.getNewDayOfWeek(Date2) << std::endl << std::endl;

//Връща обект от тип DateClass	
	DateClass Date3 = Date1.getNextDay();
	Date3.printDate();
	
	DateClass Date4 = Date3;

	std::cout << std::endl << Date3.equalDates(Date4)<<<< std::endl;;
}
