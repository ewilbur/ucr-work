//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<6>/IntList.cpp
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

/* ==================== Constructors & Destructors ==================== */
IntList::IntList()
{
	head = tail = NULL;
}

IntList::~IntList()
{
	IntNode *currNode = head;
	while(currNode)
	{
		IntNode *nxt = currNode->next;
		delete currNode;
		currNode = nxt;
	}
}

/* ================== End Constructors & Destructors ================== */

/* ==================== Accessors ==================== */

void IntList::display() const
{
	if(head != NULL)
	{
		for(IntNode *i = head; i != tail; i = i->next)
		{
			std::cout << i->data << ' ';
		}
		std::cout << tail->data;
	}
}

/* =================== End Accessors =================== */

/* ====================== Mutators ====================== */

void IntList::push_front(int value)
{
	IntNode *newNode = new IntNode(value);

	if(head != NULL)
	{
		newNode->next = head;
		head = newNode;
	}

	else
		tail = head = newNode;
}

void IntList::push_back(int value)
{
	

	if(head != NULL)
	{
		IntNode *newNode = new IntNode(value);
		IntNode *temp = tail;
		tail = newNode;
		temp->next = newNode;
	}

	else
		push_front(value);
	
}

void IntList::pop_front()
{
	if(head && head != tail)
	{
		IntNode *temp = head;
		head = head->next;
		delete temp;
	}
	else if(head == tail)
	{
		delete head;
		head = tail = NULL;
	}
}

void IntList::select_sort()
{
	
	for(IntNode *piv = head; piv; piv = piv->next)
	{
		IntNode *lowest = piv;

		for(IntNode *pt = piv; pt; pt = pt->next)
			if(pt->data < lowest->data)
				lowest = pt;

		swap(lowest, piv);
	}
}

void IntList::insert_sorted(int value)
{
	if(head)
	{
		if(value <= head->data)
			push_front(value);

		else if(value >= tail->data)
			push_back(value);

		else
		{
			IntNode *valueNode = new IntNode(value);
			IntNode *slider = head;

			while(slider->next->data < value)
				slider = slider->next;

			valueNode->next = slider->next;
			slider->next = valueNode;
		}
	}
	else
		push_front(value);
			
}

void IntList::remove_duplicates()
{
	IntNode *temp;
	IntNode *slider;
	for(IntNode *pivot = head; pivot != NULL; pivot = pivot->next)
	{
		slider = pivot;
		while(slider->next)
		{
			if(slider->next->data == pivot->data)
			{
				if(slider->next == tail)
					tail = slider;

				temp = slider->next->next;
				delete slider->next;
				slider->next = temp;
			}
			else
			{
				slider = slider->next;
			}
		}
	}
}

void IntList::swap(IntNode *n1 ,IntNode *n2)
{
	int temp = n2->data;
	n2->data = n1->data;
	n1->data = temp;
}

int IntList::sumNode(IntNode *n) const
{

	return (!n) ? 0 : n->data + sumNode(n->next);
}

int IntList::sum() const
{
	return sumNode(head);
}