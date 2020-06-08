#pragma once
#include "node.h"

void number_of_nodes(node* r, int& n); //���������� ���������� ����� � ������

node* get_to_node(node* r, int num); //���������� ���� �� ������

bool is_edge(node* r, int num); //�������� ������������� ����� ����� ���������

void floyd(node* r, int** d, int n); //�������� ������-��������

