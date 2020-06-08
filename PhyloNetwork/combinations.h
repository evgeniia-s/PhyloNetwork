#pragma once
#include <vector>
#include "node.h"
#include "floyd_warshall.h"

using namespace std;

void get_edges(node* tree, vector<vector<int>>& edg); //Генерация всех рёбер дерева

void get_pairs(vector<vector<int>> edg, int** d, vector<vector<vector<int>>>& prs); //Выбор всех допустимых для ретикуляции пар рёбер

bool next_set(int* a, int n, int m); //Генерация сочетаний

vector<vector<int>> get_sets(int* a, int k, int n); //Получение наборов сочетаний 

