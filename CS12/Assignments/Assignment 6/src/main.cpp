//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<6>/main.cpp
/// @brief Assignment <6> for CS 12 <Fall 2015>
///
/// @author <Evan Wilbur> [ewilb001@ucr.edu]
/// @date <11/17/2015>
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

#include "IntList.h"
#include <iostream>
#include <cmath>

int main()
{
	IntList a;
	for(int i = 0; i < 100; i++)
		a.push_back(2);

	a.display();
	cout << "\n\n";
	cout << a.sum();


}

