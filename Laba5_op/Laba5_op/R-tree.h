#pragma once
#include "libraries.h"
int MaxDots = 10;


struct Dot
{
	float latitude;
	float longitude;
	string data;
};

class Node
{
public:
	Node();
	Node* child_1;
	Node* child_2;
	
	void AdjustBounds(Dot);
	float left;
	float top; 
	float right;
	float bottom;

	vector<Dot> dots;
};

Node::Node()
{
	child_1 = nullptr;
	child_2 = nullptr;
	// MBR
	left = 360;
	top = 0;
	right = 0;
	bottom = 180;
}

inline void Node::AdjustBounds(Dot dot)
{
	if (dot.latitude > right) right = dot.latitude;
	if (dot.latitude < left) left = dot.latitude;
	if (dot.longitude > top) top = dot.longitude;
	if (dot.longitude < bottom) bottom = dot.longitude;
}

class Tree
{
public:
	Tree();
	~Tree();

	void insert(string);
private:
	Node* root;
	int switcher;
	
	void ChooseLeaf(Node*, Dot);
	void Split(Node*);
};

Tree::Tree()
{
	root = new Node;
	switcher = 0;
}

Tree::~Tree()
{
}

inline void Tree::insert(string data) // на вход идет строка
{
	Dot dot;
	// parsing
	ChooseLeaf(root, dot);
}

inline void Tree::ChooseLeaf(Node* root, Dot dot)
{
	if (root->child_1 == nullptr && root->child_2 == nullptr) // если нет детей
	{
		root->AdjustBounds(dot); // расширить прямоугольник
		if (root->dots.size() < MaxDots) // если не переполнен
		{
			root->dots.push_back(dot); // добавляем точку
		}
		else
		{
			Split(root); // разделяем 
			ChooseLeaf(root, dot); // проверяем снова
		}
	}
	else
	{
		root->AdjustBounds(dot); // расширить прямоугольник
		if (switcher == 0) ChooseLeaf(root->child_1, dot); // переход к ребенку
		else ChooseLeaf(root->child_2, dot);
	}
}

inline void Tree::Split(Node* root)
{
	switcher = (switcher + 1) % 2; // чтобы делилось по горизонтали и вертикали 
	root->child_1 = new Node;
	root->child_2 = new Node;

	if (switcher == 0)
	{
		float half = (root->top - root->bottom) / 2; // половина высоты

		for (size_t i = 0; i < MaxDots; i++)
		{
			if (root->dots[i].latitude >= half)
			{
				root->child_1->AdjustBounds(root->dots[i]);
				root->child_1->dots.push_back(root->dots[i]);
			}
		}
	}
	else
	{
		float half = (root->right - root->left) / 2; // половина ширины

		for (size_t i = 0; i < MaxDots; i++)
		{
			if (root->dots[i].longitude >= half)
			{
				root->child_1->AdjustBounds(root->dots[i]);
				root->child_1->dots.push_back(root->dots[i]);
			}
		}
	}
}

