/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */

#include "Smart.h"

Smart::Smart(unsigned val)
: Martian(val)
{}

/*
 * Tests if a number is a perfect square
 */
const bool Smart::perfect_square(int val) const
{
	return pow(floor(sqrt(val)), 2) == val;
}

/*
 * Uses Legrendre's theorem to determine if a number must be written as a sum
 * of four squares.
 */
const bool Smart::four_square(int val) const
{
	while(pow_2_divides_number(val, 2))
		val /= 4;

	return pow_2_divides_number(val - 7, 3);
}

/*
 * Tests divisibity by powers of 2. Because why not make things more
 * complicated than necessary by using bitshift?
 */
const bool Smart::pow_2_divides_number(int val, unsigned power) const
{

	if(power == 0)
		return true;
	

	else if(val & 1 == 1)
		return false;


	else

		return pow_2_divides_number((val >> 1), power - 1);
}

/*
 * Takes a number that must be written as the sum of four squares and reduces
 * it to one that can be written as as sum of three squares.
 */
const int Smart::reduce_to_three_square(int val)
{
	/* This is the lower bound of possible options. Because math */
	int startIndex = floor(sqrt(val / 4));

	for(int i = startIndex; i * i < val; i++)
	{
		/* Take a guess, up a tick */
		ticks++;

		/* The new number passes the four-square test*/
		if(!four_square(val - i * i))
			return i;
	}
}

/*
 * Writes the number as a sum of two squares if possible.
 */
void Smart::solve_two_square()
{
	int startIndex = sqrt(denomination >> 1);

	for(int i = startIndex; i * i < denomination; i++)
	{
		ticks++;
		if(perfect_square(denomination - i * i))
		{
			solution[0] = i;
			solution[1] = sqrt(denomination - i * i);
			solutionSize = 2;
			solved = true;
		}
	}
}

/*
 * Writes a number as a sum of three squares.
 */
void Smart::solve_three_square()
{
	for(int i = sqrt(denomination / 3); i * i < denomination; i++)
	{
		ticks++;

		/* Reduce the value to solve by i^2 */
		Smart a(denomination - i * i);

		/* Try to solve it with two squares*/
		a.solve_two_square();

		/* If it has a two square solution, copy it over */
		if(a.get_size())
		{
			solution[0] = a[0];
			solution[1] = a[1];
			solution[2] = i;
			solutionSize = 3;
			solved = true;
			return;
		}
	}
}

void Smart::solve()
{
	int residue;

	/* The number is a perfect square */
	if(perfect_square(denomination))
	{
		solution[0] = sqrt(denomination);
		solutionSize = 1;
		ticks++;
	}

	/* The number must be written as a sum of four squares*/
	else if(four_square(denomination))
	{
		/* Reduce it*/
		residue = reduce_to_three_square(denomination);

		Smart a(denomination - residue * residue);

		solution[3] = residue;

		/* Solve the reduced solution */
		a.solve_three_square();

		/* Copy everything over */
		solution[0] = a[0];
		solution[1] = a[1];
		solution[2] = a[2];
		ticks += a.get_ticks();
		solutionSize = 4;
	}

	else
	{
		/* Check if it has a two square solution */
		solve_two_square();

		/* If it doesn't, solve for the three square solution */
		if(solutionSize == 0)
			solve_three_square();
	}
	solved = true;
	return;
}
