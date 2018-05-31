/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */

#ifndef MARTIAN_H_
#define MARTIAN_H_


#include <iostream>
#include <vector>
#include <cmath>

class Martian
{
	protected:
		unsigned denomination;
		unsigned * solution;
		unsigned ticks;
		unsigned solutionSize;
		bool solved;

		static std::vector<Martian*> table;

		virtual void solve() =0;

	public:
		Martian(unsigned);
		Martian();
		~Martian();
		unsigned & operator[](const int);
		const unsigned & operator[](const int) const;
		Martian & operator=(const Martian&);


		const unsigned get_denomination() const;
		const unsigned get_ticks() const;
		const unsigned get_size() const;
		const bool is_solved() const;
		void print_table() const;


		
		void set_size(int);
		void set_ticks(int);



		friend std::ostream & operator<<(std::ostream&, const Martian&);


};

#endif