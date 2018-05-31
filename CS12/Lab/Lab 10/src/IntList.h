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
	public:
		IntList();
		~IntList();
		void display() const;
		void push_front(int value);
		void pop_front();
		void displayReverse() const;
	
	private: // Helper function
		void displayReverse(IntNode *curr) const;
};
#endif  // INTLIST_H_
