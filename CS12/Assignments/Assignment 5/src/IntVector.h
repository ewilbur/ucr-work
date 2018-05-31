//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<5>/IntVector.h
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

#ifndef INTVECOR_H_
#define INTVECTOR_H_

#include <iostream>

using namespace std;

class IntVector
{
	private:
		unsigned sz, cap;
		int *data;
	public:
		void expand();
		void expand(unsigned);

	public:
		IntVector();
		IntVector(unsigned size);
		IntVector(unsigned size, int value);
		~IntVector();

		unsigned size() const;
		unsigned capacity() const;
		bool empty() const;
		const int & at(unsigned index) const;
		int & at(unsigned index);
		void insert(unsigned index, int value);
		void erase(unsigned index);
		const int &front() const;
		int & front();
		const int & back() const;
		int & back();
		void assign(unsigned n, int value);
		void push_back(int value);
		void pop_back();
		void clear();
		void resize(unsigned size);
		void resize(unsigned size, int value);
		void reserve(unsigned n);

		
		//void display() const;
		//void fill();
};

#endif //  INTVECTOR_H_