#include "reticulations.h"

void add_retic(node* tree, vector<int> edg_1, vector<int> edg_2, int num_ret)
{
	node* t_0; //4 узла - составляющие 2 дуг,
	node* t_1; //между которыми вставляются ретикуляции
	node* t_2;
	node* t_3;
	node* ret_0 = new node(); //2 узла - составляющие ретикуляции, 
	node* ret_1 = new node(); //которые вставляются посередине исходных дуг

	t_0 = get_to_node(tree, edg_1[0]); //Начало 1й дуги
	t_1 = get_to_node(tree, edg_2[0]); //Начало 2й дуги

	t_2 = get_to_node(tree, edg_1[1]); //Конец 1й дуги
	t_3 = get_to_node(tree, edg_2[1]); //Конец 2й дуги

	ret_0->p.push_back(t_2);
	ret_1->p.push_back(t_3);

	ret_0->is_retic = true;
	ret_1->is_retic = true;

	ret_0->retic = ret_1;

	ret_0->label = "#H" + to_string(num_ret);
	ret_1->label = "#H" + to_string(num_ret);

	if (t_0->p[0]->number == t_2->number)
		t_0->p[0] = ret_0;
	else
		t_0->p[1] = ret_0;
	if (t_1->p[0]->number == t_3->number)
		t_1->p[0] = ret_1;
	else
		t_1->p[1] = ret_1;
}

bool check_pairs(vector<vector<vector<int>>> prs, vector<int> nums)
{
	bool f = true;
	int k = 0; int m = 0;

	for (int i = 0; i < nums.size() && f; i++)
	{
		k = nums[i];
		for (int j = i + 1; j < nums.size() && f; j++)
		{
			m = nums[j];
			if (!(prs[k][0] != prs[m][0] && prs[k][1] != prs[m][1] && prs[k][0] != prs[m][1] && prs[k][1] != prs[m][0]))
				f = false;
		}
	}
	return f;
}

vector<vector<int>> get_retic_sets(vector<vector<vector<int>>> prs, vector<vector<int>> sets)
{
	vector<vector<int>> res;

	for (int i = 0; i < sets.size(); i++)
		if (check_pairs(prs, sets[i]))
			res.push_back(sets[i]);
	
	return res;
}

void add_k_retic(node* tree, vector<vector<vector<int>>> prs, int k, double& prob, vector<int>& rtcs)
{
	vector<int> u;
	vector<int> v;
	node* tmp;
	string net; string res;
	int t = 0;
    double p = 0, max = 1000;
	int r = 0;

	int* a = new int[prs.size()];

	for (int i = 0; i < prs.size(); i++)
		a[i] = i + 1;

	vector<vector<int>> sets = get_sets(a, k, prs.size());

	vector<vector<int>> retic_sets = get_retic_sets(prs, sets);

	for (int i = 0; i < retic_sets.size(); i++)
	{
		tmp = copy_tree(tree);
		for (int j = 0; j < k; j++)
		{ 
			t = retic_sets[i][j];
			u = prs[t][0];
			v = prs[t][1];

			add_retic(tmp, u, v, j + 1);
		}
		net = net_to_string(tmp);
		get_prob(net, p);
		if (abs(p) < max)
		{
			max = abs(p);
			r = i;
			res = net;
		}
		net.clear();
	}	

	for (int i = 0; i < retic_sets[r].size(); i++)
		rtcs.push_back(retic_sets[r][i]);
	prob = max;
}

//bool vec_contains(vector<int> cur, vector<int> src)
//{
//	for (int i = 0; i < cur.size(); i++)
//		if (find(src.begin(), src.end(), cur[i]) == src.end())
//			return false;
//
//	return true;
//}

void add_retic_to_net(node* tree, vector<vector<vector<int>>> prs, int k, double& prob, vector<int>& rtcs)
{
	vector<int> u;
	vector<int> v;
	node* tmp;
	string net; string k_net;
	int t = 0;
	double p = 0, max = 1000;
	bool f = 0;
	vector<int> tm; vector<vector<int>> retic_sets;

	for (int i = 0; i < prs.size(); i++)
	{
		for (int j = 0; j < rtcs.size(); j++)
			tm.push_back(rtcs[j]);
		tm.push_back(i);

		if (check_pairs(prs, tm))
			retic_sets.push_back(tm);

		tm.clear();
	}

	for (int i = 0; i < retic_sets.size(); i++)
	{
		tmp = copy_tree(tree);
		for (int j = 0; j < k; j++)
		{
			t = retic_sets[i][j];
			u = prs[t][0];
			v = prs[t][1];

			add_retic(tmp, u, v, j + 1);
		}
		net = net_to_string(tmp);
		get_prob(net, p);
		if (abs(p) < max)
		{
			max = abs(p);
			k_net = net;
		}
		net.clear();
	}

	prob = max;
}