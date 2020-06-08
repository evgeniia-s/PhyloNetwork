#include "floyd_warshall.h"

void number_of_nodes(node* r, int& n)
{
	if (r)
	{
		n++;
		if (r->p.size() != 0)
		{
			number_of_nodes(r->p[0], n);
			if (r->p.size() > 1)
				number_of_nodes(r->p[1], n);
		}
	}
}

node* get_to_node(node* r, int num)
{
	if (r)
	{
		if (r->number == num)
			return r;
		node* res;

		if (r->p.size() != 0)
		{
			res = get_to_node(r->p[0], num);

			if (res == nullptr && r->p.size() > 1)
				res = get_to_node(r->p[1], num);
			return res;
		}
		
		else
			return nullptr;
	}
	else
		return nullptr;
}

bool is_edge(node* r, int num)
{
	if (r->p.size() != 0)
	{
		node* r_0 = r->p[0];
		if (r_0->number == num)
			return true;
		else
			if (r->p.size() > 1)
			{
				node* r_1 = r->p[1];
				if (r_1->number == num)
					return true;
			}
		return false;
	}
	else
		return false;
}

void floyd(node* r, int** d, int n)
{
	for (int i = 0; i < n; i++) //Инициализация матрицы d 
		for (int j = 0; j < n; j++)
		{
			node* found_node = get_to_node(r, i);
			if (i == j)
				d[i][j] = 0; //Если оба узла совпадают
			else
				if (is_edge(found_node, j))
					d[i][j] = 1; //Если ребро существует
				else
					d[i][j] = 10000; //Если ребро не существует	
									 //Большое число - аналог бесконечности в алгоритме
		}

	for (int k = 0; k < n; k++) //Начало алгоритма
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (d[i][k] + d[k][j] < d[i][j])
				
					d[i][j] = d[i][k] + d[k][j];
}



