#pragma once

class Time
{
private:
	size_t seconds, minutes, hours;
public:
	Time();

	Time(size_t hours, size_t minutes, size_t seconds);

	~Time();

	size_t getMinutes()const;
	size_t getSeconds()const;
	size_t getHours()const;

	void printTime()const;

};

