#include "RTree.h"

vector<Node*> RTree::divideNodeByFourParts(Rectangle rect)
{
    Node* leftUp = new Node(), * rightUp = new Node(), * leftBottom = new Node(), * rightBottom = new Node;
    float x1 = rect.leftDown.x, y1 = rect.leftDown.y,
           x2 = rect.rightUp.x,  y2 = rect.rightUp.y;

    float midX = (x1 + x2) / 2;
    float midY = (y1 + y2) / 2;

    leftUp->rect.leftDown = { x1, midY };
    leftUp->rect.rightUp = { midX, y2 };
    rightUp->rect.leftDown = { midX, midY };
    rightUp->rect.rightUp = { x2, y2 };
    leftBottom->rect.leftDown = { x1,y1 };
    leftBottom->rect.rightUp = { midX, midY };
    rightBottom->rect.leftDown = { midX, y1 };
    rightBottom->rect.rightUp = { x2, midY };

    vector<Node*> result = { leftUp, rightUp, leftBottom, rightBottom };
    return result;
}

void RTree::buildTree(Node* node, int h)
{
    vector<Node*> children = divideNodeByFourParts(node->rect);
    for (int i = 0; i < children.size(); i++) 
        node->children.push_back(children[i]);
    if (h < height) 
        for (int i = 0; i < node->children.size(); i++)
            buildTree(node->children[i], h + 1);
}

void RTree::addPoint(Node* node, PointOnMap point, int h)
{
    if (!check_point_rectangle(point, node->rect))
        return;
    if (h == height) {
        Node* newNode = new Node();
        newNode->point = point;
        node->children.push_back(newNode);
    }
    else
    {
        for (int i = 0; i < node->children.size(); i++)
            addPoint(node->children[i], point, h + 1);
    }
}

void RTree::findPointsInRect(Node* node, Rectangle rect, string type, string subtype, vector<PointOnMap>& result)
{
    if (node->children.size() > 0)
    {
        if (check_rectangles(node->rect, rect)) 
        {
            for (int i = 0; i < node->children.size(); i++) 
            {
                findPointsInRect(node->children[i], rect, type, subtype, result);
            }
        }
    }
    else
        if (node->point.x != -1e9 && node->point.y != -1e9) 
        {
            if (check_point_rectangle(node->point, rect) && node->point.type == type && node->point.subtype == subtype) 
            {
                result.push_back(node->point);
            }
        }
}

void RTree::findPointsInCircle(Node* node, PointOnMap center, float R, string type, string subtype, vector<PointOnMap>& result)
{
    if (node->children.size() > 0) {
        if (check_circle_rectangle(center, R, node->rect)) {
            for (int i = 0; i < node->children.size(); i++) {
                findPointsInCircle(node->children[i], center, R, type, subtype, result);
            }
        }
    }
    else
        if (node->point.x != -1e9 && node->point.y != -1e9) {
            if (check_circle_point(center, R, node->point) && node->point.type == type && node->point.subtype == subtype) {
                result.push_back(node->point);
            }
        }
}