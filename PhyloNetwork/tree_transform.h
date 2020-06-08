#pragma once
#include <string>
#include "node.h"

node* string_to_tree(string src);

node* string_to_tree_recur(string src, int& num);

string remove_odd_node(string src);