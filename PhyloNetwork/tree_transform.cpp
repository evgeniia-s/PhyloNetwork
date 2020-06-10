#include "tree_transform.h"
#include <stack>


using std::stack;


// functin to return the index of close parenthesis
int find_matching_parenthesis(string str, int si, int ei)
{
	if (si > ei)
		return -1;

	// Inbuilt stack
	stack<char> s;

	for (int i = si; i <= ei; i++) {

		// if open parenthesis, push it
		if (str[i] == '(')
			s.push(str[i]);

		// if close parenthesis
		else if (str[i] == ')') {
			if (s.top() == '(') {
				s.pop();

				// if stack is empty, this is
				// the required index
				if (s.empty())
					return i;
			}
		}
	}
	// if not found return -1
	return -1;
}


node* string_to_tree(string src)
{
    src = remove_odd_node(src);

	node* root = new node();
	root->label = "root";
	root->number = 0;

	node* left, *right;

	int num = 1;
	size_t left_side_comma = 0;
	size_t next_open = src.find(string("("), 1);
	size_t first_comma = src.find(string(","), 1);
	if (next_open < first_comma)
	{
		int closing = find_matching_parenthesis(src, 1, src.length());
		left_side_comma = src.find(string(","), closing);
		left = string_to_tree_recur(src.substr(1, left_side_comma - 1), num);
	}
	else
	{
		left = new node();
		left_side_comma = src.find(string(","));
		left->label = src.substr(1, left_side_comma - 1);
		left->number = num++;
	}

	string right_substr = src.substr(left_side_comma + 1, src.length() - left_side_comma - 1);
	next_open = right_substr.find(string("("));
	if (!next_open)
	{
		// int closing = find_matching_parenthesis(right_substr, 0, src.length());
		// size_t closing_parenthesis = right_substr.find(string(","), closing);
		right = string_to_tree_recur(right_substr.substr(0, right_substr.length() - 2), num);
	}
	else
	{
		right = new node();
		right->label = right_substr.substr(0, right_substr.length() - 2);
		right->number = num++;
	}

	root->p.push_back(left);
	root->p.push_back(right);

	return root;
}


node* string_to_tree_recur(string src, int& num)
{
	node* cur = new node();
	cur->number = num++;

	size_t first_opening = src.find(string("("));
	if (first_opening)
	{
		cur->label = src;
		return cur;
	}
	int closing = find_matching_parenthesis(src, 0, src.length());
	cur->label = src.substr(closing + 1, src.length() - closing - 1);

	size_t left_opening = src.find(string("("), 1);
	node* left;
	size_t left_side_comma;
	if (left_opening == 1)
	{
		int left_closing = find_matching_parenthesis(src, left_opening, src.length());
		left_side_comma = src.find(string(","), left_closing);
		left = string_to_tree_recur(src.substr(1, left_side_comma - 1), num);
	}
	else
	{
		left = new node();
		left_side_comma = src.find(string(","));
		left->label = src.substr(1, left_side_comma - 1);
		left->number = num++;
	}

	node* right;
	string right_substr = src.substr(left_side_comma + 1, closing - left_side_comma - 1);
	size_t next_open = right_substr.find(string("("));
	if (!next_open)
		right = string_to_tree_recur(right_substr, num);
	else
	{
		right = new node();
		right->label = right_substr;
		right->number = num++;
	}

	cur->p.push_back(left);
	cur->p.push_back(right);

	return cur;
}


string remove_odd_node(string src)
{
	size_t first_comma = src.find(string(","));
	size_t second_comma = src.find(string(","), first_comma + 1);

	string first_anc = src.substr(1, first_comma - 1);
	string second_anc = src.substr(first_comma + 1, second_comma - first_comma - 1);

	size_t semicolon1 = first_anc.find(string(":"));
	double val1 = stod(first_anc.substr(semicolon1 + 1, 8));

	size_t semicolon2 = second_anc.find(string(":"));
	double val2 = stod(second_anc.substr(semicolon2 + 1, 8));

	// ???????? ?????? ??? ????????
	val1 = 10000000;

	if (val1 > val2)
		src.replace(semicolon2 + 1, second_comma - first_comma - 1, string(""));
	else
		src.replace(semicolon1 + 1, first_comma - 1, string(""));

	return src;
}
