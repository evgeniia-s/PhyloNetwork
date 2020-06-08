#include "node.h"

node* copy_node(node* src)
{
	node* res = new node();

	for (int i = 0; i < src->p.size(); i++)
		res->p.push_back(src->p[i]);
	res->label = src->label;
	res->number = src->number;
	res->is_retic = src->is_retic;
	//res->num_retic = src->num_retic;

	return res;
}

node* copy_tree(node* src)
{
	node* res;
	if (src)
	{
		res = copy_node(src);
		if (res->p.size() != 0)
		{
			res->p[0] = copy_tree(src->p[0]);
			res->p[1] = copy_tree(src->p[1]);
		}
	}
	else
		return nullptr;

	return res;
}


