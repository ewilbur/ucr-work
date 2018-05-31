/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */
#ifndef SMART_H_
#define SMART_H_

#include "Martian.h"

#include <cmath>
#include <iostream>


/*
 * This class is designed to take in a number and express it as a sum of
 * squares. I use the following theorems to optimize the code:
 * 		- Legrendre's Theorem
 *		- Lagrandre's Theorem
 *
 * The algorithm to solve it is wholly contained within the private helper
 * functions. A detailed explination of each helper function can be found
 * above the function definition in the "Smart.cpp" file.
 */


class Smart : public Martian
{
	protected:

		const bool perfect_square(int) const;
		const bool four_square(int) const;
		const bool pow_2_divides_number(int, unsigned) const;

		const int reduce_to_three_square(int);

	public:
		Smart(unsigned);
		virtual void solve();
		virtual void solve_three_square();
		virtual void solve_two_square();
};

#endif	// SMART_H_