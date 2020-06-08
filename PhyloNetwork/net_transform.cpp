#include "net_transform.h"

void nums_to_labels(node* r)
{
	if (r)
	{
		if (!r->is_retic)
			r->label = to_string(r->number);
		if (r->p.size() != 0)
		{
			nums_to_labels(r->p[0]);

			if (!r->is_retic)
				nums_to_labels(r->p[1]);
		}
	}
}

string net_to_string_recur(node* cur, int& num_retic)
{
	if (cur->p.empty())
		return cur->label;

	if (!cur->is_retic) 
	{
		bool has_retic_ascendant = cur->p[0]->is_retic || cur->p[1]->is_retic;
		if (has_retic_ascendant) 
		{
			int num_retics = (int)cur->p[0]->is_retic + (int)cur->p[1]->is_retic;

			if (num_retics == 2) 
			{
				bool is_0_main_retic = cur->p[0]->retic != nullptr;
				bool is_1_main_retic = cur->p[1]->retic != nullptr;
				node* ret0 = cur->p[0], *ret1 = cur->p[1];
				string ret0_lab = is_0_main_retic ? "," + ret0->label + ")" : ")" + ret0->label;
				string ret1_lab = is_1_main_retic ? "," + ret1->label + ")" : ")" + ret1->label;
				return "((" + net_to_string_recur(cur->p[0]->p[0], num_retic) + ret0_lab + "," + "(" + net_to_string_recur(cur->p[1]->p[0], num_retic) + ret1_lab + ")" + cur->label;
			}
			else 
			{
				int which_is_retic = cur->p[0]->is_retic ? 0 : 1;
				node* retic_node = cur->p[which_is_retic];
				string ret_label = retic_node->label;
				bool main_retic = retic_node->retic != nullptr;
				if (main_retic) 
				{
					return "(" + net_to_string_recur(cur->p[1 - which_is_retic], num_retic) + "," + "(" + net_to_string_recur(cur->p[which_is_retic]->p[0], num_retic) + "," + retic_node->label + ")" +
						")" + cur->label;
				}
				else 
				{
					return "(" + net_to_string_recur(cur->p[1 - which_is_retic], num_retic) + "," + "(" + net_to_string_recur(cur->p[which_is_retic]->p[0], num_retic) + ")" + retic_node->label +
						")" + cur->label;
				}
			}
		}
		else
			return "(" + net_to_string_recur(cur->p[0], num_retic) + "," + net_to_string_recur(cur->p[1], num_retic) +
			")" + cur->label;
	}
	else 
	{
		cout << "Unexpected case occurred! Retic nodes should not be processed by net_to_string_recur. Inspect this case to handle it properly" << endl;
		return "";
	}
}


string net_to_string(node* root) 
{
	int num_retic = 0;
	string s1 = net_to_string_recur(root->p[0], num_retic);
	string s2 = net_to_string_recur(root->p[1], num_retic);
	return "(" + s1 + "," + s2 + ");";
}