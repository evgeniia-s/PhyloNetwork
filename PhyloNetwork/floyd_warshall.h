#pragma once
#include "node.h"

void number_of_nodes(node* r, int& n); //Нахождение количества узлов в дереве

node* get_to_node(node* r, int num); //Нахождение узла по номеру

bool is_edge(node* r, int num); //Проверка существования ребра между вершинами

void floyd(node* r, int** d, int n); //Алгоритм Флойда-Уоршелла

