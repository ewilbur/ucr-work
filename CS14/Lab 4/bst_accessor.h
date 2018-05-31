#ifndef BST_ACCESSOR_H_
#define BST_ACCESSOR_H_


/***************************************************************************/
/****************************** Accessors **********************************/
/***************************************************************************/


template<class Type>
typename BST<Type>::Branch* BST<Type>::search(Type v, BST<Type>::Branch *node) const
{
	if(!node) return 0;

	else if(node->value == v) return node;

	else if(node->value < v) return search(v, node->right);

	else return search(v, node->left);
}



template<class Type>
bool BST<Type>::search(Type val) const
{
	return search(val, rt) != 0;
}



template<class Type>
typename BST<Type>::Branch* BST<Type>::min(BST<Type>::Branch *node) const
{
	if(node->left)
		return min(node->left);

	return node;
}



template<class Type>
int BST<Type>::size() const
{
	return sz;
}



template<class Type>
int BST<Type>::height() const
{
	return rt->height;
}



template<class Type>
const typename BST<Type>::Branch* BST<Type>::root() const
{
	return rt;
}



template<class Type>
const std::vector<Type>& BST<Type>::values() const
{
	return vals;
}


#endif	// BST_ACCESSOR_H_