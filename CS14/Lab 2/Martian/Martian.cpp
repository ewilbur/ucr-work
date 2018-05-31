/*
 ******************************************************************************
 Evan Wilbur
 CS14 UCR Winter 2016
 January 2016
 Assignment 2
 Lab Section 21
 ******************************************************************************
 */

#include "Martian.h"


std::vector<Martian*> Martian::table;

Martian::Martian()
: denomination(0),
  ticks(0),
  solutionSize(0),
  solved(false)
{

	while(table.size() < denomination + 1)
		table.push_back(0);

	solution = new unsigned[4];

	for(int i = 0; i < 4; i++)
		solution[i] = 0;
}

Martian::Martian(unsigned val)
: denomination(val),
  ticks(0),
  solutionSize(0),
  solved(false)
{
	while(table.size() < denomination + 1)
		table.push_back(0);

	solution = new unsigned[4];

	for(int i = 0; i < 4; i++)
		solution[i] = 0;
}

Martian::~Martian()
{
	delete[] solution;
}

unsigned & Martian::operator[](const int index)
{
	return solution[index];
}

const unsigned & Martian::operator[](const int index) const
{
	return solution[index];
}

Martian & Martian::operator=(const Martian &rhs)
{
	this->solutionSize = rhs.get_size();
	this->ticks = rhs.get_ticks();
	this->denomination = rhs.get_denomination();
	this->solved = rhs.is_solved();

	for(int i = 0; i < 4; i++)
		solution[i] = rhs[i];
}

std::ostream &operator<<(std::ostream &os, const Martian &mars)
{
	for(int i = 0; i < 4; i++)
		os << mars.solution[i] << ' ';

	/*std::vector<unsigned> v;

	for(int i = 0; i < 4; i++)
	{
		while(v.size() <= mars.solution[i])
			v.push_back(0);

		v.at(mars.solution[i])++;
	}

	for(int i = 1; i < v.size(); i++)
	{
		os << v.at(i);
		if(v.size() - i != 1)
			os << ", ";
	}*/

	return os;
}

void Martian::set_size(int val)
{
	solutionSize = val;
}

void Martian::set_ticks(int val)
{
	ticks = val;
}

const unsigned Martian::get_denomination() const
{
	return denomination;
}

const unsigned Martian::get_ticks() const
{
	return ticks;
}

const unsigned Martian::get_size() const
{
	return solutionSize;
}

const bool Martian::is_solved() const
{
	return solved;
}

void Martian::print_table() const
{
	for(int i = 0; i < table.size(); i++)
	{
		if(table.at(i))
		{
			std::cout << i << '\t' << *table.at(i);
			std::cout << std::endl;
		}
	}
}