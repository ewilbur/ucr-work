#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <string>


class Date
{
	public:
		unsigned day; 
		unsigned month;
		std::string monthName;
		unsigned year;
		bool isLeap(unsigned) const;
		unsigned daysPerMonth(unsigned m, unsigned y) const;
		std::string name(unsigned m) const;
		unsigned number(const std::string &mn) const;



	public:
		/* ===== Constructors and Destructors ===== */
		Date();
		Date(unsigned m, unsigned d, unsigned y);
		Date(const std::string &mn, unsigned d, unsigned y);

		/* ===== Display functions ===== */
		std::ostream& printNumeric(std::ostream& = std::cout) const;
		std::ostream& printAlpha(std::ostream& = std::cout) const;

		/* ===== Extra Credit ===== */
		Date addDays(int) const;

		/* ========= Added Features ============= */
		Date tomorrow() const;
		int subDays(const Date&) const;

		friend std::ostream& operator<<(std::ostream&, const Date&);
		friend std::ostream& operator<<(std::ostream&, const Date*);

		Date operator+(int) const;
		Date operator-(int) const;

		int operator+(const Date&) const;
		int operator-(const Date&) const;

		bool operator<(const Date&) const;
		bool operator>(const Date&) const;
		bool operator<=(const Date&) const;
		bool operator>=(const Date&) const;
		bool operator==(const Date&) const;
		bool operator!=(const Date&) const;

};

#endif	// DATE_H_
