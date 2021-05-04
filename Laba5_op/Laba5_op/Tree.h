#pragma once
#include "Node.h"
#include "libraries.h"

class Tree
{
public:
	Tree();
	void GetCoordinates(float&, string&, Dot);
	void insert(string);
    void output(vector<Dot>&, string);
	void print();

private:
	Node* root;
	int switcher;

	void ChooseLeaf(Node*, Dot);
	void Split(Node*);

};

void readFile(string, Tree);
