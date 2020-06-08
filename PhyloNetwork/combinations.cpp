#include "combinations.h"

//bool equal_vec(vector<int> left, vector<int> right)
//{
//	if (left.size() != right.size())
//		return false;
//	else
//	{
//		for (int i = 0; i < left.size(); i++)
//			if (left[i] != right[i])
//				return false;
//		return true;
//	}
//}

void get_edges(node* r, vector<vector<int>>& edg)
{
	vector<int> tmp;
	if (r)
	{
		if (r->p.size() != 0)
		{
			tmp.push_back(r->number);
			tmp.push_back(r->p[0]->number);
			if (tmp[0] !=0) 
				edg.push_back(tmp);
			tmp.pop_back();
			tmp.push_back(r->p[1]->number);
			if (tmp[0] != 0)
				edg.push_back(tmp);

			tmp.clear();

			get_edges(r->p[0], edg);
			get_edges(r->p[1], edg);
		}
	}
}

bool next_set(int *a, int n, int m)
{
	int k = m;
	for (int i = k - 1; i >= 0; --i)
		if (a[i] < n - k + i + 1)
		{
			++a[i];
			for (int j = i + 1; j < k; ++j)
				a[j] = a[j - 1] + 1;
			return true;
		}
	return false;
}

void get_pairs(vector<vector<int>> edg, int** d, vector<vector<vector<int>>>& prs)
{
	vector<int> u;
	vector<int> v;
	vector<vector<int>> tmp;

	for (int i = 0; i < edg.size(); i++)
		for (int j = 0; j < edg.size(); j++)
		{
			u = edg[i];
			v = edg[j];

			if (d[u[0]][v[1]] == 10000)
			{
				tmp.push_back(u);
				tmp.push_back(v);
				prs.push_back(tmp);

				tmp.clear();
			}
		}
}

vector<vector<int>> get_sets(int* a, int k, int n)
{
	vector<vector<int>> res;
	vector<int> tmp;

	int j = 0;

	for (int i = 0; i < k; i++)
		tmp.push_back(a[i] - 1);

	res.push_back(tmp);

	tmp.clear();

	while (next_set(a, n, k))
	{
		j++;
		for (int i = 0; i < k; i++)
			tmp.push_back(a[i] - 1);

		res.push_back(tmp);

		tmp.clear();
	}

	return res;
}