
#include "IntList.h"
#include <iostream>

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


void IntList::displayReverse(IntNode *curr) const
{
	if(!curr) return;

	else if(!curr->next)
		cout << curr->data;

	else
	{
		displayReverse(curr->next);
		cout << " "  << curr->data;
	}
}

void IntList::displayReverse() const
{
	displayReverse(head);
}
