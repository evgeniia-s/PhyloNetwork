#pragma once
#include <string>
#include "node.h"

node* string_to_tree(string src); //Перевод строки в дерево

node* string_to_tree_recur(string src, int& num);  