#ifndef BST_MUTATOR_H_
#define BST_MUTATOR_H_

/***************************************************************************/
/************************** Mutators ***************************************/
/***************************************************************************/


/************************** Insert *****************************************/

template<class Type>
int BST<Type>::insert(Type val, Branch *node)
{
	// The value should be placed in the left subtree
	if(val < node->value)
	{
		// The left subtree is empty
		if(!node->left)
		{
			// Place the value there
			node->left = new Branch(val);

			// Fix the node height
			node->repair_height();

			// And give the poor child a parent
			node->left->parent = node;

			vals.push_back(val);

			return 1;
		}

		// Able to insert in left subtree
		else if(insert(val, node->left))
		{
			balance(node, false);

			// Insertion successful
			return 1;
		}

		else return 0;
	}

	// Insert value into the right subtree
	else if(val > node->value)
	{
		// The node has no left child
		if(!node->right)
		{
			// Congrats, node, you now adopted a healthy node
			node->right = new Branch(val);

			// So you better fix that family size of yours
			node->repair_height();

			// And make sure your new child knows who its parent is
			node->right->parent = node;


			vals.push_back(val);

			return 1;
		}
		// The first node didn't want you, but we found you a home
		// in the right subtree!
		else if(insert(val, node->right))
		{
			balance(node, false); 

			// Time to tell your family about your new adoption
			return 1;
		}

		else return 0;
	}

	// Nobody wants twins!
	else return 0;
}



template<class Type>
void BST<Type>::insert(Type val)
{
	if(!rt)
	{
		rt = new Branch(val);
		++sz;
		vals.push_back(val);
	}

	else 
		if(insert(val, rt))
			++sz;
}



/**************************** Rotations ************************************/


template<class Type>
typename BST<Type>::Branch* BST<Type>::rotate_right(Branch *node)
{
	// Can't rotate a NULL node or if it has a NULL left child
	if(!node || !node->left) return node;

	// Set the pivot
	Branch *pivot = node->left;

	// The node has no parent (ie it's the rt)
	if(!node->parent)
		rt = pivot;

	// The node is its parent's left child
	else if(node->parent->left == node)
		// So adjust its left child
		node->parent->left = pivot;

	// Node is a right child
	else
		// Adjust the right child of node parent
		node->parent->right = pivot;

	// The pivot has a right child
	if(pivot->right)
		// And that right child is now the node
		pivot->right->parent = node;

	// Fix the parents
	pivot->parent = node->parent;
	node->parent = pivot;

	// Fix the node and pivots children
	node->left = pivot->right;
	pivot->right = node;

	// Fix the height
	node->repair_height();
	
	return pivot;
}



template<class Type>
typename BST<Type>::Branch* BST<Type>::rotate_left(Branch *node)
{
	if(!node || !node->right) return node;

	Branch *pivot = node->right;

	if(!node->parent)
		rt = pivot;

	else if(node->parent->left == node)
		node->parent->left = pivot;

	else
		node->parent->right = pivot;



	if(pivot->left)
		pivot->left->parent = node;

	pivot->parent = node->parent;
	node->parent = pivot;


	node->right = pivot->left;
	pivot->left = node;


	node->repair_height();

	return pivot;
}



template<class Type>
void BST<Type>::balance(Branch *node, bool recurse = true)
{
	if(!node) return;
	Branch *temp = node;
	// Left case
	if(node->balance_factor() == 2)
	{
		// left right
		if(node->left->balance_factor() == -1)
			rotate_left(node->left);

		// now in left-left
		temp = rotate_right(node);

	}

	// Right case
	else if(node->balance_factor() == -2)
	{
		if(node->right->balance_factor() == 1)
			rotate_right(node->right);

		temp = rotate_left(node);
	}

	// If asked, recurse upwards thru tree until root
	if(recurse) balance(temp->parent);
}



/************************** Deletions **************************************/


// Removes the children of a passed node
template<class Type>
void BST<Type>::prune(Branch *node)
{
	if(!node) return;

	else
	{
		prune(node->right);
		prune(node->left);

		sz -= (size(node) - 1);

		delete node->right;
		delete node->left;
		node->right = node->left = 0;

		node->repair_height();
		balance(node);
	}
}



// Removes children of a passed value
template<class Type>
void BST<Type>::prune(Type val)
{
	prune(search(val, rt));
}



// DELETE EVERYTHING!!!!!!!!
template<class Type>
void BST<Type>::clear()
{
	prune(rt);
	delete rt;
	rt = 0;
	sz = 0;
}



// Remove node
template<class Type>
int BST<Type>::remove(Branch *node)
{
	// Don't remove a node stupid!
	if(!node) return 0;

	// The node has no children
	if(!node->right && !node->left)
	{
		// The node is a root
		if(!node->parent || node == rt)
		{
			// Delete it and reset the rt
			delete node;
			node = 0;
			rt = 0;
			return 1;
		}

		else
		{
			// Delete the node like you would usually, repair height, rebalance tree
			Branch *prnt = node->parent;

			if(prnt->left == node)
				prnt->left = 0;

			else
				prnt->right = 0;

			delete node;
			node = 0;
			prnt->repair_height();
			balance(prnt);

			return 1;
		}
	}

	// If it's missing a child
	else if(!node->right || !node->left)
	{
		// Do stuff
		// honestly forgot what i did, and it's late, and im tired
		Branch *prnt = node->parent;
		if(!prnt)
		{
			rt = (node->left) ? node->left : node->right;
			rt->parent = 0;

			delete node;
			node = 0;
			return 1;
		}

		if(prnt->left == node) prnt->left = node->left;
		else prnt->right = node->left;

		if(node->left) node->left->parent = prnt;
		else node->right->parent = prnt;

		delete node;
		node = 0;

		prnt->repair_height();

		balance(prnt);
		return 1;
	}

	else
	{
		Branch *minRightSubtree = min(node->right);

		node->value = minRightSubtree->value;

		return remove(minRightSubtree);
	}
}



template<class Type>
void BST<Type>::remove(Type val)
{
	if(remove(search(val, rt)))
		--sz;
}

#endif	// BST_MUTATOR_H_
