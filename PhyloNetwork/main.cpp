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

int main()
{
	//node* tree = new node(vector<node*>(), vector<node*>(), "", 0, false);

	//node* tree_1 = new node(vector<node*>(), vector<node*>(), "", 1, false);
	//tree->p.push_back(tree_1);
	//node* tree_2 = new node(vector<node*>(), vector<node*>(), "", 2, false);
	//tree->p.push_back(tree_2);

	//node* tree_0 = new node(vector<node*>(), vector<node*>(), "", 1, false);
	//tree_0 = tree;

	//tree = tree->p[0];
	//node* tree_3 = new node(vector<node*>(), vector<node*>(), "", 3, false);
	//tree->p.push_back(tree_3);

	//tree = tree_1;
	//node* tree_6 = new node(vector<node*>(), vector<node*>(), "", 6, false);
	//tree->p.push_back(tree_6);

	//tree = tree_3; 
	//node* tree_4 = new node(vector<node*>(), vector<node*>(), "", 4, false);
	//tree->p.push_back(tree_4);

	//tree = tree_3; 
	//node* tree_7 = new node(vector<node*>(), vector<node*>(), "", 7, false);
	//tree->p.push_back(tree_7);

	//tree = tree_0->p[1];
	//node* tree_5 = new node(vector<node*>(), vector<node*>(), "", 5, false);
	//tree->p.push_back(tree_5);

	//tree = tree_0->p[1];
	//node* tree_8 = new node(vector<node*>(), vector<node*>(), "", 8, false);
	//tree->p.push_back(tree_8);


	//int n = 0;
	//number_of_nodes(tree_0, n);

	//int** d;
	//d = new int *[n];
	//for (int i = 0; i < n; i++)
	//	d[i] = new int[n];

	//floyd(tree_0, d, n);

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		cout << d[i][j] << "   ";
	//	cout << endl;
	//}
	//
	//vector<vector<int>> e;

	//get_edges(tree_0, e);

	//vector<vector<vector<int>>> p;

	//get_pairs(e, d, p);

	//cout << endl << "Possible pairs:" << endl;

	//for (int i = 0; i < p.size(); i++)
	//{
	//	cout << i + 1 << ':' << "  " << p[i][0][0] << "  " << p[i][0][1] << " ; " << p[i][1][0] << "  " << p[i][1][1] << endl;
	//}


	//vector<string> nets;
	//vector<string> k_nets;
	//nums_to_labels(tree_0);

	//double prb = 0;

	//vector<int> rtcs;

	//cout << endl << "k reticulations: " << endl;

	//add_k_retic(tree_0, p, 1, prb, rtcs);

	/*cout << endl << "k reticulations + 1: " << endl;

	add_retic_to_net(tree_0, p, 2, prb, rtcs);

	cout << endl << "k + 1 reticulations: " << endl;

	add_k_retic(tree_0, p, 2, prb, rtcs);*/

	file_process(1);

	system("pause");

	return 0;
}