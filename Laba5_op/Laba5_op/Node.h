#pragma once
#include "libraries.h"

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


