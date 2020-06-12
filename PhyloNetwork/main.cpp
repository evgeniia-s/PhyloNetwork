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
#include <ctime>

int main()
{
	srand(time(0));

	vector<string> s;
	int k = 1;
	bool pos_k = true;

	read_file(s, "D:\\res.txt");

	file_process(k, 0.000001, pos_k, s);

	write_file(s, "D:\\res.txt");

	cout << endl << "runtime = " << clock() / 1000.0 << endl; // גנולÿ נאבמעû ןנמדנאללû   

	system("pause");

	return 0;
}