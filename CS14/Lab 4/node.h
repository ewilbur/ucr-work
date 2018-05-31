#ifndef NODE_H_
#define NODE_H_

/***************************************************************************/
/************************* Branch Methods **********************************/
/***************************************************************************/

// Returns the height of the node
template<class Type>
int BST<Type>::Branch::deapth() const
{
	if(this == 0) return -1;
	int leftHeight = (!left) ? -1 : left->height;
	int rightHeight = (!right) ? -1 : right->height;
	return 1 + max(leftHeight, rightHeight); 
}


// Fixes the height of node and the parents
template<class Type>
void BST<Type>::Branch::repair_height()
{
	if(!this) return;

	else
	{
		this->height = this->deapth();
		this->parent->repair_height();
	}
}


// Returns the balance factor of the node
template<class Type>
int BST<Type>::Branch::balance_factor() const
{
	return (this->left->deapth() - this->right->deapth());
}

#endif	// NODE_H_