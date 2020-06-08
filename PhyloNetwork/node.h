#pragma once
#include <string>
#include <vector>

using namespace std;

class node //����� ���� ������
{
public:
	//vector<node*> r; //������ ���a
	vector<node*> p; //������� ����
	string label; //��� ����
	int number; //����� ����
	bool is_retic; //�������� �� ���� ������ �����������
	node* retic; //������ ���� �����������, ���� ������� - � ����� 
	int num_retic; //��� ���� �����������

	node() //����������� ��� ����������
	{
		//this->r = vector<node*>();
		this->p = vector<node*>();
		this->label = "";
		this->number = 0;
		this->is_retic = false;
	}

	node(vector<node*> n_r, vector<node*> n_p, string n_l, int n_num, bool n_is) //����������� � �����������
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

node* copy_node(node* src); //����������� ������� ������
node* copy_tree(node* src); //����������� ������

