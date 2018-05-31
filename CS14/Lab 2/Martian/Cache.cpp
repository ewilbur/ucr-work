/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */

#include "Cache.h"


Cache::Cache()
: Smart(0)
{}

Cache::Cache(unsigned val)
: Smart(val)
{}

void Cache::solve()
{
	int residue;

	if(perfect_square(denomination))
	{
		solution[0] = sqrt(denomination);
		ticks++;
		solutionSize = 1;
	}

	else if(four_square(denomination))
	{
		residue = reduce_to_three_square(denomination);

		Cache a(denomination - residue * residue);
		solution[3] = residue;

		a.solve_three_square();

		solution[0] = a[0];
		solution[1] = a[1];
		solution[2] = a[2];
		ticks += a.get_ticks();
		solutionSize = 4;
	}

	else
	{
		solve_two_square();

		if(solutionSize == 0)
			solve_three_square();

	}
	solved = true;
	update_table();
	return;

}

void Cache::solve_two_square()
{
	if(table.at(denomination) != 0)
	{
		Martian *a = table.at(denomination);

		solution[0] = (*a)[0];
		solution[1] = (*a)[1];
		solutionSize = 2;
		solved = true;
	}

	else
	{
		unsigned pos = 0;
		for(int i = sqrt(denomination >> 1); i * i < denomination; i++)
		{
			pos = denomination - i * i;
			if(table.at(pos) != NULL && table.at(pos)->get_size() == 1)
			{
				solution[0] = (*table.at(pos))[0];
				solution[1] = i;
				solutionSize = 2;
				solved = true;
				break;
			}
		}

		if(!solutionSize)
			Smart::solve_two_square();
	}

	update_table();
}

void Cache::solve_three_square()
{
	if(table.at(denomination) != 0)
	{
		Martian *a = table.at(denomination);

		solution[0] = (*a)[0];
		solution[1] = (*a)[1];
		solution[2] = (*a)[2];
		solutionSize = 3;
		solved = true;
	}

	else
	{
		unsigned pos = 0;
		for(int i = sqrt(denomination / 3); i * i < denomination; i++)
		{
			pos = denomination - i * i;
			if(table.at(pos) != NULL && table.at(pos)->get_size() == 2)
			{
				solution[0] = (*table.at(pos))[0];
				solution[1] = (*table.at(pos))[1];
				solution[2] = i;
				solved = true;
				solutionSize = 3;
				update_table();
				return;
			}
		}

		for(int i = sqrt(denomination / 3); i * i < denomination; i++)
		{
			ticks++;
			Cache a(denomination - i * i);
			a.solve_two_square();
			if(a.get_size())
			{
				solution[0] = a[0];
				solution[1] = a[1];
				solution[2] = i;
				solutionSize = 3;
				solved = true;
				update_table();
				return;
			}
		}
	}
}

void Cache::update_table()
{
	if(table.at(denomination) || solutionSize == 0)
		return;

	else
	{
		Martian *a = new Cache(denomination);
		*a = *this;
		table.at(denomination) = a;
	}
}