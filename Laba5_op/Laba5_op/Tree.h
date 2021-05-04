#pragma once
#include "Node.h"
#include "libraries.h"

class Tree
{
public:
	Tree();
	void GetCoordinates(float&, string&, Dot);
	void insert(string);

private:
	Node* root;
	int switcher;

	void ChooseLeaf(Node*, Dot);
	void Split(Node*);

};

void readFile(string, Tree);
