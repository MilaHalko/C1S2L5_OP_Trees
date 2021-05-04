#pragma once
#include "libraries.h"
#define MaxEntries = 16;
#define MinEntries = 2;


struct Dot
{
	float latitude;
	float Longitude;
	string data;
};

class Node
{
public:
	Node();
	int count;
	Node* child_1;
	Node* child_2;
	
	void set_MBR(float, float, float, float);
	float left;
	float top; 
	float right;
	float bottom;

	vector<Dot> dots;
};

Node::Node()
{
	count = 0;
	child_1 = nullptr;
	child_2 = nullptr;
	left = 0;
	top = 0;
	right = 0;
	bottom = 0;
}

inline void Node::set_MBR(float left, float top, float right, float bottom)
{

}

class Tree
{
public:
	Tree();
	~Tree();

	
private:
	Node* root;
};

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
}