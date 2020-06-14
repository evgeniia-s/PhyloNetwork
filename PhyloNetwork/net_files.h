#pragma once
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <fstream>
#include <iostream>
#include "node.h"
#include "tree_transform.h"
#include "floyd_warshall.h"
#include "combinations.h"
#include "reticulations.h"
#include "net_transform.h"

void read_file(vector<string>& cont, string file_name); //Процедура чтения содержимого файла

void upd_file(vector<string>& cont, string net, string tree); //Процедура изменения содержимого файла

void write_file(vector<string> cont, string file_name); //Процедура записи нового содержимого в файл

string exec(const char* cmd); //Вызов команды из командной строки и перехват результата в строку

void get_prob(string net, string tree, double& prob); //Получение log probability заданной сети

void file_process(int k, double eps, bool& pos_k, vector<string>& cont, string input); //Конвейер всего алгоритма