#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#pragma warning(disable: 4996)
using namespace std;
/*
Represents an instant in time, typically expressed as a date and time of day.
*/
class DateTime
{
private:
	int year;
	int month;
	int day;
	int hour;
	int mins;
	int secs;
	int weekDay;
	string dayString[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	string monthString[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

public:

	DateTime()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
		hour = TM.tm_hour;
		mins = TM.tm_min;
		secs = TM.tm_sec;
		weekDay = TM.tm_wday;
	}

	DateTime(int &year, int &month, int &day, int &hour, int &mins, int &secs, int &weekDay)
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
		hour = TM.tm_hour;
		mins = TM.tm_min;
		secs = TM.tm_sec;
		weekDay = TM.tm_wday;
	}

	DateTime(int &year, int &month, int &day, int &hour, int &mins, int &secs)
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
		hour = TM.tm_hour;
		mins = TM.tm_min;
		secs = TM.tm_sec;
	}

	DateTime(int &year, int &month, int &day, int &hour, int &mins)
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
		hour = TM.tm_hour;
		mins = TM.tm_min;
	}

	DateTime(int &year, int &month, int &day, int &hour)
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
		hour = TM.tm_hour;
	}

	DateTime(int &year, int &month, int &day)
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
	}

	DateTime(int &year, int &month)
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
	}

	DateTime(int &year)
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
	}
	/*
	Gets a DateTime object that is set to the current date and time on this computer, expressed as the local time.
	*/
	string Now()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		year = TM.tm_year + 1900;
		month = TM.tm_mon + 1;
		day = TM.tm_mday;
		hour = TM.tm_hour;
		mins = TM.tm_min;
		secs = TM.tm_sec;
		weekDay = TM.tm_wday;
		string dateNow = to_string(day) + "." + to_string(month) + "." + to_string(year) + " " + to_string(hour) + ":" + to_string(mins) + ":" + to_string(secs);
		return dateNow;
	}
	/*Gets the current day in string form.*/
	string GetDayInString()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);
		day = TM.tm_mday;
		return dayString[day];
	}
	/*Gets the current month in string form.*/
	string GetMonthInString()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);
		int _month = TM.tm_mon + 1;
		return monthString[month];
	}
	/*Gets the current day in integer form.*/
	int GetDayInInt()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);
		int _day = TM.tm_mday;
		return day;
	}
	/*Gets the current month in integer form.*/
	int GetMonthInInt()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);
		int month = TM.tm_mon + 1;
		return month;
	}
	/*Gets the current year in integer form.*/
	int GetYearInInt()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);
		int year = TM.tm_year + 1900;
		return year;
	}
	/*Gets the current date*/
	DateTime Today()
	{
		time_t tt;
		time(&tt);
		tm TM = *localtime(&tt);

		int _year = TM.tm_year + 1900;
		int _month = TM.tm_mon + 1;
		int _day = TM.tm_mday;
		DateTime date(_year, _month, _day);
		return date;

	}

	const bool operator > (const DateTime value)
	{
		if (value.year > this->year)
		{
			return true;
		}
		else if (value.year == this->year)
		{
			if (value.month > this->month && this->month != NULL)
			{
				return true;
			}
			else if (value.month == this->month && this->month != NULL)
			{
				if (value.day > this->day)
				{
					return true;
				}
				else if (value.hour > this->hour && this->hour != NULL)
				{
					if (value.mins > this->mins && this->mins != NULL)
					{
						return true;
					}
					else if (value.mins == this->mins && this->mins != NULL)
					{
						if (value.secs > this->secs && this->secs != NULL)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}

	const bool operator < (DateTime value)
	{
		if (value.year < this->year)
		{
			return true;
		}
		else if (value.year == this->year)
		{
			if (value.month < this->month && this->month != NULL)
			{
				return true;
			}
			else if (value.month == this->month && this->month != NULL)
			{
				if (value.day < this->day)
				{
					return true;
				}
				else if (value.hour < this->hour && this->hour != NULL)
				{
					if (value.mins < this->mins && this->mins != NULL)
					{
						return true;
					}
					else if (value.mins == this->mins && this->mins != NULL)
					{
						if (value.secs < this->secs && this->secs != NULL)
						{
							return true;
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	~DateTime()
	{

	}

};
