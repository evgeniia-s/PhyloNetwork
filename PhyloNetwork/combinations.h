#pragma once
#include <vector>
#include "node.h"
#include "floyd_warshall.h"

using namespace std;

//bool equal_vec(vector<int> left, vector<int> right); //�������� ��������� ���� ������� �����

void get_edges(node* tree, vector<vector<int>>& edg); //��������� ���� ���� ������

void get_pairs(vector<vector<int>> edg, int** d, vector<vector<vector<int>>>& prs); //����� ���� ���������� ��� ����������� ��� ����

bool next_set(int* a, int n, int m); //��������� ���������

vector<vector<int>> get_sets(int* a, int k, int n); //��������� ������� ���������
