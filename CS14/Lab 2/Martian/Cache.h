/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */

#ifndef CACHE_H_
#define CACHE_H_

#include "Smart.h"

class Cache : public Smart
{
	private:
		void update_table();


	public:
		Cache(unsigned);
		Cache();

		void solve();
		void solve_two_square();
		void solve_three_square();

};

#endif	// CACHE_H_