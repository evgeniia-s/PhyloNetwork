#include "net_files.h"

void read_file(vector<string>& cont, string file_name)
{
	ifstream fin(file_name);

	string line;

	while (getline(fin, line) && !fin.eof())
		cont.push_back(line);

	cont.push_back(line);

	fin.close();
}

void upd_file(vector<string>& cont, string net, string tree)
{
	for (int i = 0; i < cont.size(); i++)
	{
		size_t net_found = cont[i].find("Network net = ");
		if (net_found != -1)
		{
			string old = cont[i].substr(net_found + 14);
			cont[i].replace(cont[i].find(old), old.length(), net);
		}

		size_t tree_found = cont[i].find("geneTree1 = ");
		if (tree_found != -1)
		{
			string old_tree = cont[i].substr(tree_found + 12);
			cont[i].replace(cont[i].find(old_tree), old_tree.length(), tree);
		}
	}
}

void write_file(vector<string> cont, string file_name)
{
	ofstream fout(file_name);

	int i = 0;

	while (!fout.eof() && i < cont.size())
	{
		fout << cont[i] << endl;
		i++;
	}

	fout.close();
}

string execute(string cmd)
{
	string file_name = "result.txt";
	system((cmd + " > " + file_name).c_str()); // redirect output to file

													// open file for input, return string containing characters in the file
	ifstream file(file_name);
	return { istreambuf_iterator<char>(file), istreambuf_iterator<char>() };
}

string exec(const char* cmd) {
	array<char, 128> buffer;
	string result;
	unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

void get_prob(string net, string tree,  double& prob)
{
	vector<string> lines;

	read_file(lines, "D:\\nets.nex");
	upd_file(lines, net, tree);
	write_file(lines, "D:\\nets.nex");

	string tmp = exec("java -jar D:\\PhyloNet\\PhyloNet_3.8.0.jar D:\\nets.nex");

	size_t found = tmp.find("probability: ");
	if (found != -1)
	{
		string p = tmp.substr(found + 13, 12);
		prob = stod(p);
	}
}

void file_process(int k, double eps, bool& pos_k, vector<string>& cont)
{
	ifstream fin("D:\\trees.txt");

	node* tree;
	string line;
	string tmp; 
	string vec;
	int i = 1;
	int n = 0;
	double p_1 = 0; double p_2 = 0;

	// && !fin.eof())

	while (getline(fin, line))
	{
		tmp = line.substr(0, line.find('\t'));
		vec = to_string(i) + ": " + tmp + '\n';
		cont.push_back(vec);
		vec.clear();
		tmp = line.substr(line.find('('));

		tree = string_to_tree(tmp);
		number_of_nodes(tree, n);
		vec = "Number of nodes: " + to_string(n) + '\n';
		cont.push_back(vec);
		vec.clear();

		int** d;
		d = new int *[n];
		for (int i = 0; i < n; i++)
			d[i] = new int[n];

		floyd(tree, d, n);

		//nums_to_labels(tree);

		cout << net_to_string(tree);

		vector<vector<int>> e;

		get_edges(tree, e);

		vector<vector<vector<int>>> p;

		get_pairs(e, d, p);

		vector<int> rtcs;

		add_k_retic(tree, p, k + 1, p_1, rtcs, pos_k);
		if (!pos_k)
		{
			vec = "Not possible to add " + to_string(k + 1) + " reticulations." + '\n';
			cont.push_back(vec);
			vec.clear();
		}

		else
		{
			vec = "For k = " + to_string(k) + " probability of k + 1 usual net: " + to_string(p_1) + '\n';
			cont.push_back(vec);
			vec.clear();
			rtcs.clear();

			add_k_retic(tree, p, k, p_2, rtcs, pos_k);
			add_retic_to_net(tree, p, k + 1, p_2, rtcs);

			if (p_2 != 1000)
			{
				vec = "For k = " + to_string(k) + " probability of k + 1 increment net: " + to_string(p_2) + '\n';
				cont.push_back(vec);
				vec.clear();
			}
			else
			{
				vec = "For k = " + to_string(k) + " k + 1 increment net is not reachable from k optimal net." + '\n';
				cont.push_back(vec);
				vec.clear();
			}



			bool opt = (abs(p_1 - p_2) < eps);
			vec = "For the precision = " + to_string(eps) + " the answer is " + to_string(opt) + '\n';
			cont.push_back(vec);
			vec.clear();
		}
		i++;
	}
	fin.close();
}
