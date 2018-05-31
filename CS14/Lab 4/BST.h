#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>



inline int max(int a, int b) { return (a > b) ?  a : b; }

template<class Type>
class BST;

template<class Type>
std::ostream& operator<<(std::ostream&, const BST<Type>&);

template<class Type>
class BST
{
	private:
		typedef struct Node
			{
				// Data //
				Type value;
				int height;
				Node *left;
				Node *right;
				Node *parent;

				// Accessors
				int deapth() const;
				int balance_factor() const;


				void repair_height();
				
				Node(Type val) : value(val), height(0), left(0),
								 right(0), parent(0) {};
			} Branch;

		// Data //
		Branch *rt;
		int sz;
		std::vector<Type> vals; // TODO: Remove entries from vals as deletions occur
								// TODO2: Get rid of this and use custom iterator implementation
								//        ... once I get off my lazy ass and design one.
		

		// Mutator Helpers //
		int insert(Type, Branch*);
		int remove(Branch*);
		void prune(Branch*);

		// Mutators //
		void copy(const Branch*);

		// Accessor Helpers //
		std::ostream & print_order(Branch*, std::ostream&) const;
		Branch* search(Type, Branch*) const;

		// Accessors //
		Branch* min(Branch*) const;
		const Branch* root() const;

		// AVL balancing methods //
		Branch* rotate_right(Branch*);
		Branch* rotate_left(Branch*);
		void balance(Branch*, bool);

		// MISC //
		int size(Branch*) const;


	public:
		// Constructors and Destructors //
		BST();
		BST(Type);
		~BST();
		BST(const BST&);

		BST & operator=(const BST &rhs)
		{
			this->clear();
			copy(rhs.root());
		};


		// Display functions //
		std::ostream & prettyPrint(Branch*, std::ostream&, std::string, std::string) const;
		friend std::ostream & operator<< <>(std::ostream&, const BST<Type>&);
		std::ostream & print_order(std::ostream&) const;

		// Accessors //
		bool search(Type) const;
		int size() const;
		int height() const;
		const std::vector<Type>& values() const; // TEMPORARY. Remove once iterator is functional

		// Mutators //
		void insert(Type);
		void remove(Type);
		void clear();
		void prune(Type);

		// Iterator (In development) //
		class Iter
		{
			private:
				Branch *currNode;
				Branch *prevNode;

			public:
				Iter() : currNode(0), prevNode(0) {};
		};
};


#include "node.h"
#include "bst_accessor.h"
#include "bst_display.h"
#include "bst_mutator.h"

/***************************************************************************/
/*********************** Constructor and Destructors ***********************/
/***************************************************************************/


template <class Type>
BST<Type>::BST()
: rt(0), sz(0)
{}



template<class Type>
BST<Type>::BST(Type val)
: rt(new Branch(val)), sz(1)
{}



template<class Type>
BST<Type>::~BST()
{
	if(!rt)
	{
		prune(rt);
		delete rt;
		rt = 0;
	}
}



template<class Type>
BST<Type>::BST(const BST<Type> &a)
: rt(0), sz(0)
{
	copy(a.root());
}


/***************************************************************************/
/***************************** Misc ****************************************/
/***************************************************************************/


template<class Type>
int BST<Type>::size(Branch *node) const
{
	if(!node) return 0;

	else return 1 + size(node->left) + size(node->right);
}



template<class Type>
void BST<Type>::copy(const Branch *node)
{
	if(!node) return;

	insert(node->value);

	copy(node->left);
	copy(node->right);
}


#endif	// BST_H_