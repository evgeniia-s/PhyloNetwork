#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iterator>
#include "node.h"
#include "floyd_warshall.h"
#include "combinations.h"
#include "reticulations.h"
#include "net_transform.h"
#include "net_files.h"
#include "tree_transform.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Input file not specialized" << endl;
		return -1;
	}

	vector<string> s;
	string trees = string(argv[1]);

	int k = 1;
	bool pos_k = true;

	read_file(s, string(argv[2]));

	file_process(k, 0.000001, pos_k, s, trees);

	write_file(s, string(argv[2]));

	system("pause");

	return 0;
}