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

void read_file(vector<string>& cont); //��������� ������ ����������� �����

void upd_file(vector<string>& cont, string net); //��������� ��������� ����������� �����

void write_file(vector<string> cont); //��������� ������ ������ ����������� � ����

string execute(string cmd); 

string exec(const char* cmd);

void get_prob(string net, double& prob); //��������� log probability �������� ����