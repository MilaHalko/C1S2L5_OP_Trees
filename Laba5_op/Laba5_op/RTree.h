#pragma once
#include "Node.h"
#include "Rectangle.h"
#include <vector>

class RTree 
{
    Node* root;
    int height;
private:
    vector<Node*> divideNodeByFourParts(Rectangle);

public:
    RTree(float x1, float y1, float x2, float y2) 
    {
        root = new Node();
        root->rect.leftDown = { x1, y1 };
        root->rect.rightUp = { x2, y2 };
        height = 4; // макс детей
        buildTree(root);
    }
    Node* getRoot() { return root; }

    void buildTree(Node* node, int h = 1);
    void addPoint(Node* node, PointOnMap point, int h = 1);

    void findPointsInRect(Node* node, Rectangle rect, string type, string subtype, vector<PointOnMap>& result);
    void findPointsInCircle(Node* node, PointOnMap center, float R, string type, string subtype, vector<PointOnMap>& result);
};