//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<5>/main.cpp
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

#include "IntVector.h"

int main()
{
	IntVector a(100);
	int x = a.at(0);
	std::cout << "a.at(0) = " << a.at(0) << std::endl;
	std::cout << "x = " << x << std::endl;
	a.at(0) = 2;
	std::cout << "a.at(0) = " << a.at(0) << std::endl;
	std::cout << "x = " << x << std::endl;

	x = 5;
	std::cout << "a.at(0) = " << a.at(0) << std::endl;
	std::cout << "x = " << x << std::endl;


}
