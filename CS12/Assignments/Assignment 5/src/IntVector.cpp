//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<5>/IntVector.cpp
/// @brief Assignment <5> for CS 12 <Fall 2015>
///
/// @author <Evan Wilbur> [ewilb001@ucr.edu]
/// @date <11/6/2015>
///
/// @par Enrollment Notes
///	 Lecture Section: <21>
/// @par
///	 Lab Section: <1>
/// @par
///	 TA: <Entezari>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


#include <iostream>

#include <cstdlib>
#include "IntVector.h"

inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* ----- Constructors and Destructors ----- */
IntVector::IntVector()
: sz(0),
  cap(0),
  data(NULL)
{}

IntVector::IntVector(unsigned size)
: sz(size),
  cap(size),
  data(new int[size])
{
	for(unsigned i = 0; i < size; ++i)
		data[i] = 0;
}

IntVector::IntVector(unsigned size, int value)
: sz(size),
  cap(size),
  data(new int[size])
{
	for(unsigned i = 0; i < size; ++i)
		data[i] = value;
}

IntVector::~IntVector()
{
	delete[] data;
}




unsigned IntVector::size() const
{
	return sz;
}

unsigned IntVector::capacity() const
{
	return cap;
}

bool IntVector::empty() const
{
	return (sz == 0) ? true : false;
}

const int& IntVector::at(unsigned index) const
{
	if(index >= sz)
		exit(1);

	else
	{
		return data[index];
	}
}

int & IntVector::at(unsigned index)
{
	if(index >= sz)
		exit(1);

	else
	{
		return data[index];
	}
}




const int & IntVector::front() const
{
	if(sz == 0)
		exit(1);

	return data[0];
}

const int & IntVector::back() const
{
	if(sz == 0)
		exit(1);

	return data[(sz - 1)];
}

void IntVector::expand()
{
	if(cap == 0)
		expand(1);
	else
		expand(cap);
}

void IntVector::expand(unsigned amount)
{
	int *temp = new int[cap + amount]; 
	
	for(unsigned i = 0; i < size(); i++)
		temp[i] = data[i];
	
	delete[] data;
	data = temp;
	cap += amount;

}

void IntVector::insert(unsigned index, int value)
{
	if(index > sz)
		exit(1);

	else if(sz >= cap)
		expand();

	if(index == (sz - 1))
		push_back(value);

	else
	{
		++sz;
		for(unsigned i = sz; i > index; i--)
			data[i] = data[i - 1];

		data[index] = value;
	}
}
		

void IntVector::erase(unsigned index)
{
	

	if(index < (sz - 1))
	{
		for(unsigned i = index; i < sz; i++)
			data[i] = data[i + 1];
		--sz;
	}

	else if(index == (sz - 1))
		--sz;

	else
		exit(0);
}

void IntVector::push_back(int value)
{
	if(size() >= capacity())
		expand();
	
	sz++;

	data[size() - 1] = value;

}

void IntVector::pop_back()
{
	if(empty())
		exit(1);
	sz--;
}

void IntVector::clear()
{
	sz = 0;
}

void IntVector::resize(unsigned size)
{
	resize(size, 0);
}

void IntVector::resize(unsigned size, int value)
{
	reserve(size);
	if(size > sz)
		for(unsigned i = sz; i < size; i++)
			data[i] = value;
	sz = size;
}

void IntVector::reserve(unsigned n)
{
	if(n > cap)
		expand(max(n - cap, cap));
}

void IntVector::assign(unsigned n, int value)
{
	reserve(sz = n);
	for(unsigned i = 0; i < sz; i++)
		data[i] = value;
}

int & IntVector::front()
{
	return *data;
}

int & IntVector::back()
{
	return data[sz - 1];
}

/*
void IntVector::display() const
{
	std::cout << "data pt: "     << data       << std::endl;
	std::cout << "size() = "     << size()     << std::endl;
	std::cout << "capacity() = " << capacity() << std::endl;
	std::cout << "empty() = "    << empty()    << std::endl;


	if(!empty())
	{
		std::cout << "front() = " << front() << std::endl;
		std::cout << "back() = "  << back()  << std::endl;
		std::cout << std::endl;

		for(unsigned i = 0; i < sz; i++)
		{
			if(i % 10 == 0)
				std::cout << std::endl;
			
			std::cout << data[i] << " ";
		}
		std::cout << std::endl << std::endl; 
	}

}

void IntVector::fill()
{
	for(unsigned i = 0; i < sz; i++)
	{
		data[i] = rand() % 100;
	}
}
*/