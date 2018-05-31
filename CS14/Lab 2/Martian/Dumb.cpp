/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */

#include "Dumb.h"


Dumb::Dumb(unsigned val)
:Martian(val)
{}


/*
 * This is an incredibly stupid solution that will potentially crash your
 * computer, you have been warned.
 */
void Dumb::solve()
{
	int i = 0;

	while(i * i < denomination)
		i++;

	if(denomination < 4)
	{
		for(int j = 0; j < denomination; j++)
			solution[j] = 1;

		solutionSize = denomination;

		ticks = 1;
	}

	else if(i * i == denomination)
	{
		solution[0] = i;
		solutionSize = 1;
		ticks = 1;
	}

	else
	{
		for(; i > 0; i--)
		{
			for(int j = 1; j * i * i < denomination; j++)
			{
				unsigned newVal = denomination - (j * i * i);
				ticks++;
				Dumb reduce(newVal);
				reduce.solve();
				ticks += reduce.get_ticks();

				if((solutionSize == 0 && (j + reduce.get_size()) < 5) || j + reduce.get_size() < solutionSize)
				{
					for(int n = 0; n < 4; n++)
						solution[n] = 0;

					solutionSize = j + reduce.get_size();
					int k = 0;
					for(; k < j; k++)
						solution[k] = i;

					for(int n = 0; reduce[n] != 0; n++, k++)
					{
						solution[k] = reduce[n];
					}
				}
			}
		}
	}
}

