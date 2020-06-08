#pragma once
#include <string>
#include <vector>

using namespace std;

class node //Класс узел дерева
{
public:
	//vector<node*> r; //Предок узлa
	vector<node*> p; //Потомки узла
	string label; //Имя узла
	int number; //Номер узла
	bool is_retic; //Является ли узел частью ретикуляции
	node* retic; //Второй узел ретикуляции, если текущий - её часть 
	int num_retic; //Имя узла ретикуляции

	node() //Конструктор без параметров
	{
		//this->r = vector<node*>();
		this->p = vector<node*>();
		this->label = "";
		this->number = 0;
		this->is_retic = false;
	}

	node(vector<node*> n_r, vector<node*> n_p, string n_l, int n_num, bool n_is) //Конструктор с параметрами
	{
		/*for (int i = 0; i++; i < n_r.size())
			this->r.push_back(n_r[i]);*/
		for (int i = 0; i++; i < n_p.size())
			this->p.push_back(n_p[i]);
		this->label = n_l;
		this->number = n_num;
		this->is_retic = n_is;
	}
}
;

node* copy_node(node* src); //Копирование вершины дерева
node* copy_tree(node* src); //Копирование дерева

