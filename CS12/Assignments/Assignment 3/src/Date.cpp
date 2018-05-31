#include "Date.h"

const std::string MONTHS[12] = 
{"January", "February", "March", "April", "May", "June", 
"July", "August", "September", "October", "November", "December"};

Date::Date()
: day(1), month(1), monthName("January"), year(2000) 
{}

Date::Date(unsigned m, unsigned d, unsigned y)
: year(y)
{
	if(!m || m > 12)
	{
		std::cout << "Error, invalid month, setting month to ";
		std::cout << (!m ? (m = 1) : (m = 12)) << std::endl;
	}

	if(!d || d > daysPerMonth(m, y))
	{
		std::cout << "Error, invalid day, setting day to ";
		std::cout << (!d ? (d = 1) : (d = daysPerMonth(m, y))) << std::endl;
	}

	day = d, month = m, monthName = name(m);
}

Date::Date(const std::string &mn, unsigned d, unsigned y)
: monthName(mn), year(y) 
{
	if(!(month = number(mn)))
	{
		std::cout << "Invalid month name: the date was set to 1/1/2000";
		std::cout << std::endl;
		day = 1, month = 1, year = 2000, monthName = "January";
		return;
	}

	if(!(day = d) || d > daysPerMonth(month, year))
	{
		std::cout << "Error, invalid day, setting day to ";
		std::cout << (!d ? (day = 1) : (day = daysPerMonth(month, year)));
		std::cout << std::endl;
	}
}

std::ostream& Date::printNumeric(std::ostream &os) const
{
	os << month << '/' << day << '/' << year;
	return os;
}

std::ostream& Date::printAlpha(std::ostream &os) const
{
	os << monthName << ' ' << day << ", " << year;
	return os;
}

bool Date::isLeap(unsigned y) const
{
	if(y % 400 == 0) 
		return true;

	else if(y % 100 == 0) 
		return false;

	else if(y % 4 == 0) 
		return true;

	else 
		return false;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
	if(m == 2) 
		return isLeap(y) ? 29 : 28;

	else 
		return ((m & 1 && m <= 7) || (!(m & 1) && m > 7)) ? 31 : 30;
}

std::string Date::name(unsigned m) const
{
	return MONTHS[m - 1];
}

unsigned Date::number(const std::string &mn) const
{
	for(int i = 0; i < 12; i++) 
		if(MONTHS[i] == mn) return (i + 1);

	return 0;
}

Date Date::addDays(int n) const
{
	unsigned d = this->day, m = this->month, y = this->year;

	for(; n > 0; --n)
	{
		if(++d > daysPerMonth(m, y))
		{
			d = 1;
			if(++m > 12)
				m = 1, ++y;
		}
	}

	for(; n < 0; ++n)
	{
		if(!(--d))
		{
			if(!(--m))
				m = 12, --y;

			d = daysPerMonth(m, y);
		}
	}

	return Date(m, d, y);
}

Date Date::tomorrow() const
{
	return addDays(1);
}


int Date::subDays(const Date &rhs) const
{
	if(*this > rhs)
		return -rhs.subDays(*this);

	else if(*this == rhs)
		return 0;

	Date a = *this;
	int diff = 1;

	while((a = a.tomorrow()) != rhs)
		++diff;

	return diff;	
}

std::ostream& operator<<(std::ostream &os, const Date &rhs)
{
	return rhs.printNumeric();
}

std::ostream& operator<<(std::ostream &os, const Date *rhs)
{
	return rhs->printNumeric();
}

Date Date::operator+(int num) const
{
	return addDays(num);
}

Date Date::operator-(int num) const
{
	return addDays(-num);
}

int Date::operator-(const Date &rhs) const
{
	return subDays(rhs);
}

bool Date::operator<(const Date &rhs) const
{
	if(year < rhs.year)
		return true;

	else if(year > rhs.year)
		return false;

	else if(month < rhs.month)
		return true;

	else if(month > rhs.month)
		return false;

	else return (day < rhs.day);
}

bool Date::operator>(const Date &rhs) const
{
	if(year < rhs.year)
		return false;

	else if(year > rhs.year)
		return true;

	else if(month < rhs.month)
		return false;

	else if(month > rhs.month)
		return true;
	
	else return (day < rhs.day);

}

bool Date::operator<=(const Date &rhs) const
{
	return (*this < rhs || *this == rhs);
}

bool Date::operator>=(const Date &rhs) const
{
	return (*this > rhs || *this == rhs);
}

bool Date::operator==(const Date &rhs) const
{
	return (rhs.year == year && rhs.month == month && rhs.day == day);
}

bool Date::operator!=(const Date &rhs) const
{
	return !(*this == rhs);
}

