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

void read_file(vector<string>& cont); //Процедура чтения содержимого файла

void upd_file(vector<string>& cont, string net); //Процедура изменения содержимого файла

void write_file(vector<string> cont); //Процедура записи нового содержимого в файл

string execute(string cmd); 

string exec(const char* cmd);

void get_prob(string net, double& prob); //Получение log probability заданной сети