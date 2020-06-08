#pragma once
#include <string>
#include <iostream>
#include "node.h"
#include "combinations.h"
#include "floyd_warshall.h"
#include "net_transform.h"

void nums_to_labels(node* t); //«апись номеров вершин в их названи€ (дл€ отладки)

string net_to_string_recur(node* cur, int& num_retic); //ѕеревод филогенетической сети в строку

string net_to_string(node* root);