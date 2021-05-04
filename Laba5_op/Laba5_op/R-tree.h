#pragma once
#include "libraries.h"
int MaxDots = 5;


struct Dot
{
	float latitude;
	float longitude;
	string data;
};

struct Node
{
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
    Node* root;
    int switcher;
    
    void ChooseLeaf();
    void Split(Node*);
    void CheckingLocation(Node*, Dot, float, vector <Dot>&);
    
public:
	Tree();
	~Tree();
    
    Node* getRoot() {return root;}
	void insert(string);
    void FindLocatios (Dot, float, vector <Dot>&);
};

Tree::Tree()
{
	root = nullptr;
	switcher = 0;
}

Tree::~Tree()
{
}

inline void Tree::insert(string data)
{
	ChooseLeaf();
	AdjustBounds();
	// .. 
}

inline void Tree::ChooseLeaf(Node* root, Dot dot)
{
	if (root->child_1 == nullptr && root->child_2 == nullptr)
	{
		if (root->dots.size() <= MaxDots + 1)
		{
			root->dots.push_back(dot);
		}
		else
		{
			Split(root);
		}
	}
	else
	{

	}
}

inline void Tree::Split(Node*)
{
	switcher = (switcher + 1) % 2;

}

inline int is_better(Node* child_1, Node* child_2, Dot dot)
{

}


void Tree::FindLocatios(Dot location, float radius, vector <Dot> &locations)
{
    CheckingLocation(root, location, radius, locations);
}


void Tree::CheckingLocation(Node *node, Dot location, float radius, vector <Dot> &locations)
{
    if (pow(location.getX() - node->left.getX(), 2)  +  (pow(location.getY() - node->left.getY(), 2)  <=  pow(radius, 2))) {
        CheckingLocation(node->left, location, radius, locations);
    }

    if ((location.type == node->right.type) && (pow(location.getX() - node->rigth.getX(), 2) + (pow(location.getY() - node->right.getY(), 2) <= pow(radius, 2))){
        CheckingLocation(node->right, location, radius, locations);
    }
}
