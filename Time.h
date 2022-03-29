#pragma once
#ifndef  TIME_H
#define TIME_H
#endif

class Time
{
private:
	int seconds;
	int minutes;
	int hours;

	int convertToSeconds(int hours, int minutes, int seconds)const
	{
		return hours * 3600 + minutes * 60 + seconds;
	}

	int compare(Time secondTime)const
	{
		int firstTimeToSeconds = convertToSeconds(this->hours, this->minutes, this->seconds);
		int secondTimeToSeconds = convertToSeconds(secondTime.hours, secondTime.minutes, secondTime.seconds);

		if (firstTimeToSeconds > secondTimeToSeconds)
		{
			return 1;
		}
		else
		{
			if (firstTimeToSeconds < secondTimeToSeconds)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}

	void setNewTime(Time& newTime, int hours, int minutes, int seconds)

	{
		if (hours < 0 || hours>23)
		{
			hours = 0;
		}
		newTime.hours = hours;

		if (seconds < 0 || hours>59)
		{
			seconds = 0;
		}
		newTime.seconds = seconds;

		if (minutes < 0 || minutes>59)
		{
			minutes = 0;
		}
		newTime.minutes = minutes;
	}


public:
	
	Time()
	{
		this->hours = 0;
		this->seconds = 0;
		this->minutes = 0;
	};

	Time(int hours, int minutes, int seconds)
	{
		if (hours < 0 || hours>23)
		{
			hours = 0;
		}
		this->hours = hours;

		if (seconds < 0 || hours>59)
		{
			seconds = 0;
		}
		this->seconds = seconds;

		if (minutes < 0 || minutes>59)
		{
			minutes = 0;
		}
		this->minutes = minutes;
	};

	~Time()
	{
	
	}

	void getToMidnight()const
	{
		int secondsToMidnight= 86400- convertToSeconds(this->hours, this->minutes, this->seconds);

		int hoursToMidnight = secondsToMidnight / 3600;
		int minutesToMidnight = (secondsToMidnight - (hoursToMidnight * 3600)) % 60;
		secondsToMidnight -= convertToSeconds(hoursToMidnight, minutesToMidnight, 0);

		if (secondsToMidnight > 59)
		{
			secondsToMidnight = 0;
			minutesToMidnight++;
		}

		if (minutesToMidnight > 59)
		{
			minutesToMidnight = 0;
			hoursToMidnight++;
		}

		if (hoursToMidnight > 23)
		{
			hoursToMidnight = 0;
		}
		


		std::cout << std::endl;std::cout << std::endl;

		std::cout << "		Time left to Midnight" << std::endl;
		std::cout << "	Hours: " << hoursToMidnight<<std::endl;
		std::cout << "	Minutes: " << minutesToMidnight << std::endl;
		std::cout << "	Seconds: " << secondsToMidnight << std::endl;
	}

	bool isDinnerTime()const
	{
		Time newTime(20, 30, 0);
		if (compare(newTime) == 0 || compare(newTime) == 1)
		{
			newTime.setNewTime(newTime,22, 0, 0);
			if (compare(newTime) == 0 || compare(newTime) == -1)
			{
					return true;
			}
		}
		return false;	
	}
	
	bool isPartyTime()const
	{
		Time newTime(23, 00, 0);


		if ((compare(newTime) == 0 || compare(newTime) == 1))
		{
			return true;
		}

		newTime.setNewTime(newTime,6, 0, 0);

		if ((compare(newTime) == 0 || compare(newTime) == -1))
		{
			return true;
		}

		return false;
	}

	void print(bool is12hoursClock)const
	{
		int hours = this->hours;

		char zeroHour=NULL;
		char zeroMinutes=NULL;
		char zeroSeconds=NULL;


		if (this->hours / 10 == 0)
		{
			zeroHour = '0';
		}
		
		if (this->minutes / 10 == 0)
		{
			zeroMinutes = '0';
		}
		
		if (this->seconds / 10 == 0)
		{
			zeroSeconds = '0';
		}




		if (is12hoursClock)
		{
			bool PM = false;

			if (this->hours > 12)
			{
				PM = true;
				hours -= 12;
			}


			std::cout <<zeroHour<< hours << ':' <<zeroMinutes<< this->minutes << ':' << zeroSeconds <<this->seconds;
			if (PM)
			{
				std::cout << " PM";
			}
			else
			{
				std::cout << " AM";
			}
		}
		else
		{
			std::cout << zeroHour << hours << ':' << zeroMinutes << this->minutes << ':' << zeroSeconds << this->seconds;
		}
	}
	
};
