#ifndef BST_DISPLAY_H_
#define BST_DISPLAY_H_

/***************************************************************************/
/***************************** Display *************************************/
/***************************************************************************/

// 
template<class Type>
std::ostream & BST<Type>::print_order(Branch *node, std::ostream &os = std::cout) const
{
	if(!node) return os;

	print_order(node->left, os);

	os << node->value << ' ';

	print_order(node->right, os);

	return os;
}



template<class Type>
std::ostream & BST<Type>::print_order(std::ostream &os = std::cout) const
{
	return print_order(rt, os);	
}



template<class Type>
std::ostream & BST<Type>::prettyPrint(Branch *node, std::ostream &os, std::string linePrefix = "", std::string nodeTag = "< ") const
{
	if(!rt) return (os << "< ");

	if(!node) return os;

	else
	{
		// Housekeeping variables to prevent using string literals.
		std::string leftPrefix, rightPrefix, leftTag, rightTag;
		leftTag = " /";
		rightTag = " \\";

		leftPrefix = rightPrefix = linePrefix;

		// The last recursive call took us left.
		if(nodeTag == leftTag)
		{
			// So when going right we are going towards the inside of the
			// graph, therefore we add a vertical bar.
			rightPrefix += "| ";

			// And when going left we are going towards the outside
			// so we add two spaces.
			leftPrefix += "  ";
		}

		// The last recursive call took us right.
		else if(nodeTag == rightTag)
		{
			// So going left takes us inside.
			leftPrefix += "| ";

			// And going right takes us outside.
			rightPrefix += "  ";
		}

		// We are at the rt.
		else
			// So both directions take us outside.
			leftPrefix = rightPrefix = "  ";


		prettyPrint(node->left, os, leftPrefix, leftTag);
		os << linePrefix << nodeTag << node->value << std::endl;
		prettyPrint(node->right, os, rightPrefix, rightTag);
	}

	return os;
}



template<class Type>
std::ostream &operator<<(std::ostream &os, const BST<Type> &rhs)
{
	return rhs.prettyPrint(rhs.rt, os);
}


#endif	// BST_DISPLAY_H_