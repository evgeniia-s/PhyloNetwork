#pragma once
#include <string>
#include <iostream>
#include "node.h"
#include "combinations.h"
#include "floyd_warshall.h"
#include "net_transform.h"

void nums_to_labels(node* t);

string net_to_string_recur(node* cur, int& num_retic);

string net_to_string(node* root);