//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<6>/IntList.h
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
#ifndef INTLIST_H_
#define INTLIST_H_

#include <cstdlib>

using namespace std;

struct IntNode
	{
	    int data;
	    IntNode *next;
	    IntNode( int data ) : data(data), next(NULL) {}
	};

class IntList
{
	
	private:
		IntNode *head;
		IntNode *tail;
		void swap(IntNode*, IntNode*);
		void insert_after(IntNode*, IntNode*);

	public:
		IntList();
		~IntList();
		void display() const;
		void push_front(int value);
		void push_back(int value);
		void pop_front();
		void select_sort();
		void insert_sorted(int value);
		void remove_duplicates();

		/* for final */
		int sum() const;
		int sumNode(IntNode*) const;
};
#endif  // INTLIST_H_
