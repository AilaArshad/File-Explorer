#include "Date.h"
Date::Date() {
	time_t now = time(0);
	tm localTime;
	localtime_s(&localTime, &now);
	day = localTime.tm_mday;
	month = localTime.tm_mon + 1;
	year = localTime.tm_year + 1900;
}
void Date::printDate() {
	cout << day << "/" << month << "/" << year << endl;
}