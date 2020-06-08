#pragma once
#include <string>
#include "node.h"
#include "combinations.h"
#include "floyd_warshall.h"
#include "net_transform.h"
#include "net_files.h"

void add_retic(node* tree, vector<int> edg_1, vector<int> edg_2, int num_ret); //��������� ������������� ���������� ���������������� �����

bool check_pairs(vector<vector<vector<int>>> prs, vector<int> nums); //�������� ����������� ������ ��� ���� �� ������������ ��� ������������� �����������

vector<vector<int>> get_retic_sets(vector<vector<vector<int>>> prs, vector<vector<int>> sets); //��������� ������� �� k ��� ����, ���������� ��� �����������

void add_k_retic(node* tree, vector<vector<vector<int>>> prs, int k, double& prob, vector<int>& rtcs); //��������� ���������� k ����������� � ������

void add_retic_to_net(node* tree, vector<vector<vector<int>>> prs, int k, double& prob, vector<int>& rtcs);